#pragma once

#include "3SusEngine/ShaderScene.h"

namespace g3d
{
    class Model;
    class ShaderProgram;

    class G3DBaseNode : public CCNode {
        virtual bool init();
        GLuint framebuffer, texture, renderbuffer;
        ShaderProgram* getObjectIDByMousePositionShader;
        glm::vec3 generateUniqueColor(int objectID, int meshID);
        std::pair<int, int> getObjectAndMeshIDFromColor(const GLubyte* pixelColor);
    public:
        std::pair<int, int> getObjectIDByMousePosition(int mouseX, int mouseY);
        std::vector<Model*> models;

        Camera camera;
        Light light;

        virtual void draw();
        ~G3DBaseNode();
        Model* loadAndAddModel(std::string path, ShaderProgram* shaderProgram);
        Model* loadWithoutAddModel(std::string path, ShaderProgram* shaderProgram);
        static G3DBaseNode* create();
    };
}