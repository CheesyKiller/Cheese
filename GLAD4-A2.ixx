export module GLAD4:A2;

import GLADTypes;

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
}