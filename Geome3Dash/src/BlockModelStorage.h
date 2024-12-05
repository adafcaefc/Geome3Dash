#pragma once

#include "engine/sus3d/Model.h"

#include <unordered_map>
#include <glm/glm.hpp>

namespace sus3d
{
	class Model;
	class ShaderProgram;
	class Camera;
	class Light;
}

namespace g3d
{
	class BlockModelStorage 
	{
	private:
		BlockModelStorage() {}
	protected:
		std::unordered_map<int, sus3d::Model*> blockModels;
		std::unordered_map<std::filesystem::path, sus3d::Model*> allModels;
		sus3d::ShaderProgram* blockShaderProgram;
		sus3d::ShaderProgram* waterShaderProgram;
		sus3d::ShaderProgram* cloudShaderProgram;
		sus3d::ShaderProgram* idBufferShaderProgram;
		static BlockModelStorage* instance;
		sus3d::ShaderProgram* loadShader(const std::string& vsString, const std::string& fsString);
		void loadAllShaders();
		void loadAllModels();
		bool init();
		std::filesystem::path basePath;
	public:
		sus3d::ShaderProgram* getBlockSP() { return blockShaderProgram; }
		sus3d::ShaderProgram* getWaterSP() { return waterShaderProgram; }
		sus3d::ShaderProgram* getCloudSP() { return cloudShaderProgram; }
		sus3d::ShaderProgram* getIdBufferSP() { return idBufferShaderProgram; }
		std::filesystem::path getBP() { return basePath; }
		void tryRenderBlock(
			const int objectId, 
			sus3d::Camera* camera, 
			sus3d::Light* light);
		void parseMtlPath(const std::filesystem::path& path);
		sus3d::Model* getModel(const std::filesystem::path& path);
		sus3d::Model* getBlockModel(const int id);
		static BlockModelStorage* get();

		template <typename ModelT = sus3d::Model>
		ModelT* loadAndParseMtl(const std::filesystem::path& path)
		{
			if (!path.has_parent_path()) { return nullptr; }
			const auto modelDir = path.parent_path();
			const auto mtlPath = path.parent_path() / (path.stem().string() + ".mtl");
			parseMtlPath(mtlPath);
			return sus3d::loadModelT<ModelT>(path);
		}

		template <typename ModelT>
		ModelT* getModelT(const std::filesystem::path& path)
		{
			static std::unordered_map<std::filesystem::path, ModelT*> cModels;
			auto it = cModels.find(path);
			if (it == cModels.end()) 
			{ 
				if (auto model = loadAndParseMtl<ModelT>(path))
				{
					cModels[path] = model;
					return model;
				}
				return nullptr;
			}
			return it->second;
		}
	};
}

