export module GLAD4:A6;

import GLADTypes;

export namespace GLAD {
	using PFNGLSPECIALIZESHADERPROC = void (*)(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue);
	using PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC = void (*)(GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
	using PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC = void (*)(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
	using PFNGLPOLYGONOFFSETCLAMPPROC = void (*)(GLfloat factor, GLfloat units, GLfloat clamp);
}