export module GLAD4:V4;

import GLADBase;
import :A4;

export namespace GLAD {
	// Export the function pointers
	PFNGLBUFFERSTORAGEPROC glBufferStorage = nullptr;
	PFNGLCLEARTEXIMAGEPROC glClearTexImage = nullptr;
	PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage = nullptr;
	PFNGLBINDBUFFERSBASEPROC glBindBuffersBase = nullptr;
	PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange = nullptr;
	PFNGLBINDTEXTURESPROC glBindTextures = nullptr;
	PFNGLBINDSAMPLERSPROC glBindSamplers = nullptr;
	PFNGLBINDIMAGETEXTURESPROC glBindImageTextures = nullptr;
	PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers = nullptr;

	namespace V4_4 {
		void load_GL_RECURSIVE(GLADloadproc load);
	}
}