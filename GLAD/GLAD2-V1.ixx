export module GLAD2:V1;

import GLADBase;
import :A1;

export namespace GLAD {
	// Declare function pointers as variables
	PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv = nullptr;
	PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv = nullptr;
	PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv = nullptr;
	PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv = nullptr;
	PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv = nullptr;
	PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv = nullptr;

	namespace V2_1 {
		void load_GL_RECURSIVE(GLADloadproc load);
	}
}