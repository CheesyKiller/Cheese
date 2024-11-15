export module GLAD:V4_4;

export import :V4_3;

export using PFNGLBUFFERSTORAGEPROC = void(*)(GLenum target, GLsizeiptr size, const void* data, GLbitfield flags);
export using PFNGLCLEARTEXIMAGEPROC = void(*)(GLuint texture, GLint level, GLenum format, GLenum type, const void* data);
export using PFNGLCLEARTEXSUBIMAGEPROC = void(*)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data);
export using PFNGLBINDBUFFERSBASEPROC = void(*)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers);
export using PFNGLBINDBUFFERSRANGEPROC = void(*)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes);
export using PFNGLBINDTEXTURESPROC = void(*)(GLuint first, GLsizei count, const GLuint* textures);
export using PFNGLBINDSAMPLERSPROC = void(*)(GLuint first, GLsizei count, const GLuint* samplers);
export using PFNGLBINDIMAGETEXTURESPROC = void(*)(GLuint first, GLsizei count, const GLuint* textures);
export using PFNGLBINDVERTEXBUFFERSPROC = void(*)(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);

// Export the function pointers
export PFNGLBUFFERSTORAGEPROC glBufferStorage = nullptr;
export PFNGLCLEARTEXIMAGEPROC glClearTexImage = nullptr;
export PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage = nullptr;
export PFNGLBINDBUFFERSBASEPROC glBindBuffersBase = nullptr;
export PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange = nullptr;
export PFNGLBINDTEXTURESPROC glBindTextures = nullptr;
export PFNGLBINDSAMPLERSPROC glBindSamplers = nullptr;
export PFNGLBINDIMAGETEXTURESPROC glBindImageTextures = nullptr;
export PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers = nullptr;

export namespace GLAD_4_4 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glBufferStorage = gladLoadFunction<PFNGLBUFFERSTORAGEPROC>("glBufferStorage", load);
		glClearTexImage = gladLoadFunction<PFNGLCLEARTEXIMAGEPROC>("glClearTexImage", load);
		glClearTexSubImage = gladLoadFunction<PFNGLCLEARTEXSUBIMAGEPROC>("glClearTexSubImage", load);
		glBindBuffersBase = gladLoadFunction<PFNGLBINDBUFFERSBASEPROC>("glBindBuffersBase", load);
		glBindBuffersRange = gladLoadFunction<PFNGLBINDBUFFERSRANGEPROC>("glBindBuffersRange", load);
		glBindTextures = gladLoadFunction<PFNGLBINDTEXTURESPROC>("glBindTextures", load);
		glBindSamplers = gladLoadFunction<PFNGLBINDSAMPLERSPROC>("glBindSamplers", load);
		glBindImageTextures = gladLoadFunction<PFNGLBINDIMAGETEXTURESPROC>("glBindImageTextures", load);
		glBindVertexBuffers = gladLoadFunction<PFNGLBINDVERTEXBUFFERSPROC>("glBindVertexBuffers", load);

		GLAD_4_3::load_GL_RECURSIVE(load);
	}
}