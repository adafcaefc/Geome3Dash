#include "pch.h"
#include "../pch.h"
#include "ShaderScene.h"
#include "ShaderProgram.h"
#include "Model.h"
#include "OpenGLStateHelper.h"
#include <psapi.h>

namespace g3d
{
    Model* ShaderScene::loadAndAddModel(const std::filesystem::path& path, ShaderProgram* shaderProgram) {
        geode::log::info("loading model start");
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(path.string(),
            aiProcess_Triangulate |
            aiProcess_FlipUVs |
            aiProcess_JoinIdenticalVertices |
            aiProcess_SortByPType);

        auto model = Model::create(scene, shaderProgram);
        geode::log::info("loading model end");
        importer.FreeScene();
        geode::log::info("loading model clear");
        return model;
    }

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
}