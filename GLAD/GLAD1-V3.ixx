export module GLAD1:V3;

import GLADBase;
import :A3;

export namespace GLAD {
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

	namespace V1_3 {
		void load_GL_RECURSIVE(GLADloadproc load);
	}
}