#include "lvgl_driver.hpp"

#include <array>
#include <lvgl.h>
#include <utils/timer.hpp>
#include <esp_timer.h>

#include "spi.hpp"
#include "commands.hpp"

#define LVGL_TICK_PERIOD_MS 5

constexpr size_t BUFFER_SIZE = GooDisplay::DISPLAY_WIDTH * GooDisplay::DISPLAY_HEIGHT;

// Buffer de dessin pour LVGL
static lv_disp_draw_buf_t draw_buf;

static void rounder_cp(lv_disp_drv_t* disp_drv, lv_area_t* area)
{
    // Expand the area to the nearest multiple of 8.
    area->x1 = area->x1 - area->x1 % 8;
    area->y1 = area->y1 - area->y1 % 8;
    // TODO(arosca): 0 doesn't work
    area->x2 = (area->x2 + 7) / 8 * 8 - 1;
    area->y2 = (area->y2 + 7) / 8 * 8 - 1;
}

static std::vector<GooDisplay::PartialFramebuffer> partial_framebuffers;

static void render_start_cb(lv_disp_drv_t* disp_drv)
{
    GooDisplay::begin_partial_draw();
    //    Serial.println("Render start");
    //    area_count = 0;
}

// Callback pour la mise à jour de l’écran e-paper
static void flush_cb(lv_disp_drv_t* disp, const lv_area_t* area, lv_color_t* color_p)
{
    printf("%s\n", "flush callback");
    printf("%s\n", "area size");
    printf("%d\n", area->x1);
    printf("%d\n", area->y1);
    printf("%d\n", area->x2);
    printf("%d\n", area->y2);

    auto width = lv_area_get_width(area);
    auto height = lv_area_get_height(area);

    auto partial_framebuffer = GooDisplay::PartialFramebuffer{
        .buffer = GooDisplay::transform_buffer(color_p, width, height),
        .x = static_cast<uint16_t>(area->x1),
        .y = static_cast<uint16_t>(area->y1),
        .width = static_cast<uint16_t>(width),
        .height = static_cast<uint16_t>(height),
    };

    partial_draw(partial_framebuffer);
    partial_framebuffers.push_back(std::move(partial_framebuffer));

    if (lv_disp_flush_is_last(disp))
    {
        printf("%s\n", "update");
        GooDisplay::partial_update();

        for (const auto& framebuffer : partial_framebuffers)
            partial_draw(framebuffer);

        partial_framebuffers.clear();
    }

    lv_disp_flush_ready(disp);
}

// Fonction pour incrémenter le tick de LVGL
static void increase_lvgl_tick(void* arg)
{
    lv_tick_inc(LVGL_TICK_PERIOD_MS);
}

void lvgl_display_init_goodisplay()
{
    auto buf = new lv_color_t[BUFFER_SIZE]; // Taille du buffer (ajuster selon la RAM disponible)

    GooDisplay::init_spi();
    GooDisplay::EPD_HW_Init_Fast();

    GooDisplay::clear_screen(GooDisplay::Color::WHITE);

    // Initialisation du buffer de dessin LVGL
    lv_disp_draw_buf_init(&draw_buf, buf, nullptr, BUFFER_SIZE);

    // Configuration du driver LVGL
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = GooDisplay::DISPLAY_WIDTH;
    disp_drv.ver_res = GooDisplay::DISPLAY_HEIGHT;
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
