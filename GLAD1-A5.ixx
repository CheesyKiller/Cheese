export module GLAD1:A5;

import GLADTypes;

export namespace GLAD {
	// Alias for function pointer types
	using PFNGLGENQUERIESPROC = void(*)(GLsizei n, GLuint* ids);
	using PFNGLDELETEQUERIESPROC = void(*)(GLsizei n, const GLuint* ids);
	using PFNGLISQUERYPROC = GLboolean(*)(GLuint id);
	using PFNGLBEGINQUERYPROC = void(*)(GLenum target, GLuint id);
	using PFNGLENDQUERYPROC = void(*)(GLenum target);
	using PFNGLGETQUERYIVPROC = void(*)(GLenum target, GLenum pname, GLint* params);
	using PFNGLGETQUERYOBJECTIVPROC = void(*)(GLuint id, GLenum pname, GLint* params);
	using PFNGLGETQUERYOBJECTUIVPROC = void(*)(GLuint id, GLenum pname, GLuint* params);
	using PFNGLBINDBUFFERPROC = void(*)(GLenum target, GLuint buffer);
	using PFNGLDELETEBUFFERSPROC = void(*)(GLsizei n, const GLuint* buffers);
	using PFNGLGENBUFFERSPROC = void(*)(GLsizei n, GLuint* buffers);
	using PFNGLISBUFFERPROC = GLboolean(*)(GLuint buffer);
	using PFNGLBUFFERDATAPROC = void(*)(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
	using PFNGLBUFFERSUBDATAPROC = void(*)(GLenum target, GLintptr offset, GLsizeiptr size, const void* data);
	using PFNGLGETBUFFERSUBDATAPROC = void(*)(GLenum target, GLintptr offset, GLsizeiptr size, void* data);
	using PFNGLMAPBUFFERPROC = void* (*)(GLenum target, GLenum access);
	using PFNGLUNMAPBUFFERPROC = GLboolean(*)(GLenum target);
	using PFNGLGETBUFFERPARAMETERIVPROC = void(*)(GLenum target, GLenum pname, GLint* params);
	using PFNGLGETBUFFERPOINTERVPROC = void(*)(GLenum target, GLenum pname, void** params);
}