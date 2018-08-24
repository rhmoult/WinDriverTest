#include "driver.h"

#ifdef ALLOC_PRAGMA
#pragma alloc_text (INIT, DriverEntry)
#pragma alloc_text (PAGE, Planck_Unload)
#endif

NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
    )
{
    NTSTATUS NtStatus = STATUS_SUCCESS;
    UINT uiIndex = 0;
    PDEVICE_OBJECT DeviceObject = NULL;
    UNICODE_STRING usDriverName, usDosDeviceName;

    DbgPrint("Driver Entry Called \r\n");

    RtlInitUnicodeString(&usDriverName, L"\\Device\\Planck");
    RtlInitUnicodeString(&usDosDeviceName, L"\\DosDevices\\Planck");

    NtStatus = IoCreateDevice(DriverObject, 0, &usDriverName,
        FILE_DEVICE_UNKNOWN, FILE_DEVICE_SECURE_OPEN, FALSE, &DeviceObject);

    if(NtStatus == STATUS_SUCCESS) {
        DbgPrint("Created device! \r\n");
        DriverObject->DriverUnload = Planck_Unload;
        IoCreateSymbolicLink(&usDosDeviceName, &usDriverName);
    }

    return NtStatus;

}

VOID Planck_Unload(PDRIVER_OBJECT DriverObject) {
    UNICODE_STRING usDosDeviceName;

    DbgPrint("Planck_Unload called!  \r\n");

    RtlInitUnicodeString(&usDosDeviceName, L"\\DosDevices\\Planck");
    IoDeleteSymbolicLink(&usDosDeviceName);

    IoDeleteDevice(DriverObject->DeviceObject);
}