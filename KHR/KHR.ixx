module;

#include <cstdint>

export module KHR;

export namespace KHR {
    // Export constants
    export constexpr int KHRONOS_MAX_ENUM = 0x7FFFFFFF;

    export constexpr auto GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB = 0x00000004;
    export constexpr auto GLAD_GL_ARB_robustness = 0;
    export constexpr auto GLAD_GL_ARB_multisample = 0;

    // Handle KHRONOS_STATIC definition based on platform
#if defined(__SCITECH_SNAP__) && !defined(KHRONOS_STATIC)
#define KHRONOS_STATIC 1
#endif

// Define KHRONOS_APICALL based on platform
#if defined(KHRONOS_STATIC)
    export constexpr const char* KHRONOS_APICALL = "";
#elif defined(_WIN32)
    export constexpr const char* KHRONOS_APICALL = "__declspec(dllimport)";
#elif defined(__SYMBIAN32__)
    export constexpr const char* KHRONOS_APICALL = "IMPORT_C";
#elif defined(__ANDROID__)
    export constexpr const char* KHRONOS_APICALL = "__attribute__((visibility(\"default\")))";
#else
    export constexpr const char* KHRONOS_APICALL = "";
#endif

    // Define KHRONOS_APIENTRY based on platform
#if defined(_WIN32) && !defined(_WIN32_WCE) && !defined(__SCITECH_SNAP__)
    export constexpr const char* KHRONOS_APIENTRY = "__stdcall";
#else
    export constexpr const char* KHRONOS_APIENTRY = "";
#endif

    // Define KHRONOS_APIATTRIBUTES based on platform
#if defined(__ARMCC_2__)
    export constexpr const char* KHRONOS_APIATTRIBUTES = "__softfp";
#else
    export constexpr const char* KHRONOS_APIATTRIBUTES = "";
#endif

    // Basic type definitions
    export using khronos_int8_t = signed char;
    export using khronos_uint8_t = unsigned char;
    export using khronos_int16_t = signed short int;
    export using khronos_uint16_t = unsigned short int;
    export using khronos_int32_t = int32_t;
    export using khronos_uint32_t = uint32_t;
    export using khronos_int64_t = int64_t;
    export using khronos_uint64_t = uint64_t;

    // Conditional type definitions based on platform
#if defined(__SIZEOF_LONG__) && defined(__SIZEOF_POINTER__)
#if __SIZEOF_POINTER__ > __SIZEOF_LONG__
#define KHRONOS_USE_INTPTR_T
#endif
#endif

#ifdef KHRONOS_USE_INTPTR_T
    export using khronos_intptr_t = intptr_t;
    export using khronos_uintptr_t = uintptr_t;
#elif defined(_WIN64)
    export using khronos_intptr_t = long long int;
    export using khronos_uintptr_t = unsigned long long int;
#else
    export using khronos_intptr_t = long int;
    export using khronos_uintptr_t = unsigned long int;
#endif

#if defined(_WIN64)
    export using khronos_ssize_t = long long int;
    export using khronos_usize_t = unsigned long long int;
#else
    export using khronos_ssize_t = long int;
    export using khronos_usize_t = unsigned long int;
#endif

    // Float type
    export using khronos_float_t = float;

    // Time types
    export using khronos_time_ns_t = khronos_uint64_t;
    export using khronos_utime_nanoseconds_t = khronos_uint64_t;
    export using khronos_stime_nanoseconds_t = khronos_int64_t;

    // Enumerated boolean type
    export enum class khronos_boolean_enum_t : int {
        FALSE = 0,
        TRUE = 1,
        BOOLEAN_ENUM_FORCE_SIZE = KHRONOS_MAX_ENUM
    };
}