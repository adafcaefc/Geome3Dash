#pragma once

#include "3SusEngine/ShaderScene.h"

namespace g3d
{
    class sus3d::Model;
    class sus3d::ShaderProgram;

    class G3DBaseNode : public CCNode {
        virtual bool init();
        GLuint framebuffer, texture, renderbuffer;
        sus3d::ShaderProgram* getObjectIDByMousePositionShader;
        glm::vec3 generateUniqueColor(int objectID, int meshID);
        std::pair<int, int> getObjectAndMeshIDFromColor(const GLubyte* pixelColor);
    public:
        std::pair<int, int> getObjectIDByMousePosition(int mouseX, int mouseY);
        std::vector<sus3d::Model*> models;

        sus3d::Camera camera;
        sus3d::Light light;

        virtual void draw();
        ~G3DBaseNode();
        static G3DBaseNode* create();
    };
}