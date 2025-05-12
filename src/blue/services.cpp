#include "services.hpp"

#include <assert.h>
#include <mutex>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <utils/GYW_DisplayCommands.h>

#include "host/ble_hs.h"
#include "host/ble_uuid.h"
#include "services/gap/ble_svc_gap.h"
#include "services/gatt/ble_svc_gatt.h"

extern "C" {
#include "services/ans/ble_svc_ans.h"
}

#include "uuids.hpp"

std::string globalDataBuffer = "";
std::mutex globalDataMutex;

static uint16_t command_control_char_handle;
static uint16_t command_data_char_handle;

static int
gatt_svc_access(uint16_t conn_handle, uint16_t attr_handle,
                struct ble_gatt_access_ctxt* ctxt,
                void* arg);

static const struct ble_gatt_svc_def service_definitions[] = {
    {
        /*** Service ***/
        .type = BLE_GATT_SVC_TYPE_PRIMARY,
        .uuid = &command_service_uuid.u,
        .characteristics = (struct ble_gatt_chr_def[])
        {
            {
                .uuid = &command_control_char_uuid.u,
                .access_cb = gatt_svc_access,
                .flags = BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_WRITE_NO_RSP,
                .val_handle = &command_control_char_handle,
            },
            {
                .uuid = &command_data_char_uuid.u,
                .access_cb = gatt_svc_access,
                .flags = BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_WRITE_NO_RSP,
                .val_handle = &command_data_char_handle,
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

static int
gatt_svr_write(struct os_mbuf* om, uint16_t min_len, uint16_t max_len,
               void* dst, uint16_t* len)
{
    uint16_t om_len;
    int rc;

    om_len = OS_MBUF_PKTLEN(om);
    if (om_len < min_len || om_len > max_len)
    {
        return BLE_ATT_ERR_INVALID_ATTR_VALUE_LEN;
    }

    rc = ble_hs_mbuf_to_flat(om, dst, max_len, len);
    if (rc != 0)
    {
        return BLE_ATT_ERR_UNLIKELY;
    }

    return 0;
}

static int
gatt_svc_access(uint16_t conn_handle, uint16_t attr_handle,
                struct ble_gatt_access_ctxt* ctxt, void* arg)
{
    int rc = 0;

    switch (ctxt->op)
    {
    case BLE_GATT_ACCESS_OP_WRITE_CHR:
        if (conn_handle != BLE_HS_CONN_HANDLE_NONE)
        {
            MODLOG_DFLT(INFO, "Characteristic write; conn_handle=%d attr_handle=%d",
                        conn_handle, attr_handle);
        }
        else
        {
            MODLOG_DFLT(INFO, "Characteristic write by NimBLE stack; attr_handle=%d",
                        attr_handle);
        }
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

            return rc;
        }
        else if (attr_handle == command_data_char_handle)
        {
            uint8_t* data = ctxt->om->om_data;
            size_t data_len = OS_MBUF_PKTLEN(ctxt->om);

            if (data_len == 0)
                return 0;

            std::scoped_lock lock(globalDataMutex);
            globalDataBuffer += reinterpret_cast<const char*>(data);

            return rc;
        }
        else
        {
            return BLE_ATT_ERR_UNLIKELY;
        }
        goto unknown;

    default:
        goto unknown;
    }

unknown:
    /* Unknown characteristic/descriptor;
     * The NimBLE host should not have called this function;
     */
    assert(0);
    return BLE_ATT_ERR_UNLIKELY;
}

int gatt_svr_init(void)
{
    int rc;

    ble_svc_gap_init();
    ble_svc_gatt_init();
    ble_svc_ans_init();

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
