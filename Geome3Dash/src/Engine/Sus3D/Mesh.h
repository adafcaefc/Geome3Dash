#pragma once

#include <vector>

#include <glm/glm/glm.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace sus3d
{
    class ShaderProgram;

    class Mesh {
        unsigned int VAO, VBO, EBO;
        std::vector<float> vertices;
        std::vector<unsigned int> indices;
        bool useTexture = 0;

        glm::vec3 Ka;
        glm::vec3 Kd;
        glm::vec3 Ks;

        glm::vec3 CustomKa;
        glm::vec3 CustomKd;
        glm::vec3 CustomKs;
        bool isCustomKa = false;
        bool isCustomKd = false;
        bool isCustomKs = false;

        bool visible = 1;

        unsigned int texture;

        Mesh() {}

        bool init(aiMesh* mesh, aiMaterial* material);
        void initBuffers(aiMaterial* material);

    public:
        void setCustomKa(glm::vec3 color) { CustomKa = color; isCustomKa = true; }
        void setCustomKd(glm::vec3 color) { CustomKd = color; isCustomKd = true; }
        void setCustomKs(glm::vec3 color) { CustomKs = color; isCustomKs = true; }

        void disableKa() { isCustomKa = false; }
        void disableKd() { isCustomKd = false; }
        void disableKs() { isCustomKs = false; }

        void setVisible(bool visible) { this->visible = visible; };

        static Mesh* create(aiMesh* mesh, aiMaterial* material);
        void render(ShaderProgram* shaderProgram) const;
        ~Mesh();
    };
}