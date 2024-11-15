export module GLAD:V1_5;

export import :V1_4;

// Alias for function pointer types
export using PFNGLGENQUERIESPROC = void(*)(GLsizei n, GLuint* ids);
export using PFNGLDELETEQUERIESPROC = void(*)(GLsizei n, const GLuint* ids);
export using PFNGLISQUERYPROC = GLboolean(*)(GLuint id);
export using PFNGLBEGINQUERYPROC = void(*)(GLenum target, GLuint id);
export using PFNGLENDQUERYPROC = void(*)(GLenum target);
export using PFNGLGETQUERYIVPROC = void(*)(GLenum target, GLenum pname, GLint* params);
export using PFNGLGETQUERYOBJECTIVPROC = void(*)(GLuint id, GLenum pname, GLint* params);
export using PFNGLGETQUERYOBJECTUIVPROC = void(*)(GLuint id, GLenum pname, GLuint* params);
export using PFNGLBINDBUFFERPROC = void(*)(GLenum target, GLuint buffer);
export using PFNGLDELETEBUFFERSPROC = void(*)(GLsizei n, const GLuint* buffers);
export using PFNGLGENBUFFERSPROC = void(*)(GLsizei n, GLuint* buffers);
export using PFNGLISBUFFERPROC = GLboolean(*)(GLuint buffer);
export using PFNGLBUFFERDATAPROC = void(*)(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
export using PFNGLBUFFERSUBDATAPROC = void(*)(GLenum target, GLintptr offset, GLsizeiptr size, const void* data);
export using PFNGLGETBUFFERSUBDATAPROC = void(*)(GLenum target, GLintptr offset, GLsizeiptr size, void* data);
export using PFNGLMAPBUFFERPROC = void* (*)(GLenum target, GLenum access);
export using PFNGLUNMAPBUFFERPROC = GLboolean(*)(GLenum target);
export using PFNGLGETBUFFERPARAMETERIVPROC = void(*)(GLenum target, GLenum pname, GLint* params);
export using PFNGLGETBUFFERPOINTERVPROC = void(*)(GLenum target, GLenum pname, void** params);

// Declare function pointers as variables
export PFNGLGENQUERIESPROC glGenQueries = nullptr;
export PFNGLDELETEQUERIESPROC glDeleteQueries = nullptr;
export PFNGLISQUERYPROC glIsQuery = nullptr;
export PFNGLBEGINQUERYPROC glBeginQuery = nullptr;
export PFNGLENDQUERYPROC glEndQuery = nullptr;
export PFNGLGETQUERYIVPROC glGetQueryiv = nullptr;
export PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv = nullptr;
export PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv = nullptr;
export PFNGLBINDBUFFERPROC glBindBuffer = nullptr;
export PFNGLDELETEBUFFERSPROC glDeleteBuffers = nullptr;
export PFNGLGENBUFFERSPROC glGenBuffers = nullptr;
export PFNGLISBUFFERPROC glIsBuffer = nullptr;
export PFNGLBUFFERDATAPROC glBufferData = nullptr;
export PFNGLBUFFERSUBDATAPROC glBufferSubData = nullptr;
export PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData = nullptr;
export PFNGLMAPBUFFERPROC glMapBuffer = nullptr;
export PFNGLUNMAPBUFFERPROC glUnmapBuffer = nullptr;
export PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv = nullptr;
export PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv = nullptr;

export namespace GLAD_1_5 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glGenQueries = gladLoadFunction<PFNGLGENQUERIESPROC>("glGenQueries", load);
		glDeleteQueries = gladLoadFunction<PFNGLDELETEQUERIESPROC>("glDeleteQueries", load);
		glIsQuery = gladLoadFunction<PFNGLISQUERYPROC>("glIsQuery", load);
		glBeginQuery = gladLoadFunction<PFNGLBEGINQUERYPROC>("glBeginQuery", load);
		glEndQuery = gladLoadFunction<PFNGLENDQUERYPROC>("glEndQuery", load);
		glGetQueryiv = gladLoadFunction<PFNGLGETQUERYIVPROC>("glGetQueryiv", load);
		glGetQueryObjectiv = gladLoadFunction<PFNGLGETQUERYOBJECTIVPROC>("glGetQueryObjectiv", load);
		glGetQueryObjectuiv = gladLoadFunction<PFNGLGETQUERYOBJECTUIVPROC>("glGetQueryObjectuiv", load);
		glBindBuffer = gladLoadFunction<PFNGLBINDBUFFERPROC>("glBindBuffer", load);
		glDeleteBuffers = gladLoadFunction<PFNGLDELETEBUFFERSPROC>("glDeleteBuffers", load);
		glGenBuffers = gladLoadFunction<PFNGLGENBUFFERSPROC>("glGenBuffers", load);
		glIsBuffer = gladLoadFunction<PFNGLISBUFFERPROC>("glIsBuffer", load);
		glBufferData = gladLoadFunction<PFNGLBUFFERDATAPROC>("glBufferData", load);
		glBufferSubData = gladLoadFunction<PFNGLBUFFERSUBDATAPROC>("glBufferSubData", load);
		glGetBufferSubData = gladLoadFunction<PFNGLGETBUFFERSUBDATAPROC>("glGetBufferSubData", load);
		glMapBuffer = gladLoadFunction<PFNGLMAPBUFFERPROC>("glMapBuffer", load);
		glUnmapBuffer = gladLoadFunction<PFNGLUNMAPBUFFERPROC>("glUnmapBuffer", load);
		glGetBufferParameteriv = gladLoadFunction<PFNGLGETBUFFERPARAMETERIVPROC>("glGetBufferParameteriv", load);
		glGetBufferPointerv = gladLoadFunction<PFNGLGETBUFFERPOINTERVPROC>("glGetBufferPointerv", load);

		GLAD_1_4::load_GL_RECURSIVE(load);
	}
}