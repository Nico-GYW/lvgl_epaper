#ifndef DISPLAY_COMMANDS_H
#define DISPLAY_COMMANDS_H

#include <stdint.h>
#include <lvgl.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

#ifdef __cplusplus
extern "C" {
#endif

// Types de commandes pour l'affichage
typedef enum {
    CMD_INIT_MAIN_SCREEN = 1,
    CMD_DISPLAY_TEXT = 0x03,
    CMD_DISPLAY_ICON = 0x02,
    CMD_CLEAR_SCREEN = 0x05,
    CMD_DISPLAY_RECTANGLE = 0x0C,
    CMD_SET_SCREEN_BRIGHTNESS = 0x07,
    CMD_DISPLAY_SPINNER = 0x0D,
    // Ajoutez d'autres commandes si nécessaire
} DisplayCommandType;

// Structure pour les commandes
typedef struct {
    DisplayCommandType cmdType;
    uint8_t paramsData[256]; // Ajustez la taille si nécessaire
    size_t paramsLength;
    char dataBuffer[256];    // Pour les données supplémentaires, comme le texte ou le nom de l'icône
} DisplayCommand;

// Déclare la file de commandes pour l'affichage
extern QueueHandle_t displayCommandQueue;

/**
 * @brief Initialise la tâche de mise à jour de l'affichage.
 */
void initDisplayUpdateTask(void);

/**
 * @brief Enfile une commande pour être traitée par la tâche d'affichage.
 */
void enqueueDisplayCommand(DisplayCommand* cmd);

#ifdef __cplusplus
}
#endif

#endif // DISPLAY_COMMANDS_H