export module GLAD:V1_1;

export import :V1_0;

// Alias for function pointer types
export using PFNGLDRAWARRAYSPROC = void(*)(GLenum mode, GLint first, GLsizei count);
export using PFNGLDRAWELEMENTSPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices);
export using PFNGLPOLYGONOFFSETPROC = void(*)(GLfloat factor, GLfloat units);
export using PFNGLCOPYTEXIMAGE1DPROC = void(*)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
export using PFNGLCOPYTEXIMAGE2DPROC = void(*)(GLenum target, GLint level, GLint internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
export using PFNGLCOPYTEXSUBIMAGE1DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
export using PFNGLCOPYTEXSUBIMAGE2DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
export using PFNGLTEXSUBIMAGE1DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
export using PFNGLTEXSUBIMAGE2DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
export using PFNGLBINDTEXTUREPROC = void(*)(GLenum target, GLuint texture);
export using PFNGLDELETETEXTURESPROC = void(*)(GLsizei n, const GLuint* textures);
export using PFNGLGENTEXTURESPROC = void(*)(GLsizei n, GLuint* textures);
export using PFNGLISTEXTUREPROC = GLboolean(*)(GLuint texture);

// Declare function pointers as variables
export PFNGLDRAWARRAYSPROC glDrawArrays = nullptr;
export PFNGLDRAWELEMENTSPROC glDrawElements = nullptr;
export PFNGLPOLYGONOFFSETPROC glPolygonOffset = nullptr;
export PFNGLCOPYTEXIMAGE1DPROC glCopyTexImage1D = nullptr;
export PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D = nullptr;
export PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D = nullptr;
export PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D = nullptr;
export PFNGLTEXSUBIMAGE1DPROC glTexSubImage1D = nullptr;
export PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D = nullptr;
export PFNGLBINDTEXTUREPROC glBindTexture = nullptr;
export PFNGLDELETETEXTURESPROC glDeleteTextures = nullptr;
export PFNGLGENTEXTURESPROC glGenTextures = nullptr;
export PFNGLISTEXTUREPROC glIsTexture = nullptr;

export namespace GLAD_1_1 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glDrawArrays = gladLoadFunction<PFNGLDRAWARRAYSPROC>("glDrawArrays", load);
		glDrawElements = gladLoadFunction<PFNGLDRAWELEMENTSPROC>("glDrawElements", load);
		glPolygonOffset = gladLoadFunction<PFNGLPOLYGONOFFSETPROC>("glPolygonOffset", load);
		glCopyTexImage1D = gladLoadFunction<PFNGLCOPYTEXIMAGE1DPROC>("glCopyTexImage1D", load);
		glCopyTexImage2D = gladLoadFunction<PFNGLCOPYTEXIMAGE2DPROC>("glCopyTexImage2D", load);
		glCopyTexSubImage1D = gladLoadFunction<PFNGLCOPYTEXSUBIMAGE1DPROC>("glCopyTexSubImage1D", load);
		glCopyTexSubImage2D = gladLoadFunction<PFNGLCOPYTEXSUBIMAGE2DPROC>("glCopyTexSubImage2D", load);
		glTexSubImage1D = gladLoadFunction<PFNGLTEXSUBIMAGE1DPROC>("glTexSubImage1D", load);
		glTexSubImage2D = gladLoadFunction<PFNGLTEXSUBIMAGE2DPROC>("glTexSubImage2D", load);
		glBindTexture = gladLoadFunction<PFNGLBINDTEXTUREPROC>("glBindTexture", load);
		glDeleteTextures = gladLoadFunction<PFNGLDELETETEXTURESPROC>("glDeleteTextures", load);
		glGenTextures = gladLoadFunction<PFNGLGENTEXTURESPROC>("glGenTextures", load);
		glIsTexture = gladLoadFunction<PFNGLISTEXTUREPROC>("glIsTexture", load);

		GLAD_1_0::load_GL_RECURSIVE(load);
	}
}