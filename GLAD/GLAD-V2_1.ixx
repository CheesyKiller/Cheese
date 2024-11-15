export module GLAD:V2_1;

export import :V2_0;

// Alias for function pointer types
export using PFNGLUNIFORMMATRIX2X3FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLUNIFORMMATRIX3X2FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLUNIFORMMATRIX2X4FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLUNIFORMMATRIX4X2FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLUNIFORMMATRIX3X4FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export using PFNGLUNIFORMMATRIX4X3FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);

// Declare function pointers as variables
export PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv = nullptr;
export PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv = nullptr;
export PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv = nullptr;
export PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv = nullptr;
export PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv = nullptr;
export PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv = nullptr;

export namespace GLAD_2_1 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glUniformMatrix2x3fv = gladLoadFunction<PFNGLUNIFORMMATRIX2X3FVPROC>("glUniformMatrix2x3fv", load);
		glUniformMatrix3x2fv = gladLoadFunction<PFNGLUNIFORMMATRIX3X2FVPROC>("glUniformMatrix3x2fv", load);
		glUniformMatrix2x4fv = gladLoadFunction<PFNGLUNIFORMMATRIX2X4FVPROC>("glUniformMatrix2x4fv", load);
		glUniformMatrix4x2fv = gladLoadFunction<PFNGLUNIFORMMATRIX4X2FVPROC>("glUniformMatrix4x2fv", load);
		glUniformMatrix3x4fv = gladLoadFunction<PFNGLUNIFORMMATRIX3X4FVPROC>("glUniformMatrix3x4fv", load);
		glUniformMatrix4x3fv = gladLoadFunction<PFNGLUNIFORMMATRIX4X3FVPROC>("glUniformMatrix4x3fv", load);

		GLAD_2_0::load_GL_RECURSIVE(load);
	}
}