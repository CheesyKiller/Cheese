export module GLAD:V4_2;

export import :V4_1;

export using PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC = void(*)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
export using PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLuint baseinstance);
export using PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
export using PFNGLGETINTERNALFORMATIVPROC = void(*)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint* params);
export using PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC = void(*)(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params);
export using PFNGLBINDIMAGETEXTUREPROC = void(*)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
export using PFNGLMEMORYBARRIERPROC = void(*)(GLbitfield barriers);
export using PFNGLTEXSTORAGE1DPROC = void(*)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
export using PFNGLTEXSTORAGE2DPROC = void(*)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
export using PFNGLTEXSTORAGE3DPROC = void(*)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
export using PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC = void(*)(GLenum mode, GLuint id, GLsizei instancecount);
export using PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC = void(*)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);

// Export the function pointers
export PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance = nullptr;
export PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance = nullptr;
export PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance = nullptr;
export PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ = nullptr;
export PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv = nullptr;
export PFNGLBINDIMAGETEXTUREPROC glBindImageTexture = nullptr;
export PFNGLMEMORYBARRIERPROC glMemoryBarrier = nullptr;
export PFNGLTEXSTORAGE1DPROC glTexStorage1D = nullptr;
export PFNGLTEXSTORAGE2DPROC glTexStorage2D = nullptr;
export PFNGLTEXSTORAGE3DPROC glTexStorage3D = nullptr;
export PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced = nullptr;
export PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced = nullptr;

export namespace GLAD_4_2 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glDrawArraysInstancedBaseInstance = gladLoadFunction<PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC>("glDrawArraysInstancedBaseInstance", load);
		glDrawElementsInstancedBaseInstance = gladLoadFunction<PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC>("glDrawElementsInstancedBaseInstance", load);
		glDrawElementsInstancedBaseVertexBaseInstance = gladLoadFunction<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC>("glDrawElementsInstancedBaseVertexBaseInstance", load);
		glGetInternalformativ = gladLoadFunction<PFNGLGETINTERNALFORMATIVPROC>("glGetInternalformativ", load);
		glGetActiveAtomicCounterBufferiv = gladLoadFunction<PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC>("glGetActiveAtomicCounterBufferiv", load);
		glBindImageTexture = gladLoadFunction<PFNGLBINDIMAGETEXTUREPROC>("glBindImageTexture", load);
		glMemoryBarrier = gladLoadFunction<PFNGLMEMORYBARRIERPROC>("glMemoryBarrier", load);
		glTexStorage1D = gladLoadFunction<PFNGLTEXSTORAGE1DPROC>("glTexStorage1D", load);
		glTexStorage2D = gladLoadFunction<PFNGLTEXSTORAGE2DPROC>("glTexStorage2D", load);
		glTexStorage3D = gladLoadFunction<PFNGLTEXSTORAGE3DPROC>("glTexStorage3D", load);
		glDrawTransformFeedbackInstanced = gladLoadFunction<PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC>("glDrawTransformFeedbackInstanced", load);
		glDrawTransformFeedbackStreamInstanced = gladLoadFunction<PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC>("glDrawTransformFeedbackStreamInstanced", load);

		GLAD_4_1::load_GL_RECURSIVE(load);
	}
}