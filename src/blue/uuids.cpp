#include "uuids.hpp"

#define DEVICE_INFO_SERVICE_UUID 0x180A
#define FIRMWARE_VERSION_UUID 0x2a26
#define MANUFACTURER_NAME_UUID 0x2a29
#define MODEL_NUMBER_UUID 0x2a24
#define SERIAL_NUMBER_UUID 0x2a25

#define BATTERY_SERVICE_UUID 0x180F
#define BATTERY_LEVEL_CHAR_UUID 0x2a19

#define COMMAND_SERVICE_UUID { 0x51, 0x2e, 0xb8, 0xf7, 0xde, 0x35, 0x92, 0x9b, 0x53, 0x4d, 0x49, 0x51, 0xf3, 0x43, 0x34, 0x9f }
#define COMMAND_CONTROL_CHAR_UUID { 0x52, 0x2e, 0xb8, 0xf7, 0xde, 0x35, 0x92, 0x9b, 0x53, 0x4d, 0x49, 0x51, 0xf3, 0x43, 0x34, 0x9f }
#define COMMAND_DATA_CHAR_UUID { 0x53, 0x2e, 0xb8, 0xf7, 0xde, 0x35, 0x92, 0x9b, 0x53, 0x4d, 0x49, 0x51, 0xf3, 0x43, 0x34, 0x9f }

const ble_uuid16_t device_information_service_uuid = {
    .u = {
        .type = BLE_UUID_TYPE_16,
    },
    .value = DEVICE_INFO_SERVICE_UUID,
};

const ble_uuid16_t firmware_version_uuid = {
    .u = {
        .type = BLE_UUID_TYPE_16,
    },
    .value = FIRMWARE_VERSION_UUID,
};

const ble_uuid16_t manufacturer_name_uuid = {
    .u = {
        .type = BLE_UUID_TYPE_16,
    },
    .value = MANUFACTURER_NAME_UUID,
};

const ble_uuid16_t model_number_uuid = {
    .u = {
        .type = BLE_UUID_TYPE_16,
    },
    .value = MODEL_NUMBER_UUID,
};

const ble_uuid16_t serial_number_uuid = {
    .u = {
        .type = BLE_UUID_TYPE_16,
    },
    .value = SERIAL_NUMBER_UUID,
};


const ble_uuid16_t battery_service_uuid = {
    .u = {
        .type = BLE_UUID_TYPE_16,
    },
    .value = BATTERY_SERVICE_UUID,
};

const ble_uuid16_t battery_level_char_uuid = {
    .u = {
        .type = BLE_UUID_TYPE_16,
    },
    .value = BATTERY_LEVEL_CHAR_UUID,
};


const ble_uuid128_t command_service_uuid = {
    .u = {
        .type = BLE_UUID_TYPE_128,
    },
    .value = COMMAND_SERVICE_UUID,
};

const ble_uuid128_t command_control_char_uuid = {
    .u = {
        .type = BLE_UUID_TYPE_128,
    },
    .value = COMMAND_CONTROL_CHAR_UUID,
};

const ble_uuid128_t command_data_char_uuid = {
    .u = {
        .type = BLE_UUID_TYPE_128,
    },
    .value = COMMAND_DATA_CHAR_UUID,
};
