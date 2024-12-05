import GLADBase;
import GLAD4;

namespace GLAD::V4_6 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glSpecializeShader = GLAD::gladLoadFunction<PFNGLSPECIALIZESHADERPROC>("glSpecializeShader", load);
		glMultiDrawArraysIndirectCount = GLAD::gladLoadFunction<PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC>("glMultiDrawArraysIndirectCount", load);
		glMultiDrawElementsIndirectCount = GLAD::gladLoadFunction<PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC>("glMultiDrawElementsIndirectCount", load);
		glPolygonOffsetClamp = GLAD::gladLoadFunction<PFNGLPOLYGONOFFSETCLAMPPROC>("glPolygonOffsetClamp", load);

		GLAD::V4_5::load_GL_RECURSIVE(load);
	}
}