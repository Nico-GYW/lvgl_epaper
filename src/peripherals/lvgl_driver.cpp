#include "lvgl_driver.h"
#include <lvgl.h>
#include <GxEPD2_BW.h>

// Définition des pins SPI et de l’écran e-paper
#define EPD_SCK_PIN  5     // SPI Clock
#define EPD_MOSI_PIN 6     // SPI MOSI
#define EPD_CS_PIN   4     // Chip Select de l’e-paper
#define EPD_RST_PIN  2     // Reset de l’e-paper
#define EPD_DC_PIN   3     // Data/Command (DC)
#define EPD_BUSY_PIN 1     // Busy de l’e-paper

// Instanciation de l’écran avec la bonne classe GxEPD2
GxEPD2_BW<GxEPD2_370_TC1, GxEPD2_370_TC1::HEIGHT> display(
    GxEPD2_370_TC1(EPD_CS_PIN, EPD_DC_PIN, EPD_RST_PIN, EPD_BUSY_PIN)
);

// Buffer de dessin pour LVGL
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[LV_HOR_RES_MAX * 10];  // Taille du buffer (ajuster selon la RAM disponible)

// Efface complètement l’écran au démarrage
void clear_display() {
    display.setFullWindow();                // Mode plein écran
    display.fillScreen(GxEPD_WHITE);        // Efface l’écran en blanc
    display.display();                      // Rafraîchit pour appliquer la couleur blanche
}

// Callback pour la mise à jour de l’écran e-paper
void ssd1677_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
    // Préparer la mise à jour de la fenêtre
    Serial.println("ssd1677_flush triggered");
    display.setPartialWindow(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1);

    display.firstPage();
    do {
        // Remplir la fenêtre partielle avec des pixels LVGL
        for (int y = area->y1; y <= area->y2; y++) {
            for (int x = area->x1; x <= area->x2; x++) {
                lv_color_t pixel = color_p[(y - area->y1) * (area->x2 - area->x1 + 1) + (x - area->x1)];
                display.drawPixel(x, y, pixel.full == 0 ? GxEPD_BLACK : GxEPD_WHITE);
            }
        }
    } while (display.nextPage());

    // Signaler à LVGL que le rafraîchissement est terminé
    lv_disp_flush_ready(disp);
}


// Fonction pour incrémenter le tick de LVGL
void increase_lvgl_tick(void *arg) {
    lv_tick_inc(LVGL_TICK_PERIOD_MS);
}

void init_lvgl_display() {
    // Initialisation SPI et écran e-paper
    SPI.begin(EPD_SCK_PIN, -1, EPD_MOSI_PIN);
    display.init(115200, true, 2, false);
    clear_display();  // Efface l’écran en blanc

    // Initialisation du buffer de dessin LVGL
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, LV_HOR_RES_MAX * 10);

    // Configuration du driver LVGL
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = display.width();
    disp_drv.ver_res = display.height();
    disp_drv.flush_cb = ssd1677_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    // Configuration du timer périodique pour LVGL
    const esp_timer_create_args_t lvgl_tick_timer_args = {
        .callback = &increase_lvgl_tick,
        .name = "lvgl_tick"
    };
    esp_timer_handle_t lvgl_tick_timer;
    esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer);
    esp_timer_start_periodic(lvgl_tick_timer, LVGL_TICK_PERIOD_MS * 1000);  // En microsecondes
}