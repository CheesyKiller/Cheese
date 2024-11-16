#include <stdexcept>
#include <Windows.h>

export module GLAD:BASE;

export import DebugLogger;
export import :Types;
export import :Macros;

export using GLADloadproc = void* (*)(const char* name);
export using PFNWGLGETPROCADDRESSPROC_PRIVATE = void* (*)(const char*);

export int gladLoadGL();

export int gladLoadGLLoader(GLADloadproc);

export template <typename T>
T gladLoadFunction(const char* name, GLADloadproc loader) {
    T func = reinterpret_cast<T>(loader(name));
    if (!func) {
        warning("Failed to load function: " + std::string(name));
    }
    return func;
}

export template <typename T>
T gladLoadCoreFunction(const char* name, const char* loader) {
    T func = reinterpret_cast<T>(GetProcAddress(GetModuleHandleA(loader), name));
    if (!func) {
		warning("Failed to load function: " + std::string(name) + " using loader: " + loader);
    }
    return func;
}