export module GLAD:V1_4;

export import :V1_3;

export namespace GLAD {
	// Alias for function pointer types
	using PFNGLBLENDFUNCSEPARATEPROC = void(*)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
	using PFNGLMULTIDRAWARRAYSPROC = void(*)(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount);
	using PFNGLMULTIDRAWELEMENTSPROC = void(*)(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount);
	using PFNGLPOINTPARAMETERFPROC = void(*)(GLenum pname, GLfloat param);
	using PFNGLPOINTPARAMETERFVPROC = void(*)(GLenum pname, const GLfloat* params);
	using PFNGLPOINTPARAMETERIPROC = void(*)(GLenum pname, GLint param);
	using PFNGLPOINTPARAMETERIVPROC = void(*)(GLenum pname, const GLint* params);
	using PFNGLBLENDCOLORPROC = void(*)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	using PFNGLBLENDEQUATIONPROC = void(*)(GLenum mode);

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

	namespace GLAD_1_4 {
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

			GLAD::GLAD_1_3::load_GL_RECURSIVE(load);
		}
	}
}