export module GLAD:V3_2;

export import :V3_1;

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

	// Declare function pointers as variables
	PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex = nullptr;
	PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex = nullptr;
	PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex = nullptr;
	PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex = nullptr;
	PFNGLPROVOKINGVERTEXPROC glProvokingVertex = nullptr;
	PFNGLFENCESYNCPROC glFenceSync = nullptr;
	PFNGLISSYNCPROC glIsSync = nullptr;
	PFNGLDELETESYNCPROC glDeleteSync = nullptr;
	PFNGLCLIENTWAITSYNCPROC glClientWaitSync = nullptr;
	PFNGLWAITSYNCPROC glWaitSync = nullptr;
	PFNGLGETINTEGER64VPROC glGetInteger64v = nullptr;
	PFNGLGETSYNCIVPROC glGetSynciv = nullptr;
	PFNGLGETINTEGER64I_VPROC glGetInteger64i_v = nullptr;
	PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v = nullptr;
	PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture = nullptr;
	PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample = nullptr;
	PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample = nullptr;
	PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv = nullptr;
	PFNGLSAMPLEMASKIPROC glSampleMaski = nullptr;

	namespace GLAD_3_2 {
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

			GLAD::GLAD_3_1::load_GL_RECURSIVE(load);
		}
	}
}