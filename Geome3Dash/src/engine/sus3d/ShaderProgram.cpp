#include "ShaderProgram.h"

#include "Shader.h"

#include <glm/gtc/type_ptr.hpp>

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
        if (id) { glDeleteProgram(id); }
    }

    void ShaderProgram::use() {
        glUseProgram(id);
    }

    void ShaderProgram::disable() {
        glUseProgram(0);
    }

    GLint ShaderProgram::getUniformLocation(const std::string& s) {
        auto it = this->uniformLocationCache.find(s);
        if (it != this->uniformLocationCache.end()) {
            return it->second;
        }
        GLint location = glGetUniformLocation(this->get(), s.c_str());
        this->uniformLocationCache[s] = location;
        return location;
    }

    void ShaderProgram::setInt(const std::string& key, int i) {
        glUniform1i(this->getUniformLocation(key), i);
    }
    void ShaderProgram::setFloat(const std::string& key, float i) {
        glUniform1f(this->getUniformLocation(key), i);
    }
    void ShaderProgram::setMat4(const std::string& key, glm::mat4 mat) {
        glUniformMatrix4fv(this->getUniformLocation(key), 1, GL_FALSE, glm::value_ptr(mat));
    }
    void ShaderProgram::setVec2(const std::string& key, glm::vec2 vec) {
        glUniform2f(this->getUniformLocation(key), vec.x, vec.y);
    }
    void ShaderProgram::setVec3(const std::string& key, glm::vec3 vec) {
        glUniform3f(this->getUniformLocation(key), vec.x, vec.y, vec.z);
    }
}