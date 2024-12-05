import GLADBase;
import GLAD1;

namespace GLAD::V1_1 {
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

		GLAD::V1_0::load_GL_RECURSIVE(load);
	}
}