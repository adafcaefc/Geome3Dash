#pragma once

#include "Sus3D/Scene.h"
#include "Sus3D/Model.h"

#include "Helper/CommonHelper.h"

#include "CocosShaderProgram.h"

namespace g3d
{
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

        template <typename T>
        T* loadAndAddModel(
            const std::filesystem::path& filePath, 
            sus3d::ShaderProgram* shaderProgram)
        {
            const auto obj_path = std::filesystem::path(filePath);
            const auto mtl_path = obj_path.parent_path() / (obj_path.stem().string() + ".mtl");

            if (std::filesystem::exists(mtl_path))
            {
                auto mtl_file = utils::read_from_file(mtl_path);
                if (mtl_file.find("{{MODEL_PATH}}") != std::string::npos)
                {
                    utils::replace_all(mtl_file, "{{MODEL_PATH}}", mtl_path.parent_path().string());
                }
                utils::write_to_file(mtl_path, mtl_file);
            }

            auto model = sus3d::loadModelTemplate<T>(filePath, shaderProgram);
            models.push_back(model);
            return model;
        }
    };
}