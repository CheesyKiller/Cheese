export module GLAD:V3_1;

export import :V3_0;

// Alias for function pointer types
export using PFNGLDRAWARRAYSINSTANCEDPROC = void(*)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
export using PFNGLDRAWELEMENTSINSTANCEDPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount);
export using PFNGLTEXBUFFERPROC = void(*)(GLenum target, GLenum internalformat, GLuint buffer);
export using PFNGLPRIMITIVERESTARTINDEXPROC = void(*)(GLuint index);
export using PFNGLCOPYBUFFERSUBDATAPROC = void(*)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
export using PFNGLGETUNIFORMINDICESPROC = void(*)(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices);
export using PFNGLGETACTIVEUNIFORMSIVPROC = void(*)(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
export using PFNGLGETACTIVEUNIFORMNAMEPROC = void(*)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
export using PFNGLGETUNIFORMBLOCKINDEXPROC = GLuint(*)(GLuint program, const GLchar* uniformBlockName);
export using PFNGLGETACTIVEUNIFORMBLOCKIVPROC = void(*)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
export using PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC = void(*)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
export using PFNGLUNIFORMBLOCKBINDINGPROC = void(*)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

// Declare function pointers as variables
export PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced = nullptr;
export PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced = nullptr;
export PFNGLTEXBUFFERPROC glTexBuffer = nullptr;
export PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex = nullptr;
export PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData = nullptr;
export PFNGLGETUNIFORMINDICESPROC glGetUniformIndices = nullptr;
export PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv = nullptr;
export PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName = nullptr;
export PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex = nullptr;
export PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv = nullptr;
export PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName = nullptr;
export PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding = nullptr;

export namespace GLAD_3_1 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glDrawArraysInstanced = gladLoadFunction<PFNGLDRAWARRAYSINSTANCEDPROC>("glDrawArraysInstanced", load);
		glDrawElementsInstanced = gladLoadFunction<PFNGLDRAWELEMENTSINSTANCEDPROC>("glDrawElementsInstanced", load);
		glTexBuffer = gladLoadFunction<PFNGLTEXBUFFERPROC>("glTexBuffer", load);
		glPrimitiveRestartIndex = gladLoadFunction<PFNGLPRIMITIVERESTARTINDEXPROC>("glPrimitiveRestartIndex", load);
		glCopyBufferSubData = gladLoadFunction<PFNGLCOPYBUFFERSUBDATAPROC>("glCopyBufferSubData", load);
		glGetUniformIndices = gladLoadFunction<PFNGLGETUNIFORMINDICESPROC>("glGetUniformIndices", load);
		glGetActiveUniformsiv = gladLoadFunction<PFNGLGETACTIVEUNIFORMSIVPROC>("glGetActiveUniformsiv", load);
		glGetActiveUniformName = gladLoadFunction<PFNGLGETACTIVEUNIFORMNAMEPROC>("glGetActiveUniformName", load);
		glGetUniformBlockIndex = gladLoadFunction<PFNGLGETUNIFORMBLOCKINDEXPROC>("glGetUniformBlockIndex", load);
		glGetActiveUniformBlockiv = gladLoadFunction<PFNGLGETACTIVEUNIFORMBLOCKIVPROC>("glGetActiveUniformBlockiv", load);
		glGetActiveUniformBlockName = gladLoadFunction<PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC>("glGetActiveUniformBlockName", load);
		glUniformBlockBinding = gladLoadFunction<PFNGLUNIFORMBLOCKBINDINGPROC>("glUniformBlockBinding", load);

		GLAD_3_0::load_GL_RECURSIVE(load);
	}
}