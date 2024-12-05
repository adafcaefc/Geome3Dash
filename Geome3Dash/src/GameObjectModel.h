#pragma once

#include "engine/sus3d/Model.h"
#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Scene.h"

#include "BezierManager.h"
#include "BlockModelStorage.h"

#include "helper/Easing.h"

class GameObject;

namespace g3d
{
	class G3DPlayLayer;
	class GameObjectModel;
	class GameObjectModelTransformer
	{
	public:
		virtual void transform(GameObjectModel* gom) = 0;
		virtual ~GameObjectModelTransformer() {}
	};

	class GameObjectModel : public sus3d::ModelProtocol
	{
	protected:
		float opacity = 1.0f;
		sus3d::Model* model;
		std::vector<GameObjectModelTransformer*> transformers;
		GameObject* gameObject;
	public:
		GameObject* getGameObject() { return this->gameObject; }
		sus3d::Model* getModel() { return this->model; }
		void setOpacity(const float op) { this->opacity = op; }
		float getOpacity() const { return this->opacity; }

		virtual void update();
		virtual void applyTransformation();
		virtual void render(
			sus3d::ShaderProgram* shaderProgram,
			const sus3d::Camera& camera,
			const sus3d::Light& light);
		
		GameObjectModel() {}
		
		GameObjectModel(
			GameObject* obj, 
			const std::vector<GameObjectModelTransformer*>& transformers) 
			: gameObject(obj)
			, transformers(transformers)
		{ 
			sus3d::ModelProtocol();
			this->model = BlockModelStorage::get()->getBlockModel(gameObject->m_objectID);
		}

		virtual ~GameObjectModel()
		{
			// memory leak but idk how to fix yet
			// nvm I think the scene should own the pointer to transformers
			for (auto& transformer : transformers) { /*delete transformer;*/ }
		}
	};

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

	class DefaultGameObjectModelTransformer : public GameObjectModelTransformer
	{
	public:
		virtual void transform(GameObjectModel* gom) override {};
		virtual ~DefaultGameObjectModelTransformer() = default;
	};

	class BezierGameObjectModelTransformer : public GameObjectModelTransformer
	{
	protected:
		CubicBezier bezier;
		double bezierSegmentMultiplier;
		int bezierSegmentCount;
	public:
		virtual void transform(GameObjectModel* gom) override;
		BezierGameObjectModelTransformer(
			const CubicBezier& bezier,
			const double bezierSegmentMultiplier,
			const int bezierSegmentCount)
			: bezier(bezier)
			, bezierSegmentMultiplier(bezierSegmentMultiplier)
			, bezierSegmentCount(bezierSegmentCount)
		{

		}
		virtual ~BezierGameObjectModelTransformer() = default;
	};

	class FadeGameObjectModelTransformer : public GameObjectModelTransformer
	{
	protected:
		GJBaseGameLayer* gameLayer;
		double maxRender;
		double startFade;
		ease::Base* easing;
		glm::vec3 target;
	public:
		double getMaxRender() { return maxRender; }
		virtual void transform(GameObjectModel* gom) override;
		FadeGameObjectModelTransformer(
			GJBaseGameLayer* layer,
			double maxR, 
			double startF,
			ease::Base* easeFunc, 
			const glm::vec3& tgt)
			: gameLayer(layer)
			, maxRender(maxR)
			, startFade(startF)
			, easing(easeFunc)
			, target(tgt) 
		{
		
		}

		virtual ~FadeGameObjectModelTransformer() = default;
	};

	class AnimationGameObjectModelTransformer : public GameObjectModelTransformer
	{
	public:
		virtual void transform(GameObjectModel* gom) override 
		{
			switch (gom->getGameObject()->m_objectID)
			{
				// do animations
			}
		};
		virtual ~AnimationGameObjectModelTransformer() = default;
	};

	class BezierCameraPlayerObjectModelTransformer : public GameObjectModelTransformer
	{
	public:
		G3DPlayLayer* playLayer3d;
		virtual void transform(GameObjectModel* gom) override;
		BezierCameraPlayerObjectModelTransformer(G3DPlayLayer* playLayer3d)
			: playLayer3d(playLayer3d)
		{

		}
		virtual ~BezierCameraPlayerObjectModelTransformer() = default;
	};
}