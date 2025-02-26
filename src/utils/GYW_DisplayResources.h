// GYW_DisplayResources.h

#ifndef GYW_DISPLAY_RESOURCES_H
#define GYW_DISPLAY_RESOURCES_H

#include <lvgl.h>

// Inclure les icônes et font
#include "../assets/font/Fonts.h" // Inclut tous les fichiers de fonts

// Fonction pour obtenir l'icône en fonction du nom
const lv_img_dsc_t* getIconByName(const char* iconName);
const lv_font_t* getFont(const char* fontName, uint8_t fontSize);
void cleanupLoadedImages();

// Si vous avez besoin de fonctions pour les polices, vous pouvez les ajouter ici

#endif // GYW_DISPLAY_RESOURCES_H