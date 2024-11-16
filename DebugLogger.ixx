module;

#include <iostream>
#include <string>
#include <source_location>

export module DebugLogger;

export inline void error(
    const std::string& message,
    const std::source_location location = std::source_location::current()
) {
#ifdef _SIMPLE_DEBUG
	std::cerr << "Error: " << message << std::endl;
#else
#ifdef _DEBUG
    std::cerr << "Error in " << location.function_name() << ": " << message << std::endl;
#endif
#endif
    std::terminate();
}

export inline void warning(
    const std::string& message,
    const std::source_location location = std::source_location::current()
) {
#ifdef _SIMPLE_DEBUG
    std::cerr << "Warning: " << message << std::endl;
#else
#ifdef _DEBUG
    std::cerr << "Warning in " << location.function_name() << ": " << message << std::endl;
#endif
#endif
}