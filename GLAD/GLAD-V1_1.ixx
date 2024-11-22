export module GLAD:V1_1;

export import :V1_0;

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

	// Declare function pointers as variables
	PFNGLDRAWARRAYSPROC glDrawArrays = nullptr;
	PFNGLDRAWELEMENTSPROC glDrawElements = nullptr;
	PFNGLPOLYGONOFFSETPROC glPolygonOffset = nullptr;
	PFNGLCOPYTEXIMAGE1DPROC glCopyTexImage1D = nullptr;
	PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D = nullptr;
	PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D = nullptr;
	PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D = nullptr;
	PFNGLTEXSUBIMAGE1DPROC glTexSubImage1D = nullptr;
	PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D = nullptr;
	PFNGLBINDTEXTUREPROC glBindTexture = nullptr;
	PFNGLDELETETEXTURESPROC glDeleteTextures = nullptr;
	PFNGLGENTEXTURESPROC glGenTextures = nullptr;
	PFNGLISTEXTUREPROC glIsTexture = nullptr;

	namespace GLAD_1_1 {
		void load_GL_RECURSIVE(GLADloadproc load) {
			glDrawArrays = GLAD::gladLoadFunction<PFNGLDRAWARRAYSPROC>("glDrawArrays", load);
			glDrawElements = GLAD::gladLoadFunction<PFNGLDRAWELEMENTSPROC>("glDrawElements", load);
			glPolygonOffset = GLAD::gladLoadFunction<PFNGLPOLYGONOFFSETPROC>("glPolygonOffset", load);
			glCopyTexImage1D = GLAD::gladLoadFunction<PFNGLCOPYTEXIMAGE1DPROC>("glCopyTexImage1D", load);
			glCopyTexImage2D = GLAD::gladLoadFunction<PFNGLCOPYTEXIMAGE2DPROC>("glCopyTexImage2D", load);
			glCopyTexSubImage1D = GLAD::gladLoadFunction<PFNGLCOPYTEXSUBIMAGE1DPROC>("glCopyTexSubImage1D", load);
			glCopyTexSubImage2D = GLAD::gladLoadFunction<PFNGLCOPYTEXSUBIMAGE2DPROC>("glCopyTexSubImage2D", load);
			glTexSubImage1D = GLAD::gladLoadFunction<PFNGLTEXSUBIMAGE1DPROC>("glTexSubImage1D", load);
			glTexSubImage2D = GLAD::gladLoadFunction<PFNGLTEXSUBIMAGE2DPROC>("glTexSubImage2D", load);
			glBindTexture = GLAD::gladLoadFunction<PFNGLBINDTEXTUREPROC>("glBindTexture", load);
			glDeleteTextures = GLAD::gladLoadFunction<PFNGLDELETETEXTURESPROC>("glDeleteTextures", load);
			glGenTextures = GLAD::gladLoadFunction<PFNGLGENTEXTURESPROC>("glGenTextures", load);
			glIsTexture = GLAD::gladLoadFunction<PFNGLISTEXTUREPROC>("glIsTexture", load);

			GLAD::GLAD_1_0::load_GL_RECURSIVE(load);
		}
	}
}