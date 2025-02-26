#ifndef GYW_BLE_CALLBACKS_H
#define GYW_BLE_CALLBACKS_H

#include <BLEDevice.h>
#include <string>
#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>  // Pour utiliser les mutex FreeRTOS

// Déclaration externe du buffer global et du mutex
extern std::string globalDataBuffer;
extern SemaphoreHandle_t bufferMutex;

class DisplayDataCharacteristicCallbacks : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic* pCharacteristic) override;
};

class DisplayCommandCharacteristicCallbacks : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic* pCharacteristic) override;
};

#endif // GYW_BLE_CALLBACKS_H
