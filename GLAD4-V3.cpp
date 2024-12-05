import GLADBase;
import GLAD4;

namespace GLAD::V4_3 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glClearBufferData = GLAD::gladLoadFunction<PFNGLCLEARBUFFERDATAPROC>("glClearBufferData", load);
		glClearBufferSubData = GLAD::gladLoadFunction<PFNGLCLEARBUFFERSUBDATAPROC>("glClearBufferSubData", load);
		glDispatchCompute = GLAD::gladLoadFunction<PFNGLDISPATCHCOMPUTEPROC>("glDispatchCompute", load);
		glDispatchComputeIndirect = GLAD::gladLoadFunction<PFNGLDISPATCHCOMPUTEINDIRECTPROC>("glDispatchComputeIndirect", load);
		glCopyImageSubData = GLAD::gladLoadFunction<PFNGLCOPYIMAGESUBDATAPROC>("glCopyImageSubData", load);
		glFramebufferParameteri = GLAD::gladLoadFunction<PFNGLFRAMEBUFFERPARAMETERIPROC>("glFramebufferParameteri", load);
		glGetFramebufferParameteriv = GLAD::gladLoadFunction<PFNGLGETFRAMEBUFFERPARAMETERIVPROC>("glGetFramebufferParameteriv", load);
		glGetInternalformati64v = GLAD::gladLoadFunction<PFNGLGETINTERNALFORMATI64VPROC>("glGetInternalformati64v", load);
		glInvalidateTexSubImage = GLAD::gladLoadFunction<PFNGLINVALIDATETEXSUBIMAGEPROC>("glInvalidateTexSubImage", load);
		glInvalidateTexImage = GLAD::gladLoadFunction<PFNGLINVALIDATETEXIMAGEPROC>("glInvalidateTexImage", load);
		glInvalidateBufferSubData = GLAD::gladLoadFunction<PFNGLINVALIDATEBUFFERSUBDATAPROC>("glInvalidateBufferSubData", load);
		glInvalidateBufferData = GLAD::gladLoadFunction<PFNGLINVALIDATEBUFFERDATAPROC>("glInvalidateBufferData", load);
		glInvalidateFramebuffer = GLAD::gladLoadFunction<PFNGLINVALIDATEFRAMEBUFFERPROC>("glInvalidateFramebuffer", load);
		glInvalidateSubFramebuffer = GLAD::gladLoadFunction<PFNGLINVALIDATESUBFRAMEBUFFERPROC>("glInvalidateSubFramebuffer", load);
		glMultiDrawArraysIndirect = GLAD::gladLoadFunction<PFNGLMULTIDRAWARRAYSINDIRECTPROC>("glMultiDrawArraysIndirect", load);
		glMultiDrawElementsIndirect = GLAD::gladLoadFunction<PFNGLMULTIDRAWELEMENTSINDIRECTPROC>("glMultiDrawElementsIndirect", load);
		glGetProgramInterfaceiv = GLAD::gladLoadFunction<PFNGLGETPROGRAMINTERFACEIVPROC>("glGetProgramInterfaceiv", load);
		glGetProgramResourceIndex = GLAD::gladLoadFunction<PFNGLGETPROGRAMRESOURCEINDEXPROC>("glGetProgramResourceIndex", load);
		glGetProgramResourceName = GLAD::gladLoadFunction<PFNGLGETPROGRAMRESOURCENAMEPROC>("glGetProgramResourceName", load);
		glGetProgramResourceiv = GLAD::gladLoadFunction<PFNGLGETPROGRAMRESOURCEIVPROC>("glGetProgramResourceiv", load);
		glGetProgramResourceLocation = GLAD::gladLoadFunction<PFNGLGETPROGRAMRESOURCELOCATIONPROC>("glGetProgramResourceLocation", load);
		glGetProgramResourceLocationIndex = GLAD::gladLoadFunction<PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC>("glGetProgramResourceLocationIndex", load);
		glShaderStorageBlockBinding = GLAD::gladLoadFunction<PFNGLSHADERSTORAGEBLOCKBINDINGPROC>("glShaderStorageBlockBinding", load);
		glTexBufferRange = GLAD::gladLoadFunction<PFNGLTEXBUFFERRANGEPROC>("glTexBufferRange", load);
		glTexStorage2DMultisample = GLAD::gladLoadFunction<PFNGLTEXSTORAGE2DMULTISAMPLEPROC>("glTexStorage2DMultisample", load);
		glTexStorage3DMultisample = GLAD::gladLoadFunction<PFNGLTEXSTORAGE3DMULTISAMPLEPROC>("glTexStorage3DMultisample", load);
		glTextureView = GLAD::gladLoadFunction<PFNGLTEXTUREVIEWPROC>("glTextureView", load);
		glBindVertexBuffer = GLAD::gladLoadFunction<PFNGLBINDVERTEXBUFFERPROC>("glBindVertexBuffer", load);
		glVertexAttribFormat = GLAD::gladLoadFunction<PFNGLVERTEXATTRIBFORMATPROC>("glVertexAttribFormat", load);
		glVertexAttribIFormat = GLAD::gladLoadFunction<PFNGLVERTEXATTRIBIFORMATPROC>("glVertexAttribIFormat", load);
		glVertexAttribLFormat = GLAD::gladLoadFunction<PFNGLVERTEXATTRIBLFORMATPROC>("glVertexAttribLFormat", load);
		glVertexAttribBinding = GLAD::gladLoadFunction<PFNGLVERTEXATTRIBBINDINGPROC>("glVertexAttribBinding", load);
		glVertexBindingDivisor = GLAD::gladLoadFunction<PFNGLVERTEXBINDINGDIVISORPROC>("glVertexBindingDivisor", load);
		glDebugMessageControl = GLAD::gladLoadFunction<PFNGLDEBUGMESSAGECONTROLPROC>("glDebugMessageControl", load);
		glDebugMessageInsert = GLAD::gladLoadFunction<PFNGLDEBUGMESSAGEINSERTPROC>("glDebugMessageInsert", load);
		glDebugMessageCallback = GLAD::gladLoadFunction<PFNGLDEBUGMESSAGECALLBACKPROC>("glDebugMessageCallback", load);
		glGetDebugMessageLog = GLAD::gladLoadFunction<PFNGLGETDEBUGMESSAGELOGPROC>("glGetDebugMessageLog", load);
		glPushDebugGroup = GLAD::gladLoadFunction<PFNGLPUSHDEBUGGROUPPROC>("glPushDebugGroup", load);
		glPopDebugGroup = GLAD::gladLoadFunction<PFNGLPOPDEBUGGROUPPROC>("glPopDebugGroup", load);
		glObjectLabel = GLAD::gladLoadFunction<PFNGLOBJECTLABELPROC>("glObjectLabel", load);
		glGetObjectLabel = GLAD::gladLoadFunction<PFNGLGETOBJECTLABELPROC>("glGetObjectLabel", load);
		glObjectPtrLabel = GLAD::gladLoadFunction<PFNGLOBJECTPTRLABELPROC>("glObjectPtrLabel", load);
		glGetObjectPtrLabel = GLAD::gladLoadFunction<PFNGLGETOBJECTPTRLABELPROC>("glGetObjectPtrLabel", load);
		glGetPointerv = GLAD::gladLoadFunction<PFNGLGETPOINTERVPROC>("glGetPointerv", load);

		GLAD::V4_2::load_GL_RECURSIVE(load);
	}
}