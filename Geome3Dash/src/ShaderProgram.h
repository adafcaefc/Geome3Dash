#pragma once

namespace g3d
{
    class Shader;

    class ShaderProgram {
        unsigned int id;
        bool initProgram(Shader* vertexShader, Shader* fragmentShader);
    public:
        ~ShaderProgram();
        static ShaderProgram* create(Shader* vertexShader, Shader* fragmentShader);
        int get() { return id; }
        void use();
        static void disable();

        void setInt(const char* key, int i) {
            glUniform1i(glGetUniformLocation(this->get(), key), i);
        }
        void setFloat(const char* key, float i) {
            glUniform1f(glGetUniformLocation(this->get(), key), i);
        }
        void setMat4(const char* key, glm::mat4 mat) {
            glUniformMatrix4fv(glGetUniformLocation(this->get(), key), 1, GL_FALSE, glm::value_ptr(mat));
        }
        void setVec3(const char* key, glm::vec3 vec) {
            glUniform3f(glGetUniformLocation(this->get(), key), vec.x, vec.y, vec.z);
        }
    };
}