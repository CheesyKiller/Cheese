export module GLAD4:V0;

import GLADBase;
import :A0;

export namespace GLAD {
	// Declare function pointers as variables
	PFNGLMINSAMPLESHADINGPROC glMinSampleShading = nullptr;
	PFNGLBLENDEQUATIONIPROC glBlendEquationi = nullptr;
	PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei = nullptr;
	PFNGLBLENDFUNCIPROC glBlendFunci = nullptr;
	PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei = nullptr;
	PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect = nullptr;
	PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect = nullptr;
	PFNGLUNIFORM1DPROC glUniform1d = nullptr;
	PFNGLUNIFORM2DPROC glUniform2d = nullptr;
	PFNGLUNIFORM3DPROC glUniform3d = nullptr;
	PFNGLUNIFORM4DPROC glUniform4d = nullptr;
	PFNGLUNIFORM1DVPROC glUniform1dv = nullptr;
	PFNGLUNIFORM2DVPROC glUniform2dv = nullptr;
	PFNGLUNIFORM3DVPROC glUniform3dv = nullptr;
	PFNGLUNIFORM4DVPROC glUniform4dv = nullptr;
	PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv = nullptr;
	PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv = nullptr;
	PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv = nullptr;
	PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv = nullptr;
	PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv = nullptr;
	PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv = nullptr;
	PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv = nullptr;
	PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv = nullptr;
	PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv = nullptr;
	PFNGLGETUNIFORMDVPROC glGetUniformdv = nullptr;
	PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation = nullptr;
	PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex = nullptr;
	PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv = nullptr;
	PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName = nullptr;
	PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName = nullptr;
	PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv = nullptr;
	PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv = nullptr;
	PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv = nullptr;
	PFNGLPATCHPARAMETERIPROC glPatchParameteri = nullptr;
	PFNGLPATCHPARAMETERFVPROC glPatchParameterfv = nullptr;
	PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback = nullptr;
	PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks = nullptr;
	PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks = nullptr;
	PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback = nullptr;
	PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback = nullptr;
	PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback = nullptr;
	PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback = nullptr;
	PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream = nullptr;
	PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed = nullptr;
	PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed = nullptr;
	PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv = nullptr;

	namespace V4_0 {
		void load_GL_RECURSIVE(GLADloadproc load);
	}
}