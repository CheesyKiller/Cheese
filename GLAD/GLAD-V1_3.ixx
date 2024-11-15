export module GLAD:V1_3;

export import :V1_2;

// Alias for function pointer types
export using PFNGLACTIVETEXTUREPROC = void(*)(GLenum texture);
export using PFNGLSAMPLECOVERAGEPROC = void(*)(GLfloat value, GLboolean invert);
export using PFNGLCOMPRESSEDTEXIMAGE3DPROC = void(*)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data);
export using PFNGLCOMPRESSEDTEXIMAGE2DPROC = void(*)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data);
export using PFNGLCOMPRESSEDTEXIMAGE1DPROC = void(*)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data);
export using PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data);
export using PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data);
export using PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC = void(*)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data);
export using PFNGLGETCOMPRESSEDTEXIMAGEPROC = void(*)(GLenum target, GLint level, void* img);

// Declare function pointers as variables
export PFNGLACTIVETEXTUREPROC glActiveTexture = nullptr;
export PFNGLSAMPLECOVERAGEPROC glSampleCoverage = nullptr;
export PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D = nullptr;
export PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D = nullptr;
export PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D = nullptr;
export PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D = nullptr;
export PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D = nullptr;
export PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D = nullptr;
export PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage = nullptr;

export namespace GLAD_1_3 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glActiveTexture = gladLoadFunction<PFNGLACTIVETEXTUREPROC>("glActiveTexture", load);
		glSampleCoverage = gladLoadFunction<PFNGLSAMPLECOVERAGEPROC>("glSampleCoverage", load);
		glCompressedTexImage3D = gladLoadFunction<PFNGLCOMPRESSEDTEXIMAGE3DPROC>("glCompressedTexImage3D", load);
		glCompressedTexImage2D = gladLoadFunction<PFNGLCOMPRESSEDTEXIMAGE2DPROC>("glCompressedTexImage2D", load);
		glCompressedTexImage1D = gladLoadFunction<PFNGLCOMPRESSEDTEXIMAGE1DPROC>("glCompressedTexImage1D", load);
		glCompressedTexSubImage3D = gladLoadFunction<PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC>("glCompressedTexSubImage3D", load);
		glCompressedTexSubImage2D = gladLoadFunction<PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC>("glCompressedTexSubImage2D", load);
		glCompressedTexSubImage1D = gladLoadFunction<PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC>("glCompressedTexSubImage1D", load);
		glGetCompressedTexImage = gladLoadFunction<PFNGLGETCOMPRESSEDTEXIMAGEPROC>("glGetCompressedTexImage", load);

		GLAD_1_2::load_GL_RECURSIVE(load);
	}
}