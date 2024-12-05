export module GLAD3:V2;

import GLADBase;
import :A2;

export namespace GLAD {
	// Declare function pointers as variables
	PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex = nullptr;
	PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex = nullptr;
	PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex = nullptr;
	PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex = nullptr;
	PFNGLPROVOKINGVERTEXPROC glProvokingVertex = nullptr;
	PFNGLFENCESYNCPROC glFenceSync = nullptr;
	PFNGLISSYNCPROC glIsSync = nullptr;
	PFNGLDELETESYNCPROC glDeleteSync = nullptr;
	PFNGLCLIENTWAITSYNCPROC glClientWaitSync = nullptr;
	PFNGLWAITSYNCPROC glWaitSync = nullptr;
	PFNGLGETINTEGER64VPROC glGetInteger64v = nullptr;
	PFNGLGETSYNCIVPROC glGetSynciv = nullptr;
	PFNGLGETINTEGER64I_VPROC glGetInteger64i_v = nullptr;
	PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v = nullptr;
	PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture = nullptr;
	PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample = nullptr;
	PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample = nullptr;
	PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv = nullptr;
	PFNGLSAMPLEMASKIPROC glSampleMaski = nullptr;

	namespace V3_2 {
		void load_GL_RECURSIVE(GLADloadproc load);
	}
}