export module GLAD:V3_1;

export import :V3_0;

export namespace GLAD {
	// Alias for function pointer types
	using PFNGLDRAWARRAYSINSTANCEDPROC = void(*)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
	using PFNGLDRAWELEMENTSINSTANCEDPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount);
	using PFNGLTEXBUFFERPROC = void(*)(GLenum target, GLenum internalformat, GLuint buffer);
	using PFNGLPRIMITIVERESTARTINDEXPROC = void(*)(GLuint index);
	using PFNGLCOPYBUFFERSUBDATAPROC = void(*)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
	using PFNGLGETUNIFORMINDICESPROC = void(*)(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices);
	using PFNGLGETACTIVEUNIFORMSIVPROC = void(*)(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
	using PFNGLGETACTIVEUNIFORMNAMEPROC = void(*)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
	using PFNGLGETUNIFORMBLOCKINDEXPROC = GLuint(*)(GLuint program, const GLchar* uniformBlockName);
	using PFNGLGETACTIVEUNIFORMBLOCKIVPROC = void(*)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
	using PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC = void(*)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
	using PFNGLUNIFORMBLOCKBINDINGPROC = void(*)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

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

	namespace GLAD_3_1 {
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

			GLAD::GLAD_3_0::load_GL_RECURSIVE(load);
		}
	}
}