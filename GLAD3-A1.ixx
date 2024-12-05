export module GLAD3:A1;

import GLADTypes;

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
}