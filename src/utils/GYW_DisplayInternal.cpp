#include "GYW_DisplayInternal.h"

#include <lvgl_mutex.hpp>
#include <mutex>

#include "GYW_DisplayResources.h"
#include "./peripherals/lvgl_driver.h"
#include "./GYW_Debug.h"

#include <stdio.h>

// Définition de la fenêtre principale
lv_obj_t *main_screen = nullptr;

// Implémentation des fonctions internes

void initMainScreen_internal() {
    std::scoped_lock lock(lvgl_mutex);

    DEBUG_INFO("[initMainScreen_internal] Initialisation de l'écran principal.\n");

    // Utiliser l'écran par défaut
    main_screen = lv_scr_act();
    lv_obj_set_size(main_screen, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_style_bg_color(main_screen, lv_color_white(), 0);
    
    // Afficher l'icône du logo
    lv_color_t logo_color = lv_color_black();
    displayIcon_internal("GYW", 180, 120, 1.5, logo_color);

    // Afficher le texte "Get Your Way"
    const char* text = "Get Your Way";
    int16_t text_y = 230;
    uint8_t fontSize = 20;
    lv_color_t text_color = lv_color_black();

    displayText_internal(text, 80, 150, "montserrat", fontSize, text_color);
}

void displayText_internal(const char* text, int16_t x, int16_t y, const char* fontName, uint8_t fontSize, lv_color_t color) {
    std::scoped_lock lock(lvgl_mutex);

    DEBUG_INFO("[displayText_internal] Affichage du texte.\n");
    DEBUG_INFO("  Texte : '%s'\n", text);
    DEBUG_INFO("  Position : (%d, %d)\n", x, y);
    DEBUG_INFO("  Taille de police : %d\n", fontSize);
    DEBUG_INFO("  Couleur : 0x%04X\n", color.full);

    lv_obj_t *label = lv_label_create(main_screen);
    if (label == NULL) {
        DEBUG_ERROR("[displayText_internal] Échec de la création du label.\n");
        return;
    }
    lv_label_set_text(label, text);
    lv_obj_align(label, LV_ALIGN_TOP_LEFT, x, y);

    lv_obj_set_style_text_color(label, color, 0);

    // Sélection de la police en fonction de la taille
    const lv_font_t* font = getFont("montserrat", fontSize); // à changer si on veut une autre font
    if (font == NULL) {
        DEBUG_WARNING("[displayText_internal] Police '%s' de taille %d non trouvée. Utilisation de la police par défaut.\n", fontName, fontSize);
    }
    lv_obj_set_style_text_font(label, font, 0);
}

void displayIcon_internal(const char* iconName, int16_t x, int16_t y, float scale, lv_color_t color) {
    std::scoped_lock lock(lvgl_mutex);

    DEBUG_INFO("[displayIcon_internal] Affichage de l'icône.\n");
    DEBUG_INFO("  Icône: '%s'\n", iconName);
    DEBUG_INFO("  Position: (%d, %d)\n", x, y);
    DEBUG_INFO("  Échelle: %.2f\n", scale);
    DEBUG_INFO("  Couleur: 0x%04X\n", color.full);

    const lv_img_dsc_t* icon_dsc = getIconByName(iconName);

    if (icon_dsc) {
        lv_obj_t *img_obj = lv_img_create(main_screen);
        lv_img_set_src(img_obj, icon_dsc);

        // Application de la recoloration si nécessaire
        lv_obj_set_style_img_recolor(img_obj, color, LV_PART_MAIN);
        lv_obj_set_style_img_recolor_opa(img_obj, LV_OPA_COVER, LV_PART_MAIN);

        // Application du facteur de zoom
        if (scale > 0.0f) {
            uint16_t zoom_factor = (uint16_t)(scale * 256); // LVGL utilise 256 pour 1x
            DEBUG_INFO("  Facteur de zoom calculé: %u\n", zoom_factor);
            lv_img_set_zoom(img_obj, zoom_factor);
        } else {
            DEBUG_ERROR("  Échelle invalide: %.2f\n", scale);
        }

        // Calcul du décalage en tenant compte de la mise à l'échelle
        int16_t adjusted_x = x - (int16_t)(icon_dsc->header.w * scale) / 2;
        int16_t adjusted_y = y - (int16_t)(icon_dsc->header.h * scale) / 2;

        // Alignement avec les coordonnées ajustées
        lv_obj_align(img_obj, LV_ALIGN_TOP_LEFT, adjusted_x, adjusted_y);
    } else {
        DEBUG_ERROR("[displayIcon_internal] Impossible d'afficher l'icône '%s'.\n", iconName);
    }
}

void clearScreen_internal(lv_color_t color) {
    std::scoped_lock lock(lvgl_mutex);

    DEBUG_INFO("[clearScreen_internal] Nettoyage de l'écran avec la couleur 0x%04X.\n", color.full);

    lv_obj_clean(lv_scr_act());
    lv_obj_set_style_bg_color(main_screen, color, 0);
}

void displayRectangle_internal(int16_t x, int16_t y, uint16_t width, uint16_t height, lv_color_t color) {
    std::scoped_lock lock(lvgl_mutex);

    DEBUG_INFO("[displayRectangle_internal] Affichage d'un rectangle.\n");
    DEBUG_INFO("  Position : (%d, %d)\n", x, y);
    DEBUG_INFO("  Taille : %d x %d\n", width, height);
    DEBUG_INFO("  Couleur : 0x%04X\n", color.full);

    lv_obj_t *rect = lv_obj_create(main_screen);
    if (rect == NULL) {
        DEBUG_ERROR("[displayRectangle_internal] Échec de la création de l'objet rectangle.\n");
        return;
    }
    lv_obj_set_size(rect, width, height);
    lv_obj_align(rect, LV_ALIGN_TOP_LEFT, x, y);

    lv_obj_set_style_bg_color(rect, color, 0);
    lv_obj_set_style_border_width(rect, 0, 0);
}

void setScreenBrightness_internal(uint8_t brightness) {
    DEBUG_INFO("[setScreenBrightness_internal] Réglage de la luminosité de l'écran à %d.\n", brightness);
    // set_backlight_brightness(brightness);
}

void displaySpinner_internal(int16_t x, int16_t y, float scale, lv_color_t color, float spins_per_second) {
    std::scoped_lock lock(lvgl_mutex);

    DEBUG_INFO("[displaySpinner_internal] Affichage d'un spinner.\n");
    DEBUG_INFO("  Position : (%d, %d)\n", x, y);
    DEBUG_INFO("  Échelle : %.2f\n", scale);
    DEBUG_INFO("  Couleur : 0x%04X\n", color.full);
    DEBUG_INFO("  Vitesse : %.2f tours/s\n", spins_per_second);

    // Créer un nouveau spinner sur l'écran actuel
    lv_obj_t *spinner = lv_spinner_create(main_screen, (uint32_t)(1000 / spins_per_second), 60); // 60 degrés pour la longueur de l'arc par défaut
    if (spinner == NULL) {
        DEBUG_ERROR("[displaySpinner_internal] Échec de la création du spinner.\n");
        return;
    }

    // Définir la taille du spinner en fonction de l'échelle
    int16_t size = (int16_t)(100 * scale); // Taille de base de 100 pixels
    lv_obj_set_size(spinner, size, size);

    // Positionner le spinner selon les coordonnées x et y
    lv_obj_align(spinner, LV_ALIGN_TOP_LEFT, x, y);

    // Personnaliser la couleur du spinner
    lv_obj_set_style_arc_color(spinner, color, LV_PART_INDICATOR | LV_STATE_DEFAULT); // Partie tournante
    lv_obj_set_style_arc_width(spinner, 4, LV_PART_INDICATOR | LV_STATE_DEFAULT);     // Largeur de la ligne de l'arc

    // Rendre le fond du spinner transparent
    lv_obj_set_style_bg_opa(spinner, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT);
}
