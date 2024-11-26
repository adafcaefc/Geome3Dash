#include "pch.h"
#include "../pch.h"
#include "ShaderProgram.h"
#include "Shader.h"

namespace g3d
{
    bool ShaderProgram::initProgram(Shader* vertexShader, Shader* fragmentShader) {
        int success;
        char infoLog[512];
        id = glCreateProgram();
        glAttachShader(id, vertexShader->get());
        glAttachShader(id, fragmentShader->get());
        glLinkProgram(id);
        glGetProgramiv(id, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(id, 512, NULL, infoLog);
            return 0;
        }
        return 1;
    }

    ShaderProgram::~ShaderProgram() {
        if (id)
            glDeleteProgram(id);
    }

    ShaderProgram* ShaderProgram::create(Shader* vertexShader, Shader* fragmentShader) {
        auto ret = new ShaderProgram();
        if (vertexShader && fragmentShader && vertexShader->getType() == ShaderType::kVertexShader && fragmentShader->getType() == ShaderType::kFragmentShader && ret && ret->initProgram(vertexShader, fragmentShader)) {
            return ret;
        }
        return nullptr;
    }

    void ShaderProgram::use() {
        glUseProgram(id);
    }

    void ShaderProgram::disable() {
        glUseProgram(0);
    }
}