export module GLAD1:V4;

import GLADBase;
import :A4;

export namespace GLAD {
	// Declare function pointers as variables
	PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate = nullptr;
	PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays = nullptr;
	PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements = nullptr;
	PFNGLPOINTPARAMETERFPROC glPointParameterf = nullptr;
	PFNGLPOINTPARAMETERFVPROC glPointParameterfv = nullptr;
	PFNGLPOINTPARAMETERIPROC glPointParameteri = nullptr;
	PFNGLPOINTPARAMETERIVPROC glPointParameteriv = nullptr;
	PFNGLBLENDCOLORPROC glBlendColor = nullptr;
	PFNGLBLENDEQUATIONPROC glBlendEquation = nullptr;

	namespace V1_4 {
		void load_GL_RECURSIVE(GLADloadproc load);
	}
}