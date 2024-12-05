module;

#include <Windows.h>

export module GLADWGL:Types;

export namespace GLAD {
    // WGL Constants
    using HPBUFFEREXT = HANDLE;
    using HPBUFFERARB = HANDLE;
    using HGPUNV = HANDLE;

    // Structure Definition for GPU_DEVICE
    struct GPU_DEVICE {
        int cb;                     // Size of the structure in bytes
        int Device;                 // Device identifier
        int NodeMask;               // Node mask for multi-GPU systems
        int Flags;                  // Flags indicating device properties
        WCHAR DeviceString[32];     // Descriptive string for the device
    };

    using PGPU_DEVICE = GPU_DEVICE*;
}