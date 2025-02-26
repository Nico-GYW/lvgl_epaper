#include "lvgl_driver.h"
#include <lvgl.h>
#include <GxEPD2_BW.h>

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

// Callback pour la mise à jour de l’écran e-paper
void ssd1677_flush(lv_disp_drv_t* disp, const lv_area_t* area, lv_color_t* color_p)
{
    // Préparer la mise à jour de la fenêtre
    Serial.println("ssd1677_flush triggered");

    auto width = area->x2 - area->x1 + 1;
    auto height = area->y2 - area->y1 + 1;

    display.setPartialWindow(area->x1, area->y1, width, height);
    display.firstPage();

    do
    {
        // Remplir la fenêtre partielle avec des pixels LVGL
        for (auto y = area->y1; y <= area->y2; y++)
        {
            for (auto x = area->x1; x <= area->x2; x++)
            {
                lv_color_t pixel = color_p[(y - area->y1) * width + (x - area->x1)];

                display.drawPixel(x, y, pixel.full == 0 ? GxEPD_BLACK : GxEPD_WHITE);

                // const double l = luminance(pixel);
                //
                // Serial.println(l);
                //
                // uint16_t color = 0;
                //
                // if (pixel.full == 0xFFFFFF)
                // {
                //     color = GxEPD_WHITE;
                // }
                // else if (pixel.full == 0x000000)
                // {
                //     color = GxEPD_BLACK;
                // }
                // else if (l >= 0.5)
                // {
                //     color = GxEPD_LIGHTGREY;
                // }
                // else
                // {
                //     color = GxEPD_DARKGREY;
                // }
                //
                // display.drawPixel(x, y, color);
            }
        }
    } while (display.nextPage());

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
    esp_timer_start_periodic(lvgl_tick_timer, LVGL_TICK_PERIOD_MS * 1000); // En microsecondes
}

static double luminance(lv_color_t color)
{
    return 0.299 * color.ch.red / 255 +
        0.587 * color.ch.green / 255 +
        0.114 * color.ch.blue / 255;
}
