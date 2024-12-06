#include "pch.h"

#include "BlockModelStorage.h"

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
	sus3d::ShaderProgram* BlockModelStorage::loadShader(
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

	void BlockModelStorage::loadAllShaders()
	{
		OpenGLStateHelper::saveState();

		const auto shaderPath = basePath / "planet" / "shader";

		blockShaderProgram = loadShader(
			sus3d::shaders::vertexShaderSource,
			sus3d::shaders::fragmentShaderSource);

		waterShaderProgram = loadShader(
			sus3d::shaders::vertexShaderSource,
			utils::read_from_file(shaderPath / "water2.fsh"));

		cloudShaderProgram = loadShader(
			utils::read_from_file(shaderPath / "cloud.vsh"),
			utils::read_from_file(shaderPath / "cloud.fsh"));

		idBufferShaderProgram = loadShader(
			sus3d::shaders::idBufferingVertexShader,
			sus3d::shaders::idBufferingFragmentShader);

		OpenGLStateHelper::pushState();
	}

	bool BlockModelStorage::init() 
	{
		basePath = geode::Mod::get()->getResourcesDir() / "model3d";
		loadAllShaders();
		loadAllModels();
		return true;
	}
	
    // mtl model path fix (model path must be absolute)
    void BlockModelStorage::parseMtlPath(const std::filesystem::path& path)
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

    void BlockModelStorage::loadAllModels()
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

			constexpr int MAX_OBJECT_ID = 10000;
			for (int i = 0; i < MAX_OBJECT_ID; i++)
			{
				const auto modelPath = basePath / "object" / std::to_string(i) / "model.obj";
				if (auto blockModel = getModel(modelPath)) { blockModels[i] = blockModel; }
			}
		}
		catch (...) 
		{
			
		}
    }

	sus3d::Model* BlockModelStorage::getBlockModel(const int id)
	{
		auto it = blockModels.find(id);
		if (it == blockModels.end()) { return nullptr; }
		return it->second;
	}

	sus3d::Model* BlockModelStorage::getModel(const std::filesystem::path& path)
	{
		auto it = allModels.find(path);
		if (it == allModels.end()) { return nullptr; }
		return it->second;
	}

	void BlockModelStorage::tryRenderBlock(
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

	BlockModelStorage* BlockModelStorage::get() 
	{
		if (!instance) 
		{
			instance = new BlockModelStorage;
			instance->init();
		}
		return instance;
	}

	BlockModelStorage* BlockModelStorage::instance = nullptr;
}