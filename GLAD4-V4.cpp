import GLADBase;
import GLAD4;

namespace GLAD::V4_4 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glBufferStorage = GLAD::gladLoadFunction<PFNGLBUFFERSTORAGEPROC>("glBufferStorage", load);
		glClearTexImage = GLAD::gladLoadFunction<PFNGLCLEARTEXIMAGEPROC>("glClearTexImage", load);
		glClearTexSubImage = GLAD::gladLoadFunction<PFNGLCLEARTEXSUBIMAGEPROC>("glClearTexSubImage", load);
		glBindBuffersBase = GLAD::gladLoadFunction<PFNGLBINDBUFFERSBASEPROC>("glBindBuffersBase", load);
		glBindBuffersRange = GLAD::gladLoadFunction<PFNGLBINDBUFFERSRANGEPROC>("glBindBuffersRange", load);
		glBindTextures = GLAD::gladLoadFunction<PFNGLBINDTEXTURESPROC>("glBindTextures", load);
		glBindSamplers = GLAD::gladLoadFunction<PFNGLBINDSAMPLERSPROC>("glBindSamplers", load);
		glBindImageTextures = GLAD::gladLoadFunction<PFNGLBINDIMAGETEXTURESPROC>("glBindImageTextures", load);
		glBindVertexBuffers = GLAD::gladLoadFunction<PFNGLBINDVERTEXBUFFERSPROC>("glBindVertexBuffers", load);

		GLAD::V4_3::load_GL_RECURSIVE(load);
	}
}