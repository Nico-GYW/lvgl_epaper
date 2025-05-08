#include "lvgl_driver.hpp"

#include <HardwareSerial.h>
#include <array>
#include <esp_timer.h>
#include <lvgl.h>
#include <sys/types.h>
#include <utils/timer.hpp>

#include "commands.hpp"
#include "display/lv_display.h"
#include "spi.hpp"

#define LVGL_TICK_PERIOD_MS 5

constexpr size_t BUFFER_SIZE =
    GooDisplay::DISPLAY_WIDTH * GooDisplay::DISPLAY_HEIGHT;

// Buffer de dessin pour LVGL
static lv_draw_buf_t draw_buf;

static void rounder_cp(lv_area_t *area) {
  // Expand the area to the nearest multiple of 8.
  area->x1 = area->x1 - area->x1 % 8;
  area->y1 = area->y1 - area->y1 % 8;
  // TODO(arosca): 0 doesn't work
  area->x2 = (area->x2 + 7) / 8 * 8 - 1;
  area->y2 = (area->y2 + 7) / 8 * 8 - 1;
}

static std::vector<GooDisplay::PartialFramebuffer> partial_framebuffers;

// Callback pour la mise à jour de l’écran e-paper
static void flush_cb(lv_display_t *disp, const lv_area_t *area,
                     u_int8_t *color_p) {
  static bool first_flush = true;

  if (first_flush) {
    GooDisplay::begin_partial_draw();
  }

  Serial.println("flush callback");
  Serial.println("area size");
  Serial.println(area->x1);
  Serial.println(area->y1);
  Serial.println(area->x2);
  Serial.println(area->y2);

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

  if (lv_display_flush_is_last(disp)) {
    Serial.println("update");
    GooDisplay::partial_update();

    for (const auto &framebuffer : partial_framebuffers)
      partial_draw(framebuffer);

    partial_framebuffers.clear();
  }

  lv_disp_flush_ready(disp);

  first_flush = lv_display_flush_is_last(disp);
}

// Fonction pour incrémenter le tick de LVGL
static void increase_lvgl_tick(void *arg) { lv_tick_inc(LVGL_TICK_PERIOD_MS); }

void lvgl_display_init_goodisplay() {
  auto buf = new lv_color_t[BUFFER_SIZE]; // Taille du buffer (ajuster selon la
                                          // RAM disponible)

  GooDisplay::init_spi();
  GooDisplay::EPD_HW_Init_Fast();

  GooDisplay::clear_screen(GooDisplay::Color::WHITE);

  // for (size_t i = 0; i < 100; i++)
  // {
  //     GooDisplay::draw_pixel(i, 100, GooDisplay::Color::BLACK);
  //     GooDisplay::draw_pixel(i, 101, GooDisplay::Color::BLACK);
  //     GooDisplay::draw_pixel(i, 102, GooDisplay::Color::BLACK);
  // }

  // GooDisplay::fill(GooDisplay::Color::BLACK);

  // GooDisplay::partial_draw(0, 0, GooDisplay::DISPLAY_WIDTH,
  // GooDisplay::DISPLAY_HEIGHT);

  // const unsigned char buffer[] = {
  //     (unsigned char)0b00000000,
  //     (unsigned char)0b00000000,
  //     (unsigned char)0b00000000,
  //     (unsigned char)0b00101011,
  //     (unsigned char)0b01010101,
  //     (unsigned char)0b00101011,
  //     (unsigned char)0b01010101,
  //     (unsigned char)0b01111111,
  // };

  // GooDisplay::partial_draw(0, GooDisplay::DISPLAY_WIDTH - 1,
  // GooDisplay::DISPLAY_WIDTH, GooDisplay::DISPLAY_HEIGHT);
  static lv_display_t *disp =
      lv_display_create(GooDisplay::DISPLAY_WIDTH, GooDisplay::DISPLAY_HEIGHT);


  lv_display_set_buffers(disp, buf, nullptr, BUFFER_SIZE,
                         LV_DISPLAY_RENDER_MODE_PARTIAL);

  lv_display_set_flush_cb(disp, flush_cb);

  lv_display_set_color_format(disp, LV_COLOR_FORMAT_I8);

  auto round_callback = [](lv_event_t *e) {
    lv_area_t *area = static_cast<lv_area_t *>(lv_event_get_param(e));
    rounder_cp(area);
  };

  lv_obj_add_event_cb(lv_screen_active(), round_callback,
                      LV_EVENT_INVALIDATE_AREA, NULL);

  // Configuration du timer périodique pour LVGL
  esp_timer_create_args_t lvgl_tick_timer_args{};
  lvgl_tick_timer_args.callback = &increase_lvgl_tick;
  lvgl_tick_timer_args.name = "lvgl_tick";

  esp_timer_handle_t lvgl_tick_timer;
  esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer);
  esp_timer_start_periodic(lvgl_tick_timer,
                           LVGL_TICK_PERIOD_MS * 1000); // En microsecondes
}
