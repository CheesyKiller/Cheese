export module GLAD4:V6;

import GLADBase;
import :A6;

export namespace GLAD {
	PFNGLSPECIALIZESHADERPROC glSpecializeShader = nullptr;
	PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount = nullptr;
	PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount = nullptr;
	PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp = nullptr;

	namespace V4_6 {
		void load_GL_RECURSIVE(GLADloadproc load);
	}
}