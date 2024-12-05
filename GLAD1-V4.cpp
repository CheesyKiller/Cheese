import GLADBase;
import GLAD1;

namespace GLAD::V1_4 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glBlendFuncSeparate = GLAD::gladLoadFunction<PFNGLBLENDFUNCSEPARATEPROC>("glBlendFuncSeparate", load);
		glMultiDrawArrays = GLAD::gladLoadFunction<PFNGLMULTIDRAWARRAYSPROC>("glMultiDrawArrays", load);
		glMultiDrawElements = GLAD::gladLoadFunction<PFNGLMULTIDRAWELEMENTSPROC>("glMultiDrawElements", load);
		glPointParameterf = GLAD::gladLoadFunction<PFNGLPOINTPARAMETERFPROC>("glPointParameterf", load);
		glPointParameterfv = GLAD::gladLoadFunction<PFNGLPOINTPARAMETERFVPROC>("glPointParameterfv", load);
		glPointParameteri = GLAD::gladLoadFunction<PFNGLPOINTPARAMETERIPROC>("glPointParameteri", load);
		glPointParameteriv = GLAD::gladLoadFunction<PFNGLPOINTPARAMETERIVPROC>("glPointParameteriv", load);
		glBlendColor = GLAD::gladLoadFunction<PFNGLBLENDCOLORPROC>("glBlendColor", load);
		glBlendEquation = GLAD::gladLoadFunction <PFNGLBLENDEQUATIONPROC>("glBlendEquation", load);

		GLAD::V1_3::load_GL_RECURSIVE(load);
	}
}