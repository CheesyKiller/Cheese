export module GLAD1:A4;

import GLADTypes;

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
}