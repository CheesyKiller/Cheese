export module GLAD1:V5;

import GLADBase;
import :A5;

export namespace GLAD {
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

	namespace V1_5 {
		void load_GL_RECURSIVE(GLADloadproc load);
	}
}