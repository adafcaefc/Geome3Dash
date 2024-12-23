#pragma once

#include <Geode/cocos/platform/CCGL.h>

#include <glm/glm.hpp>

#include <unordered_map>
#include <string>

namespace sus3d
{
    class Shader;

    class ShaderProgram {
    protected:
        unsigned int id;
        bool initProgram(Shader* vertexShader, Shader* fragmentShader);
        std::unordered_map<std::string, GLint> uniformLocationCache;
        GLint getUniformLocation(const std::string& s);
    public:
        virtual ~ShaderProgram();
        int get() { return id; }
        void use();
        static void disable();
        virtual void setBasicUniforms() = 0;

        void setInt(const std::string& key, int i);
        void setFloat(const std::string& key, float i);
        void setMat4(const std::string& key, glm::mat4 mat);
        void setVec2(const std::string& key, glm::vec2 vec);
        void setVec3(const std::string& key, glm::vec3 vec);
    };
}
