#include "ShaderScene.h"

#include "ShaderProgram.h"
#include "Model.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <glm/glm/gtc/matrix_transform.hpp>

#include <CCGL.h>

namespace sus3d
{
    Model* ShaderScene::loadWithoutAddModel(const std::filesystem::path& path, ShaderProgram* shaderProgram) {
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(path.string(),
            aiProcess_Triangulate |
            aiProcess_FlipUVs |
            aiProcess_JoinIdenticalVertices |
            aiProcess_SortByPType);

        auto model = Model::create(scene, shaderProgram);
        importer.FreeScene();
        return model;
    }

    glm::mat4 Camera::getViewMat() { return glm::lookAt(position, position + front, up); }
    glm::mat4 Camera::getProjectionMat() { return glm::perspective(glm::radians(fov), (float)1920 / float(1080), 0.1f, 6000.0f); }
}