export module GLAD:V1_5;

export import :V1_4;

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

	// Declare function pointers as variables
	PFNGLGENQUERIESPROC glGenQueries = nullptr;
	PFNGLDELETEQUERIESPROC glDeleteQueries = nullptr;
	PFNGLISQUERYPROC glIsQuery = nullptr;
	PFNGLBEGINQUERYPROC glBeginQuery = nullptr;
	PFNGLENDQUERYPROC glEndQuery = nullptr;
	PFNGLGETQUERYIVPROC glGetQueryiv = nullptr;
	PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv = nullptr;
	PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv = nullptr;
	PFNGLBINDBUFFERPROC glBindBuffer = nullptr;
	PFNGLDELETEBUFFERSPROC glDeleteBuffers = nullptr;
	PFNGLGENBUFFERSPROC glGenBuffers = nullptr;
	PFNGLISBUFFERPROC glIsBuffer = nullptr;
	PFNGLBUFFERDATAPROC glBufferData = nullptr;
	PFNGLBUFFERSUBDATAPROC glBufferSubData = nullptr;
	PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData = nullptr;
	PFNGLMAPBUFFERPROC glMapBuffer = nullptr;
	PFNGLUNMAPBUFFERPROC glUnmapBuffer = nullptr;
	PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv = nullptr;
	PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv = nullptr;

	namespace GLAD_1_5 {
		void load_GL_RECURSIVE(GLADloadproc load) {
			glGenQueries = GLAD::gladLoadFunction<PFNGLGENQUERIESPROC>("glGenQueries", load);
			glDeleteQueries = GLAD::gladLoadFunction<PFNGLDELETEQUERIESPROC>("glDeleteQueries", load);
			glIsQuery = GLAD::gladLoadFunction<PFNGLISQUERYPROC>("glIsQuery", load);
			glBeginQuery = GLAD::gladLoadFunction<PFNGLBEGINQUERYPROC>("glBeginQuery", load);
			glEndQuery = GLAD::gladLoadFunction<PFNGLENDQUERYPROC>("glEndQuery", load);
			glGetQueryiv = GLAD::gladLoadFunction<PFNGLGETQUERYIVPROC>("glGetQueryiv", load);
			glGetQueryObjectiv = GLAD::gladLoadFunction<PFNGLGETQUERYOBJECTIVPROC>("glGetQueryObjectiv", load);
			glGetQueryObjectuiv = GLAD::gladLoadFunction<PFNGLGETQUERYOBJECTUIVPROC>("glGetQueryObjectuiv", load);
			glBindBuffer = GLAD::gladLoadFunction<PFNGLBINDBUFFERPROC>("glBindBuffer", load);
			glDeleteBuffers = GLAD::gladLoadFunction<PFNGLDELETEBUFFERSPROC>("glDeleteBuffers", load);
			glGenBuffers = GLAD::gladLoadFunction<PFNGLGENBUFFERSPROC>("glGenBuffers", load);
			glIsBuffer = GLAD::gladLoadFunction<PFNGLISBUFFERPROC>("glIsBuffer", load);
			glBufferData = GLAD::gladLoadFunction<PFNGLBUFFERDATAPROC>("glBufferData", load);
			glBufferSubData = GLAD::gladLoadFunction<PFNGLBUFFERSUBDATAPROC>("glBufferSubData", load);
			glGetBufferSubData = GLAD::gladLoadFunction<PFNGLGETBUFFERSUBDATAPROC>("glGetBufferSubData", load);
			glMapBuffer = GLAD::gladLoadFunction<PFNGLMAPBUFFERPROC>("glMapBuffer", load);
			glUnmapBuffer = GLAD::gladLoadFunction<PFNGLUNMAPBUFFERPROC>("glUnmapBuffer", load);
			glGetBufferParameteriv = GLAD::gladLoadFunction<PFNGLGETBUFFERPARAMETERIVPROC>("glGetBufferParameteriv", load);
			glGetBufferPointerv = GLAD::gladLoadFunction<PFNGLGETBUFFERPOINTERVPROC>("glGetBufferPointerv", load);

			GLAD::GLAD_1_4::load_GL_RECURSIVE(load);
		}
	}
}