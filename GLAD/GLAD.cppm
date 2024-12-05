import GLAD;

#include <chrono>

namespace GLAD {
    static PFNWGLGETPROCADDRESSPROC_PRIVATE gladGetProcAddressPtr;

    static void* get_proc(const char* namez);

    #if defined(_WIN32) || defined(__CYGWIN__)
    #ifndef _WINDOWS_
    #undef APIENTRY
    #endif
    #include <windows.h>
    static HMODULE libGL;

    #ifdef _MSC_VER
    #ifdef __has_include
    #if __has_include(<winapifamily.h>)
    #define HAVE_WINAPIFAMILY 1
    #endif
    #elif _MSC_VER >= 1700 && !_USING_V110_SDK71_
    #define HAVE_WINAPIFAMILY 1
    #endif
    #endif

    #ifdef HAVE_WINAPIFAMILY
    #include <winapifamily.h>
    #if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    #define IS_UWP 1
    #endif
    #endif

    static int open_gl(void) {
    #ifndef IS_UWP
        libGL = LoadLibraryW(L"opengl32.dll");
        if (libGL != nullptr) {
            void (*tmp)(void);
            tmp = (void(*)(void)) GetProcAddress(libGL, "wglGetProcAddress");
            gladGetProcAddressPtr = (GLAD::PFNWGLGETPROCADDRESSPROC_PRIVATE)tmp;
            return gladGetProcAddressPtr != nullptr;
        }
    #endif

        return 0;
    }

    static
    void close_gl(void) {
        if (libGL != nullptr) {
            FreeLibrary((HMODULE)libGL);
            libGL = nullptr;
        }
    }
    #else
    #include <dlfcn.h>
    static void* libGL;

    #if !defined(__APPLE__) && !defined(__HAIKU__)
    typedef void* (APIENTRYP PFNGLXGETPROCADDRESSPROC_PRIVATE)(const char*);
    static PFNGLXGETPROCADDRESSPROC_PRIVATE gladGetProcAddressPtr;
    #endif

    static
    int open_gl(void) {
    #ifdef __APPLE__
        static const char* NAMES[] = {
            "../Frameworks/OpenGL.framework/OpenGL",
            "/Library/Frameworks/OpenGL.framework/OpenGL",
            "/System/Library/Frameworks/OpenGL.framework/OpenGL",
            "/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL"
        };
    #else
        static const char* NAMES[] = { "libGL.so.1", "libGL.so" };
    #endif

        unsigned int index = 0;
        for (index = 0; index < (sizeof(NAMES) / sizeof(NAMES[0])); index++) {
            libGL = dlopen(NAMES[index], RTLD_NOW | RTLD_GLOBAL);

            if (libGL != nullptr) {
    #if defined(__APPLE__) || defined(__HAIKU__)
                return 1;
    #else
                gladGetProcAddressPtr = (GLAD::PFNGLXGETPROCADDRESSPROC_PRIVATE)dlsym(libGL,
                    "glXGetProcAddressARB");
                return gladGetProcAddressPtr != nullptr;
    #endif
            }
        }

        return 0;
    }

    static
    void close_gl(void) {
        if (libGL != nullptr) {
            dlclose(libGL);
            libGL = nullptr;
        }
    }
    #endif

    static
    void* get_proc(const char* namez) {
        void* result = nullptr;
        if (libGL == nullptr) return nullptr;

    #if !defined(__APPLE__) && !defined(__HAIKU__)
        if (gladGetProcAddressPtr != nullptr) {
            result = gladGetProcAddressPtr(namez);
        }
    #endif
        if (result == nullptr) {
    #if defined(_WIN32) || defined(__CYGWIN__)
            result = (void*)GetProcAddress((HMODULE)libGL, namez);
    #else
            result = dlsym(libGL, namez);
    #endif
        }

        return result;
    }

    bool gladLoaded = false;

    int GLAD::gladLoadGL(void) {
        if (gladLoaded) {
            return 1;
        }

        int status = 0;

        if (open_gl()) {
            status = GLAD::gladLoadGLLoader(&get_proc);
#ifdef _DEBUG
            GLAD::glEnable(GLAD::GL_DEBUG_OUTPUT);
            GLAD::glDebugMessageCallback(GLAD::ErrorMessageCallback, nullptr);
#endif
            close_gl();
        }

        gladLoaded = true;
        return status;
    }

    int GLAD::gladLoadGLLoader(GLADloadproc load) {
	    GLAD::V4_6::load_GL_RECURSIVE(load);
        GLAD::load_WGL_BASE(load);
        return 1;
    }

    Time* Time::getInstance() {
        static Time instance;
        return &instance;
    }

    float Time::timeElapsed() {
        auto now = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration<float>(now - initializedGlad).count(); // Converts to seconds
        return elapsed;
    }

    float gladGetDeltaTime() {
        return Time::getInstance()->timeElapsed();
    }
}

