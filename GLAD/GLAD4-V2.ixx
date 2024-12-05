export module GLAD4:V2;

import GLADBase;
import :A2;

export namespace GLAD {
	// Export the function pointers
	PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance = nullptr;
	PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance = nullptr;
	PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance = nullptr;
	PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ = nullptr;
	PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv = nullptr;
	PFNGLBINDIMAGETEXTUREPROC glBindImageTexture = nullptr;
	PFNGLMEMORYBARRIERPROC glMemoryBarrier = nullptr;
	PFNGLTEXSTORAGE1DPROC glTexStorage1D = nullptr;
	PFNGLTEXSTORAGE2DPROC glTexStorage2D = nullptr;
	PFNGLTEXSTORAGE3DPROC glTexStorage3D = nullptr;
	PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced = nullptr;
	PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced = nullptr;

	namespace V4_2 {
		void load_GL_RECURSIVE(GLADloadproc load);
	}
}