#pragma once

#include "ShaderProgram.h"

#include <glm/glm.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <filesystem>
#include <vector>

namespace sus3d
{
    class Mesh;
    class ShaderProgram;

    class ModelProtocol {
    protected:
        glm::vec3 rotation = glm::vec3(0, 0, 0);;
        glm::vec3 position = glm::vec3(0, 0, 0);;
        glm::vec3 scale = glm::vec3(1.0);
        bool visible = 1;
    public:
        virtual void setRotation(glm::vec3 rotation) { this->rotation = rotation; }
        virtual void setRotationX(float rotation) { this->rotation.x = rotation; }
        virtual void setRotationY(float rotation) { this->rotation.y = rotation; }
        virtual void setRotationZ(float rotation) { this->rotation.z = rotation; }
        virtual glm::vec3 getRotation() const { return this->rotation; }
        virtual float getRotationX() const { return this->rotation.x; }
        virtual float getRotationY() const { return this->rotation.y; }
        virtual float getRotationZ() const { return this->rotation.z; }

        virtual void setPosition(glm::vec3 position) { this->position = position; }
        virtual void setPositionX(float position) { this->position.x = position; }
        virtual void setPositionY(float position) { this->position.y = position; }
        virtual void setPositionZ(float position) { this->position.z = position; }
        virtual glm::vec3 getPosition() const { return this->position; }
        virtual float getPositionX() const { return this->position.x; }
        virtual float getPositionY() const { return this->position.y; }
        virtual float getPositionZ() const { return this->position.z; }

        virtual void setScale(glm::vec3 scale) { this->scale = scale; }
        virtual void setScaleX(float scale) { this->scale.x = scale; }
        virtual void setScaleY(float scale) { this->scale.y = scale; }
        virtual void setScaleZ(float scale) { this->scale.z = scale; }
        virtual glm::vec3 getScale() const { return this->scale; }
        virtual float getScaleX() const { return this->scale.x; }
        virtual float getScaleY() const { return this->scale.y; }
        virtual float getScaleZ() const { return this->scale.z; }

        virtual void setVisible(bool visible) { this->visible = visible; }
        virtual bool getVisible() const { return this->visible; }

        virtual ~ModelProtocol() {};
    };

    class Model : public ModelProtocol {
    protected:
        virtual bool init(const aiScene* scene);
    public:
        std::vector<Mesh*> meshes;
        static Model* create(const aiScene* scene);
        virtual void render(
            ShaderProgram* shaderProgram, 
            const glm::mat4& view, 
            const glm::vec3& lightPos, 
            const glm::vec3& lightColor, 
            const glm::vec3& cameraPos, 
            const glm::mat4& projection);

        virtual glm::mat4 prepareModelMatrix();

        virtual ~Model();
    };

    template <typename T>
    T* loadModelT(const std::filesystem::path& path) 
    {
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(
            path.string(),
            aiProcess_Triangulate |
            aiProcess_FlipUVs |
            aiProcess_JoinIdenticalVertices |
            aiProcess_SortByPType);
        auto model = T::create(scene);
        importer.FreeScene();
        return model;
    }

    Model* loadModel(const std::filesystem::path& path);
}
