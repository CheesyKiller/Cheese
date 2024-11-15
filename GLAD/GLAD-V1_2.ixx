export module GLAD:V1_2;

export import :V1_1;

// Alias for function pointer types
export using PFNGLDRAWRANGEELEMENTSPROC = void(*)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices);
export using PFNGLTEXIMAGE3DPROC = void(*)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels);
export using PFNGLTEXSUBIMAGE3DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
export using PFNGLCOPYTEXSUBIMAGE3DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

// Declare function pointers as variables
export PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements = nullptr;
export PFNGLTEXIMAGE3DPROC glTexImage3D = nullptr;
export PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D = nullptr;
export PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D = nullptr;

export namespace GLAD_1_2 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glDrawRangeElements = gladLoadFunction<PFNGLDRAWRANGEELEMENTSPROC>("glDrawRangeElements", load);
		glTexImage3D = gladLoadFunction<PFNGLTEXIMAGE3DPROC>("glTexImage3D", load);
		glTexSubImage3D = gladLoadFunction<PFNGLTEXSUBIMAGE3DPROC>("glTexSubImage3D", load);
		glCopyTexSubImage3D = gladLoadFunction<PFNGLCOPYTEXSUBIMAGE3DPROC>("glCopyTexSubImage3D", load);

		GLAD_1_1::load_GL_RECURSIVE(load);
	}
}