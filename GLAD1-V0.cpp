import GLADBase;
import GLAD1;

namespace GLAD::V1_0 {
	void load_GL_RECURSIVE(GLAD::GLADloadproc load) {
		glCullFace = GLAD::gladLoadCoreFunction<PFNGLCULLFACEPROC>("glCullFace", "opengl32.dll");
		glFrontFace = GLAD::gladLoadCoreFunction<PFNGLFRONTFACEPROC>("glFrontFace", "opengl32.dll");
		glHint = GLAD::gladLoadCoreFunction<PFNGLHINTPROC>("glHint", "opengl32.dll");
		glLineWidth = GLAD::gladLoadCoreFunction<PFNGLLINEWIDTHPROC>("glLineWidth", "opengl32.dll");
		glPointSize = GLAD::gladLoadCoreFunction<PFNGLPOINTSIZEPROC>("glPointSize", "opengl32.dll");
		glPolygonMode = GLAD::gladLoadCoreFunction<PFNGLPOLYGONMODEPROC>("glPolygonMode", "opengl32.dll");
		glScissor = GLAD::gladLoadCoreFunction<PFNGLSCISSORPROC>("glScissor", "opengl32.dll");
		glTexParameterf = GLAD::gladLoadCoreFunction<PFNGLTEXPARAMETERFPROC>("glTexParameterf", "opengl32.dll");
		glTexParameterfv = GLAD::gladLoadCoreFunction<PFNGLTEXPARAMETERFVPROC>("glTexParameterfv", "opengl32.dll");
		glTexParameteri = GLAD::gladLoadCoreFunction<PFNGLTEXPARAMETERIPROC>("glTexParameteri", "opengl32.dll");
		glTexParameteriv = GLAD::gladLoadCoreFunction<PFNGLTEXPARAMETERIVPROC>("glTexParameteriv", "opengl32.dll");
		glTexImage1D = GLAD::gladLoadCoreFunction<PFNGLTEXIMAGE1DPROC>("glTexImage1D", "opengl32.dll");
		glTexImage2D = GLAD::gladLoadCoreFunction<PFNGLTEXIMAGE2DPROC>("glTexImage2D", "opengl32.dll");
		glDrawBuffer = GLAD::gladLoadCoreFunction<PFNGLDRAWBUFFERPROC>("glDrawBuffer", "opengl32.dll");
		glClear = GLAD::gladLoadCoreFunction<PFNGLCLEARPROC>("glClear", "opengl32.dll");
		glClearColor = GLAD::gladLoadCoreFunction<PFNGLCLEARCOLORPROC>("glClearColor", "opengl32.dll");
		glClearStencil = GLAD::gladLoadCoreFunction<PFNGLCLEARSTENCILPROC>("glClearStencil", "opengl32.dll");
		glClearDepth = GLAD::gladLoadCoreFunction<PFNGLCLEARDEPTHPROC>("glClearDepth", "opengl32.dll");
		glStencilMask = GLAD::gladLoadCoreFunction<PFNGLSTENCILMASKPROC>("glStencilMask", "opengl32.dll");
		glColorMask = GLAD::gladLoadCoreFunction<PFNGLCOLORMASKPROC>("glColorMask", "opengl32.dll");
		glDepthMask = GLAD::gladLoadCoreFunction<PFNGLDEPTHMASKPROC>("glDepthMask", "opengl32.dll");
		glDisable = GLAD::gladLoadCoreFunction<PFNGLDISABLEPROC>("glDisable", "opengl32.dll");
		glEnable = GLAD::gladLoadCoreFunction<PFNGLENABLEPROC>("glEnable", "opengl32.dll");
		glFinish = GLAD::gladLoadCoreFunction<PFNGLFINISHPROC>("glFinish", "opengl32.dll");
		glFlush = GLAD::gladLoadCoreFunction<PFNGLFLUSHPROC>("glFlush", "opengl32.dll");
		glBlendFunc = GLAD::gladLoadCoreFunction<PFNGLBLENDFUNCPROC>("glBlendFunc", "opengl32.dll");
		glLogicOp = GLAD::gladLoadCoreFunction<PFNGLLOGICOPPROC>("glLogicOp", "opengl32.dll");
		glStencilFunc = GLAD::gladLoadCoreFunction<PFNGLSTENCILFUNCPROC>("glStencilFunc", "opengl32.dll");
		glStencilOp = GLAD::gladLoadCoreFunction<PFNGLSTENCILOPPROC>("glStencilOp", "opengl32.dll");
		glDepthFunc = GLAD::gladLoadCoreFunction<PFNGLDEPTHFUNCPROC>("glDepthFunc", "opengl32.dll");
		glPixelStoref = GLAD::gladLoadCoreFunction<PFNGLPIXELSTOREFPROC>("glPixelStoref", "opengl32.dll");
		glPixelStorei = GLAD::gladLoadCoreFunction<PFNGLPIXELSTOREIPROC>("glPixelStorei", "opengl32.dll");
		glReadBuffer = GLAD::gladLoadCoreFunction<PFNGLREADBUFFERPROC>("glReadBuffer", "opengl32.dll");
		glReadPixels = GLAD::gladLoadCoreFunction<PFNGLREADPIXELSPROC>("glReadPixels", "opengl32.dll");
		glGetBooleanv = GLAD::gladLoadCoreFunction<PFNGLGETBOOLEANVPROC>("glGetBooleanv", "opengl32.dll");
		glGetDoublev = GLAD::gladLoadCoreFunction<PFNGLGETDOUBLEVPROC>("glGetDoublev", "opengl32.dll");
		glGetError = GLAD::gladLoadCoreFunction<PFNGLGETERRORPROC>("glGetError", "opengl32.dll");
		glGetFloatv = GLAD::gladLoadCoreFunction<PFNGLGETFLOATVPROC>("glGetFloatv", "opengl32.dll");
		glGetIntegerv = GLAD::gladLoadCoreFunction<PFNGLGETINTEGERVPROC>("glGetIntegerv", "opengl32.dll");
		glGetString = GLAD::gladLoadCoreFunction<PFNGLGETSTRINGPROC>("glGetString", "opengl32.dll");
		glGetTexImage = GLAD::gladLoadCoreFunction<PFNGLGETTEXIMAGEPROC>("glGetTexImage", "opengl32.dll");
		glGetTexParameterfv = GLAD::gladLoadCoreFunction<PFNGLGETTEXPARAMETERFVPROC>("glGetTexParameterfv", "opengl32.dll");
		glGetTexParameteriv = GLAD::gladLoadCoreFunction<PFNGLGETTEXPARAMETERIVPROC>("glGetTexParameteriv", "opengl32.dll");
		glGetTexLevelParameterfv = GLAD::gladLoadCoreFunction<PFNGLGETTEXLEVELPARAMETERFVPROC>("glGetTexLevelParameterfv", "opengl32.dll");
		glGetTexLevelParameteriv = GLAD::gladLoadCoreFunction<PFNGLGETTEXLEVELPARAMETERIVPROC>("glGetTexLevelParameteriv", "opengl32.dll");
		glIsEnabled = GLAD::gladLoadCoreFunction<PFNGLISENABLEDPROC>("glIsEnabled", "opengl32.dll");
		glDepthRange = GLAD::gladLoadCoreFunction<PFNGLDEPTHRANGEPROC>("glDepthRange", "opengl32.dll");
		glViewport = GLAD::gladLoadCoreFunction<PFNGLVIEWPORTPROC>("glViewport", "opengl32.dll");
	}
}