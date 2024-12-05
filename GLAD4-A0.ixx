export module GLAD4:A0;

import GLADTypes;

export namespace GLAD {
	// Alias for function pointer types
	using PFNGLMINSAMPLESHADINGPROC = void(*)(GLfloat value);
	using PFNGLBLENDEQUATIONIPROC = void(*)(GLuint buf, GLenum mode);
	using PFNGLBLENDEQUATIONSEPARATEIPROC = void(*)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
	using PFNGLBLENDFUNCIPROC = void(*)(GLuint buf, GLenum src, GLenum dst);
	using PFNGLBLENDFUNCSEPARATEIPROC = void(*)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
	using PFNGLDRAWARRAYSINDIRECTPROC = void(*)(GLenum mode, const void* indirect);
	using PFNGLDRAWELEMENTSINDIRECTPROC = void(*)(GLenum mode, GLenum type, const void* indirect);
	using PFNGLUNIFORM1DPROC = void(*)(GLint location, GLdouble x);
	using PFNGLUNIFORM2DPROC = void(*)(GLint location, GLdouble x, GLdouble y);
	using PFNGLUNIFORM3DPROC = void(*)(GLint location, GLdouble x, GLdouble y, GLdouble z);
	using PFNGLUNIFORM4DPROC = void(*)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	using PFNGLUNIFORM1DVPROC = void(*)(GLint location, GLsizei count, const GLdouble* value);
	using PFNGLUNIFORM2DVPROC = void(*)(GLint location, GLsizei count, const GLdouble* value);
	using PFNGLUNIFORM3DVPROC = void(*)(GLint location, GLsizei count, const GLdouble* value);
	using PFNGLUNIFORM4DVPROC = void(*)(GLint location, GLsizei count, const GLdouble* value);
	using PFNGLUNIFORMMATRIX2DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PFNGLUNIFORMMATRIX3DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PFNGLUNIFORMMATRIX4DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PFNGLUNIFORMMATRIX2X3DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PFNGLUNIFORMMATRIX2X4DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PFNGLUNIFORMMATRIX3X2DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PFNGLUNIFORMMATRIX3X4DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PFNGLUNIFORMMATRIX4X2DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PFNGLUNIFORMMATRIX4X3DVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PFNGLGETUNIFORMDVPROC = void(*)(GLuint program, GLint location, GLdouble* params);
	using PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC = GLint(*)(GLuint program, GLenum shadertype, const GLchar* name);
	using PFNGLGETSUBROUTINEINDEXPROC = GLuint(*)(GLuint program, GLenum shadertype, const GLchar* name);
	using PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC = void(*)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values);
	using PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC = void(*)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
	using PFNGLGETACTIVESUBROUTINENAMEPROC = void(*)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
	using PFNGLUNIFORMSUBROUTINESUIVPROC = void(*)(GLenum shadertype, GLsizei count, const GLuint* indices);
	using PFNGLGETUNIFORMSUBROUTINEUIVPROC = void(*)(GLenum shadertype, GLint location, GLuint* params);
	using PFNGLGETPROGRAMSTAGEIVPROC = void(*)(GLuint program, GLenum shadertype, GLenum pname, GLint* values);
	using PFNGLPATCHPARAMETERIPROC = void(*)(GLenum pname, GLint value);
	using PFNGLPATCHPARAMETERFVPROC = void(*)(GLenum pname, const GLfloat* values);
	using PFNGLBINDTRANSFORMFEEDBACKPROC = void(*)(GLenum target, GLuint id);
	using PFNGLDELETETRANSFORMFEEDBACKSPROC = void(*)(GLsizei n, const GLuint* ids);
	using PFNGLGENTRANSFORMFEEDBACKSPROC = void(*)(GLsizei n, GLuint* ids);
	using PFNGLISTRANSFORMFEEDBACKPROC = GLboolean(*)(GLuint id);
	using PFNGLPAUSETRANSFORMFEEDBACKPROC = void(*)();
	using PFNGLRESUMETRANSFORMFEEDBACKPROC = void(*)();
	using PFNGLDRAWTRANSFORMFEEDBACKPROC = void(*)(GLenum mode, GLuint id);
	using PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC = void(*)(GLenum mode, GLuint id, GLuint stream);
	using PFNGLBEGINQUERYINDEXEDPROC = void(*)(GLenum target, GLuint index, GLuint id);
	using PFNGLENDQUERYINDEXEDPROC = void(*)(GLenum target, GLuint index);
	using PFNGLGETQUERYINDEXEDIVPROC = void(*)(GLenum target, GLuint index, GLenum pname, GLint* params);
}