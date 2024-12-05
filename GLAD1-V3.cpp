import GLADBase;
import GLAD1;

namespace GLAD::V1_3 {
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

		GLAD::V1_2::load_GL_RECURSIVE(load);
	}
}