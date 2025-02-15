#include <Arduino.h>
#include <lvgl.h>
#include "peripherals/lvgl_driver.h"

void setup() {
    Serial.begin(115200);

    // Initialize LVGL
    lv_init();

    // Initialize display driver
    lvgl_display_init();

    // Create a simple UI
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello, World!");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, -20);

    lv_obj_t *rect = lv_obj_create(lv_scr_act());
    lv_obj_set_size(rect, 100, 50);
    lv_obj_align(rect, LV_ALIGN_CENTER, 0, 30);
    lv_obj_set_style_bg_color(rect, lv_color_black(), LV_PART_MAIN);
}

void loop() {
    lv_timer_handler();
    delay(5);
}