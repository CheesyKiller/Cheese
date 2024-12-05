import GLADBase;
import GLAD3;
import GLAD4;

namespace GLAD::V4_0 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glMinSampleShading = GLAD::gladLoadFunction<PFNGLMINSAMPLESHADINGPROC>("glMinSampleShading", load);
		glBlendEquationi = GLAD::gladLoadFunction<PFNGLBLENDEQUATIONIPROC>("glBlendEquationi", load);
		glBlendEquationSeparatei = GLAD::gladLoadFunction<PFNGLBLENDEQUATIONSEPARATEIPROC>("glBlendEquationSeparatei", load);
		glBlendFunci = GLAD::gladLoadFunction<PFNGLBLENDFUNCIPROC>("glBlendFunci", load);
		glBlendFuncSeparatei = GLAD::gladLoadFunction<PFNGLBLENDFUNCSEPARATEIPROC>("glBlendFuncSeparatei", load);
		glDrawArraysIndirect = GLAD::gladLoadFunction<PFNGLDRAWARRAYSINDIRECTPROC>("glDrawArraysIndirect", load);
		glDrawElementsIndirect = GLAD::gladLoadFunction<PFNGLDRAWELEMENTSINDIRECTPROC>("glDrawElementsIndirect", load);
		glUniform1d = GLAD::gladLoadFunction<PFNGLUNIFORM1DPROC>("glUniform1d", load);
		glUniform2d = GLAD::gladLoadFunction<PFNGLUNIFORM2DPROC>("glUniform2d", load);
		glUniform3d = GLAD::gladLoadFunction<PFNGLUNIFORM3DPROC>("glUniform3d", load);
		glUniform4d = GLAD::gladLoadFunction<PFNGLUNIFORM4DPROC>("glUniform4d", load);
		glUniform1dv = GLAD::gladLoadFunction<PFNGLUNIFORM1DVPROC>("glUniform1dv", load);
		glUniform2dv = GLAD::gladLoadFunction<PFNGLUNIFORM2DVPROC>("glUniform2dv", load);
		glUniform3dv = GLAD::gladLoadFunction<PFNGLUNIFORM3DVPROC>("glUniform3dv", load);
		glUniform4dv = GLAD::gladLoadFunction<PFNGLUNIFORM4DVPROC>("glUniform4dv", load);
		glUniformMatrix2dv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX2DVPROC>("glUniformMatrix2dv", load);
		glUniformMatrix3dv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX3DVPROC>("glUniformMatrix3dv", load);
		glUniformMatrix4dv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX4DVPROC>("glUniformMatrix4dv", load);
		glUniformMatrix2x3dv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX2X3DVPROC>("glUniformMatrix2x3dv", load);
		glUniformMatrix2x4dv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX2X4DVPROC>("glUniformMatrix2x4dv", load);
		glUniformMatrix3x2dv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX3X2DVPROC>("glUniformMatrix3x2dv", load);
		glUniformMatrix3x4dv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX3X4DVPROC>("glUniformMatrix3x4dv", load);
		glUniformMatrix4x2dv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX4X2DVPROC>("glUniformMatrix4x2dv", load);
		glUniformMatrix4x3dv = GLAD::gladLoadFunction<PFNGLUNIFORMMATRIX4X3DVPROC>("glUniformMatrix4x3dv", load);
		glGetUniformdv = GLAD::gladLoadFunction<PFNGLGETUNIFORMDVPROC>("glGetUniformdv", load);
		glGetSubroutineUniformLocation = GLAD::gladLoadFunction<PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC>("glGetSubroutineUniformLocation", load);
		glGetSubroutineIndex = GLAD::gladLoadFunction<PFNGLGETSUBROUTINEINDEXPROC>("glGetSubroutineIndex", load);
		glGetActiveSubroutineUniformiv = GLAD::gladLoadFunction<PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC>("glGetActiveSubroutineUniformiv", load);
		glGetActiveSubroutineUniformName = GLAD::gladLoadFunction<PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC>("glGetActiveSubroutineUniformName", load);
		glGetActiveSubroutineName = GLAD::gladLoadFunction<PFNGLGETACTIVESUBROUTINENAMEPROC>("glGetActiveSubroutineName", load);
		glUniformSubroutinesuiv = GLAD::gladLoadFunction<PFNGLUNIFORMSUBROUTINESUIVPROC>("glUniformSubroutinesuiv", load);
		glGetUniformSubroutineuiv = GLAD::gladLoadFunction<PFNGLGETUNIFORMSUBROUTINEUIVPROC>("glGetUniformSubroutineuiv", load);
		glGetProgramStageiv = GLAD::gladLoadFunction<PFNGLGETPROGRAMSTAGEIVPROC>("glGetProgramStageiv", load);
		glPatchParameteri = GLAD::gladLoadFunction<PFNGLPATCHPARAMETERIPROC>("glPatchParameteri", load);
		glPatchParameterfv = GLAD::gladLoadFunction<PFNGLPATCHPARAMETERFVPROC>("glPatchParameterfv", load);
		glBindTransformFeedback = GLAD::gladLoadFunction<PFNGLBINDTRANSFORMFEEDBACKPROC>("glBindTransformFeedback", load);
		glDeleteTransformFeedbacks = GLAD::gladLoadFunction<PFNGLDELETETRANSFORMFEEDBACKSPROC>("glDeleteTransformFeedbacks", load);
		glGenTransformFeedbacks = GLAD::gladLoadFunction<PFNGLGENTRANSFORMFEEDBACKSPROC>("glGenTransformFeedbacks", load);
		glIsTransformFeedback = GLAD::gladLoadFunction<PFNGLISTRANSFORMFEEDBACKPROC>("glIsTransformFeedback", load);
		glPauseTransformFeedback = GLAD::gladLoadFunction<PFNGLPAUSETRANSFORMFEEDBACKPROC>("glPauseTransformFeedback", load);
		glResumeTransformFeedback = GLAD::gladLoadFunction<PFNGLRESUMETRANSFORMFEEDBACKPROC>("glResumeTransformFeedback", load);
		glDrawTransformFeedback = GLAD::gladLoadFunction<PFNGLDRAWTRANSFORMFEEDBACKPROC>("glDrawTransformFeedback", load);
		glDrawTransformFeedbackStream = GLAD::gladLoadFunction<PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC>("glDrawTransformFeedbackStream", load);
		glBeginQueryIndexed = GLAD::gladLoadFunction<PFNGLBEGINQUERYINDEXEDPROC>("glBeginQueryIndexed", load);
		glEndQueryIndexed = GLAD::gladLoadFunction<PFNGLENDQUERYINDEXEDPROC>("glEndQueryIndexed", load);
		glGetQueryIndexediv = GLAD::gladLoadFunction<PFNGLGETQUERYINDEXEDIVPROC>("glGetQueryIndexediv", load);

		GLAD::V3_3::load_GL_RECURSIVE(load);
	}
}