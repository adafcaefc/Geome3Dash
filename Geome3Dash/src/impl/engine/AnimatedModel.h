#pragma once

#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Model.h"
#include "engine/sus3d/ShaderProgram.h"

namespace g3d
{
    class AnimatedModelNode : public CCNode
    {
    protected:
        std::vector<sus3d::Model*> models;
        float fps = 60.f;
        float timeAccumulator = 0.0f;
        size_t currentModelIndex = 0u;
        bool isLooping = true;
        sus3d::Model* getCurrentModel() { return this->models.at(currentModelIndex); }
        std::filesystem::path basePath;
    public:
        ~AnimatedModelNode() override = default;
        static AnimatedModelNode* create(const aiScene* scene);
        virtual bool setup(const std::filesystem::path& base);
        virtual void update(float dt) override;
        static AnimatedModelNode* create(const std::filesystem::path& base);
        friend class AnimatedModel;
    };

    class AnimatedModel : public sus3d::Model
    {
    protected:
        AnimatedModelNode* node = nullptr;
    public:
        // the dual class system caused these functions to be placed here while 
        // the actions happened in the node itself
        // I don't really like this honestly
        void setLoop(const bool loop) { node->isLooping = loop; }
        void resetAnimation() { node->currentModelIndex = 0u; node->timeAccumulator = 0.f; }

        // memory leak but I cba to fix this right now
        // this is because this model is not automatically cleaned
        // I tried to put a destructor but it crashed... why?
        // maybe it's because it's deleting an empty model?
        // but the mesh should be empty...?
        ~AnimatedModel() override = default;
        virtual bool setup(const std::filesystem::path& base, PlayerObject* player);
        static AnimatedModel* create(const std::filesystem::path& base, PlayerObject* player);

        void render(
            sus3d::ShaderProgram* shaderProgram,
            const glm::mat4& view,
            const glm::vec3& lightPos,
            const glm::vec3& lightColor,
            const glm::vec3& cameraPos,
            const glm::mat4& projection) override
        {
            this->node->getCurrentModel()->render(shaderProgram, view, lightPos, lightColor, cameraPos, projection);
        }

        // transform setters

        void setRotation(glm::vec3 rotation) override;
        void setRotationX(float rotation) override;
        void setRotationY(float rotation) override;
        void setRotationZ(float rotation) override;

        void setPosition(glm::vec3 position) override;
        void setPositionX(float position) override;
        void setPositionY(float position) override;
        void setPositionZ(float position) override;

        void setScale(glm::vec3 scale) override;
        void setScaleX(float scale) override;
        void setScaleY(float scale) override;
        void setScaleZ(float scale) override;

        void setVisible(bool visible) override;
    };
}