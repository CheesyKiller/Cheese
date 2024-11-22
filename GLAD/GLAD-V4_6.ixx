export module GLAD:V4_6;

export import :V4_5;

export namespace GLAD {
	using PFNGLSPECIALIZESHADERPROC = void (*)(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue);
	using PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC = void (*)(GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
	using PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC = void (*)(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
	using PFNGLPOLYGONOFFSETCLAMPPROC = void (*)(GLfloat factor, GLfloat units, GLfloat clamp);

	PFNGLSPECIALIZESHADERPROC glSpecializeShader = nullptr;
	PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount = nullptr;
	PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount = nullptr;
	PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp = nullptr;

	namespace GLAD_4_6 {
		void load_GL_RECURSIVE(GLADloadproc load) {
			glSpecializeShader = GLAD::gladLoadFunction<PFNGLSPECIALIZESHADERPROC>("glSpecializeShader", load);
			glMultiDrawArraysIndirectCount = GLAD::gladLoadFunction<PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC>("glMultiDrawArraysIndirectCount", load);
			glMultiDrawElementsIndirectCount = GLAD::gladLoadFunction<PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC>("glMultiDrawElementsIndirectCount", load);
			glPolygonOffsetClamp = GLAD::gladLoadFunction<PFNGLPOLYGONOFFSETCLAMPPROC>("glPolygonOffsetClamp", load);

			GLAD::GLAD_4_5::load_GL_RECURSIVE(load);
		}
	}
}