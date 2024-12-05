module;

#include <Windows.h>

export module GLADWGL:AWGL;

import GLADTypes;
import :Types;

export namespace GLAD {
    // WGL_VERSION_BASE
    using PFNWGLCHOOSEPIXELFORMATPROC = int(__stdcall*)(HDC hdc, const PIXELFORMATDESCRIPTOR* ppfd);
    using PFNWGLGETPIXELFORMATPROC = int(__stdcall*)(HDC hdc);
    using PFNWGLSETPIXELFORMATPROC = BOOL(__stdcall*)(HDC hdc, int format, const PIXELFORMATDESCRIPTOR* ppfd);
    using PFNWGLSWAPBUFFERSPROC = BOOL(__stdcall*)(HDC hdc);
    using PFNWGLSWAPINTERVALEXTPROC = BOOL(__stdcall*)(int interval);
    using PFNWGLGETSWAPINTERVALEXTPROC = int(__stdcall*)(void);

    // WGL_ARB_extensions_string
    using PFNWGLGETEXTENSIONSSTRINGARBPROC = const char* (__stdcall*)(HDC hdc);

    // WGL_EXT_extensions_string
    using PFNWGLGETEXTENSIONSSTRINGEXTPROC = const char* (__stdcall*)(void);

    // WGL_ARB_pixel_format
    using PFNWGLCHOOSEPIXELFORMATARBPROC = BOOL(__stdcall*)(HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats);
    using PFNWGLGETPIXELFORMATATTRIBIVARBPROC = BOOL(__stdcall*)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, int* piValues);
    using PFNWGLGETPIXELFORMATATTRIBFVARBPROC = BOOL(__stdcall*)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, FLOAT* pfValues);

    // WGL_ARB_create_context
    using PFNWGLCREATECONTEXTATTRIBSARBPROC = HGLRC(__stdcall*)(HDC hDC, HGLRC hShareContext, const int* attribList);

    // WGL_ARB_make_current_read
    using PFNWGLMAKECONTEXTCURRENTARBPROC = BOOL(__stdcall*)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
    using PFNWGLGETCURRENTREADDCARBPROC = HDC(__stdcall*)(void);

    // WGL_ARB_pbuffer
    using PFNWGLCREATEPBUFFERARBPROC = HPBUFFERARB(__stdcall*)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList);
    using PFNWGLGETPBUFFERDCARBPROC = HDC(__stdcall*)(HPBUFFERARB hPbuffer);
    using PFNWGLRELEASEPBUFFERDCARBPROC = int(__stdcall*)(HPBUFFERARB hPbuffer, HDC hDC);
    using PFNWGLDESTROYPBUFFERARBPROC = BOOL(__stdcall*)(HPBUFFERARB hPbuffer);
    using PFNWGLQUERYPBUFFERARBPROC = BOOL(__stdcall*)(HPBUFFERARB hPbuffer, int iAttribute, int* piValue);

    // WGL_ARB_render_texture
    using PFNWGLBINDTEXIMAGEARBPROC = BOOL(__stdcall*)(HPBUFFERARB hPbuffer, int iBuffer);
    using PFNWGLRELEASETEXIMAGEARBPROC = BOOL(__stdcall*)(HPBUFFERARB hPbuffer, int iBuffer);
    using PFNWGLSETPBUFFERATTRIBARBPROC = BOOL(__stdcall*)(HPBUFFERARB hPbuffer, const int* piAttribList);

    // WGL_EXT_framebuffer_sRGB
    // No functions, only pixel format attributes.

    // WGL_ARB_framebuffer_sRGB
    // No functions, only pixel format attributes.

    // WGL_EXT_make_current_read
    using PFNWGLMAKECONTEXTCURRENTEXTPROC = BOOL(__stdcall*)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
    using PFNWGLGETCURRENTREADDCEXTPROC = HDC(__stdcall*)(void);

    // WGL_EXT_pbuffer
    using PFNWGLCREATEPBUFFEREXTPROC = HPBUFFEREXT(__stdcall*)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList);
    using PFNWGLGETPBUFFERDCEXTPROC = HDC(__stdcall*)(HPBUFFEREXT hPbuffer);
    using PFNWGLRELEASEPBUFFERDCEXTPROC = int(__stdcall*)(HPBUFFEREXT hPbuffer, HDC hDC);
    using PFNWGLDESTROYPBUFFEREXTPROC = BOOL(__stdcall*)(HPBUFFEREXT hPbuffer);
    using PFNWGLQUERYPBUFFEREXTPROC = BOOL(__stdcall*)(HPBUFFEREXT hPbuffer, int iAttribute, int* piValue);

    // WGL_EXT_pixel_format
    using PFNWGLCHOOSEPIXELFORMATEXTPROC = BOOL(__stdcall*)(HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats);
    using PFNWGLGETPIXELFORMATATTRIBIVEXTPROC = BOOL(__stdcall*)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, int* piValues);
    using PFNWGLGETPIXELFORMATATTRIBFVEXTPROC = BOOL(__stdcall*)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, FLOAT* pfValues);

    // WGL_EXT_depth_float
    // No functions, only pixel format attributes.

    // WGL_NV_swap_group
    using PFNWGLJOINSWAPGROUPNVPROC = BOOL(__stdcall*)(HDC hDC, GLuint group);
    using PFNWGLBINDSWAPBARRIERNVPROC = BOOL(__stdcall*)(GLuint group, GLuint barrier);
    using PFNWGLQUERYSWAPGROUPNVPROC = BOOL(__stdcall*)(HDC hDC, GLuint* group, GLuint* barrier);
    using PFNWGLQUERYMAXSWAPGROUPSNVPROC = BOOL(__stdcall*)(HDC hDC, GLuint* maxGroups, GLuint* maxBarriers);
    using PFNWGLQUERYFRAMECOUNTNVPROC = BOOL(__stdcall*)(HDC hDC, GLuint* count);
    using PFNWGLRESETFRAMECOUNTNVPROC = BOOL(__stdcall*)(HDC hDC);

    // WGL_NV_gpu_affinity
    using PFNWGLENUMGPUSNVPROC = BOOL(__stdcall*)(UINT iGpuIndex, HGPUNV* phGpu);
    using PFNWGLENUMGPUDEVICESNVPROC = BOOL(__stdcall*)(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
    using PFNWGLCREATEAFFINITYDCNVPROC = HDC(__stdcall*)(const HGPUNV* phGpuList);
    using PFNWGLENUMGPUSFROMAFFINITYDCNVPROC = BOOL(__stdcall*)(HDC hAffinityDC, UINT iGpuIndex, HGPUNV* hGpu);
    using PFNWGLDELETEDCNVPROC = BOOL(__stdcall*)(HDC hdc);

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

    // WGL_I3D_swap_frame_lock
    using PFNWGLENABLEFRAMELOCKI3DPROC = BOOL(__stdcall*)(void);
    using PFNWGLDISABLEFRAMELOCKI3DPROC = BOOL(__stdcall*)(void);
    using PFNWGLISENABLEDFRAMELOCKI3DPROC = BOOL(__stdcall*)(BOOL* pFlag);
    using PFNWGLQUERYFRAMELOCKMASTERI3DPROC = BOOL(__stdcall*)(BOOL* pFlag);

    // WGL_I3D_swap_frame_usage
    using PFNWGLGETFRAMEUSAGEI3DPROC = BOOL(__stdcall*)(float* pUsage);
    using PFNWGLBEGINFRAMETRACKINGI3DPROC = BOOL(__stdcall*)(void);
    using PFNWGLENDFRAMETRACKINGI3DPROC = BOOL(__stdcall*)(void);
    using PFNWGLQUERYFRAMETRACKINGI3DPROC = BOOL(__stdcall*)(DWORD* pFrameCount, DWORD* pMissedFrames, float* pLastMissedUsage);
}