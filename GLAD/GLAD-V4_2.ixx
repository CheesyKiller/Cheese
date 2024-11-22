export module GLAD:V4_2;

export import :V4_1;

export namespace GLAD {
	using PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC = void(*)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
	using PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLuint baseinstance);
	using PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
	using PFNGLGETINTERNALFORMATIVPROC = void(*)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint* params);
	using PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC = void(*)(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params);
	using PFNGLBINDIMAGETEXTUREPROC = void(*)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
	using PFNGLMEMORYBARRIERPROC = void(*)(GLbitfield barriers);
	using PFNGLTEXSTORAGE1DPROC = void(*)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
	using PFNGLTEXSTORAGE2DPROC = void(*)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
	using PFNGLTEXSTORAGE3DPROC = void(*)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
	using PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC = void(*)(GLenum mode, GLuint id, GLsizei instancecount);
	using PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC = void(*)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);

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

	namespace GLAD_4_2 {
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

			GLAD::GLAD_4_1::load_GL_RECURSIVE(load);
		}
	}
}