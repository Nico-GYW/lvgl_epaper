#include "services.hpp"

#include <cassert>
#include <mutex>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <utils/GYW_DisplayCommands.h>

#include "host/ble_hs.h"
#include "host/ble_uuid.h"
#include "services/gap/ble_svc_gap.h"
#include "services/gatt/ble_svc_gatt.h"

#include "uuids.hpp"

static const char* firmware_version = "1.0.0";
static const char* manufacturer_name = "Get Your Way";
static const char* model_number = "GYW_OLED_DISPLAY";
static const char* serial_number = "GYW_OLED_DISPLAY_001";

std::string globalDataBuffer;
std::mutex globalDataMutex;

static uint16_t firmware_version_char_handle;
static uint16_t manufacturer_name_char_handle;
static uint16_t model_number_char_handle;
static uint16_t serial_number_char_handle;

static uint16_t command_control_char_handle;
static uint16_t command_data_char_handle;

static int gatt_read_handler(uint16_t conn_handle, uint16_t attr_handle,
                             ble_gatt_access_ctxt* ctxt,
                             void* arg);

static int gatt_write_handler(uint16_t conn_handle, uint16_t attr_handle,
                              ble_gatt_access_ctxt* ctxt,
                              void* arg);

static const ble_gatt_svc_def service_definitions[] = {
    {
        /*** Service ***/
        .type = BLE_GATT_SVC_TYPE_PRIMARY,
        .uuid = &command_service_uuid.u,
        .characteristics = (struct ble_gatt_chr_def[])
        {
            {
                .uuid = &command_control_char_uuid.u,
                .access_cb = gatt_write_handler,
                .flags = BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_WRITE_NO_RSP,
                .val_handle = &command_control_char_handle,
            },
            {
                .uuid = &command_data_char_uuid.u,
                .access_cb = gatt_write_handler,
                .flags = BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_WRITE_NO_RSP,
                .val_handle = &command_data_char_handle,
            },

            {
                0,
            }
        },
    },
    {
        /*** Service ***/
        .type = BLE_GATT_SVC_TYPE_PRIMARY,
        .uuid = &device_information_service_uuid.u,
        .characteristics = (struct ble_gatt_chr_def[])
        {
            {
                .uuid = &firmware_version_uuid.u,
                .access_cb = gatt_read_handler,
                .flags = BLE_GATT_CHR_F_READ,
                .val_handle = &firmware_version_char_handle,
            },

            {
                .uuid = &manufacturer_name_uuid.u,
                .access_cb = gatt_read_handler,
                .flags = BLE_GATT_CHR_F_READ,
                .val_handle = &manufacturer_name_char_handle,
            },

            {
                .uuid = &model_number_uuid.u,
                .access_cb = gatt_read_handler,
                .flags = BLE_GATT_CHR_F_READ,
                .val_handle = &model_number_char_handle,
            },

            {
                .uuid = &serial_number_uuid.u,
                .access_cb = gatt_read_handler,
                .flags = BLE_GATT_CHR_F_READ,
                .val_handle = &serial_number_char_handle,
            },
            {
                0,
            }
        },
    },
    {
        0,
    },
};

static int gatt_read_handler(uint16_t conn_handle, uint16_t attr_handle,
                             ble_gatt_access_ctxt* ctxt, void* arg)
{
    const char* data;
    if (attr_handle == firmware_version_char_handle)
    {
        data = firmware_version;
    }
    else if (attr_handle == manufacturer_name_char_handle)
    {
        data = manufacturer_name;
    }
    else if (attr_handle == model_number_char_handle)
    {
        data = model_number;
    }
    else if (attr_handle == serial_number_char_handle)
    {
        data = serial_number;
    }
    else
    {
        return BLE_ATT_ERR_UNLIKELY;
    }

    const int rc = os_mbuf_append(ctxt->om, data, strlen(data));
    return rc == 0 ? 0 : BLE_ATT_ERR_INSUFFICIENT_RES;
}

static int gatt_write_handler(uint16_t conn_handle, uint16_t attr_handle,
                              ble_gatt_access_ctxt* ctxt, void* arg)
{
    assert(ctxt->op == BLE_GATT_ACCESS_OP_READ_CHR);

    if (attr_handle == command_control_char_handle)
    {
        uint8_t* data = ctxt->om->om_data;
        size_t data_len = OS_MBUF_PKTLEN(ctxt->om);

        if (data_len == 0)
            return 0;

        uint8_t commandCode = data[0];
        uint8_t* paramsData = data + 1;
        size_t paramsLength = data_len - 1;

        DisplayCommand command = {};
        command.cmdType = static_cast<DisplayCommandType>(commandCode);
        command.paramsLength = paramsLength;

        memcpy(command.paramsData, paramsData, paramsLength);

        std::scoped_lock lock(globalDataMutex);

        // Si nécessaire, copie le buffer global de données
        if (!globalDataBuffer.empty())
        {
            strncpy(command.dataBuffer, globalDataBuffer.c_str(), sizeof(command.dataBuffer) - 1);
        }

        // Enfile la commande
        process_command(command);

        // Vide le buffer global après le traitement
        globalDataBuffer.clear();

        return 0;
    }
    else if (attr_handle == command_data_char_handle)
    {
        uint8_t* data = ctxt->om->om_data;
        size_t data_len = OS_MBUF_PKTLEN(ctxt->om);

        if (data_len == 0)
            return 0;

        std::scoped_lock lock(globalDataMutex);
        globalDataBuffer += reinterpret_cast<const char*>(data);

        return 0;
    }
    else
    {
        return BLE_ATT_ERR_UNLIKELY;
    }
}

int gatt_svr_init()
{
    int rc;

    ble_svc_gap_init();
    ble_svc_gatt_init();

    rc = ble_gatts_count_cfg(service_definitions);
    if (rc != 0)
    {
        return rc;
    }

    rc = ble_gatts_add_svcs(service_definitions);
    if (rc != 0)
    {
        return rc;
    }

    return 0;
}
