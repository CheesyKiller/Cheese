export module KHR:Types;

import <cstdint>;

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