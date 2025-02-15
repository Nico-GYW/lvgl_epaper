#ifndef LVGL_DRIVER_H
#define LVGL_DRIVER_H

#include <lvgl.h>

#define LV_HOR_RES_MAX 480
#define LVGL_TICK_PERIOD_MS 500

// Fonction pour initialiser l’affichage e-paper avec LVGL
void init_lvgl_display();

#endif  // LVGL_DRIVER_H