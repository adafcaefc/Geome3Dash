#pragma once

namespace g3d
{
    class Mesh;
    class ShaderProgram;

    class Model {
        glm::vec3 rotation;
        glm::vec3 position;
        glm::vec3 scale = glm::vec3(1.0);
        ShaderProgram* shaderProgram;
        std::vector<Mesh*> meshes;
        bool visible = 1;
        virtual bool init(const aiScene* scene);
        glm::mat4 prepareModelMatrix();
    public:
        static Model* create(const aiScene* scene, ShaderProgram* shaderProgram);
        void render(glm::mat4 view, glm::vec3 lightPos, glm::vec3 lightColor, glm::vec3 cameraPos, glm::mat4 projection);
        void setRotation(glm::vec3 rotation) { this->rotation = rotation; }
        void setRotationX(float rotation) { this->rotation.x = rotation; }
        void setRotationY(float rotation) { this->rotation.y = rotation; }
        void setRotationZ(float rotation) { this->rotation.z = rotation; }
        glm::vec3 getRotation() { return this->rotation; }
        float getRotationX() { return this->rotation.x; }
        float getRotationY() { return this->rotation.y; }
        float getRotationZ() { return this->rotation.z; }
        void setPosition(glm::vec3 position) { this->position = position; }
        void setPositionX(float position) { this->position.x = position; }
        void setPositionY(float position) { this->position.y = position; }
        void setPositionZ(float position) { this->position.z = position; }
        glm::vec3 getPosition() { return this->position; }
        float getPositionX() { return this->position.x; }
        float getPositionY() { return this->position.y; }
        float getPositionZ() { return this->position.z; }
        void setVisible(bool visible) { this->visible = visible; }

        void setScale(glm::vec3 scale) { this->scale = scale; }
        ~Model() {
            for (Mesh* mesh : meshes) {
                delete mesh;
            }
            meshes.clear();
        }
    };
}
