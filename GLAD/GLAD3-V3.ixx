export module GLAD3:V3;

import GLADBase;
import :A3;

export namespace GLAD {
	// Declare function pointers as variables
	PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed = nullptr;
	PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex = nullptr;
	PFNGLGENSAMPLERSPROC glGenSamplers = nullptr;
	PFNGLDELETESAMPLERSPROC glDeleteSamplers = nullptr;
	PFNGLISSAMPLERPROC glIsSampler = nullptr;
	PFNGLBINDSAMPLERPROC glBindSampler = nullptr;
	PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri = nullptr;
	PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv = nullptr;
	PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf = nullptr;
	PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv = nullptr;
	PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv = nullptr;
	PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv = nullptr;
	PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv = nullptr;
	PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv = nullptr;
	PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv = nullptr;
	PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv = nullptr;
	PFNGLQUERYCOUNTERPROC glQueryCounter = nullptr;
	PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v = nullptr;
	PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v = nullptr;
	PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor = nullptr;
	PFNGLVERTEXATTRIBP1UIPROC glVertexAttribP1ui = nullptr;
	PFNGLVERTEXATTRIBP1UIVPROC glVertexAttribP1uiv = nullptr;
	PFNGLVERTEXATTRIBP2UIPROC glVertexAttribP2ui = nullptr;
	PFNGLVERTEXATTRIBP2UIVPROC glVertexAttribP2uiv = nullptr;
	PFNGLVERTEXATTRIBP3UIPROC glVertexAttribP3ui = nullptr;
	PFNGLVERTEXATTRIBP3UIVPROC glVertexAttribP3uiv = nullptr;
	PFNGLVERTEXATTRIBP4UIPROC glVertexAttribP4ui = nullptr;
	PFNGLVERTEXATTRIBP4UIVPROC glVertexAttribP4uiv = nullptr;
	PFNGLVERTEXP2UIPROC glVertexP2ui = nullptr;
	PFNGLVERTEXP2UIVPROC glVertexP2uiv = nullptr;
	PFNGLVERTEXP3UIPROC glVertexP3ui = nullptr;
	PFNGLVERTEXP3UIVPROC glVertexP3uiv = nullptr;
	PFNGLVERTEXP4UIPROC glVertexP4ui = nullptr;
	PFNGLVERTEXP4UIVPROC glVertexP4uiv = nullptr;
	PFNGLTEXCOORDP1UIPROC glTexCoordP1ui = nullptr;
	PFNGLTEXCOORDP1UIVPROC glTexCoordP1uiv = nullptr;
	PFNGLTEXCOORDP2UIPROC glTexCoordP2ui = nullptr;
	PFNGLTEXCOORDP2UIVPROC glTexCoordP2uiv = nullptr;
	PFNGLTEXCOORDP3UIPROC glTexCoordP3ui = nullptr;
	PFNGLTEXCOORDP3UIVPROC glTexCoordP3uiv = nullptr;
	PFNGLTEXCOORDP4UIPROC glTexCoordP4ui = nullptr;
	PFNGLTEXCOORDP4UIVPROC glTexCoordP4uiv = nullptr;
	PFNGLMULTITEXCOORDP1UIPROC glMultiTexCoordP1ui = nullptr;
	PFNGLMULTITEXCOORDP1UIVPROC glMultiTexCoordP1uiv = nullptr;
	PFNGLMULTITEXCOORDP2UIPROC glMultiTexCoordP2ui = nullptr;
	PFNGLMULTITEXCOORDP2UIVPROC glMultiTexCoordP2uiv = nullptr;
	PFNGLMULTITEXCOORDP3UIPROC glMultiTexCoordP3ui = nullptr;
	PFNGLMULTITEXCOORDP3UIVPROC glMultiTexCoordP3uiv = nullptr;
	PFNGLMULTITEXCOORDP4UIPROC glMultiTexCoordP4ui = nullptr;
	PFNGLMULTITEXCOORDP4UIVPROC glMultiTexCoordP4uiv = nullptr;
	PFNGLNORMALP3UIPROC glNormalP3ui = nullptr;
	PFNGLNORMALP3UIVPROC glNormalP3uiv = nullptr;
	PFNGLCOLORP3UIPROC glColorP3ui = nullptr;
	PFNGLCOLORP3UIVPROC glColorP3uiv = nullptr;
	PFNGLCOLORP4UIPROC glColorP4ui = nullptr;
	PFNGLCOLORP4UIVPROC glColorP4uiv = nullptr;
	PFNGLSECONDARYCOLORP3UIPROC glSecondaryColorP3ui = nullptr;
	PFNGLSECONDARYCOLORP3UIVPROC glSecondaryColorP3uiv = nullptr;

	namespace V3_3 {
		void load_GL_RECURSIVE(GLADloadproc load);
	}
}