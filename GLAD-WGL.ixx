module;

#include <Windows.h>

export module GLAD:WGL;

export import :BASE;

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

    // WGL Function Pointer Type Definitions and Declarations

    // WGL_VERSION_BASE

    using PFNWGLCHOOSEPIXELFORMATPROC = int(__stdcall*)(HDC hdc, const PIXELFORMATDESCRIPTOR* ppfd);
    using PFNWGLGETPIXELFORMATPROC = int(__stdcall*)(HDC hdc);
    using PFNWGLSETPIXELFORMATPROC = BOOL(__stdcall*)(HDC hdc, int format, const PIXELFORMATDESCRIPTOR* ppfd);
    using PFNWGLSWAPBUFFERSPROC = BOOL(__stdcall*)(HDC hdc);
    using PFNWGLSWAPINTERVALEXTPROC = BOOL(__stdcall*)(int interval);
    using PFNWGLGETSWAPINTERVALEXTPROC = int(__stdcall*)(void);

    // Function Pointer Declarations
    PFNWGLCHOOSEPIXELFORMATPROC wglChoosePixelFormat = nullptr;
    PFNWGLGETPIXELFORMATPROC wglGetPixelFormat = nullptr;
    PFNWGLSETPIXELFORMATPROC wglSetPixelFormat = nullptr;
    PFNWGLSWAPBUFFERSPROC wglSwapBuffers = nullptr;
    PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = nullptr;
    PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT = nullptr;

    // WGL_ARB_extensions_string
    using PFNWGLGETEXTENSIONSSTRINGARBPROC = const char* (__stdcall*)(HDC hdc);
    PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB = nullptr;

    // WGL_EXT_extensions_string
    using PFNWGLGETEXTENSIONSSTRINGEXTPROC = const char* (__stdcall*)(void);
    PFNWGLGETEXTENSIONSSTRINGEXTPROC wglGetExtensionsStringEXT = nullptr;

    // WGL_ARB_pixel_format
    using PFNWGLCHOOSEPIXELFORMATARBPROC = BOOL(__stdcall*)(HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats);
    using PFNWGLGETPIXELFORMATATTRIBIVARBPROC = BOOL(__stdcall*)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, int* piValues);
    using PFNWGLGETPIXELFORMATATTRIBFVARBPROC = BOOL(__stdcall*)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, FLOAT* pfValues);
    PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
    PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribivARB = nullptr;
    PFNWGLGETPIXELFORMATATTRIBFVARBPROC wglGetPixelFormatAttribfvARB = nullptr;

    // WGL_ARB_create_context
    using PFNWGLCREATECONTEXTATTRIBSARBPROC = HGLRC(__stdcall*)(HDC hDC, HGLRC hShareContext, const int* attribList);
    PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;

    // WGL_ARB_make_current_read
    using PFNWGLMAKECONTEXTCURRENTARBPROC = BOOL(__stdcall*)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
    using PFNWGLGETCURRENTREADDCARBPROC = HDC(__stdcall*)(void);
    PFNWGLMAKECONTEXTCURRENTARBPROC wglMakeContextCurrentARB = nullptr;
    PFNWGLGETCURRENTREADDCARBPROC wglGetCurrentReadDCARB = nullptr;

    // WGL_ARB_pbuffer
    using PFNWGLCREATEPBUFFERARBPROC = HPBUFFERARB(__stdcall*)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList);
    using PFNWGLGETPBUFFERDCARBPROC = HDC(__stdcall*)(HPBUFFERARB hPbuffer);
    using PFNWGLRELEASEPBUFFERDCARBPROC = int(__stdcall*)(HPBUFFERARB hPbuffer, HDC hDC);
    using PFNWGLDESTROYPBUFFERARBPROC = BOOL(__stdcall*)(HPBUFFERARB hPbuffer);
    using PFNWGLQUERYPBUFFERARBPROC = BOOL(__stdcall*)(HPBUFFERARB hPbuffer, int iAttribute, int* piValue);
    PFNWGLCREATEPBUFFERARBPROC wglCreatePbufferARB = nullptr;
    PFNWGLGETPBUFFERDCARBPROC wglGetPbufferDCARB = nullptr;
    PFNWGLRELEASEPBUFFERDCARBPROC wglReleasePbufferDCARB = nullptr;
    PFNWGLDESTROYPBUFFERARBPROC wglDestroyPbufferARB = nullptr;
    PFNWGLQUERYPBUFFERARBPROC wglQueryPbufferARB = nullptr;

    // WGL_ARB_render_texture
    using PFNWGLBINDTEXIMAGEARBPROC = BOOL(__stdcall*)(HPBUFFERARB hPbuffer, int iBuffer);
    using PFNWGLRELEASETEXIMAGEARBPROC = BOOL(__stdcall*)(HPBUFFERARB hPbuffer, int iBuffer);
    using PFNWGLSETPBUFFERATTRIBARBPROC = BOOL(__stdcall*)(HPBUFFERARB hPbuffer, const int* piAttribList);
    PFNWGLBINDTEXIMAGEARBPROC wglBindTexImageARB = nullptr;
    PFNWGLRELEASETEXIMAGEARBPROC wglReleaseTexImageARB = nullptr;
    PFNWGLSETPBUFFERATTRIBARBPROC wglSetPbufferAttribARB = nullptr;

    // WGL_EXT_framebuffer_sRGB
    // No functions, only pixel format attributes.

    // WGL_ARB_framebuffer_sRGB
    // No functions, only pixel format attributes.

    // WGL_EXT_make_current_read
    using PFNWGLMAKECONTEXTCURRENTEXTPROC = BOOL(__stdcall*)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
    using PFNWGLGETCURRENTREADDCEXTPROC = HDC(__stdcall*)(void);
    PFNWGLMAKECONTEXTCURRENTEXTPROC wglMakeContextCurrentEXT = nullptr;
    PFNWGLGETCURRENTREADDCEXTPROC wglGetCurrentReadDCEXT = nullptr;

    // WGL_EXT_pbuffer
    using PFNWGLCREATEPBUFFEREXTPROC = HPBUFFEREXT(__stdcall*)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList);
    using PFNWGLGETPBUFFERDCEXTPROC = HDC(__stdcall*)(HPBUFFEREXT hPbuffer);
    using PFNWGLRELEASEPBUFFERDCEXTPROC = int(__stdcall*)(HPBUFFEREXT hPbuffer, HDC hDC);
    using PFNWGLDESTROYPBUFFEREXTPROC = BOOL(__stdcall*)(HPBUFFEREXT hPbuffer);
    using PFNWGLQUERYPBUFFEREXTPROC = BOOL(__stdcall*)(HPBUFFEREXT hPbuffer, int iAttribute, int* piValue);
    PFNWGLCREATEPBUFFEREXTPROC wglCreatePbufferEXT = nullptr;
    PFNWGLGETPBUFFERDCEXTPROC wglGetPbufferDCEXT = nullptr;
    PFNWGLRELEASEPBUFFERDCEXTPROC wglReleasePbufferDCEXT = nullptr;
    PFNWGLDESTROYPBUFFEREXTPROC wglDestroyPbufferEXT = nullptr;
    PFNWGLQUERYPBUFFEREXTPROC wglQueryPbufferEXT = nullptr;

    // WGL_EXT_pixel_format
    using PFNWGLCHOOSEPIXELFORMATEXTPROC = BOOL(__stdcall*)(HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats);
    using PFNWGLGETPIXELFORMATATTRIBIVEXTPROC = BOOL(__stdcall*)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, int* piValues);
    using PFNWGLGETPIXELFORMATATTRIBFVEXTPROC = BOOL(__stdcall*)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, FLOAT* pfValues);
    PFNWGLCHOOSEPIXELFORMATEXTPROC wglChoosePixelFormatEXT = nullptr;
    PFNWGLGETPIXELFORMATATTRIBIVEXTPROC wglGetPixelFormatAttribivEXT = nullptr;
    PFNWGLGETPIXELFORMATATTRIBFVEXTPROC wglGetPixelFormatAttribfvEXT = nullptr;

    // WGL_EXT_depth_float
    // No functions, only pixel format attributes.

    // WGL_NV_swap_group
    using PFNWGLJOINSWAPGROUPNVPROC = BOOL(__stdcall*)(HDC hDC, GLuint group);
    using PFNWGLBINDSWAPBARRIERNVPROC = BOOL(__stdcall*)(GLuint group, GLuint barrier);
    using PFNWGLQUERYSWAPGROUPNVPROC = BOOL(__stdcall*)(HDC hDC, GLuint* group, GLuint* barrier);
    using PFNWGLQUERYMAXSWAPGROUPSNVPROC = BOOL(__stdcall*)(HDC hDC, GLuint* maxGroups, GLuint* maxBarriers);
    using PFNWGLQUERYFRAMECOUNTNVPROC = BOOL(__stdcall*)(HDC hDC, GLuint* count);
    using PFNWGLRESETFRAMECOUNTNVPROC = BOOL(__stdcall*)(HDC hDC);
    PFNWGLJOINSWAPGROUPNVPROC wglJoinSwapGroupNV = nullptr;
    PFNWGLBINDSWAPBARRIERNVPROC wglBindSwapBarrierNV = nullptr;
    PFNWGLQUERYSWAPGROUPNVPROC wglQuerySwapGroupNV = nullptr;
    PFNWGLQUERYMAXSWAPGROUPSNVPROC wglQueryMaxSwapGroupsNV = nullptr;
    PFNWGLQUERYFRAMECOUNTNVPROC wglQueryFrameCountNV = nullptr;
    PFNWGLRESETFRAMECOUNTNVPROC wglResetFrameCountNV = nullptr;

    // WGL_NV_gpu_affinity
    using PFNWGLENUMGPUSNVPROC = BOOL(__stdcall*)(UINT iGpuIndex, HGPUNV* phGpu);
    using PFNWGLENUMGPUDEVICESNVPROC = BOOL(__stdcall*)(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
    using PFNWGLCREATEAFFINITYDCNVPROC = HDC(__stdcall*)(const HGPUNV* phGpuList);
    using PFNWGLENUMGPUSFROMAFFINITYDCNVPROC = BOOL(__stdcall*)(HDC hAffinityDC, UINT iGpuIndex, HGPUNV* hGpu);
    using PFNWGLDELETEDCNVPROC = BOOL(__stdcall*)(HDC hdc);
    PFNWGLENUMGPUSNVPROC wglEnumGpusNV = nullptr;
    PFNWGLENUMGPUDEVICESNVPROC wglEnumGpuDevicesNV = nullptr;
    PFNWGLCREATEAFFINITYDCNVPROC wglCreateAffinityDCNV = nullptr;
    PFNWGLENUMGPUSFROMAFFINITYDCNVPROC wglEnumGpusFromAffinityDCNV = nullptr;
    PFNWGLDELETEDCNVPROC wglDeleteDCNV = nullptr;

    // WGL_AMD_gpu_association
    using PFNWGLGETGPUIDSAMDPROC = UINT(__stdcall*)(UINT maxCount, UINT* ids);
    using PFNWGLGETGPUINFOAMDPROC = INT(__stdcall*)(UINT id, int property, GLenum dataType, UINT size, void* data);
    using PFNWGLGETCONTEXTGPUIDAMDPROC = UINT(__stdcall*)(HGLRC hglrc);
    using PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC = HGLRC(__stdcall*)(UINT id);
    using PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC = HGLRC(__stdcall*)(UINT id, HGLRC hShareContext, const int* attribList);
    using PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC = BOOL(__stdcall*)(HGLRC hglrc);
    using PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC = BOOL(__stdcall*)(HGLRC hglrc);
    using PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC = HGLRC(__stdcall*)(void);
    using PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC = VOID(__stdcall*)(HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
    PFNWGLGETGPUIDSAMDPROC wglGetGPUIDsAMD = nullptr;
    PFNWGLGETGPUINFOAMDPROC wglGetGPUInfoAMD = nullptr;
    PFNWGLGETCONTEXTGPUIDAMDPROC wglGetContextGPUIDAMD = nullptr;
    PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC wglCreateAssociatedContextAMD = nullptr;
    PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC wglCreateAssociatedContextAttribsAMD = nullptr;
    PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC wglDeleteAssociatedContextAMD = nullptr;
    PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC wglMakeAssociatedContextCurrentAMD = nullptr;
    PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC wglGetCurrentAssociatedContextAMD = nullptr;
    PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC wglBlitContextFramebufferAMD = nullptr;

    // WGL_I3D_swap_frame_lock
    using PFNWGLENABLEFRAMELOCKI3DPROC = BOOL(__stdcall*)(void);
    using PFNWGLDISABLEFRAMELOCKI3DPROC = BOOL(__stdcall*)(void);
    using PFNWGLISENABLEDFRAMELOCKI3DPROC = BOOL(__stdcall*)(BOOL* pFlag);
    using PFNWGLQUERYFRAMELOCKMASTERI3DPROC = BOOL(__stdcall*)(BOOL* pFlag);
    PFNWGLENABLEFRAMELOCKI3DPROC wglEnableFrameLockI3D = nullptr;
    PFNWGLDISABLEFRAMELOCKI3DPROC wglDisableFrameLockI3D = nullptr;
    PFNWGLISENABLEDFRAMELOCKI3DPROC wglIsEnabledFrameLockI3D = nullptr;
    PFNWGLQUERYFRAMELOCKMASTERI3DPROC wglQueryFrameLockMasterI3D = nullptr;

    // WGL_I3D_swap_frame_usage
    using PFNWGLGETFRAMEUSAGEI3DPROC = BOOL(__stdcall*)(float* pUsage);
    using PFNWGLBEGINFRAMETRACKINGI3DPROC = BOOL(__stdcall*)(void);
    using PFNWGLENDFRAMETRACKINGI3DPROC = BOOL(__stdcall*)(void);
    using PFNWGLQUERYFRAMETRACKINGI3DPROC = BOOL(__stdcall*)(DWORD* pFrameCount, DWORD* pMissedFrames, float* pLastMissedUsage);
    PFNWGLGETFRAMEUSAGEI3DPROC wglGetFrameUsageI3D = nullptr;
    PFNWGLBEGINFRAMETRACKINGI3DPROC wglBeginFrameTrackingI3D = nullptr;
    PFNWGLENDFRAMETRACKINGI3DPROC wglEndFrameTrackingI3D = nullptr;
    PFNWGLQUERYFRAMETRACKINGI3DPROC wglQueryFrameTrackingI3D = nullptr;

    // Loading Functions
    void load_WGL_BASE(GLADloadproc load) {
        wglSwapIntervalEXT = GLAD::gladLoadFunction<PFNWGLSWAPINTERVALEXTPROC>("wglSwapIntervalEXT", load);
        wglGetSwapIntervalEXT = GLAD::gladLoadFunction<PFNWGLGETSWAPINTERVALEXTPROC>("wglGetSwapIntervalEXT", load);
    }

    // Don't know why the following sub-categories can't load quite yet.
    void load_WGL_SwapBuffers(GLADloadproc load) {
        wglSwapBuffers = GLAD::gladLoadFunction<PFNWGLSWAPBUFFERSPROC>("wglSwapBuffers", load);
    }

    void load_WGL_PixelFormat(GLADloadproc load) {
        wglChoosePixelFormat = GLAD::gladLoadFunction<PFNWGLCHOOSEPIXELFORMATPROC>("wglChoosePixelFormat", load);
        wglGetPixelFormat = GLAD::gladLoadFunction<PFNWGLGETPIXELFORMATPROC>("wglGetPixelFormat", load);
        wglSetPixelFormat = GLAD::gladLoadFunction<PFNWGLSETPIXELFORMATPROC>("wglSetPixelFormat", load);
    }

    void load_WGL_ARB(GLADloadproc load) {
        wglGetExtensionsStringARB = GLAD::gladLoadFunction<PFNWGLGETEXTENSIONSSTRINGARBPROC>("wglGetExtensionsStringARB", load);
        wglChoosePixelFormatARB = GLAD::gladLoadFunction<PFNWGLCHOOSEPIXELFORMATARBPROC>("wglChoosePixelFormatARB", load);
        wglGetPixelFormatAttribivARB = GLAD::gladLoadFunction<PFNWGLGETPIXELFORMATATTRIBIVARBPROC>("wglGetPixelFormatAttribivARB", load);
        wglGetPixelFormatAttribfvARB = GLAD::gladLoadFunction<PFNWGLGETPIXELFORMATATTRIBFVARBPROC>("wglGetPixelFormatAttribfvARB", load);
        wglCreateContextAttribsARB = GLAD::gladLoadFunction<PFNWGLCREATECONTEXTATTRIBSARBPROC>("wglCreateContextAttribsARB", load);
        wglMakeContextCurrentARB = GLAD::gladLoadFunction<PFNWGLMAKECONTEXTCURRENTARBPROC>("wglMakeContextCurrentARB", load);
        wglGetCurrentReadDCARB = GLAD::gladLoadFunction<PFNWGLGETCURRENTREADDCARBPROC>("wglGetCurrentReadDCARB", load);
        wglCreatePbufferARB = GLAD::gladLoadFunction<PFNWGLCREATEPBUFFERARBPROC>("wglCreatePbufferARB", load);
        wglGetPbufferDCARB = GLAD::gladLoadFunction<PFNWGLGETPBUFFERDCARBPROC>("wglGetPbufferDCARB", load);
        wglReleasePbufferDCARB = GLAD::gladLoadFunction<PFNWGLRELEASEPBUFFERDCARBPROC>("wglReleasePbufferDCARB", load);
        wglDestroyPbufferARB = GLAD::gladLoadFunction<PFNWGLDESTROYPBUFFERARBPROC>("wglDestroyPbufferARB", load);
        wglQueryPbufferARB = GLAD::gladLoadFunction<PFNWGLQUERYPBUFFERARBPROC>("wglQueryPbufferARB", load);
        wglBindTexImageARB = GLAD::gladLoadFunction<PFNWGLBINDTEXIMAGEARBPROC>("wglBindTexImageARB", load);
        wglReleaseTexImageARB = GLAD::gladLoadFunction<PFNWGLRELEASETEXIMAGEARBPROC>("wglReleaseTexImageARB", load);
        wglSetPbufferAttribARB = GLAD::gladLoadFunction<PFNWGLSETPBUFFERATTRIBARBPROC>("wglSetPbufferAttribARB", load);
    }

    void load_WGL_EXT(GLADloadproc load) {
        wglGetExtensionsStringEXT = GLAD::gladLoadFunction<PFNWGLGETEXTENSIONSSTRINGEXTPROC>("wglGetExtensionsStringEXT", load);
        wglChoosePixelFormatEXT = GLAD::gladLoadFunction<PFNWGLCHOOSEPIXELFORMATEXTPROC>("wglChoosePixelFormatEXT", load);
        wglGetPixelFormatAttribivEXT = GLAD::gladLoadFunction<PFNWGLGETPIXELFORMATATTRIBIVEXTPROC>("wglGetPixelFormatAttribivEXT", load);
        wglGetPixelFormatAttribfvEXT = GLAD::gladLoadFunction<PFNWGLGETPIXELFORMATATTRIBFVEXTPROC>("wglGetPixelFormatAttribfvEXT", load);
        wglCreatePbufferEXT = GLAD::gladLoadFunction<PFNWGLCREATEPBUFFEREXTPROC>("wglCreatePbufferEXT", load);
        wglGetPbufferDCEXT = GLAD::gladLoadFunction<PFNWGLGETPBUFFERDCEXTPROC>("wglGetPbufferDCEXT", load);
        wglReleasePbufferDCEXT = GLAD::gladLoadFunction<PFNWGLRELEASEPBUFFERDCEXTPROC>("wglReleasePbufferDCEXT", load);
        wglDestroyPbufferEXT = GLAD::gladLoadFunction<PFNWGLDESTROYPBUFFEREXTPROC>("wglDestroyPbufferEXT", load);
        wglQueryPbufferEXT = GLAD::gladLoadFunction<PFNWGLQUERYPBUFFEREXTPROC>("wglQueryPbufferEXT", load);
        wglChoosePixelFormatEXT = GLAD::gladLoadFunction<PFNWGLCHOOSEPIXELFORMATEXTPROC>("wglChoosePixelFormatEXT", load);
        wglGetPixelFormatAttribivEXT = GLAD::gladLoadFunction<PFNWGLGETPIXELFORMATATTRIBIVEXTPROC>("wglGetPixelFormatAttribivEXT", load);
        wglGetPixelFormatAttribfvEXT = GLAD::gladLoadFunction<PFNWGLGETPIXELFORMATATTRIBFVEXTPROC>("wglGetPixelFormatAttribfvEXT", load);
    }

    void load_WGL_NV(GLADloadproc load) {
        wglJoinSwapGroupNV = GLAD::gladLoadFunction<PFNWGLJOINSWAPGROUPNVPROC>("wglJoinSwapGroupNV", load);
        wglBindSwapBarrierNV = GLAD::gladLoadFunction<PFNWGLBINDSWAPBARRIERNVPROC>("wglBindSwapBarrierNV", load);
        wglQuerySwapGroupNV = GLAD::gladLoadFunction<PFNWGLQUERYSWAPGROUPNVPROC>("wglQuerySwapGroupNV", load);
        wglQueryMaxSwapGroupsNV = GLAD::gladLoadFunction<PFNWGLQUERYMAXSWAPGROUPSNVPROC>("wglQueryMaxSwapGroupsNV", load);
        wglQueryFrameCountNV = GLAD::gladLoadFunction<PFNWGLQUERYFRAMECOUNTNVPROC>("wglQueryFrameCountNV", load);
        wglResetFrameCountNV = GLAD::gladLoadFunction<PFNWGLRESETFRAMECOUNTNVPROC>("wglResetFrameCountNV", load);
        wglEnumGpusNV = GLAD::gladLoadFunction<PFNWGLENUMGPUSNVPROC>("wglEnumGpusNV", load);
        wglEnumGpuDevicesNV = GLAD::gladLoadFunction<PFNWGLENUMGPUDEVICESNVPROC>("wglEnumGpuDevicesNV", load);
        wglCreateAffinityDCNV = GLAD::gladLoadFunction<PFNWGLCREATEAFFINITYDCNVPROC>("wglCreateAffinityDCNV", load);
        wglEnumGpusFromAffinityDCNV = GLAD::gladLoadFunction<PFNWGLENUMGPUSFROMAFFINITYDCNVPROC>("wglEnumGpusFromAffinityDCNV", load);
        wglDeleteDCNV = GLAD::gladLoadFunction<PFNWGLDELETEDCNVPROC>("wglDeleteDCNV", load);
    }

    void load_WGL_AMD(GLADloadproc load) {
        wglGetGPUIDsAMD = GLAD::gladLoadFunction<PFNWGLGETGPUIDSAMDPROC>("wglGetGPUIDsAMD", load);
        wglGetGPUInfoAMD = GLAD::gladLoadFunction<PFNWGLGETGPUINFOAMDPROC>("wglGetGPUInfoAMD", load);
        wglGetContextGPUIDAMD = GLAD::gladLoadFunction<PFNWGLGETCONTEXTGPUIDAMDPROC>("wglGetContextGPUIDAMD", load);
        wglCreateAssociatedContextAMD = GLAD::gladLoadFunction<PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC>("wglCreateAssociatedContextAMD", load);
        wglCreateAssociatedContextAttribsAMD = GLAD::gladLoadFunction<PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC>("wglCreateAssociatedContextAttribsAMD", load);
        wglDeleteAssociatedContextAMD = GLAD::gladLoadFunction<PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC>("wglDeleteAssociatedContextAMD", load);
        wglMakeAssociatedContextCurrentAMD = GLAD::gladLoadFunction<PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC>("wglMakeAssociatedContextCurrentAMD", load);
        wglGetCurrentAssociatedContextAMD = GLAD::gladLoadFunction<PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC>("wglGetCurrentAssociatedContextAMD", load);
        wglBlitContextFramebufferAMD = GLAD::gladLoadFunction<PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC>("wglBlitContextFramebufferAMD", load);
    }

    void load_WGL_I3D(GLADloadproc load) {
        wglEnableFrameLockI3D = GLAD::gladLoadFunction<PFNWGLENABLEFRAMELOCKI3DPROC>("wglEnableFrameLockI3D", load);
        wglDisableFrameLockI3D = GLAD::gladLoadFunction<PFNWGLDISABLEFRAMELOCKI3DPROC>("wglDisableFrameLockI3D", load);
        wglIsEnabledFrameLockI3D = GLAD::gladLoadFunction<PFNWGLISENABLEDFRAMELOCKI3DPROC>("wglIsEnabledFrameLockI3D", load);
        wglQueryFrameLockMasterI3D = GLAD::gladLoadFunction<PFNWGLQUERYFRAMELOCKMASTERI3DPROC>("wglQueryFrameLockMasterI3D", load);
        wglGetFrameUsageI3D = GLAD::gladLoadFunction<PFNWGLGETFRAMEUSAGEI3DPROC>("wglGetFrameUsageI3D", load);
        wglBeginFrameTrackingI3D = GLAD::gladLoadFunction<PFNWGLBEGINFRAMETRACKINGI3DPROC>("wglBeginFrameTrackingI3D", load);
        wglEndFrameTrackingI3D = GLAD::gladLoadFunction<PFNWGLENDFRAMETRACKINGI3DPROC>("wglEndFrameTrackingI3D", load);
        wglQueryFrameTrackingI3D = GLAD::gladLoadFunction<PFNWGLQUERYFRAMETRACKINGI3DPROC>("wglQueryFrameTrackingI3D", load);
    }

    void load_WGL(GLADloadproc load) {
        load_WGL_BASE(load);
        load_WGL_ARB(load);
        load_WGL_EXT(load);
        load_WGL_NV(load);
        load_WGL_AMD(load);
        load_WGL_I3D(load);
    }
}