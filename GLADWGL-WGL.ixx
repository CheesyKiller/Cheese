module;

#include <Windows.h>

export module GLADWGL:WGL;

import GLADBase;
import :AWGL;
import :Types;

export namespace GLAD {
    // WGL_VERSION_BASE
    PFNWGLCHOOSEPIXELFORMATPROC wglChoosePixelFormat = nullptr;
    PFNWGLGETPIXELFORMATPROC wglGetPixelFormat = nullptr;
    PFNWGLSETPIXELFORMATPROC wglSetPixelFormat = nullptr;
    PFNWGLSWAPBUFFERSPROC wglSwapBuffers = nullptr;
    PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = nullptr;
    PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT = nullptr;

    // WGL_ARB_extensions_string
    PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB = nullptr;

    // WGL_EXT_extensions_string
    PFNWGLGETEXTENSIONSSTRINGEXTPROC wglGetExtensionsStringEXT = nullptr;

    // WGL_ARB_pixel_format
    PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
    PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribivARB = nullptr;
    PFNWGLGETPIXELFORMATATTRIBFVARBPROC wglGetPixelFormatAttribfvARB = nullptr;

    // WGL_ARB_create_context
    PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;

    // WGL_ARB_make_current_read
    PFNWGLMAKECONTEXTCURRENTARBPROC wglMakeContextCurrentARB = nullptr;
    PFNWGLGETCURRENTREADDCARBPROC wglGetCurrentReadDCARB = nullptr;

    // WGL_ARB_pbuffer
    PFNWGLCREATEPBUFFERARBPROC wglCreatePbufferARB = nullptr;
    PFNWGLGETPBUFFERDCARBPROC wglGetPbufferDCARB = nullptr;
    PFNWGLRELEASEPBUFFERDCARBPROC wglReleasePbufferDCARB = nullptr;
    PFNWGLDESTROYPBUFFERARBPROC wglDestroyPbufferARB = nullptr;
    PFNWGLQUERYPBUFFERARBPROC wglQueryPbufferARB = nullptr;

    // WGL_ARB_render_texture
    PFNWGLBINDTEXIMAGEARBPROC wglBindTexImageARB = nullptr;
    PFNWGLRELEASETEXIMAGEARBPROC wglReleaseTexImageARB = nullptr;
    PFNWGLSETPBUFFERATTRIBARBPROC wglSetPbufferAttribARB = nullptr;

    // WGL_EXT_framebuffer_sRGB
    // No functions, only pixel format attributes.

    // WGL_ARB_framebuffer_sRGB
    // No functions, only pixel format attributes.

    // WGL_EXT_make_current_read
    PFNWGLMAKECONTEXTCURRENTEXTPROC wglMakeContextCurrentEXT = nullptr;
    PFNWGLGETCURRENTREADDCEXTPROC wglGetCurrentReadDCEXT = nullptr;

    // WGL_EXT_pbuffer
    PFNWGLCREATEPBUFFEREXTPROC wglCreatePbufferEXT = nullptr;
    PFNWGLGETPBUFFERDCEXTPROC wglGetPbufferDCEXT = nullptr;
    PFNWGLRELEASEPBUFFERDCEXTPROC wglReleasePbufferDCEXT = nullptr;
    PFNWGLDESTROYPBUFFEREXTPROC wglDestroyPbufferEXT = nullptr;
    PFNWGLQUERYPBUFFEREXTPROC wglQueryPbufferEXT = nullptr;

    // WGL_EXT_pixel_format
    PFNWGLCHOOSEPIXELFORMATEXTPROC wglChoosePixelFormatEXT = nullptr;
    PFNWGLGETPIXELFORMATATTRIBIVEXTPROC wglGetPixelFormatAttribivEXT = nullptr;
    PFNWGLGETPIXELFORMATATTRIBFVEXTPROC wglGetPixelFormatAttribfvEXT = nullptr;

    // WGL_EXT_depth_float
    // No functions, only pixel format attributes.

    // WGL_NV_swap_group
    PFNWGLJOINSWAPGROUPNVPROC wglJoinSwapGroupNV = nullptr;
    PFNWGLBINDSWAPBARRIERNVPROC wglBindSwapBarrierNV = nullptr;
    PFNWGLQUERYSWAPGROUPNVPROC wglQuerySwapGroupNV = nullptr;
    PFNWGLQUERYMAXSWAPGROUPSNVPROC wglQueryMaxSwapGroupsNV = nullptr;
    PFNWGLQUERYFRAMECOUNTNVPROC wglQueryFrameCountNV = nullptr;
    PFNWGLRESETFRAMECOUNTNVPROC wglResetFrameCountNV = nullptr;

    // WGL_NV_gpu_affinity
    PFNWGLENUMGPUSNVPROC wglEnumGpusNV = nullptr;
    PFNWGLENUMGPUDEVICESNVPROC wglEnumGpuDevicesNV = nullptr;
    PFNWGLCREATEAFFINITYDCNVPROC wglCreateAffinityDCNV = nullptr;
    PFNWGLENUMGPUSFROMAFFINITYDCNVPROC wglEnumGpusFromAffinityDCNV = nullptr;
    PFNWGLDELETEDCNVPROC wglDeleteDCNV = nullptr;

    // WGL_AMD_gpu_association
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
    PFNWGLENABLEFRAMELOCKI3DPROC wglEnableFrameLockI3D = nullptr;
    PFNWGLDISABLEFRAMELOCKI3DPROC wglDisableFrameLockI3D = nullptr;
    PFNWGLISENABLEDFRAMELOCKI3DPROC wglIsEnabledFrameLockI3D = nullptr;
    PFNWGLQUERYFRAMELOCKMASTERI3DPROC wglQueryFrameLockMasterI3D = nullptr;

    // WGL_I3D_swap_frame_usage
    PFNWGLGETFRAMEUSAGEI3DPROC wglGetFrameUsageI3D = nullptr;
    PFNWGLBEGINFRAMETRACKINGI3DPROC wglBeginFrameTrackingI3D = nullptr;
    PFNWGLENDFRAMETRACKINGI3DPROC wglEndFrameTrackingI3D = nullptr;
    PFNWGLQUERYFRAMETRACKINGI3DPROC wglQueryFrameTrackingI3D = nullptr;

    // Loading Functions
    void load_WGL_BASE(GLADloadproc load);

    // Don't know why the following sub-categories can't load quite yet.
    void load_WGL_SwapBuffers(GLADloadproc load);

    void load_WGL_PixelFormat(GLADloadproc load);

    void load_WGL_ARB(GLADloadproc load);

    void load_WGL_EXT(GLADloadproc load);

    void load_WGL_NV(GLADloadproc load);

    void load_WGL_AMD(GLADloadproc load);

    void load_WGL_I3D(GLADloadproc load);

    void load_WGL(GLADloadproc load);
}