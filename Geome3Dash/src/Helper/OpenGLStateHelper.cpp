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
        glGetIntegerv(GL_FRAMEBUFFER_BINDING, &state.frameBuffer);

        glGetIntegerv(GL_VIEWPORT, state.viewport);
        glGetIntegerv(GL_SCISSOR_BOX, state.scissorBox);
        glGetBooleanv(GL_SCISSOR_TEST, &state.scissorTestEnabled);
        //glGetBooleanv(GL_DEPTH_TEST, &state.depthTestEnabled);
        glGetBooleanv(GL_CULL_FACE, &state.cullFaceEnabled);
        //glGetIntegerv(GL_DEPTH_FUNC, &state.depthFunc);

        state.blendEnabled = glIsEnabled(GL_BLEND);
        glGetIntegerv(GL_POLYGON_MODE, state.polygonMode);
        glGetIntegerv(GL_ACTIVE_TEXTURE, &state.activeTexture);
    }
    void OpenGLStateHelper::pushState() {
        for (int i = 0; i < 32; ++i) {
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, state.boundTextures[i]);
        }
        glActiveTexture(state.activeTexture);
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
        glBindFramebuffer(GL_FRAMEBUFFER, state.frameBuffer);

        glViewport(state.viewport[0], state.viewport[1], state.viewport[2], state.viewport[3]);
        glScissor(state.scissorBox[0], state.scissorBox[1], state.scissorBox[2], state.scissorBox[3]);
        if (state.scissorTestEnabled) {
            glEnable(GL_SCISSOR_TEST);
        }
        else {
            glDisable(GL_SCISSOR_TEST);
        }
        /*
        if (state.depthTestEnabled) {
            glEnable(GL_DEPTH_TEST);
        }
        else {
            glDisable(GL_DEPTH_TEST);
        }*/

        if (state.cullFaceEnabled) {
            glEnable(GL_CULL_FACE);
        }
        else {
            glDisable(GL_CULL_FACE);
        }

        //glDepthFunc(state.depthFunc);
        glPolygonMode(GL_FRONT_AND_BACK, state.polygonMode[0]);
    }

    OpenGLState OpenGLStateHelper::state = OpenGLState();
}