import GLAD;

namespace GLAD::V3_3 {
	void load_GL_RECURSIVE(GLADloadproc load) {
		glBindFragDataLocationIndexed = GLAD::gladLoadFunction<PFNGLBINDFRAGDATALOCATIONINDEXEDPROC>("glBindFragDataLocationIndexed", load);
		glGetFragDataIndex = GLAD::gladLoadFunction<PFNGLGETFRAGDATAINDEXPROC>("glGetFragDataIndex", load);
		glGenSamplers = GLAD::gladLoadFunction<PFNGLGENSAMPLERSPROC>("glGenSamplers", load);
		glDeleteSamplers = GLAD::gladLoadFunction<PFNGLDELETESAMPLERSPROC>("glDeleteSamplers", load);
		glIsSampler = GLAD::gladLoadFunction<PFNGLISSAMPLERPROC>("glIsSampler", load);
		glBindSampler = GLAD::gladLoadFunction<PFNGLBINDSAMPLERPROC>("glBindSampler", load);
		glSamplerParameteri = GLAD::gladLoadFunction<PFNGLSAMPLERPARAMETERIPROC>("glSamplerParameteri", load);
		glSamplerParameteriv = GLAD::gladLoadFunction<PFNGLSAMPLERPARAMETERIVPROC>("glSamplerParameteriv", load);
		glSamplerParameterf = GLAD::gladLoadFunction<PFNGLSAMPLERPARAMETERFPROC>("glSamplerParameterf", load);
		glSamplerParameterfv = GLAD::gladLoadFunction<PFNGLSAMPLERPARAMETERFVPROC>("glSamplerParameterfv", load);
		glSamplerParameterIiv = GLAD::gladLoadFunction<PFNGLSAMPLERPARAMETERIIVPROC>("glSamplerParameterIiv", load);
		glSamplerParameterIuiv = GLAD::gladLoadFunction<PFNGLSAMPLERPARAMETERIUIVPROC>("glSamplerParameterIuiv", load);
		glGetSamplerParameteriv = GLAD::gladLoadFunction<PFNGLGETSAMPLERPARAMETERIVPROC>("glGetSamplerParameteriv", load);
		glGetSamplerParameterIiv = GLAD::gladLoadFunction<PFNGLGETSAMPLERPARAMETERIIVPROC>("glGetSamplerParameterIiv", load);
		glGetSamplerParameterfv = GLAD::gladLoadFunction<PFNGLGETSAMPLERPARAMETERFVPROC>("glGetSamplerParameterfv", load);
		glGetSamplerParameterIuiv = GLAD::gladLoadFunction<PFNGLGETSAMPLERPARAMETERIUIVPROC>("glGetSamplerParameterIuiv", load);
		glQueryCounter = GLAD::gladLoadFunction<PFNGLQUERYCOUNTERPROC>("glQueryCounter", load);
		glGetQueryObjecti64v = GLAD::gladLoadFunction<PFNGLGETQUERYOBJECTI64VPROC>("glGetQueryObjecti64v", load);
		glGetQueryObjectui64v = GLAD::gladLoadFunction<PFNGLGETQUERYOBJECTUI64VPROC>("glGetQueryObjectui64v", load);
		glVertexAttribDivisor = GLAD::gladLoadFunction<PFNGLVERTEXATTRIBDIVISORPROC>("glVertexAttribDivisor", load);
		glVertexAttribP1ui = GLAD::gladLoadFunction<PFNGLVERTEXATTRIBP1UIPROC>("glVertexAttribP1ui", load);
		glVertexAttribP1uiv = GLAD::gladLoadFunction<PFNGLVERTEXATTRIBP1UIVPROC>("glVertexAttribP1uiv", load);
		glVertexAttribP2ui = GLAD::gladLoadFunction<PFNGLVERTEXATTRIBP2UIPROC>("glVertexAttribP2ui", load);
		glVertexAttribP2uiv = GLAD::gladLoadFunction<PFNGLVERTEXATTRIBP2UIVPROC>("glVertexAttribP2uiv", load);
		glVertexAttribP3ui = GLAD::gladLoadFunction<PFNGLVERTEXATTRIBP3UIPROC>("glVertexAttribP3ui", load);
		glVertexAttribP3uiv = GLAD::gladLoadFunction<PFNGLVERTEXATTRIBP3UIVPROC>("glVertexAttribP3uiv", load);
		glVertexAttribP4ui = GLAD::gladLoadFunction<PFNGLVERTEXATTRIBP4UIPROC>("glVertexAttribP4ui", load);
		glVertexAttribP4uiv = GLAD::gladLoadFunction<PFNGLVERTEXATTRIBP4UIVPROC>("glVertexAttribP4uiv", load);
		glVertexP2ui = GLAD::gladLoadFunction<PFNGLVERTEXP2UIPROC>("glVertexP2ui", load);
		glVertexP2uiv = GLAD::gladLoadFunction<PFNGLVERTEXP2UIVPROC>("glVertexP2uiv", load);
		glVertexP3ui = GLAD::gladLoadFunction<PFNGLVERTEXP3UIPROC>("glVertexP3ui", load);
		glVertexP3uiv = GLAD::gladLoadFunction<PFNGLVERTEXP3UIVPROC>("glVertexP3uiv", load);
		glVertexP4ui = GLAD::gladLoadFunction<PFNGLVERTEXP4UIPROC>("glVertexP4ui", load);
		glVertexP4uiv = GLAD::gladLoadFunction<PFNGLVERTEXP4UIVPROC>("glVertexP4uiv", load);
		glTexCoordP1ui = GLAD::gladLoadFunction<PFNGLTEXCOORDP1UIPROC>("glTexCoordP1ui", load);
		glTexCoordP1uiv = GLAD::gladLoadFunction<PFNGLTEXCOORDP1UIVPROC>("glTexCoordP1uiv", load);
		glTexCoordP2ui = GLAD::gladLoadFunction<PFNGLTEXCOORDP2UIPROC>("glTexCoordP2ui", load);
		glTexCoordP2uiv = GLAD::gladLoadFunction<PFNGLTEXCOORDP2UIVPROC>("glTexCoordP2uiv", load);
		glTexCoordP3ui = GLAD::gladLoadFunction<PFNGLTEXCOORDP3UIPROC>("glTexCoordP3ui", load);
		glTexCoordP3uiv = GLAD::gladLoadFunction<PFNGLTEXCOORDP3UIVPROC>("glTexCoordP3uiv", load);
		glTexCoordP4ui = GLAD::gladLoadFunction<PFNGLTEXCOORDP4UIPROC>("glTexCoordP4ui", load);
		glTexCoordP4uiv = GLAD::gladLoadFunction<PFNGLTEXCOORDP4UIVPROC>("glTexCoordP4uiv", load);
		glMultiTexCoordP1ui = GLAD::gladLoadFunction<PFNGLMULTITEXCOORDP1UIPROC>("glMultiTexCoordP1ui", load);
		glMultiTexCoordP1uiv = GLAD::gladLoadFunction<PFNGLMULTITEXCOORDP1UIVPROC>("glMultiTexCoordP1uiv", load);
		glMultiTexCoordP2ui = GLAD::gladLoadFunction<PFNGLMULTITEXCOORDP2UIPROC>("glMultiTexCoordP2ui", load);
		glMultiTexCoordP2uiv = GLAD::gladLoadFunction<PFNGLMULTITEXCOORDP2UIVPROC>("glMultiTexCoordP2uiv", load);
		glMultiTexCoordP3ui = GLAD::gladLoadFunction<PFNGLMULTITEXCOORDP3UIPROC>("glMultiTexCoordP3ui", load);
		glMultiTexCoordP3uiv = GLAD::gladLoadFunction<PFNGLMULTITEXCOORDP3UIVPROC>("glMultiTexCoordP3uiv", load);
		glMultiTexCoordP4ui = GLAD::gladLoadFunction<PFNGLMULTITEXCOORDP4UIPROC>("glMultiTexCoordP4ui", load);
		glMultiTexCoordP4uiv = GLAD::gladLoadFunction<PFNGLMULTITEXCOORDP4UIVPROC>("glMultiTexCoordP4uiv", load);
		glNormalP3ui = GLAD::gladLoadFunction<PFNGLNORMALP3UIPROC>("glNormalP3ui", load);
		glNormalP3uiv = GLAD::gladLoadFunction<PFNGLNORMALP3UIVPROC>("glNormalP3uiv", load);
		glColorP3ui = GLAD::gladLoadFunction<PFNGLCOLORP3UIPROC>("glColorP3ui", load);
		glColorP3uiv = GLAD::gladLoadFunction<PFNGLCOLORP3UIVPROC>("glColorP3uiv", load);
		glColorP4ui = GLAD::gladLoadFunction<PFNGLCOLORP4UIPROC>("glColorP4ui", load);
		glColorP4uiv = GLAD::gladLoadFunction<PFNGLCOLORP4UIVPROC>("glColorP4uiv", load);
		glSecondaryColorP3ui = GLAD::gladLoadFunction<PFNGLSECONDARYCOLORP3UIPROC>("glSecondaryColorP3ui", load);
		glSecondaryColorP3uiv = GLAD::gladLoadFunction<PFNGLSECONDARYCOLORP3UIVPROC>("glSecondaryColorP3uiv", load);

		GLAD::V3_2::load_GL_RECURSIVE(load);
	}
}