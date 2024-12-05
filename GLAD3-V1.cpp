import GLADBase;
import GLAD3;

namespace GLAD::V3_1 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glDrawArraysInstanced = GLAD::gladLoadFunction<PFNGLDRAWARRAYSINSTANCEDPROC>("glDrawArraysInstanced", load);
		glDrawElementsInstanced = GLAD::gladLoadFunction<PFNGLDRAWELEMENTSINSTANCEDPROC>("glDrawElementsInstanced", load);
		glTexBuffer = GLAD::gladLoadFunction<PFNGLTEXBUFFERPROC>("glTexBuffer", load);
		glPrimitiveRestartIndex = GLAD::gladLoadFunction<PFNGLPRIMITIVERESTARTINDEXPROC>("glPrimitiveRestartIndex", load);
		glCopyBufferSubData = GLAD::gladLoadFunction<PFNGLCOPYBUFFERSUBDATAPROC>("glCopyBufferSubData", load);
		glGetUniformIndices = GLAD::gladLoadFunction<PFNGLGETUNIFORMINDICESPROC>("glGetUniformIndices", load);
		glGetActiveUniformsiv = GLAD::gladLoadFunction<PFNGLGETACTIVEUNIFORMSIVPROC>("glGetActiveUniformsiv", load);
		glGetActiveUniformName = GLAD::gladLoadFunction<PFNGLGETACTIVEUNIFORMNAMEPROC>("glGetActiveUniformName", load);
		glGetUniformBlockIndex = GLAD::gladLoadFunction<PFNGLGETUNIFORMBLOCKINDEXPROC>("glGetUniformBlockIndex", load);
		glGetActiveUniformBlockiv = GLAD::gladLoadFunction<PFNGLGETACTIVEUNIFORMBLOCKIVPROC>("glGetActiveUniformBlockiv", load);
		glGetActiveUniformBlockName = GLAD::gladLoadFunction<PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC>("glGetActiveUniformBlockName", load);
		glUniformBlockBinding = GLAD::gladLoadFunction<PFNGLUNIFORMBLOCKBINDINGPROC>("glUniformBlockBinding", load);

		GLAD::V3_0::load_GL_RECURSIVE(load);
	}
}