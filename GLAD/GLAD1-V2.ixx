export module GLAD1:V2;

import GLADBase;
import :A2;

export namespace GLAD {
	// Declare function pointers as variables
	PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements = nullptr;
	PFNGLTEXIMAGE3DPROC glTexImage3D = nullptr;
	PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D = nullptr;
	PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D = nullptr;

	namespace V1_2 {
		void load_GL_RECURSIVE(GLADloadproc load);
	}
}