export module GLAD:V3_2;

export import :V3_1;

// Alias for function pointer types
export using PFNGLDRAWELEMENTSBASEVERTEXPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex);
export using PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC = void(*)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex);
export using PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC = void(*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex);
export using PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC = void(*)(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex);
export using PFNGLPROVOKINGVERTEXPROC = void(*)(GLenum mode);
export using PFNGLFENCESYNCPROC = GLsync(*)(GLenum condition, GLbitfield flags);
export using PFNGLISSYNCPROC = GLboolean(*)(GLsync sync);
export using PFNGLDELETESYNCPROC = void(*)(GLsync sync);
export using PFNGLCLIENTWAITSYNCPROC = GLenum(*)(GLsync sync, GLbitfield flags, GLuint64 timeout);
export using PFNGLWAITSYNCPROC = void(*)(GLsync sync, GLbitfield flags, GLuint64 timeout);
export using PFNGLGETINTEGER64VPROC = void(*)(GLenum pname, GLint64* data);
export using PFNGLGETSYNCIVPROC = void(*)(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values);
export using PFNGLGETINTEGER64I_VPROC = void(*)(GLenum target, GLuint index, GLint64* data);
export using PFNGLGETBUFFERPARAMETERI64VPROC = void(*)(GLenum target, GLenum pname, GLint64* params);
export using PFNGLFRAMEBUFFERTEXTUREPROC = void(*)(GLenum target, GLenum attachment, GLuint texture, GLint level);
export using PFNGLTEXIMAGE2DMULTISAMPLEPROC = void(*)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
export using PFNGLTEXIMAGE3DMULTISAMPLEPROC = void(*)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
export using PFNGLGETMULTISAMPLEFVPROC = void(*)(GLenum pname, GLuint index, GLfloat* val);
export using PFNGLSAMPLEMASKIPROC = void(*)(GLuint maskNumber, GLbitfield mask);

// Declare function pointers as variables
export PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex = nullptr;
export PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex = nullptr;
export PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex = nullptr;
export PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex = nullptr;
export PFNGLPROVOKINGVERTEXPROC glProvokingVertex = nullptr;
export PFNGLFENCESYNCPROC glFenceSync = nullptr;
export PFNGLISSYNCPROC glIsSync = nullptr;
export PFNGLDELETESYNCPROC glDeleteSync = nullptr;
export PFNGLCLIENTWAITSYNCPROC glClientWaitSync = nullptr;
export PFNGLWAITSYNCPROC glWaitSync = nullptr;
export PFNGLGETINTEGER64VPROC glGetInteger64v = nullptr;
export PFNGLGETSYNCIVPROC glGetSynciv = nullptr;
export PFNGLGETINTEGER64I_VPROC glGetInteger64i_v = nullptr;
export PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v = nullptr;
export PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture = nullptr;
export PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample = nullptr;
export PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample = nullptr;
export PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv = nullptr;
export PFNGLSAMPLEMASKIPROC glSampleMaski = nullptr;

export namespace GLAD_3_2 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glDrawElementsBaseVertex = gladLoadFunction<PFNGLDRAWELEMENTSBASEVERTEXPROC>("glDrawElementsBaseVertex", load);
		glDrawRangeElementsBaseVertex = gladLoadFunction<PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC>("glDrawRangeElementsBaseVertex", load);
		glDrawElementsInstancedBaseVertex = gladLoadFunction<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC>("glDrawElementsInstancedBaseVertex", load);
		glMultiDrawElementsBaseVertex = gladLoadFunction<PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC>("glMultiDrawElementsBaseVertex", load);
		glProvokingVertex = gladLoadFunction<PFNGLPROVOKINGVERTEXPROC>("glProvokingVertex", load);
		glFenceSync = gladLoadFunction<PFNGLFENCESYNCPROC>("glFenceSync", load);
		glIsSync = gladLoadFunction<PFNGLISSYNCPROC>("glIsSync", load);
		glDeleteSync = gladLoadFunction<PFNGLDELETESYNCPROC>("glDeleteSync", load);
		glClientWaitSync = gladLoadFunction<PFNGLCLIENTWAITSYNCPROC>("glClientWaitSync", load);
		glWaitSync = gladLoadFunction<PFNGLWAITSYNCPROC>("glWaitSync", load);
		glGetInteger64v = gladLoadFunction<PFNGLGETINTEGER64VPROC>("glGetInteger64v", load);
		glGetSynciv = gladLoadFunction<PFNGLGETSYNCIVPROC>("glGetSynciv", load);
		glGetInteger64i_v = gladLoadFunction<PFNGLGETINTEGER64I_VPROC>("glGetInteger64i_v", load);
		glGetBufferParameteri64v = gladLoadFunction<PFNGLGETBUFFERPARAMETERI64VPROC>("glGetBufferParameteri64v", load);
		glFramebufferTexture = gladLoadFunction<PFNGLFRAMEBUFFERTEXTUREPROC>("glFramebufferTexture", load);
		glTexImage2DMultisample = gladLoadFunction<PFNGLTEXIMAGE2DMULTISAMPLEPROC>("glTexImage2DMultisample", load);
		glTexImage3DMultisample = gladLoadFunction<PFNGLTEXIMAGE3DMULTISAMPLEPROC>("glTexImage3DMultisample", load);
		glGetMultisamplefv = gladLoadFunction<PFNGLGETMULTISAMPLEFVPROC>("glGetMultisamplefv", load);
		glSampleMaski = gladLoadFunction<PFNGLSAMPLEMASKIPROC>("glSampleMaski", load);

		GLAD_3_1::load_GL_RECURSIVE(load);
	}
}