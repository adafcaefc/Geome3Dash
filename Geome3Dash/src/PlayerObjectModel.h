#pragma once

#include "GameObjectModel.h"

class GameObject;
class PlayerObject;

namespace g3d
{
	class PlayerObjectModel : public GameObjectModel
	{
	protected:
		sus3d::Model* cube;
		sus3d::Model* ship;
		sus3d::Model* ball;
		sus3d::Model* bird;
		sus3d::Model* dart;
		sus3d::Model* robot;
		sus3d::Model* spider;
		sus3d::Model* swing;
		PlayerObject* playerObject;
	public:
		virtual void update() override;
		PlayerObject* getPlayerObject() const { return playerObject; }

		std::filesystem::path getPlayerModelPath(const std::string& type, const int id);
		std::filesystem::path getFixedPlayerModelPath(const std::string& type, const int id);
		void loadPlayerModel(sus3d::Model** model, const std::string& type, const int id);
		void loadPlayerModels();

		PlayerObjectModel() {}

		PlayerObjectModel(
			PlayerObject* obj,
			const std::vector<GameObjectModelTransformer*>& transformers)
			: GameObjectModel(obj, transformers)
			, playerObject(obj)
		{
			loadPlayerModels();
		}

		virtual ~PlayerObjectModel() = default;
	};
}