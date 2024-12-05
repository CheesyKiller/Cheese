export module GLAD1:A1;

import GLADTypes;

export namespace GLAD {
	// Alias for function pointer types
	using PFNGLDRAWARRAYSPROC = void(*)(GLenum mode, GLint first, GLsizei count);
	using PFNGLDRAWELEMENTSPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices);
	using PFNGLPOLYGONOFFSETPROC = void(*)(GLfloat factor, GLfloat units);
	using PFNGLCOPYTEXIMAGE1DPROC = void(*)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
	using PFNGLCOPYTEXIMAGE2DPROC = void(*)(GLenum target, GLint level, GLint internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
	using PFNGLCOPYTEXSUBIMAGE1DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	using PFNGLCOPYTEXSUBIMAGE2DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	using PFNGLTEXSUBIMAGE1DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
	using PFNGLTEXSUBIMAGE2DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
	using PFNGLBINDTEXTUREPROC = void(*)(GLenum target, GLuint texture);
	using PFNGLDELETETEXTURESPROC = void(*)(GLsizei n, const GLuint* textures);
	using PFNGLGENTEXTURESPROC = void(*)(GLsizei n, GLuint* textures);
	using PFNGLISTEXTUREPROC = GLboolean(*)(GLuint texture);
}