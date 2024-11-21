#include "pch.h"
#include "ShaderScene.h"
#include "ShaderProgram.h"
#include "Model.h"
#include "OpenGLStateHelper.h"
#include <psapi.h>

namespace g3d
{
    void printMemoryUsage() {
        PROCESS_MEMORY_COUNTERS memInfo;
        BOOL result = GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));

        if (result) {
            std::cout << "Working Set Size: " << memInfo.WorkingSetSize / 1024 << " KB" << std::endl;
            std::cout << "Peak Working Set Size: " << memInfo.PeakWorkingSetSize / 1024 << " KB" << std::endl;
            std::cout << "Pagefile Usage: " << memInfo.PagefileUsage / 1024 << " KB" << std::endl;
        }
        else {
            std::cerr << "Failed to get memory usage information" << std::endl;
        }
    }

    void ShaderScene::draw() {
        OpenGLStateHelper::saveState();

        glDisable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);

        glm::mat4 view = camera->getViewMat();

        glm::mat4 projection = camera->getProjectionMat();

        for (auto model : models) {
            model->render(view, light->getPosition(), light->getColor(), camera->getPosition(), projection);
        }

        glDisable(GL_DEPTH_TEST);

        OpenGLStateHelper::pushState();
    }

    ShaderScene::~ShaderScene() {
        for (auto model : models) {
            delete model;
        }
    }

    Model* ShaderScene::loadAndAddModel(std::string path, ShaderProgram* shaderProgram) {
        std::cout << "loading start" << std::endl;
        printMemoryUsage();
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(path,
            aiProcess_Triangulate |
            aiProcess_FlipUVs |
            aiProcess_JoinIdenticalVertices |
            aiProcess_SortByPType);

        auto model = Model::create(scene, shaderProgram);
        std::cout << "loading end" << std::endl;
        printMemoryUsage();
        importer.FreeScene();
        std::cout << "loading clear" << std::endl;
        printMemoryUsage();
        models.push_back(model);
        return model;
    }

    Model* ShaderScene::loadWithoutAddModel(std::string path, ShaderProgram* shaderProgram) {
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(path,
            aiProcess_Triangulate |
            aiProcess_FlipUVs |
            aiProcess_JoinIdenticalVertices |
            aiProcess_SortByPType);

        auto model = Model::create(scene, shaderProgram);
        importer.FreeScene();
        return model;
    }

    auto ShaderScene::create() {
        auto node = new ShaderScene;
        if (node->init()) {
            node->autorelease();
        }
        else {
            CC_SAFE_DELETE(node);
        }
        return node;
    }
}