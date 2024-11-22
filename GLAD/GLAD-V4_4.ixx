export module GLAD:V4_4;

export import :V4_3;

export namespace GLAD {
	using PFNGLBUFFERSTORAGEPROC = void(*)(GLenum target, GLsizeiptr size, const void* data, GLbitfield flags);
	using PFNGLCLEARTEXIMAGEPROC = void(*)(GLuint texture, GLint level, GLenum format, GLenum type, const void* data);
	using PFNGLCLEARTEXSUBIMAGEPROC = void(*)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data);
	using PFNGLBINDBUFFERSBASEPROC = void(*)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers);
	using PFNGLBINDBUFFERSRANGEPROC = void(*)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes);
	using PFNGLBINDTEXTURESPROC = void(*)(GLuint first, GLsizei count, const GLuint* textures);
	using PFNGLBINDSAMPLERSPROC = void(*)(GLuint first, GLsizei count, const GLuint* samplers);
	using PFNGLBINDIMAGETEXTURESPROC = void(*)(GLuint first, GLsizei count, const GLuint* textures);
	using PFNGLBINDVERTEXBUFFERSPROC = void(*)(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);

	// Export the function pointers
	PFNGLBUFFERSTORAGEPROC glBufferStorage = nullptr;
	PFNGLCLEARTEXIMAGEPROC glClearTexImage = nullptr;
	PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage = nullptr;
	PFNGLBINDBUFFERSBASEPROC glBindBuffersBase = nullptr;
	PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange = nullptr;
	PFNGLBINDTEXTURESPROC glBindTextures = nullptr;
	PFNGLBINDSAMPLERSPROC glBindSamplers = nullptr;
	PFNGLBINDIMAGETEXTURESPROC glBindImageTextures = nullptr;
	PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers = nullptr;

	namespace GLAD_4_4 {
		void load_GL_RECURSIVE(GLADloadproc load) {
			glBufferStorage = GLAD::gladLoadFunction<PFNGLBUFFERSTORAGEPROC>("glBufferStorage", load);
			glClearTexImage = GLAD::gladLoadFunction<PFNGLCLEARTEXIMAGEPROC>("glClearTexImage", load);
			glClearTexSubImage = GLAD::gladLoadFunction<PFNGLCLEARTEXSUBIMAGEPROC>("glClearTexSubImage", load);
			glBindBuffersBase = GLAD::gladLoadFunction<PFNGLBINDBUFFERSBASEPROC>("glBindBuffersBase", load);
			glBindBuffersRange = GLAD::gladLoadFunction<PFNGLBINDBUFFERSRANGEPROC>("glBindBuffersRange", load);
			glBindTextures = GLAD::gladLoadFunction<PFNGLBINDTEXTURESPROC>("glBindTextures", load);
			glBindSamplers = GLAD::gladLoadFunction<PFNGLBINDSAMPLERSPROC>("glBindSamplers", load);
			glBindImageTextures = GLAD::gladLoadFunction<PFNGLBINDIMAGETEXTURESPROC>("glBindImageTextures", load);
			glBindVertexBuffers = GLAD::gladLoadFunction<PFNGLBINDVERTEXBUFFERSPROC>("glBindVertexBuffers", load);

			GLAD_4_3::load_GL_RECURSIVE(load);
		}
	}
}