export module GLAD2:A1;

import GLADTypes;

export namespace GLAD {
	// Alias for function pointer types
	using PFNGLUNIFORMMATRIX2X3FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX3X2FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX2X4FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX4X2FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX3X4FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX4X3FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
}