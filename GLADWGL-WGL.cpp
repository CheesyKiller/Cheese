import GLADBase;
import GLADWGL;

namespace GLAD {
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