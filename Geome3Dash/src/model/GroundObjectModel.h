#pragma once

#include "GameObjectModel.h"

class GameObject;
class PlayerObject;

namespace g3d
{
	class GroundObjectModel : public GameObjectModel
	{
	protected:
		float groundSize;
		int groundCount;
		int groundId;
		GJBaseGameLayer* gameLayer;
	public:
		virtual void update() override;
		virtual void render(
			sus3d::ShaderProgram* shaderProgram,
			const sus3d::Camera& camera,
			const sus3d::Light& light) override;

		void loadGroundModel();
		void enableColor();
		void disableColor();

		GroundObjectModel() {}
		GroundObjectModel(
			const float groundSize,
			const int groundCount,
			const int groundId,
			GJBaseGameLayer* gameLayer,
			const std::vector<AGomtBase*>& transformers)
			: GameObjectModel(gameLayer->m_player1, transformers)
			, groundSize(groundSize)
			, groundCount(groundCount)
			, groundId(groundId)
			, gameLayer(gameLayer)
		{
			this->loadGroundModel();
		}

		virtual ~GroundObjectModel() = default;
	};
}