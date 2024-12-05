export module GLAD1:V1;

import GLADBase;
import :A1;

export namespace GLAD {
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

	namespace V1_1 {
		void load_GL_RECURSIVE(GLADloadproc load);
	}
}