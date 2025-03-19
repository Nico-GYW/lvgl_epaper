#include "lvgl_driver.h"
#include <lvgl.h>
#include <GxEPD2_BW.h>
#include "GxEPD2_370_TC1_mod.h"
#include <utils/timer.hpp>

#define LV_HOR_RES_MAX 480
#define LVGL_TICK_PERIOD_MS 5

// Définition des pins SPI et de l’écran e-paper
#define EPD_SCK_PIN  5     // SPI Clock
#define EPD_MOSI_PIN 6     // SPI MOSI
#define EPD_CS_PIN   4     // Chip Select de l’e-paper
#define EPD_RST_PIN  2     // Reset de l’e-paper
#define EPD_DC_PIN   3     // Data/Command (DC)
#define EPD_BUSY_PIN 1     // Busy de l’e-paper

using DisplayDriverClass = GxEPD2_370_TC1_mod;

constexpr size_t BUFFER_SIZE = DisplayDriverClass::WIDTH * DisplayDriverClass::HEIGHT;

// Buffer de dessin pour LVGL
static lv_disp_draw_buf_t draw_buf;

static size_t area_count = 0;

// Instanciation de l’écran avec la bonne classe GxEPD2
GxEPD2_BW<DisplayDriverClass, DisplayDriverClass::HEIGHT> display(
    DisplayDriverClass(EPD_CS_PIN, EPD_DC_PIN, EPD_RST_PIN, EPD_BUSY_PIN)
);

void partial_update_one_region(lv_disp_drv_t* disp, const lv_area_t* area, lv_color_t* color_p);
void partial_update_entire_screen(lv_disp_drv_t* disp, const lv_area_t* area, lv_color_t* color_p);
void blit_lvgl_framebuffer_to_display(const lv_area_t* area, lv_color_t* color_p);

// Efface complètement l’écran au démarrage
void clear_display()
{
    display.setFullWindow(); // Mode plein écran
    display.fillScreen(GxEPD_WHITE); // Efface l’écran en blanc
    display.display(); // Rafraîchit pour appliquer la couleur blanche
}

void rounder_cp(lv_disp_drv_t* disp_drv, lv_area_t* area)
{
    // Expand the area to the nearest multiple of 8.
    area->x1 = area->x1 - area->x1 % 8;
    area->y1 = area->y1 - area->y1 % 8;
    area->x2 = (area->x2 + 7) / 8 * 8 - 1;
    area->y2 = (area->y2 + 7) / 8 * 8 - 1;
}

void render_start_cb(lv_disp_drv_t* disp_drv)
{
    Serial.println("Render start");
    area_count = 0;
}

// Callback pour la mise à jour de l’écran e-paper
void flush_cb(lv_disp_drv_t* disp, const lv_area_t* area, lv_color_t* color_p)
{
    Serial.println(area->x1);
    Serial.println(area->y1);
    Serial.println(area->x2);
    Serial.println(area->y2);

    auto width = lv_area_get_width(area);
    auto height = lv_area_get_height(area);

    // TODO(arosca): Why does LVGL update this area?
    // I think it's the size of the digit pressed, but as if it were positioned at 0,0.
    if (area->x1 == 0 && area->y1 == 0 && width <= 32 && height <= 48)
    {
        lv_disp_flush_ready(disp);
        return;
    }

    area_count++;

    Serial.println("Area count");
    Serial.println(area_count);

    if (area_count == 1 and lv_disp_flush_is_last(disp))
    {
        auto t = Timer("partial update");
        partial_update_one_region(disp, area, color_p);
    }
    else
    {
        auto t = Timer("full update");
        partial_update_entire_screen(disp, area, color_p);
    }

    lv_disp_flush_ready(disp);
}

void partial_update_one_region(lv_disp_drv_t* disp, const lv_area_t* area, lv_color_t* color_p)
{
    lv_coord_t width = lv_area_get_width(area);
    lv_coord_t height = lv_area_get_height(area);

    display.setPartialWindow(area->x1, area->y1, width, height);

    display.firstPage();
    do
    {
        blit_lvgl_framebuffer_to_display(area, color_p);
    }
    while (display.nextPage());
}

void partial_update_entire_screen(lv_disp_drv_t* disp, const lv_area_t* area, lv_color_t* color_p)
{
    blit_lvgl_framebuffer_to_display(area, color_p);

    if (lv_disp_flush_is_last(disp))
    {
        display.display(true);
    }
}

void blit_lvgl_framebuffer_to_display(const lv_area_t* area, lv_color_t* color_p)
{
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
    disp_drv.rounder_cb = rounder_cp;
    disp_drv.render_start_cb = render_start_cb;
    disp_drv.flush_cb = flush_cb;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    // Configuration du timer périodique pour LVGL
    esp_timer_create_args_t lvgl_tick_timer_args{};
    lvgl_tick_timer_args.callback = &increase_lvgl_tick;
    lvgl_tick_timer_args.name = "lvgl_tick";

    esp_timer_handle_t lvgl_tick_timer;
    esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer);
    esp_timer_start_periodic(lvgl_tick_timer, LVGL_TICK_PERIOD_MS * 1000); // En microsecondes
}
