module;

#include <Windows.h>

export module GLADBase;

import DebugLogger;
import GLADTypes;
import GLADMacros;

export namespace GLAD {
    using GLADloadproc = void* (*)(const char* name);
    using PFNWGLGETPROCADDRESSPROC_PRIVATE = void* (*)(const char*);

    int gladLoadGL();

    int gladLoadGLLoader(GLADloadproc);

    template <typename T>
        T gladLoadFunction(const char* name, GLADloadproc loader) {
        T func = reinterpret_cast<T>(loader(name));
        if (!func) {
            warning("Failed to load function: " + std::string(name));
        }
        return func;
    }

    template <typename T>
        T gladLoadCoreFunction(const char* name, const char* loader) {
        T func = reinterpret_cast<T>(GetProcAddress(GetModuleHandleA(loader), name));
        if (!func) {
            warning("Failed to load function: " + std::string(name) + " using loader: " + loader);
        }
        return func;
    }
}