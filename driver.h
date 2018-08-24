/*
 * Copyright (c) 2018 Planck Star Online Solutions
 */

#define INIT GUID

#include <ntddk.h>
#include <wdf.h>


typedef unsigned int UINT;

/*
 * WDFDriver Events
 */

 DRIVER_INITIALIZE DriverEntry;
 VOID Planck_Unload(PDRIVER_OBJECT DriverObject);