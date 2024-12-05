import GLADBase;
import GLAD2;

namespace GLAD::V2_1 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glUniformMatrix2x3fv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX2X3FVPROC>("glUniformMatrix2x3fv", load);
		glUniformMatrix3x2fv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX3X2FVPROC>("glUniformMatrix3x2fv", load);
		glUniformMatrix2x4fv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX2X4FVPROC>("glUniformMatrix2x4fv", load);
		glUniformMatrix4x2fv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX4X2FVPROC>("glUniformMatrix4x2fv", load);
		glUniformMatrix3x4fv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX3X4FVPROC>("glUniformMatrix3x4fv", load);
		glUniformMatrix4x3fv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX4X3FVPROC>("glUniformMatrix4x3fv", load);

		GLAD::V2_0::load_GL_RECURSIVE(load);
	}
}