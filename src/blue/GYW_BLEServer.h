#ifndef GYW_BLE_SERVER_H
#define GYW_BLE_SERVER_H

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// Variables globales pour la connexion et la gestion BLE
extern BLEServer* pServer;
extern BLECharacteristic* pDisplayCommandCharacteristic;
extern BLECharacteristic* pDisplayDataCharacteristic;
extern BLECharacteristic* pBatteryCharacteristic;
extern bool deviceConnected;

// Fonctions d'initialisation et de gestion BLE
void BLE_Init(const char* deviceName);
void BLE_StartAdvertising();
void initOTAService();
void initOTSService();

#endif // GYW_BLE_SERVER_H
