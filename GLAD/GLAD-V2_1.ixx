export module GLAD:V2_1;

export import :V2_0;

export namespace GLAD {
	// Alias for function pointer types
	using PFNGLUNIFORMMATRIX2X3FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX3X2FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX2X4FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX4X2FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX3X4FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PFNGLUNIFORMMATRIX4X3FVPROC = void(*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);

	// Declare function pointers as variables
	PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv = nullptr;
	PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv = nullptr;
	PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv = nullptr;
	PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv = nullptr;
	PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv = nullptr;
	PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv = nullptr;

	namespace GLAD_2_1 {
		void load_GL_RECURSIVE(GLADloadproc load) {
			glUniformMatrix2x3fv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX2X3FVPROC>("glUniformMatrix2x3fv", load);
			glUniformMatrix3x2fv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX3X2FVPROC>("glUniformMatrix3x2fv", load);
			glUniformMatrix2x4fv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX2X4FVPROC>("glUniformMatrix2x4fv", load);
			glUniformMatrix4x2fv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX4X2FVPROC>("glUniformMatrix4x2fv", load);
			glUniformMatrix3x4fv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX3X4FVPROC>("glUniformMatrix3x4fv", load);
			glUniformMatrix4x3fv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX4X3FVPROC>("glUniformMatrix4x3fv", load);

			GLAD::GLAD_2_0::load_GL_RECURSIVE(load);
		}
	}
}