#include <Arduino.h>
#include <lvgl.h>
#include <mutex>
#include <peripherals/goodisplay/commands.hpp>
#include <peripherals/goodisplay/spi.hpp>

#include "peripherals/goodisplay/lvgl_driver.hpp"      // Utilisation du driver LVGL personnalisé
#include "utils/GYW_DisplayCommands.h"    // Commandes spécifiques de l'affichage
#include "utils/GYW_DisplayInternal.h"    //
#include "blue/GYW_BLE.h"                 // Pour la connexion BLE
#include "lvgl_mutex.hpp"
#include "Ap_29demo.h"

extern const uint8_t GYW_map[];

// void setup_()
// {
//     constexpr size_t BUFFER_SIZE = GooDisplay::DISPLAY_WIDTH * GooDisplay::DISPLAY_HEIGHT;
//
//     Serial.begin(115200); // Initialisation de la communication série
//
//     auto buf = new lv_color_t[BUFFER_SIZE]; // Taille du buffer (ajuster selon la RAM disponible)
//
//     memset(buf, 0xFF, BUFFER_SIZE * sizeof(lv_color_t));
//
//     GooDisplay::init_spi();
//     GooDisplay::EPD_HW_Init_Fast();
//
//     GooDisplay::clear_screen(GooDisplay::Color::WHITE);
//
//     // for (auto x = 32; x < 64; x++)
//     // {
//     //     for (auto y = 32; y < 64; y++)
//     //     {
//     //         buf[x + y * GooDisplay::DISPLAY_WIDTH] = lv_color_black();
//     //     }
//     // }
//
//     // for (auto x = 0; x < 32; x++)
//     // {
//     //     for (auto y = 0; y < 32; y++)
//     //     {
//     //         buf[x + y * GooDisplay::DISPLAY_WIDTH] = lv_color_black();
//     //     }
//     // }
//     //
//     // auto area = lv_area_t{0, 0, 64, 64};
//
//     int x = 100;
//     int y = 100;
//
//     int width = 121;
//     int height = 48;
//
//     GooDisplay::EPD_Dis_Part(y, GooDisplay::DISPLAY_WIDTH - x, width, height);
//
//     GooDisplay::Epaper_Write_Command(0x24); //Write Black and White image to RAM
//
//     for (int x = 0; x < width; x++)
//     {
//         uint8_t byte = 0;
//         uint8_t accumulated = 0;
//
//         for (int y = 0; y < height; y++)
//         {
//             uint8_t pixel = GYW_map[2 * (x + y * width) + 1];
//
//             byte <<= 1;
//             byte |= (pixel == 0xFF ? 0 : 1);
//             accumulated++;
//
//             if (accumulated == 8)
//             {
//                 GooDisplay::Epaper_Write_Data(byte);
//                 byte = 0;
//                 accumulated = 0;
//             }
//         }
//     }
//
//     // GooDisplay::partial_draw(buf, &area);
//     GooDisplay::partial_update();
// }

void setup()
{
    Serial.begin(115200); // Initialisation de la communication série

    lv_init(); // Initialisation de la bibliothèque LVGL
    lvgl_display_init_goodisplay();

    // return;

    // Initialisation du buzzer
    //pinMode(BUZZER_PIN, OUTPUT);
    //digitalWrite(BUZZER_PIN, LOW);  // Désactiver le buzzer

    //pinMode(BL, OUTPUT);
    //digitalWrite(BL, LOW);  // Désactiver le buzzer

    // Configuration de l'affichage principal et des fonctions Bluetooth
    initDisplayUpdateTask(); // Tâche pour mettre à jour l'affichage
    // initMainScreen_internal();

    // Utiliser l'écran par défaut
    main_screen = lv_scr_act();
    lv_obj_set_size(main_screen, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_style_bg_color(main_screen, lv_color_white(), 0);

    delay(1000);

    // Afficher l'icône du logo
    lv_color_t logo_color = lv_color_black();
    displayIcon_internal("GYW", 100, 100, 1, logo_color);

    // displayRectangle_internal(1, 2, 6, 4, lv_color_black());

    // Afficher le texte "Get Your Way"
    // const char* text = "Get Your Way";
    // int16_t text_y = 230;
    // uint8_t fontSize = 20;
    // lv_color_t text_color = lv_color_black();

    // displayText_internal(text, 10, 0, "montserrat", fontSize, text_color);

    BLE_Init("GYW aRdent"); // Initialisation de la connexion BLE avec le nom donné
}

void loop_()
{
}

void loop()
{
    {
        std::scoped_lock lock(lvgl_mutex);
        lv_timer_handler(); // Traite les événements et les changements
    }
    delay(5);
}
