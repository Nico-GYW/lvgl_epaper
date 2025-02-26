#include <Arduino.h>
#include <lvgl.h>

#include "peripherals/lvgl_driver.h"      // Utilisation du driver LVGL personnalisé
#include "utils/GYW_DisplayCommands.h"    // Commandes spécifiques de l'affichage
#include "utils/GYW_DisplayInternal.h"    //
#include "blue/GYW_BLE.h"                 // Pour la connexion BLE

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
    BLE_Init("GYW aRdent"); // Initialisation de la connexion BLE avec le nom donné
}

void loop()
{
    lv_timer_handler(); // Traite les événements et les changements
    delay(5);
}
