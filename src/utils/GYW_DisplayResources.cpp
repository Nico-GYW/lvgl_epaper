// GYW_DisplayResources.cpp

#include "GYW_DisplayResources.h"
#include "./assets/icon/Icons.h"
#include <string.h>
#include <stdio.h>
#include <unordered_map>

// Structure pour mapper les noms aux icônes
typedef struct
{
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
const lv_img_dsc_t* getIconByName(const char* iconName)
{
    // Créer une copie du nom de l'icône pour manipulation
    char iconNameNoExt[64];
    strncpy(iconNameNoExt, iconName, sizeof(iconNameNoExt) - 1);
    iconNameNoExt[sizeof(iconNameNoExt) - 1] = '\0'; // Assurer la terminaison de la chaîne

    // Retirer l'extension '.svg' si présente
    char* dotPosition = strstr(iconNameNoExt, ".svg");
    if (dotPosition != NULL)
    {
        *dotPosition = '\0'; // Terminer la chaîne à l'endroit du '.'
    }

    // Parcourir le tableau de mappage des icônes
    for (size_t i = 0; i < sizeof(iconMappings) / sizeof(iconMappings[0]); i++)
    {
        if (strcmp(iconNameNoExt, iconMappings[i].name) == 0)
        {
            return iconMappings[i].img_dsc;
        }
    }
    printf("[getIconByName] Icône '%s' non reconnue.\n", iconNameNoExt);
    return nullptr;
}


typedef struct
{
    const char* name;
    uint8_t size;
    const lv_font_t* font;
} FontMapping;


// Déclaration des polices avec leurs tailles
static const FontMapping fontMappings[] = {
    // Polices Roboto Mono
    {"roboto_mono_bold", 12, &roboto_mono_bold_12},
    {"roboto_mono_bold", 14, &roboto_mono_bold_14},
    {"roboto_mono_bold", 16, &roboto_mono_bold_16},
    {"roboto_mono_bold", 18, &roboto_mono_bold_18},
    {"roboto_mono_bold", 20, &roboto_mono_bold_20},
    {"roboto_mono_bold", 22, &roboto_mono_bold_22},
    {"roboto_mono_bold", 24, &roboto_mono_bold_24},
    {"roboto_mono_bold", 26, &roboto_mono_bold_26},
    {"roboto_mono_bold", 28, &roboto_mono_bold_28},
    {"roboto_mono_bold", 30, &roboto_mono_bold_30},
    {"roboto_mono_bold", 32, &roboto_mono_bold_32},
    {"roboto_mono_bold", 34, &roboto_mono_bold_34},

    {"roboto_mono_medium", 12, &roboto_mono_medium_12},
    {"roboto_mono_medium", 14, &roboto_mono_medium_14},
    {"roboto_mono_medium", 16, &roboto_mono_medium_16},
    {"roboto_mono_medium", 18, &roboto_mono_medium_18},
    {"roboto_mono_medium", 20, &roboto_mono_medium_20},
    {"roboto_mono_medium", 22, &roboto_mono_medium_22},
    {"roboto_mono_medium", 24, &roboto_mono_medium_24},
    {"roboto_mono_medium", 26, &roboto_mono_medium_26},
    {"roboto_mono_medium", 28, &roboto_mono_medium_28},
    {"roboto_mono_medium", 30, &roboto_mono_medium_30},
    {"roboto_mono_medium", 32, &roboto_mono_medium_32},
    {"roboto_mono_medium", 34, &roboto_mono_medium_34},
};

// Fonction pour obtenir la police en fonction du nom et de la taille
const lv_font_t* getFont(const char* fontName, uint8_t fontSize)
{
    if (fontSize > 48)
    {
        return &roboto_mono_bold_16; // Police par défaut
    }

    // Parcourir le tableau de mappage des polices
    for (size_t i = 0; i < sizeof(fontMappings) / sizeof(fontMappings[0]); i++)
    {
        if (strcmp(fontName, fontMappings[i].name) == 0 && fontSize == fontMappings[i].size)
        {
            return fontMappings[i].font;
        }
    }

    return getFont(fontName, fontSize + 1);
}
