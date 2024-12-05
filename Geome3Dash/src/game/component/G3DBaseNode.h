#pragma once

#include "engine/sus3d/Scene.h"
#include "engine/sus3d/Model.h"

#include "helper/CommonHelper.h"

#include "CocosShaderProgram.h"
#include "BlockModelsStorage.h"

namespace g3d
{
    class G3DCurveEditorLayer;
    class G3DBaseNode : public CCNode
    {
        friend class G3DCurveEditorLayer;
    protected:
        virtual bool init() override;
        GLuint framebuffer, texture, renderbuffer;
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
        sus3d::ShaderProgram* getObjectIDByMousePositionShader;
    public:
        std::vector<sus3d::Model*> models;
        sus3d::Camera camera;
        sus3d::Light light;
        sus3d::ShaderProgram* shaderProgram;

        std::pair<int, int> getObjectIDByMousePosition();
        //void renderModel(sus3d::Model* model);

        virtual void draw() override;
        ~G3DBaseNode();
        static G3DBaseNode* create();

 

        template <typename T>
        T* loadAndAddModel(const std::filesystem::path& filePath)
        {
            auto model = BlockModelsStorage::getInstance()->getModelT<T>(filePath);
            if (model) { models.push_back(model); }
            return model;
        }

  
    };
}