export module GLAD:V4_6;

export import :V4_5;

export using PFNGLSPECIALIZESHADERPROC = void (*)(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue);
export using PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC = void (*)(GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
export using PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC = void (*)(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
export using PFNGLPOLYGONOFFSETCLAMPPROC = void (*)(GLfloat factor, GLfloat units, GLfloat clamp);

export PFNGLSPECIALIZESHADERPROC glSpecializeShader = nullptr;
export PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount = nullptr;
export PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount = nullptr;
export PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp = nullptr;

export namespace GLAD_4_6 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glSpecializeShader = gladLoadFunction<PFNGLSPECIALIZESHADERPROC>("glSpecializeShader", load);
		glMultiDrawArraysIndirectCount = gladLoadFunction<PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC>("glMultiDrawArraysIndirectCount", load);
		glMultiDrawElementsIndirectCount = gladLoadFunction<PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC>("glMultiDrawElementsIndirectCount", load);
		glPolygonOffsetClamp = gladLoadFunction<PFNGLPOLYGONOFFSETCLAMPPROC>("glPolygonOffsetClamp", load);

		GLAD_4_5::load_GL_RECURSIVE(load);
	}
}