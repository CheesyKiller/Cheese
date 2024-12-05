export module GLAD3:V1;

import GLADBase;
import :A1;

export namespace GLAD {
	// Declare function pointers as variables
	PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced = nullptr;
	PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced = nullptr;
	PFNGLTEXBUFFERPROC glTexBuffer = nullptr;
	PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex = nullptr;
	PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData = nullptr;
	PFNGLGETUNIFORMINDICESPROC glGetUniformIndices = nullptr;
	PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv = nullptr;
	PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName = nullptr;
	PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex = nullptr;
	PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv = nullptr;
	PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName = nullptr;
	PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding = nullptr;

	namespace V3_1 {
		void load_GL_RECURSIVE(GLADloadproc load);
	}
}