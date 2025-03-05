#include "lvgl_driver.h"
#include <lvgl.h>
#include <GxEPD2_BW.h>
#include <vector>

#define LV_HOR_RES_MAX 480
#define LVGL_TICK_PERIOD_MS 500

// Définition des pins SPI et de l’écran e-paper
#define EPD_SCK_PIN  5     // SPI Clock
#define EPD_MOSI_PIN 6     // SPI MOSI
#define EPD_CS_PIN   4     // Chip Select de l’e-paper
#define EPD_RST_PIN  2     // Reset de l’e-paper
#define EPD_DC_PIN   3     // Data/Command (DC)
#define EPD_BUSY_PIN 1     // Busy de l’e-paper

constexpr size_t BUFFER_SIZE = GxEPD2_370_TC1::WIDTH * GxEPD2_370_TC1::HEIGHT;

// Buffer de dessin pour LVGL
static lv_disp_draw_buf_t draw_buf;

// Instanciation de l’écran avec la bonne classe GxEPD2
GxEPD2_BW<GxEPD2_370_TC1, GxEPD2_370_TC1::HEIGHT> display(
    GxEPD2_370_TC1(EPD_CS_PIN, EPD_DC_PIN, EPD_RST_PIN, EPD_BUSY_PIN)
);

static double luminance(lv_color_t color);

// Efface complètement l’écran au démarrage
void clear_display()
{
    display.setFullWindow(); // Mode plein écran
    display.fillScreen(GxEPD_WHITE); // Efface l’écran en blanc
    display.display(); // Rafraîchit pour appliquer la couleur blanche
}

lv_area_t pad_area(const lv_area_t& area)
{
    lv_area_t padded_area = area;

    // Round down to the nearest multiple of 8.
    padded_area.x1 = area.x1 - area.x1 % 8;
    padded_area.y1 = area.y1 - area.y1 % 8;

    // Round up to the nearest multiple of 8. -1 because the boundary is inclusive.
    padded_area.x2 = (area.x2 + 7) / 8 * 8 - 1;
    padded_area.y2 = (area.y2 + 7) / 8 * 8 - 1;

    return padded_area;
}

void expand_invalidated_area(lv_disp_drv_t* disp_drv, lv_area_t* area)
{
    // Expand the area to the nearest multiple of 8.
    area->x1 = area->x1 - area->x1 % 8;
    area->y1 = area->y1 - area->y1 % 8;
    area->x2 = (area->x2 + 7) / 8 * 8 - 1;
    area->y2 = (area->y2 + 7) / 8 * 8 - 1;
}

// Callback pour la mise à jour de l’écran e-paper
void flush_display(lv_disp_drv_t* disp, const lv_area_t* area, lv_color_t* color_p)
{
    Serial.println("flush_display");

    lv_coord_t width = lv_area_get_width(area);

    // Remplir la fenêtre partielle avec des pixels LVGL
    for (auto y = area->y1; y <= area->y2; y++)
    {
        for (auto x = area->x1; x <= area->x2; x++)
        {
            lv_color_t pixel = color_p[(y - area->y1) * width + (x - area->x1)];

            display.drawPixel(x, y, pixel.full != 0xFF ? GxEPD_BLACK : GxEPD_WHITE);
        }
    }

    display.display(true);

    // Signaler à LVGL que le rafraîchissement est terminé
    lv_disp_flush_ready(disp);
}

// Fonction pour incrémenter le tick de LVGL
void increase_lvgl_tick(void* arg)
{
    lv_tick_inc(LVGL_TICK_PERIOD_MS);
}

void lvgl_display_init()
{
    auto buf = new lv_color_t[BUFFER_SIZE]; // Taille du buffer (ajuster selon la RAM disponible)

    // Initialisation SPI et écran e-paper
    SPI.begin(EPD_SCK_PIN, -1, EPD_MOSI_PIN);
    display.init(115200, true, 2, false);
    display.setRotation(1);
    clear_display(); // Efface l’écran en blanc

    // Initialisation du buffer de dessin LVGL
    lv_disp_draw_buf_init(&draw_buf, buf, nullptr, BUFFER_SIZE);

    // Configuration du driver LVGL
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = display.width();
    disp_drv.ver_res = display.height();
    disp_drv.rounder_cb = expand_invalidated_area;
    disp_drv.flush_cb = flush_display;
    disp_drv.full_refresh = true;
    disp_drv.antialiasing = false;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    // Configuration du timer périodique pour LVGL
    const esp_timer_create_args_t lvgl_tick_timer_args = {
        .callback = &increase_lvgl_tick,
        .name = "lvgl_tick"
    };
    esp_timer_handle_t lvgl_tick_timer;
    esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer);
    esp_timer_start_periodic(lvgl_tick_timer, LVGL_TICK_PERIOD_MS * 1000); // En microsecondes
}

static double luminance(lv_color_t color)
{
    // Transform RGB565 to RGB888.
    uint8_t r8 = (color.ch.red * 527 + 23) >> 6;
    uint8_t g8 = (color.ch.green * 259 + 33) >> 6;
    uint8_t b8 = (color.ch.blue * 527 + 23) >> 6;

    return 0.299 * r8 / 255 +
        0.587 * g8 / 255 +
        0.114 * b8 / 255;
}
