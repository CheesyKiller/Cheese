import GLADBase;
import GLAD1;

namespace GLAD::V1_5 {
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

		GLAD::V1_4::load_GL_RECURSIVE(load);
	}
}