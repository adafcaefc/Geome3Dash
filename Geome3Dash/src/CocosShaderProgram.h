#pragma once

#include "engine/sus3d/ShaderProgram.h"

namespace g3d
{ 
    class CocosShaderProgram : public sus3d::ShaderProgram {
    public:
        using ShaderProgram::ShaderProgram;

        ~CocosShaderProgram() override = default;

        // Override the static create method
        static CocosShaderProgram* create(sus3d::Shader* vertexShader, sus3d::Shader* fragmentShader) {
            CocosShaderProgram* program = new CocosShaderProgram();
            if (program && program->initProgram(vertexShader, fragmentShader)) {
                return program;
            }
            delete program;
            return nullptr;
        }

        void setBasicUniforms() override;
    };
}