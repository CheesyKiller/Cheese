import GLADBase;
import GLAD3;

namespace GLAD::V3_2 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glDrawElementsBaseVertex = GLAD::gladLoadFunction<PFNGLDRAWELEMENTSBASEVERTEXPROC>("glDrawElementsBaseVertex", load);
		glDrawRangeElementsBaseVertex = GLAD::gladLoadFunction<PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC>("glDrawRangeElementsBaseVertex", load);
		glDrawElementsInstancedBaseVertex = GLAD::gladLoadFunction<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC>("glDrawElementsInstancedBaseVertex", load);
		glMultiDrawElementsBaseVertex = GLAD::gladLoadFunction<PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC>("glMultiDrawElementsBaseVertex", load);
		glProvokingVertex = GLAD::gladLoadFunction<PFNGLPROVOKINGVERTEXPROC>("glProvokingVertex", load);
		glFenceSync = GLAD::gladLoadFunction<PFNGLFENCESYNCPROC>("glFenceSync", load);
		glIsSync = GLAD::gladLoadFunction<PFNGLISSYNCPROC>("glIsSync", load);
		glDeleteSync = GLAD::gladLoadFunction<PFNGLDELETESYNCPROC>("glDeleteSync", load);
		glClientWaitSync = GLAD::gladLoadFunction<PFNGLCLIENTWAITSYNCPROC>("glClientWaitSync", load);
		glWaitSync = GLAD::gladLoadFunction<PFNGLWAITSYNCPROC>("glWaitSync", load);
		glGetInteger64v = GLAD::gladLoadFunction<PFNGLGETINTEGER64VPROC>("glGetInteger64v", load);
		glGetSynciv = GLAD::gladLoadFunction<PFNGLGETSYNCIVPROC>("glGetSynciv", load);
		glGetInteger64i_v = GLAD::gladLoadFunction<PFNGLGETINTEGER64I_VPROC>("glGetInteger64i_v", load);
		glGetBufferParameteri64v = GLAD::gladLoadFunction<PFNGLGETBUFFERPARAMETERI64VPROC>("glGetBufferParameteri64v", load);
		glFramebufferTexture = GLAD::gladLoadFunction<PFNGLFRAMEBUFFERTEXTUREPROC>("glFramebufferTexture", load);
		glTexImage2DMultisample = GLAD::gladLoadFunction<PFNGLTEXIMAGE2DMULTISAMPLEPROC>("glTexImage2DMultisample", load);
		glTexImage3DMultisample = GLAD::gladLoadFunction<PFNGLTEXIMAGE3DMULTISAMPLEPROC>("glTexImage3DMultisample", load);
		glGetMultisamplefv = GLAD::gladLoadFunction<PFNGLGETMULTISAMPLEFVPROC>("glGetMultisamplefv", load);
		glSampleMaski = GLAD::gladLoadFunction<PFNGLSAMPLEMASKIPROC>("glSampleMaski", load);

		GLAD::V3_1::load_GL_RECURSIVE(load);
	}
}