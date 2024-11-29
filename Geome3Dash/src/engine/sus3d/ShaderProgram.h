#pragma once

#include <glm/glm/glm.hpp>

namespace sus3d
{
    class Shader;

    class ShaderProgram {
    protected:
        unsigned int id;
        bool initProgram(Shader* vertexShader, Shader* fragmentShader);
    public:
        virtual ~ShaderProgram();
        int get() { return id; }
        void use();
        static void disable();
        virtual void setBasicUniforms() = 0;

        void setInt(const char* key, int i);
        void setFloat(const char* key, float i);
        void setMat4(const char* key, glm::mat4 mat);
        void setVec2(const char* key, glm::vec2 vec);
        void setVec3(const char* key, glm::vec3 vec);
    };
}