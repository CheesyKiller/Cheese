module;

#include <cstdint>

export module KHR:Macros;

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