#pragma once

#include <vector>

#include <glm/glm.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace sus3d
{
    class ShaderProgram;

    class Mesh {
    protected:
        unsigned int VAO, VBO, EBO;
        std::vector<float> vertices;
        std::vector<unsigned int> indices;
        bool useTexture = 0;

        glm::vec3 Ka;
        glm::vec3 Kd;
        glm::vec3 Ks;

        glm::vec3 customKa;
        glm::vec3 customKd;
        glm::vec3 customKs;
        bool isCustomKa = false;
        bool isCustomKd = false;
        bool isCustomKs = false;

        float d = 1;
        float customD = 1;
        bool isCustomD = false;

        bool visible = 1;

        unsigned int texture;

        Mesh() {}

        virtual bool init(aiMesh* mesh, aiMaterial* material);
        virtual void initBuffers(aiMaterial* material);

    public:
        void setCustomKa(glm::vec3 color) { customKa = color; isCustomKa = true; }
        void setCustomKd(glm::vec3 color) { customKd = color; isCustomKd = true; }
        void setCustomKs(glm::vec3 color) { customKs = color; isCustomKs = true; }

        void disableKa() { isCustomKa = false; }
        void disableKd() { isCustomKd = false; }
        void disableKs() { isCustomKs = false; }

        void setCustomD(float opacity) { customD = opacity; isCustomD = true; }
        void disableD() { isCustomD = false; }

        void setVisible(bool visible) { this->visible = visible; };

        static Mesh* create(aiMesh* mesh, aiMaterial* material);
        virtual void render(ShaderProgram* shaderProgram) const;
        virtual ~Mesh();
    };
}