#pragma once

namespace g3d
{
	struct OpenGLState {
        GLint boundTextures[32];
        GLint currentProgram;
        GLint arrayBuffer;
        GLint elementArrayBuffer;
        GLint blendSrc;
        GLint blendDst;
        GLint blendSrcAlpha;
        GLint blendDstAlpha;
        GLint blendEquationRGB;
        GLint blendEquationAlpha;
        GLboolean blendEnabled;
        GLint frameBuffer;
        GLint viewport[4];
        GLint scissorBox[4];
        GLboolean scissorTestEnabled;
        GLboolean depthTestEnabled;
        GLboolean cullFaceEnabled;
        GLint depthFunc;
        GLint polygonMode[2];
        GLint activeTexture;
	};

	class OpenGLStateHelper {
	public:
		static void saveState();
		static void pushState();
		static OpenGLState state;
	};
}