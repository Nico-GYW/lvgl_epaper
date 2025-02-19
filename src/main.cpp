#include <Arduino.h>
#include <lvgl.h>
#include "peripherals/lvgl_driver.h"

lv_obj_t *label;
bool toggle = true;

// Fonction pour afficher "Hello World!"
void display_hello_world() {
    label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello World!");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_color(label, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_40, LV_PART_MAIN);
    //
    // label = lv_label_create(lv_scr_act());
    // lv_label_set_text(label, "Hello World!");
    // lv_obj_align(label, LV_ALIGN_CENTER, 0, 200);
    // lv_obj_set_style_text_color(label, lv_color_make(0xee, 0xee, 0xee), LV_PART_MAIN);
    // lv_obj_set_style_text_font(label, &lv_font_montserrat_40, LV_PART_MAIN);
    //
    // label = lv_label_create(lv_scr_act());
    // lv_label_set_text(label, "Hello World!");
    // lv_obj_align(label, LV_ALIGN_CENTER, 0, 300);
    // lv_obj_set_style_text_color(label, lv_color_white(), LV_PART_MAIN);
    // lv_obj_set_style_text_font(label, &lv_font_montserrat_40, LV_PART_MAIN);
}

void setup() {
    Serial.begin(115200);
    lv_init();
    lvgl_display_init();

    display_hello_world();
}

void loop() {
    // Gestion des changements de texte pour forcer le flush
    // static unsigned long previousUpdateTime = 0;
    // unsigned long currentTime = millis();
    //
    // if (currentTime - previousUpdateTime >= 1000) {
    //     if (toggle) {
    //         lv_label_set_text(label, "Hello World!");
    //     } else {
    //         lv_label_set_text(label, "Bonjour!");
    //     }
    //     toggle = !toggle;
    //     previousUpdateTime = currentTime;
    // }

    // Appelle explicitement la gestion des tâches LVGL
    lv_timer_handler(); // Traite les événements et les changements
    delay(5);  // Pause courte pour éviter la surcharge CPU
}
