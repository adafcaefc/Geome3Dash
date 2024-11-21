#include "pch.h"
#include "../pch.h"
#include "OpenGLStateHelper.h"

namespace g3d
{
    void OpenGLStateHelper::saveState() {
        for (int i = 0; i < 32; ++i) {
            glActiveTexture(GL_TEXTURE0 + i);
            glGetIntegerv(GL_TEXTURE_BINDING_2D, &state.boundTextures[i]);
        }
        glActiveTexture(GL_TEXTURE0);
        glGetIntegerv(GL_CURRENT_PROGRAM, &state.currentProgram);
        glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &state.arrayBuffer);
        glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &state.elementArrayBuffer);

        glGetIntegerv(GL_BLEND_SRC_RGB, &state.blendSrc);
        glGetIntegerv(GL_BLEND_DST_RGB, &state.blendDst);
        glGetIntegerv(GL_BLEND_SRC_ALPHA, &state.blendSrcAlpha);
        glGetIntegerv(GL_BLEND_DST_ALPHA, &state.blendDstAlpha);
        glGetIntegerv(GL_BLEND_EQUATION_RGB, &state.blendEquationRGB);
        glGetIntegerv(GL_BLEND_EQUATION_ALPHA, &state.blendEquationAlpha);

        state.blendEnabled = glIsEnabled(GL_BLEND);
    }
    void OpenGLStateHelper::pushState() {
        for (int i = 0; i < 32; ++i) {
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, state.boundTextures[i]);
        }
        glActiveTexture(GL_TEXTURE0);
        glUseProgram(state.currentProgram);
        glBindBuffer(GL_ARRAY_BUFFER, state.arrayBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, state.elementArrayBuffer);
        if (state.blendEnabled) {
            glEnable(GL_BLEND);
        }
        else {
            glDisable(GL_BLEND);
        }

        glBlendFuncSeparate(state.blendSrc, state.blendDst, state.blendSrcAlpha, state.blendDstAlpha);
        glBlendEquationSeparate(state.blendEquationRGB, state.blendEquationAlpha);
    }

    OpenGLState OpenGLStateHelper::state = OpenGLState();
}