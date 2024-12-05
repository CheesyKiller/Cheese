import GLADBase;
import GLAD4;

namespace GLAD::V4_2 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glDrawArraysInstancedBaseInstance = GLAD::gladLoadFunction<PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC>("glDrawArraysInstancedBaseInstance", load);
		glDrawElementsInstancedBaseInstance = GLAD::gladLoadFunction<PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC>("glDrawElementsInstancedBaseInstance", load);
		glDrawElementsInstancedBaseVertexBaseInstance = GLAD::gladLoadFunction<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC>("glDrawElementsInstancedBaseVertexBaseInstance", load);
		glGetInternalformativ = GLAD::gladLoadFunction<PFNGLGETINTERNALFORMATIVPROC>("glGetInternalformativ", load);
		glGetActiveAtomicCounterBufferiv = GLAD::gladLoadFunction<PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC>("glGetActiveAtomicCounterBufferiv", load);
		glBindImageTexture = GLAD::gladLoadFunction<PFNGLBINDIMAGETEXTUREPROC>("glBindImageTexture", load);
		glMemoryBarrier = GLAD::gladLoadFunction<PFNGLMEMORYBARRIERPROC>("glMemoryBarrier", load);
		glTexStorage1D = GLAD::gladLoadFunction<PFNGLTEXSTORAGE1DPROC>("glTexStorage1D", load);
		glTexStorage2D = GLAD::gladLoadFunction<PFNGLTEXSTORAGE2DPROC>("glTexStorage2D", load);
		glTexStorage3D = GLAD::gladLoadFunction<PFNGLTEXSTORAGE3DPROC>("glTexStorage3D", load);
		glDrawTransformFeedbackInstanced = GLAD::gladLoadFunction<PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC>("glDrawTransformFeedbackInstanced", load);
		glDrawTransformFeedbackStreamInstanced = GLAD::gladLoadFunction<PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC>("glDrawTransformFeedbackStreamInstanced", load);

		GLAD::V4_1::load_GL_RECURSIVE(load);
	}
}