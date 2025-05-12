#include <lvgl.h>
#include <mutex>
#include <blue/services.hpp>
#include <peripherals/goodisplay/commands.hpp>

#include "peripherals/goodisplay/lvgl_driver.hpp"      // Utilisation du driver LVGL personnalisé
#include "utils/GYW_DisplayCommands.h"    // Commandes spécifiques de l'affichage
#include "utils/GYW_DisplayInternal.h"    //
#include "lvgl_mutex.hpp"

extern const uint8_t GYW_map[];

static void loop();

extern "C" void app_main()
{
    lv_init(); // Initialisation de la bibliothèque LVGL
    lvgl_display_init_goodisplay();

    init_bluetooth_peripheral();

    // Configuration de l'affichage principal et des fonctions Bluetooth
    initDisplayUpdateTask(); // Tâche pour mettre à jour l'affichage

    // Utiliser l'écran par défaut
    main_screen = lv_scr_act();
    lv_obj_set_size(main_screen, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_style_bg_color(main_screen, lv_color_white(), 0);

    vTaskDelay(pdMS_TO_TICKS(1000));

    // Afficher l'icône du logo
    lv_color_t logo_color = lv_color_black();
    displayIcon_internal("GYW", 100, 100, 1, logo_color);

    while (true)
    {
        loop();
    }
}

static void loop()
{
    {
        std::scoped_lock lock(lvgl_mutex);
        lv_timer_handler(); // Traite les événements et les changements
    }
    vTaskDelay(pdMS_TO_TICKS(5));
}
