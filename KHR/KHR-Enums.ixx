export module KHR:Enums;

import :Macros;

// Enumerated boolean type
export enum class khronos_boolean_enum_t : int {
    FALSE = 0,
    TRUE = 1,
    BOOLEAN_ENUM_FORCE_SIZE = KHRONOS_MAX_ENUM
};