#pragma once

#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Model.h"
#include "engine/sus3d/ShaderProgram.h"

namespace g3d
{
    class AnimatedModelInner : public CCNode
    {
    protected:
        std::vector<sus3d::Model*> models;
        float fps = 60.f;
        float timeAccumulator = 0.0f;
        size_t currentModelIndex = 0u;
        sus3d::Model* getCurrentModel() { return this->models.at(currentModelIndex); }
        std::filesystem::path basePath;
    public:
        ~AnimatedModelInner() override = default;
        static AnimatedModelInner* create(const aiScene* scene);
        virtual bool setup(const std::filesystem::path& base);
        virtual void update(float dt) override;
        static AnimatedModelInner* create(const std::filesystem::path& base);
        friend class AnimatedModel;
    };

    class AnimatedModel : public sus3d::Model
    {
    protected:
        AnimatedModelInner* node = nullptr;
    public:
        ~AnimatedModel() override = default;
        virtual bool setup(const std::filesystem::path& base, PlayerObject* player);
        // memory leak but I cba to fix this right now
        // this is because this model is not automatically cleaned
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