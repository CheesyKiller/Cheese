export module GLAD:V1_3;

export import :V1_2;

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

	// Declare function pointers as variables
	PFNGLACTIVETEXTUREPROC glActiveTexture = nullptr;
	PFNGLSAMPLECOVERAGEPROC glSampleCoverage = nullptr;
	PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D = nullptr;
	PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D = nullptr;
	PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D = nullptr;
	PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D = nullptr;
	PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D = nullptr;
	PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D = nullptr;
	PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage = nullptr;

	namespace GLAD_1_3 {
		void load_GL_RECURSIVE(GLADloadproc load) {
			glActiveTexture = GLAD::gladLoadFunction<PFNGLACTIVETEXTUREPROC>("glActiveTexture", load);
			glSampleCoverage = GLAD::gladLoadFunction<PFNGLSAMPLECOVERAGEPROC>("glSampleCoverage", load);
			glCompressedTexImage3D = GLAD::gladLoadFunction<PFNGLCOMPRESSEDTEXIMAGE3DPROC>("glCompressedTexImage3D", load);
			glCompressedTexImage2D = GLAD::gladLoadFunction<PFNGLCOMPRESSEDTEXIMAGE2DPROC>("glCompressedTexImage2D", load);
			glCompressedTexImage1D = GLAD::gladLoadFunction<PFNGLCOMPRESSEDTEXIMAGE1DPROC>("glCompressedTexImage1D", load);
			glCompressedTexSubImage3D = GLAD::gladLoadFunction<PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC>("glCompressedTexSubImage3D", load);
			glCompressedTexSubImage2D = GLAD::gladLoadFunction<PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC>("glCompressedTexSubImage2D", load);
			glCompressedTexSubImage1D = GLAD::gladLoadFunction<PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC>("glCompressedTexSubImage1D", load);
			glGetCompressedTexImage = GLAD::gladLoadFunction<PFNGLGETCOMPRESSEDTEXIMAGEPROC>("glGetCompressedTexImage", load);

			GLAD::GLAD_1_2::load_GL_RECURSIVE(load);
		}
	}
}