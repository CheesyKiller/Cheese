export module GLAD4:A4;

import GLADTypes;

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
}