export module GLAD:V1_2;

export import :V1_1;

export namespace GLAD {
	// Alias for function pointer types
	using PFNGLDRAWRANGEELEMENTSPROC = void(*)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices);
	using PFNGLTEXIMAGE3DPROC = void(*)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels);
	using PFNGLTEXSUBIMAGE3DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
	using PFNGLCOPYTEXSUBIMAGE3DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

	// Declare function pointers as variables
	PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements = nullptr;
	PFNGLTEXIMAGE3DPROC glTexImage3D = nullptr;
	PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D = nullptr;
	PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D = nullptr;

	namespace GLAD_1_2 {
		void load_GL_RECURSIVE(GLADloadproc load) {
			glDrawRangeElements = GLAD::gladLoadFunction<PFNGLDRAWRANGEELEMENTSPROC>("glDrawRangeElements", load);
			glTexImage3D = GLAD::gladLoadFunction<PFNGLTEXIMAGE3DPROC>("glTexImage3D", load);
			glTexSubImage3D = GLAD::gladLoadFunction<PFNGLTEXSUBIMAGE3DPROC>("glTexSubImage3D", load);
			glCopyTexSubImage3D = GLAD::gladLoadFunction<PFNGLCOPYTEXSUBIMAGE3DPROC>("glCopyTexSubImage3D", load);

			GLAD::GLAD_1_1::load_GL_RECURSIVE(load);
		}
	}
}