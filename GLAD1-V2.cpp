import GLADBase;
import GLAD1;

namespace GLAD::V1_2 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glDrawRangeElements = GLAD::gladLoadFunction<PFNGLDRAWRANGEELEMENTSPROC>("glDrawRangeElements", load);
		glTexImage3D = GLAD::gladLoadFunction<PFNGLTEXIMAGE3DPROC>("glTexImage3D", load);
		glTexSubImage3D = GLAD::gladLoadFunction<PFNGLTEXSUBIMAGE3DPROC>("glTexSubImage3D", load);
		glCopyTexSubImage3D = GLAD::gladLoadFunction<PFNGLCOPYTEXSUBIMAGE3DPROC>("glCopyTexSubImage3D", load);

		GLAD::V1_1::load_GL_RECURSIVE(load);
	}
}