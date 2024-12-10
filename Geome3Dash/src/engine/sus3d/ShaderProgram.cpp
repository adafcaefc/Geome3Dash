#include "ShaderProgram.h"

#include "Shader.h"

#include <glm/gtc/type_ptr.hpp>

#include <Geode/cocos/platform/CCGL.h>

namespace sus3d
{
    bool ShaderProgram::initProgram(Shader* vertexShader, Shader* fragmentShader) {
        int success = 0;
        char infoLog[512] = { 0 };
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

    void ShaderProgram::use() {
        glUseProgram(id);
    }

    void ShaderProgram::disable() {
        glUseProgram(0);
    }

    void ShaderProgram::setInt(const char* key, int i) {
        glUniform1i(glGetUniformLocation(this->get(), key), i);
    }
    void ShaderProgram::setFloat(const char* key, float i) {
        glUniform1f(glGetUniformLocation(this->get(), key), i);
    }
    void ShaderProgram::setMat3(const char* key, glm::mat3 mat) {
    glUniformMatrix3fv(glGetUniformLocation(this->get(), key), 1, GL_FALSE, glm::value_ptr(mat));
    }
    void ShaderProgram::setMat4(const char* key, glm::mat4 mat) {
        glUniformMatrix4fv(glGetUniformLocation(this->get(), key), 1, GL_FALSE, glm::value_ptr(mat));
    }
    void ShaderProgram::setVec2(const char* key, glm::vec2 vec) {
        glUniform2f(glGetUniformLocation(this->get(), key), vec.x, vec.y);
    }
    void ShaderProgram::setVec3(const char* key, glm::vec3 vec) {
        glUniform3f(glGetUniformLocation(this->get(), key), vec.x, vec.y, vec.z);
    }
}