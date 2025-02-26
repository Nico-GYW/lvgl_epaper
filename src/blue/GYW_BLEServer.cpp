#include <Arduino.h>
#include <nvs_flash.h>

#include "GYW_BLEServer.h"
#include "GYW_BLECallbacks.h"

// Variables globales pour la connexion et la gestion BLE
BLEServer* pServer = nullptr;
BLECharacteristic* pDisplayCommandCharacteristic = nullptr;
BLECharacteristic* pDisplayDataCharacteristic = nullptr;
BLECharacteristic* pBatteryCharacteristic = nullptr;
bool deviceConnected = false;

// Déclaration des UUIDs pour les services et caractéristiques
#define COMMAND_SERVICE_UUID        "9f3443f3-5149-4d53-9b92-35def7b82e51"
#define COMMAND_CONTROL_CHAR_UUID   "9f3443f3-5149-4d53-9b92-35def7b82e52"
#define COMMAND_DATA_CHAR_UUID      "9f3443f3-5149-4d53-9b92-35def7b82e53"
#define BATTERY_SERVICE_UUID        BLEUUID((uint16_t)0x180F)
#define BATTERY_LEVEL_CHAR_UUID     BLEUUID((uint16_t)0x2A19)
#define TARGET_SERVICE_UUID         "564ce655-d27c-4401-815b-fac78545835c"
#define TARGET_CTRL_CHAR_UUID       "564ce655-d27c-4401-815b-fac78545835d"
#define DEVICE_INFO_SERVICE_UUID    "0000180A-0000-1000-8000-00805f9b34fb"
#define FIRMWARE_VERSION_UUID       "00002a26-0000-1000-8000-00805f9b34fb"
#define MANUFACTURER_NAME_UUID      "00002a29-0000-1000-8000-00805f9b34fb"
#define MODEL_NUMBER_UUID           "00002a24-0000-1000-8000-00805f9b34fb"
#define SERIAL_NUMBER_UUID          "00002a25-0000-1000-8000-00805f9b34fb"

// UUIDs pour le service OTS (Object Transfer Service)
#define OTS_SERVICE_UUID            "00001825-0000-1000-8000-00805f9b34fb"
#define OTS_FEATURE_CHAR_UUID       "00002abd-0000-1000-8000-00805f9b34fb"
#define OTS_OBJECT_NAME_CHAR_UUID   "00002abe-0000-1000-8000-00805f9b34fb"
#define OTS_OBJECT_SIZE_CHAR_UUID   "00002ac0-0000-1000-8000-00805f9b34fb"
#define OTS_OACP_CHAR_UUID          "00002ac5-0000-1000-8000-00805f9b34fb"
#define OTS_CHANNEL_CHAR_UUID       "030012ac-4202-d690-ec11-006fcee44c41"

// UUIDs pour le service OTA (Over-The-Air Update)
#define OTA_SERVICE_UUID            "030012ac-4202-d690-ec11-006fcee44c3e"
#define OTA_CONTROL_CHAR_UUID       "030012ac-4202-d690-ec11-006fcee44c3f"
#define OTA_CHANNEL_CHAR_UUID       "030012ac-4202-d690-ec11-006fcee44c40"

// Gestion de connexion et déconnexion BLE
class ServerCallbacks : public BLEServerCallbacks
{
    void onConnect(BLEServer* pServer) override
    {
        deviceConnected = true;
        Serial.printf("Appareil BLE connecté.\n");
    }

    void onDisconnect(BLEServer* pServer) override
    {
        deviceConnected = false;
        BLE_StartAdvertising(); // Relance l'advertising après déconnexion
        Serial.printf("Appareil BLE déconnecté.\n");
    }
};

// Ajout des informations d’appareil au service BLE
void addDeviceInfoService(BLEServer* pServer)
{
    BLEService* pDeviceInfoService = pServer->createService(DEVICE_INFO_SERVICE_UUID);

    // Version du Firmware
    BLECharacteristic* firmwareVersionChar = pDeviceInfoService->createCharacteristic(
        FIRMWARE_VERSION_UUID,
        BLECharacteristic::PROPERTY_READ
    );
    firmwareVersionChar->setValue("1.0.0");

    // Nom du Fabricant
    BLECharacteristic* manufacturerNameChar = pDeviceInfoService->createCharacteristic(
        MANUFACTURER_NAME_UUID,
        BLECharacteristic::PROPERTY_READ
    );
    manufacturerNameChar->setValue("Nicolas");

    // Numéro de Modèle
    BLECharacteristic* modelNumberChar = pDeviceInfoService->createCharacteristic(
        MODEL_NUMBER_UUID,
        BLECharacteristic::PROPERTY_READ
    );
    modelNumberChar->setValue("GYW_WATCH");

    // Numéro de Série
    BLECharacteristic* serialNumberChar = pDeviceInfoService->createCharacteristic(
        SERIAL_NUMBER_UUID,
        BLECharacteristic::PROPERTY_READ
    );
    serialNumberChar->setValue("GYW_WATCH_001");

    pDeviceInfoService->start();
}

// Callbacks pour les caractéristiques OTS
class OTSObjectNameCharacteristicCallbacks : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic* pCharacteristic) override
    {
        String value = String(pCharacteristic->getValue().c_str()); // Conversion de std::string à Arduino String
        Serial.printf("OTS Object Name Written: %s\n", value.c_str());
        // Traitez le nom de l'objet ici
    }
};

class OTSCommandCharacteristicCallbacks : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic* pCharacteristic) override
    {
        String value = String(pCharacteristic->getValue().c_str());
        Serial.printf("OTS Command Received. Length: %d\n", value.length());
        // Traitez la commande OTS ici
    }
};

class OTSChannelCharacteristicCallbacks : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic* pCharacteristic) override
    {
        String value = String(pCharacteristic->getValue().c_str());
        Serial.printf("OTS Channel Data Received. Length: %d\n", value.length());
        // Traitez les données du canal OTS ici
    }
};

// Callbacks pour les caractéristiques OTA
class OTAControlCharacteristicCallbacks : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic* pCharacteristic) override
    {
        String value = String(pCharacteristic->getValue().c_str());
        Serial.printf("OTA Control Command Received. Length: %d\n", value.length());
        // Traitez la commande OTA ici
    }
};

class OTAChannelCharacteristicCallbacks : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic* pCharacteristic) override
    {
        String value = String(pCharacteristic->getValue().c_str());
        Serial.printf("OTA Channel Data Received. Length: %d\n", value.length());
        // Traitez les données du canal OTA ici
    }
};

// Initialisation des services et caractéristiques BLE
void BLE_Init(const char* deviceName)
{
    nvs_flash_init();

    BLEDevice::init(deviceName);
    pServer = BLEDevice::createServer();
    pServer->setCallbacks(new ServerCallbacks());

    // Service de Commande
    BLEService* pCommandService = pServer->createService(COMMAND_SERVICE_UUID);

    // Caractéristique Command_Control
    pDisplayCommandCharacteristic = pCommandService->createCharacteristic(
        COMMAND_CONTROL_CHAR_UUID,
        BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_WRITE_NR
    );
    pDisplayCommandCharacteristic->setCallbacks(new DisplayCommandCharacteristicCallbacks());

    // Caractéristique Command_Data
    pDisplayDataCharacteristic = pCommandService->createCharacteristic(
        COMMAND_DATA_CHAR_UUID,
        BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_WRITE_NR
    );
    pDisplayDataCharacteristic->setCallbacks(new DisplayDataCharacteristicCallbacks());

    pCommandService->start();

    // Service de Batterie
    BLEService* pBatteryService = pServer->createService(BATTERY_SERVICE_UUID);

    // Caractéristique Battery Level
    pBatteryCharacteristic = pBatteryService->createCharacteristic(
        BATTERY_LEVEL_CHAR_UUID,
        BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY
    );
    pBatteryService->start();

    // Service Cible
    BLEService* pTargetService = pServer->createService(TARGET_SERVICE_UUID);

    BLECharacteristic* pTargetCtrlCharacteristic = pTargetService->createCharacteristic(
        TARGET_CTRL_CHAR_UUID,
        BLECharacteristic::PROPERTY_WRITE
    );
    pTargetService->start();

    // Ajout du service Device Information avec les informations d'appareil
    addDeviceInfoService(pServer);

    // Ajout du service OTS
    initOTSService();

    // Ajout du service OTA
    initOTAService();

    BLE_StartAdvertising();
}

// Démarrage de la publicité BLE
void BLE_StartAdvertising()
{
    BLEAdvertising* pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(COMMAND_SERVICE_UUID);
    pAdvertising->addServiceUUID(OTS_SERVICE_UUID);
    pAdvertising->addServiceUUID(OTA_SERVICE_UUID);
    pAdvertising->setScanResponse(true);
    BLEDevice::startAdvertising();
    Serial.printf("Démarrage de l'advertising BLE...\n");
}

// Initialisation du service OTS
void initOTSService()
{
    BLEService* pOTSService = pServer->createService(OTS_SERVICE_UUID);

    // Caractéristique OTS Feature
    BLECharacteristic* pOTSFeatureCharacteristic = pOTSService->createCharacteristic(
        OTS_FEATURE_CHAR_UUID,
        BLECharacteristic::PROPERTY_READ
    );
    uint8_t otsFeatureValue[8] = {0x46, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    pOTSFeatureCharacteristic->setValue(otsFeatureValue, 8);

    // Caractéristique Object Name
    BLECharacteristic* pOTSObjectNameCharacteristic = pOTSService->createCharacteristic(
        OTS_OBJECT_NAME_CHAR_UUID,
        BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE
    );
    pOTSObjectNameCharacteristic->setCallbacks(new OTSObjectNameCharacteristicCallbacks());

    // Caractéristique Object Size
    BLECharacteristic* pOTSObjectSizeCharacteristic = pOTSService->createCharacteristic(
        OTS_OBJECT_SIZE_CHAR_UUID,
        BLECharacteristic::PROPERTY_READ
    );
    uint8_t otsObjectSizeValue[8] = {0}; // Taille initiale à zéro
    pOTSObjectSizeCharacteristic->setValue(otsObjectSizeValue, 8);

    // Caractéristique OACP (Object Action Control Point)
    BLECharacteristic* pOTSCommandCharacteristic = pOTSService->createCharacteristic(
        OTS_OACP_CHAR_UUID,
        BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_INDICATE
    );
    pOTSCommandCharacteristic->setCallbacks(new OTSCommandCharacteristicCallbacks());
    // Ajouter le descripteur pour les indications
    pOTSCommandCharacteristic->addDescriptor(new BLE2902());

    // Caractéristique OTS Channel
    BLECharacteristic* pOTSChannelCharacteristic = pOTSService->createCharacteristic(
        OTS_CHANNEL_CHAR_UUID,
        BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_NOTIFY
    );
    pOTSChannelCharacteristic->setCallbacks(new OTSChannelCharacteristicCallbacks());
    // Ajouter le descripteur pour les notifications
    pOTSChannelCharacteristic->addDescriptor(new BLE2902());

    pOTSService->start();
}

// Initialisation du service OTA
void initOTAService()
{
    BLEService* pOTAService = pServer->createService(OTA_SERVICE_UUID);

    // Caractéristique OTA Control
    BLECharacteristic* pOTAControlCharacteristic = pOTAService->createCharacteristic(
        OTA_CONTROL_CHAR_UUID,
        BLECharacteristic::PROPERTY_WRITE
    );
    pOTAControlCharacteristic->setCallbacks(new OTAControlCharacteristicCallbacks());

    // Caractéristique OTA Channel
    BLECharacteristic* pOTAChannelCharacteristic = pOTAService->createCharacteristic(
        OTA_CHANNEL_CHAR_UUID,
        BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_NOTIFY
    );
    pOTAChannelCharacteristic->setCallbacks(new OTAChannelCharacteristicCallbacks());
    // Ajouter le descripteur pour les notifications
    pOTAChannelCharacteristic->addDescriptor(new BLE2902());

    pOTAService->start();
}
