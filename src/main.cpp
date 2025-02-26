#include <Arduino.h>
#include <lvgl.h>
#include <mutex>

#include "peripherals/lvgl_driver.h"      // Utilisation du driver LVGL personnalisé
#include "utils/GYW_DisplayCommands.h"    // Commandes spécifiques de l'affichage
#include "utils/GYW_DisplayInternal.h"    //
#include "blue/GYW_BLE.h"                 // Pour la connexion BLE
#include "lvgl_mutex.hpp"

void setup()
{
    Serial.begin(115200); // Initialisation de la communication série
    lv_init(); // Initialisation de la bibliothèque LVGL
    lvgl_display_init();

    // Initialisation du buzzer
    //pinMode(BUZZER_PIN, OUTPUT);
    //digitalWrite(BUZZER_PIN, LOW);  // Désactiver le buzzer

    //pinMode(BL, OUTPUT);
    //digitalWrite(BL, LOW);  // Désactiver le buzzer

    // Configuration de l'affichage principal et des fonctions Bluetooth
    initDisplayUpdateTask(); // Tâche pour mettre à jour l'affichage
    initMainScreen_internal();

    // Utiliser l'écran par défaut
    main_screen = lv_scr_act();
    lv_obj_set_size(main_screen, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_style_bg_color(main_screen, lv_color_white(), 0);

    // Afficher l'icône du logo
    lv_color_t logo_color = lv_color_black();
    displayIcon_internal("GYW", 180, 170, 1.5, logo_color);

    // Afficher le texte "Get Your Way"
    const char* text = "Get Your Way";
    int16_t text_y = 230;
    uint8_t fontSize = 20;
    lv_color_t text_color = lv_color_black();

    displayText_internal(text, 80, 190, "montserrat", fontSize, text_color);

    BLE_Init("GYW aRdent"); // Initialisation de la connexion BLE avec le nom donné
}

void loop()
{
    {
        std::scoped_lock lock(lvgl_mutex);
        lv_timer_handler(); // Traite les événements et les changements
    }
    delay(5);
}
