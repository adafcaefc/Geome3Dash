#include "pch.h"

#include "ModelManager.h"

#include "engine/sus3d/ShaderProgram.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Texture.h"
#include "engine/sus3d/Model.h"
#include "engine/sus3d/Scene.h"
#include "engine/sus3d/Shaders.h"

#include "helper/OpenGLStateHelper.h"
#include "helper/CommonHelper.h"

#include "impl/engine/CocosShaderProgram.h"

namespace g3d
{
	sus3d::ShaderProgram* ModelManager::loadShader(
		const std::string& vsString, 
		const std::string& fsString)
	{
		auto vertexShader = sus3d::Shader::createWithString(
			vsString,
			sus3d::ShaderType::kVertexShader);

		auto fragmentShader = sus3d::Shader::createWithString(
			fsString,
			sus3d::ShaderType::kFragmentShader);

		auto tmpSP = CocosShaderProgram::create(vertexShader, fragmentShader);

		delete vertexShader;
		delete fragmentShader;

		return tmpSP;
	}

	bool ModelManager::init() 
	{
		basePath = geode::Mod::get()->getResourcesDir() / "model3d";
		return true;
	}
	
    // mtl model path fix (model path must be absolute)
    void ModelManager::parseMtlPath(const std::filesystem::path& path)
    {
        if (std::filesystem::exists(path))
        {
            auto mtl_file = utils::read_from_file(path);
            if (mtl_file.find("{{MODEL_PATH}}") != std::string::npos)
            {
                utils::replace_all(mtl_file, "{{MODEL_PATH}}", path.parent_path().string());
            }
            utils::write_to_file(path, mtl_file);
        }
    }

	sus3d::Model* ModelManager::getBlockModel(const int id)
	{
		auto it = blockModels.find(id);
		if (it == blockModels.end()) { return nullptr; }
		return it->second;
	}

	sus3d::Model* ModelManager::getModel(const std::filesystem::path& path)
	{
		auto it = allModels.find(path);
		if (it == allModels.end()) { return nullptr; }
		return it->second;
	}

	void ModelManager::tryRenderBlock(
		const int objectId,
		sus3d::Camera* camera,
		sus3d::Light* light)
	{
		if (auto model = getBlockModel(objectId))
		{
			model->render(
				blockShaderProgram,
				camera->getViewMat(),
				light->getPosition(),
				light->getColor(),
				camera->getPosition(),
				camera->getProjectionMat());
		}
	}

	ModelManager* ModelManager::get() 
	{
		if (!instance) 
		{
			instance = new ModelManager;
			instance->init();
		}
		return instance;
	}

	ModelManager* ModelManager::instance = nullptr;
}