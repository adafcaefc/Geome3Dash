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
	};

	class OpenGLStateHelper {
	public:
		static void saveState();
		static void pushState();
		static OpenGLState state;
	};
}