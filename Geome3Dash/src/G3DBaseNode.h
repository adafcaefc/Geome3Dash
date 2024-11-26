#pragma once

#include "Sus3D/Scene.h"
#include "CocosShaderProgram.h"

namespace g3d
{
    class sus3d::Model;
    class sus3d::ShaderProgram;

    class G3DBaseNode : public CCNode {
        virtual bool init();
        GLuint framebuffer, texture, renderbuffer;
        CocosShaderProgram* getObjectIDByMousePositionShader;
        glm::vec3 generateUniqueColor(int objectID, int meshID) {
            int uniqueID = (objectID + 1) << 16 | (meshID + 1);

            GLuint r = (uniqueID >> 16) & 0xFF;
            GLuint g = (uniqueID >> 8) & 0xFF;
            GLuint b = uniqueID & 0xFF;

            return glm::vec3(r / 255.0f, g / 255.0f, b / 255.0f);
        }
        std::pair<int, int> getObjectAndMeshIDFromColor(const GLubyte* pixelColor) {
            int uniqueID = (pixelColor[0] << 16) | (pixelColor[1] << 8) | pixelColor[2];

            int objectID = ((uniqueID >> 16) & 0xFFFF) - 1;
            int meshID = (uniqueID & 0xFFFF) - 1;

            return { objectID, meshID };
        }
    public:
        std::pair<int, int> getObjectIDByMousePosition();
        std::vector<sus3d::Model*> models;
        sus3d::Camera camera;
        sus3d::Light light;

        virtual void draw();
        ~G3DBaseNode();
        static G3DBaseNode* create();
    };
}