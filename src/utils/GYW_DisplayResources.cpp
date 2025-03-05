// GYW_DisplayResources.cpp

#include "GYW_DisplayResources.h"
#include "./assets/icon/Icons.h"
#include <string.h>
#include <stdio.h>


// Structure pour mapper les noms aux icônes
typedef struct {
    const char* name;
    const lv_img_dsc_t* img_dsc;
} IconMapping;

// Tableau de correspondance des icônes
static const IconMapping iconMappings[] = {
    {"done", &done},
    {"key_5", &key_5},
    {"down", &down},
    {"warning", &warning},
    {"key_1", &key_1},
    {"GYW", &GYW},
    {"key_A", &key_A},
    {"key_hash", &key_hash},
    {"check", &check},
    {"cloud_backup", &cloud_backup},
    {"info", &info},
    {"key_6", &key_6},
    {"key_8", &key_8},
    {"cloud_done", &cloud_done},
    {"key_2", &key_2},
    {"location", &location},
    {"next", &next},
    {"left", &left},
    {"up", &up},
    {"key_B", &key_B},
    {"folder", &folder},
    {"blank", &blank},
    {"edit", &edit},
    {"wifi", &wifi},
    {"uncheck", &uncheck},
    {"prev", &prev},
    {"key_7", &key_7},
    {"person", &person},
    {"key_3", &key_3},
    {"key_9", &key_9},
    {"help", &help},
    {"nfc", &nfc},
    {"build", &build},
    {"key_C", &key_C},
    {"settings", &settings},
    {"wifi_off", &wifi_off},
    {"key_4", &key_4},
    {"file", &file},
    {"right", &right},
    {"camera", &camera},
    {"key_0", &key_0},
    {"key_star", &key_star},
    {"key_D", &key_D},
    // Ajoutez toutes les autres icônes ici
};

// Fonction pour obtenir l'icône en fonction du nom
const lv_img_dsc_t* getIconByName(const char* iconName) {
    // Créer une copie du nom de l'icône pour manipulation
    char iconNameNoExt[64];
    strncpy(iconNameNoExt, iconName, sizeof(iconNameNoExt) - 1);
    iconNameNoExt[sizeof(iconNameNoExt) - 1] = '\0'; // Assurer la terminaison de la chaîne

    // Retirer l'extension '.svg' si présente
    char* dotPosition = strstr(iconNameNoExt, ".svg");
    if (dotPosition != NULL) {
        *dotPosition = '\0'; // Terminer la chaîne à l'endroit du '.'
    }

    // Parcourir le tableau de mappage des icônes
    for (size_t i = 0; i < sizeof(iconMappings)/sizeof(iconMappings[0]); i++) {
        if (strcmp(iconNameNoExt, iconMappings[i].name) == 0) {
            return iconMappings[i].img_dsc;
        }
    }
    printf("[getIconByName] Icône '%s' non reconnue.\n", iconNameNoExt);
    return nullptr;
}


typedef struct {
    const char* name;
    uint8_t size;
    const lv_font_t* font;
} FontMapping;


// Déclaration des polices avec leurs tailles
static const FontMapping fontMappings[] = {
    // Polices Raleway
    {"raleway", 12, &raleway_12},
    {"raleway", 14, &raleway_14},
    {"raleway", 16, &raleway_16},
    {"raleway", 18, &raleway_18},
    {"raleway", 20, &raleway_20},
    {"raleway", 22, &raleway_22},
    {"raleway", 24, &raleway_24},
    {"raleway", 26, &raleway_26},
    {"raleway", 28, &raleway_28},
    {"raleway", 30, &raleway_30},
    {"raleway", 32, &raleway_32},
    {"raleway", 34, &raleway_34},
    {"raleway", 36, &raleway_36},
    {"raleway", 38, &raleway_38},
    {"raleway", 40, &raleway_40},
    {"raleway", 42, &raleway_42},
    {"raleway", 44, &raleway_44},
    {"raleway", 46, &raleway_46},
    {"raleway", 48, &raleway_48},

    // Polices Montserrat
    {"montserrat", 8, &lv_font_montserrat_8},
    {"montserrat", 10, &lv_font_montserrat_10},
    {"montserrat", 12, &lv_font_montserrat_12},
    {"montserrat", 14, &lv_font_montserrat_14},
    {"montserrat", 16, &lv_font_montserrat_16},
    {"montserrat", 18, &lv_font_montserrat_18},
    {"montserrat", 20, &lv_font_montserrat_20},
    {"montserrat", 22, &lv_font_montserrat_22},
    {"montserrat", 24, &lv_font_montserrat_24},
    {"montserrat", 26, &lv_font_montserrat_26},
    {"montserrat", 28, &lv_font_montserrat_28},
    {"montserrat", 30, &lv_font_montserrat_30},
    {"montserrat", 32, &lv_font_montserrat_32},
    {"montserrat", 34, &lv_font_montserrat_34},
    {"montserrat", 36, &lv_font_montserrat_36},
    {"montserrat", 38, &lv_font_montserrat_38},
    {"montserrat", 40, &lv_font_montserrat_40},
    {"montserrat", 42, &lv_font_montserrat_42},
    {"montserrat", 44, &lv_font_montserrat_44},
    {"montserrat", 46, &lv_font_montserrat_46},
    {"montserrat", 48, &lv_font_montserrat_48}
    // Ajoutez d'autres polices et tailles ici si nécessaire
};

// Fonction pour obtenir la police en fonction du nom et de la taille
const lv_font_t* getFont(const char* fontName, uint8_t fontSize) {
    // Parcourir le tableau de mappage des polices
    for (size_t i = 0; i < sizeof(fontMappings) / sizeof(fontMappings[0]); i++) {
        if (strcmp(fontName, fontMappings[i].name) == 0 && fontSize == fontMappings[i].size) {
            return fontMappings[i].font;
        }
    }

    printf("[getFont] Police '%s' de taille %d non reconnue. Utilisation de la police par défaut.\n", fontName, fontSize);
    return &lv_font_montserrat_16; // Police par défaut
}