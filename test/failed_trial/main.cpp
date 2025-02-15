#include <Arduino.h>
#include <lvgl.h>
#include "peripherals/lvgl_driver.h"

lv_obj_t *label;
bool toggle = false;

// Fonction pour afficher "Hello World!"
void display_hello_world() {
    label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello World!");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

// Fonction de gestion de la boucle LVGL (ton ancienne logique)
void Lvgl_Loop() {
    lv_timer_handler();  // Traite les événements et les changements
}

void setup() {
    Serial.begin(115200);
    lv_init();
    init_lvgl_display();  

    display_hello_world();
}

void loop() {
    // Gestion des changements de texte pour forcer le flush
    static unsigned long previousUpdateTime = 0;
    unsigned long currentTime = millis();
    if (currentTime - previousUpdateTime >= 500) {
        if (toggle) {
            lv_label_set_text(label, "Hello World!");
        } else {
            lv_label_set_text(label, "Bonjour!");
        }
        toggle = !toggle;

        lv_refr_now(NULL);  // Forcer la mise à jour de l’écran
        previousUpdateTime = currentTime;
    }

    // Appelle explicitement la gestion des tâches LVGL
    Lvgl_Loop();

    delay(5);  // Pause courte pour éviter la surcharge CPU
}