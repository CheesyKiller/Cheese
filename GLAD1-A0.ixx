export module GLAD1:A0;

import GLADTypes;

export namespace GLAD {
	// Alias for function pointer types
	using PFNGLCULLFACEPROC = void(*)(GLenum mode);
	using PFNGLFRONTFACEPROC = void(*)(GLenum mode);
	using PFNGLHINTPROC = void(*)(GLenum target, GLenum mode);
	using PFNGLLINEWIDTHPROC = void(*)(GLfloat width);
	using PFNGLPOINTSIZEPROC = void(*)(GLfloat size);
	using PFNGLPOLYGONMODEPROC = void(*)(GLenum face, GLenum mode);
	using PFNGLSCISSORPROC = void(*)(GLint x, GLint y, GLsizei width, GLsizei height);
	using PFNGLTEXPARAMETERFPROC = void(*)(GLenum target, GLenum pname, GLfloat param);
	using PFNGLTEXPARAMETERFVPROC = void(*)(GLenum target, GLenum pname, const GLfloat* params);
	using PFNGLTEXPARAMETERIPROC = void(*)(GLenum target, GLenum pname, GLint param);
	using PFNGLTEXPARAMETERIVPROC = void(*)(GLenum target, GLenum pname, const GLint* params);
	using PFNGLTEXIMAGE1DPROC = void(*)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels);
	using PFNGLTEXIMAGE2DPROC = void(*)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels);
	using PFNGLDRAWBUFFERPROC = void(*)(GLenum buf);
	using PFNGLCLEARPROC = void(*)(GLbitfield mask);
	using PFNGLCLEARCOLORPROC = void(*)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	using PFNGLCLEARSTENCILPROC = void(*)(GLint s);
	using PFNGLCLEARDEPTHPROC = void(*)(GLdouble depth);
	using PFNGLSTENCILMASKPROC = void(*)(GLuint mask);
	using PFNGLCOLORMASKPROC = void(*)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
	using PFNGLDEPTHMASKPROC = void(*)(GLboolean flag);
	using PFNGLDISABLEPROC = void(*)(GLenum cap);
	using PFNGLENABLEPROC = void(*)(GLenum cap);
	using PFNGLFINISHPROC = void(*)(void);
	using PFNGLFLUSHPROC = void(*)(void);
	using PFNGLBLENDFUNCPROC = void(*)(GLenum sfactor, GLenum dfactor);
	using PFNGLLOGICOPPROC = void(*)(GLenum opcode);
	using PFNGLSTENCILFUNCPROC = void(*)(GLenum func, GLint ref, GLuint mask);
	using PFNGLSTENCILOPPROC = void(*)(GLenum fail, GLenum zfail, GLenum zpass);
	using PFNGLDEPTHFUNCPROC = void(*)(GLenum func);
	using PFNGLPIXELSTOREFPROC = void(*)(GLenum pname, GLfloat param);
	using PFNGLPIXELSTOREIPROC = void(*)(GLenum pname, GLint param);
	using PFNGLREADBUFFERPROC = void(*)(GLenum src);
	using PFNGLREADPIXELSPROC = void(*)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels);
	using PFNGLGETBOOLEANVPROC = void(*)(GLenum pname, GLboolean* data);
	using PFNGLGETDOUBLEVPROC = void(*)(GLenum pname, GLdouble* data);
	using PFNGLGETERRORPROC = GLenum(*)(void);
	using PFNGLGETFLOATVPROC = void(*)(GLenum pname, GLfloat* data);
	using PFNGLGETINTEGERVPROC = void(*)(GLenum pname, GLint* data);
	using PFNGLGETSTRINGPROC = const GLubyte* (*)(GLenum name);
	using PFNGLGETTEXIMAGEPROC = void(*)(GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
	using PFNGLGETTEXPARAMETERFVPROC = void(*)(GLenum target, GLenum pname, GLfloat* params);
	using PFNGLGETTEXPARAMETERIVPROC = void(*)(GLenum target, GLenum pname, GLint* params);
	using PFNGLGETTEXLEVELPARAMETERFVPROC = void(*)(GLenum target, GLint level, GLenum pname, GLfloat* params);
	using PFNGLGETTEXLEVELPARAMETERIVPROC = void(*)(GLenum target, GLint level, GLenum pname, GLint* params);
	using PFNGLISENABLEDPROC = GLboolean(*)(GLenum cap);
	using PFNGLDEPTHRANGEPROC = void(*)(GLdouble n, GLdouble f);
	using PFNGLVIEWPORTPROC = void(*)(GLint x, GLint y, GLsizei width, GLsizei height);
}