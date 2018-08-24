#include "public.h"

typedef struct _DEVICE_CONTEXT {
    ULONG PrivateDeviceData;
} DEVICE_CONTEXT, *PDEVICE_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE(DEVICE_CONTEXT)

NTSTATUS 
PlanckDeviceCreate(
    PWDFDEVICE_INIT DeviceInit
);

// Device Events
EVT_WDF_DEVICE_SELF_MANAGED_IO_INIT PlanckEvtDeviceSelfManagedIoStart;

EVT_WDF_DEVICE_SELF_MANAGED_IO_SUSPEND PlanckEvtDeviceSelfManagedIoSuspend;
