export module GLAD1:V0;

import GLADBase;
import :A0;

export namespace GLAD {
	// Declare function pointers as variables
	PFNGLCULLFACEPROC glCullFace = nullptr;
	PFNGLFRONTFACEPROC glFrontFace = nullptr;
	PFNGLHINTPROC glHint = nullptr;
	PFNGLLINEWIDTHPROC glLineWidth = nullptr;
	PFNGLPOINTSIZEPROC glPointSize = nullptr;
	PFNGLPOLYGONMODEPROC glPolygonMode = nullptr;
	PFNGLSCISSORPROC glScissor = nullptr;
	PFNGLTEXPARAMETERFPROC glTexParameterf = nullptr;
	PFNGLTEXPARAMETERFVPROC glTexParameterfv = nullptr;
	PFNGLTEXPARAMETERIPROC glTexParameteri = nullptr;
	PFNGLTEXPARAMETERIVPROC glTexParameteriv = nullptr;
	PFNGLTEXIMAGE1DPROC glTexImage1D = nullptr;
	PFNGLTEXIMAGE2DPROC glTexImage2D = nullptr;
	PFNGLDRAWBUFFERPROC glDrawBuffer = nullptr;
	PFNGLCLEARPROC glClear = nullptr;
	PFNGLCLEARCOLORPROC glClearColor = nullptr;
	PFNGLCLEARSTENCILPROC glClearStencil = nullptr;
	PFNGLCLEARDEPTHPROC glClearDepth = nullptr;
	PFNGLSTENCILMASKPROC glStencilMask = nullptr;
	PFNGLCOLORMASKPROC glColorMask = nullptr;
	PFNGLDEPTHMASKPROC glDepthMask = nullptr;
	PFNGLDISABLEPROC glDisable = nullptr;
	PFNGLENABLEPROC glEnable = nullptr;
	PFNGLFINISHPROC glFinish = nullptr;
	PFNGLFLUSHPROC glFlush = nullptr;
	PFNGLBLENDFUNCPROC glBlendFunc = nullptr;
	PFNGLLOGICOPPROC glLogicOp = nullptr;
	PFNGLSTENCILFUNCPROC glStencilFunc = nullptr;
	PFNGLSTENCILOPPROC glStencilOp = nullptr;
	PFNGLDEPTHFUNCPROC glDepthFunc = nullptr;
	PFNGLPIXELSTOREFPROC glPixelStoref = nullptr;
	PFNGLPIXELSTOREIPROC glPixelStorei = nullptr;
	PFNGLREADBUFFERPROC glReadBuffer = nullptr;
	PFNGLREADPIXELSPROC glReadPixels = nullptr;
	PFNGLGETBOOLEANVPROC glGetBooleanv = nullptr;
	PFNGLGETDOUBLEVPROC glGetDoublev = nullptr;
	PFNGLGETERRORPROC glGetError = nullptr;
	PFNGLGETFLOATVPROC glGetFloatv = nullptr;
	PFNGLGETINTEGERVPROC glGetIntegerv = nullptr;
	PFNGLGETSTRINGPROC glGetString = nullptr;
	PFNGLGETTEXIMAGEPROC glGetTexImage = nullptr;
	PFNGLGETTEXPARAMETERFVPROC glGetTexParameterfv = nullptr;
	PFNGLGETTEXPARAMETERIVPROC glGetTexParameteriv = nullptr;
	PFNGLGETTEXLEVELPARAMETERFVPROC glGetTexLevelParameterfv = nullptr;
	PFNGLGETTEXLEVELPARAMETERIVPROC glGetTexLevelParameteriv = nullptr;
	PFNGLISENABLEDPROC glIsEnabled = nullptr;
	PFNGLDEPTHRANGEPROC glDepthRange = nullptr;
	PFNGLVIEWPORTPROC glViewport = nullptr;

	namespace V1_0 {
		void load_GL_RECURSIVE(GLADloadproc load);
	}
}