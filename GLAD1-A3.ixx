export module GLAD1:A3;

import GLADTypes;

export namespace GLAD {
	// Alias for function pointer types
	using PFNGLACTIVETEXTUREPROC = void(*)(GLenum texture);
	using PFNGLSAMPLECOVERAGEPROC = void(*)(GLfloat value, GLboolean invert);
	using PFNGLCOMPRESSEDTEXIMAGE3DPROC = void(*)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data);
	using PFNGLCOMPRESSEDTEXIMAGE2DPROC = void(*)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data);
	using PFNGLCOMPRESSEDTEXIMAGE1DPROC = void(*)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data);
	using PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data);
	using PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data);
	using PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data);
	using PFNGLGETCOMPRESSEDTEXIMAGEPROC = void(*)(GLenum target, GLint level, void* img);
}