#ifndef GYW_DISPLAY_INTERNAL_H
#define GYW_DISPLAY_INTERNAL_H

#include <lvgl.h>

// Déclaration de la fenêtre principale (à partager entre les modules si nécessaire)
extern lv_obj_t *main_screen;

// Fonctions internes
void initMainScreen_internal();
void displayText_internal(const char* text, int16_t x, int16_t y, const char* fontName, uint8_t fontSize, lv_color_t color);
void displayIcon_internal(const char* iconName, int16_t x, int16_t y, float scale, lv_color_t color);
void clearScreen_internal(lv_color_t color);
void displayRectangle_internal(int16_t x, int16_t y, uint16_t width, uint16_t height, lv_color_t color);
void setScreenBrightness_internal(uint8_t brightness);
void displaySpinner_internal(int16_t x, int16_t y, float scale, lv_color_t color, float spins_per_second);

#endif // GYW_DISPLAY_INTERNAL_H
