#pragma once

#include "services/gap/ble_svc_gap.h"

void gatt_svr_register_cb(struct ble_gatt_register_ctxt *ctxt, void *arg);
int gatt_svr_init();
