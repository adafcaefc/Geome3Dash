#pragma once

namespace g3d
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

        unsigned int texture;

        Mesh() {}

        bool init(aiMesh* mesh, aiMaterial* material);
        void initBuffers(aiMaterial* material);

    public:
        static Mesh* create(aiMesh* mesh, aiMaterial* material);
        void render(ShaderProgram* shaderProgram) const;
        ~Mesh();
    };
}