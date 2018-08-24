/*
 * Copyright (c) 2018 Planck Star Online Solutions
 */

#define INITGUID

#include <ntddk.h>
#include <wdf.h>

#include "device.h"


typedef unsigned int UINT;

/*
 * WDFDriver Events
 */

 DRIVER_INITIALIZE DriverEntry;
 EVT_WDF_DRIVER_DEVICE_ADD PlanckEvtDeviceAdd;