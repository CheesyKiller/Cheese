export module GLAD:V1_4;

export import :V1_3;

// Alias for function pointer types
export using PFNGLBLENDFUNCSEPARATEPROC = void(*)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
export using PFNGLMULTIDRAWARRAYSPROC = void(*)(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount);
export using PFNGLMULTIDRAWELEMENTSPROC = void(*)(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount);
export using PFNGLPOINTPARAMETERFPROC = void(*)(GLenum pname, GLfloat param);
export using PFNGLPOINTPARAMETERFVPROC = void(*)(GLenum pname, const GLfloat* params);
export using PFNGLPOINTPARAMETERIPROC = void(*)(GLenum pname, GLint param);
export using PFNGLPOINTPARAMETERIVPROC = void(*)(GLenum pname, const GLint* params);
export using PFNGLBLENDCOLORPROC = void(*)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
export using PFNGLBLENDEQUATIONPROC = void(*)(GLenum mode);

// Declare function pointers as variables
export PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate = nullptr;
export PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays = nullptr;
export PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements = nullptr;
export PFNGLPOINTPARAMETERFPROC glPointParameterf = nullptr;
export PFNGLPOINTPARAMETERFVPROC glPointParameterfv = nullptr;
export PFNGLPOINTPARAMETERIPROC glPointParameteri = nullptr;
export PFNGLPOINTPARAMETERIVPROC glPointParameteriv = nullptr;
export PFNGLBLENDCOLORPROC glBlendColor = nullptr;
export PFNGLBLENDEQUATIONPROC glBlendEquation = nullptr;

export namespace GLAD_1_4 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glBlendFuncSeparate = gladLoadFunction<PFNGLBLENDFUNCSEPARATEPROC>("glBlendFuncSeparate", load);
		glMultiDrawArrays = gladLoadFunction<PFNGLMULTIDRAWARRAYSPROC>("glMultiDrawArrays", load);
		glMultiDrawElements = gladLoadFunction<PFNGLMULTIDRAWELEMENTSPROC>("glMultiDrawElements", load);
		glPointParameterf = gladLoadFunction<PFNGLPOINTPARAMETERFPROC>("glPointParameterf", load);
		glPointParameterfv = gladLoadFunction<PFNGLPOINTPARAMETERFVPROC>("glPointParameterfv", load);
		glPointParameteri = gladLoadFunction<PFNGLPOINTPARAMETERIPROC>("glPointParameteri", load);
		glPointParameteriv = gladLoadFunction<PFNGLPOINTPARAMETERIVPROC>("glPointParameteriv", load);
		glBlendColor = gladLoadFunction<PFNGLBLENDCOLORPROC>("glBlendColor", load);
		glBlendEquation = gladLoadFunction <PFNGLBLENDEQUATIONPROC>("glBlendEquation", load);

		GLAD_1_3::load_GL_RECURSIVE(load);
	}
}