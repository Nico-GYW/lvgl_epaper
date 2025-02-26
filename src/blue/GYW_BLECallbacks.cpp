#include "GYW_BLECallbacks.h"
#include "./GYW_Debug.h"
#include "./utils/GYW_DisplayCommands.h"
#include <Arduino.h>
#include <future>

// Initialisation du buffer global et du mutex FreeRTOS
std::string globalDataBuffer = "";
SemaphoreHandle_t bufferMutex = xSemaphoreCreateMutex();

void DisplayDataCharacteristicCallbacks::onWrite(BLECharacteristic* pCharacteristic)
{
    xSemaphoreTake(bufferMutex, portMAX_DELAY);
    std::string value = std::string(pCharacteristic->getValue().c_str());
    DEBUG_INFO("Données reçues : %s\n", value.c_str()); // Affiche les données reçues

    if (!value.empty())
    {
        globalDataBuffer += value; // Ajoute la nouvelle portion de données au buffer global
        DEBUG_INFO("Taille actuelle du buffer : %d octets.\n", globalDataBuffer.size());
    }

    // Libération du mutex après l'opération
    xSemaphoreGive(bufferMutex);
}

void DisplayCommandCharacteristicCallbacks::onWrite(BLECharacteristic* pCharacteristic)
{
    // Verrouillage du mutex pour protéger l'accès à `globalDataBuffer`
    xSemaphoreTake(bufferMutex, portMAX_DELAY);

    uint8_t* data = pCharacteristic->getData();
    size_t length = pCharacteristic->getLength();

    if (length > 0)
    {
        // Le premier octet est le code de commande
        uint8_t commandCode = data[0];
        uint8_t* paramsData = data + 1;
        size_t paramsLength = length - 1;

        // Crée une structure DisplayCommand
        DisplayCommand cmd = {};
        cmd.cmdType = (DisplayCommandType)commandCode;
        cmd.paramsLength = paramsLength;
        memcpy(cmd.paramsData, paramsData, paramsLength);

        // Si nécessaire, copie le buffer global de données
        if (!globalDataBuffer.empty())
        {
            strncpy(cmd.dataBuffer, globalDataBuffer.c_str(), sizeof(cmd.dataBuffer) - 1);
        }

        // Enfile la commande
        enqueueDisplayCommand(&cmd);

        // Vide le buffer global après le traitement
        globalDataBuffer.clear();
    }
    else
    {
        DEBUG_WARNING("Aucune donnée reçue dans la commande.\n");
    }

    // Libération du mutex après l'opération
    xSemaphoreGive(bufferMutex);
}
