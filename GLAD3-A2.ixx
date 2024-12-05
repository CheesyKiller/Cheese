export module GLAD3:A2;

import GLADTypes;

export namespace GLAD {
	// Alias for function pointer types
	using PFNGLDRAWELEMENTSBASEVERTEXPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex);
	using PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC = void(*)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex);
	using PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex);
	using PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC = void(*)(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex);
	using PFNGLPROVOKINGVERTEXPROC = void(*)(GLenum mode);
	using PFNGLFENCESYNCPROC = GLsync(*)(GLenum condition, GLbitfield flags);
	using PFNGLISSYNCPROC = GLboolean(*)(GLsync sync);
	using PFNGLDELETESYNCPROC = void(*)(GLsync sync);
	using PFNGLCLIENTWAITSYNCPROC = GLenum(*)(GLsync sync, GLbitfield flags, GLuint64 timeout);
	using PFNGLWAITSYNCPROC = void(*)(GLsync sync, GLbitfield flags, GLuint64 timeout);
	using PFNGLGETINTEGER64VPROC = void(*)(GLenum pname, GLint64* data);
	using PFNGLGETSYNCIVPROC = void(*)(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values);
	using PFNGLGETINTEGER64I_VPROC = void(*)(GLenum target, GLuint index, GLint64* data);
	using PFNGLGETBUFFERPARAMETERI64VPROC = void(*)(GLenum target, GLenum pname, GLint64* params);
	using PFNGLFRAMEBUFFERTEXTUREPROC = void(*)(GLenum target, GLenum attachment, GLuint texture, GLint level);
	using PFNGLTEXIMAGE2DMULTISAMPLEPROC = void(*)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
	using PFNGLTEXIMAGE3DMULTISAMPLEPROC = void(*)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
	using PFNGLGETMULTISAMPLEFVPROC = void(*)(GLenum pname, GLuint index, GLfloat* val);
	using PFNGLSAMPLEMASKIPROC = void(*)(GLuint maskNumber, GLbitfield mask);
}