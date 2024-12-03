#include "pch.h"

#include "BlockModelsStorage.h"

#include "engine/sus3d/ShaderProgram.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Texture.h"
#include "engine/sus3d/Model.h"
#include "engine/sus3d/Scene.h"
#include "engine/sus3d/Shaders.h"

#include "helper/OpenGLStateHelper.h"
#include "helper/CommonHelper.h"

#include "CocosShaderProgram.h"

namespace g3d
{
	bool BlockModelsStorage::init() 
	{
		basePath = geode::Mod::get()->getResourcesDir() / "model3d";
		OpenGLStateHelper::saveState();
		auto vertexShader = sus3d::Shader::createWithString(
			sus3d::shaders::vertexShaderSource, 
			sus3d::ShaderType::kVertexShader);
		auto fragmentShader = sus3d::Shader::createWithString(
			sus3d::shaders::fragmentShaderSource, 
			sus3d::ShaderType::kFragmentShader);
		blockShaderProgram = CocosShaderProgram::create(vertexShader, fragmentShader);
		delete vertexShader;
		delete fragmentShader;
		loadAllModels();
		OpenGLStateHelper::pushState();
		return true;
	}
	
    // mtl model path fix (model path must be absolute)
    void BlockModelsStorage::parseMtlPath(const std::filesystem::path& path)
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

    void BlockModelsStorage::loadAllModels()
    {
		try 
		{
			for (const auto& entry : std::filesystem::recursive_directory_iterator(basePath)) 
			{
				if (entry.is_regular_file() && entry.path().extension() == ".obj") 
				{
					if (auto blockModel = loadAndParseMtl(entry.path()))
					{
						allModels.emplace(entry.path(), blockModel);
					}
				}
			}

			constexpr int MAX_OBJECT_ID = 3000;
			for (int i = 0; i < MAX_OBJECT_ID; i++)
			{
				const auto modelPath = basePath /  "object" / std::to_string(i) / "model.obj";
				if (auto blockModel = getModel(modelPath)) { blockModels[i] = blockModel; }
			}
		}
		catch (const std::filesystem::filesystem_error& e) 
		{
			
		}
    }

	sus3d::Model* BlockModelsStorage::getBlockModel(const int id)
	{
		auto it = blockModels.find(id);
		if (it == blockModels.end()) { return nullptr; }
		return it->second;
	}

	sus3d::Model* BlockModelsStorage::getModel(const std::filesystem::path& path)
	{
		auto it = allModels.find(path);
		if (it == allModels.end()) { return nullptr; }
		return it->second;
	}

	void BlockModelsStorage::tryRenderBlock(
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

	BlockModelsStorage* BlockModelsStorage::getInstance() 
	{

		if (!instance) 
		{
			instance = new BlockModelsStorage;
			instance->init();
		}
		return instance;
	}

	BlockModelsStorage* BlockModelsStorage::instance = nullptr;
}