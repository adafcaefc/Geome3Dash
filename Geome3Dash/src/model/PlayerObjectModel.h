#pragma once

#include "GameObjectModel.h"

#include "impl/engine/AnimatedModel.h"

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
		sus3d::Model* swing;
		AnimatedModel* robot;
		AnimatedModel* robotJump;
		AnimatedModel* spider;
		PlayerObject* playerObject;
	public:
		virtual void update() override;
		PlayerObject* getPlayerObject() const { return playerObject; }

		std::filesystem::path getPlayerModelPath(const std::string& type, const int id);
		std::filesystem::path getFixedPlayerModelPath(const std::string& type, const int id);
		void loadPlayerModel(sus3d::Model** model, const std::string& type, const int id);
		std::filesystem::path getAnimatedPlayerModelPath(const std::string& type, const int id);
		std::filesystem::path getAnimatedFixedPlayerModelPath(const std::string& type, const int id);
		void loadAnimatedPlayerModel(AnimatedModel** model, const std::string& type, const int id);
		void loadPlayerModels();

		PlayerObjectModel() {}

		PlayerObjectModel(
			PlayerObject* obj,
			const std::vector<AGomtBase*>& transformers)
			: GameObjectModel(obj, transformers)
			, playerObject(obj)
		{
			loadPlayerModels();
		}

		virtual ~PlayerObjectModel() = default;
	};
}