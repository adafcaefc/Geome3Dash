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

		virtual void update()
		{
			this->setPosition(glm::vec3(
				gameObject->m_positionX * 0.05,
				gameObject->m_positionY * 0.05,
				20.f));
			this->setRotationX(0);
			this->setRotationZ(360 - gameObject->getRotation());
			this->setScale(glm::vec3(
				0.75 * (gameObject->m_startFlipX ? -1 : 1), 
				0.75 * (gameObject->m_startFlipY ? -1 : 1), 0.75));
			this->setScaleX(this->getScaleX() * gameObject->m_scaleX);
			this->setScaleY(this->getScaleY() * gameObject->m_scaleY);
			this->setOpacity(gameObject->groupOpacityMod());
			//this->setVisible(gameObject->isVisible());
		}

		virtual void applyTransformation()
		{
			for (auto& transformer : transformers) { transformer->transform(this); }
		}

		virtual void render(
			sus3d::ShaderProgram* shaderProgram,
			const sus3d::Camera& camera,
			const sus3d::Light& light)
		{
			this->update();
			this->applyTransformation();

			//if (!this->getVisible()) { return; }

			auto tScale = model->getScale();
			auto tPos = model->getPosition();
			auto tRot = model->getRotation();

			model->setScale(this->getScale());
			model->setRotation(this->getRotation());
			model->setPosition(this->getPosition());

			for (auto& mesh : model->meshes) { mesh->setCustomD(this->getOpacity()); }

			model->render(
				shaderProgram,
				camera.getViewMat(),
				light.getPosition(),
				light.getColor(),
				camera.getPosition(),
				camera.getProjectionMat());

			model->setScale(tScale);
			model->setRotation(tPos);
			model->setPosition(tRot);

			for (auto& mesh : model->meshes) { mesh->disableD(); }
		}

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
		virtual void update() override
		{
			model = cube;
			if (playerObject->m_isShip) {
				model = ship;
			}
			else if (playerObject->m_isBall) {
				model = ball;
			}
			else if (playerObject->m_isBird) {
				model = bird;
			}
			else if (playerObject->m_isDart) {
				model = dart;
			}
			else if (playerObject->m_isRobot) {
				model = robot;
			}
			else if (playerObject->m_isSpider) {
				model = spider;
			}
			else if (playerObject->m_isSwing) {
				model = swing;
			}
			this->setPositionX(playerObject->m_position.x * 0.05);
			this->setPositionY(playerObject->m_position.y * 0.05);
			this->setPositionZ(20.f);
			this->setScale(glm::vec3(0.75) * glm::vec3(playerObject->getScale()));
			this->setScaleY(std::abs(this->getScaleY()) * (playerObject->m_isUpsideDown ? -1.f : 1.f));
			this->setRotationZ(360 - playerObject->getRotation());
		}

		std::filesystem::path getPlayerModelPath(const std::string& type, const int id)
		{
			return BlockModelStorage::get()->getBP() / "player" / type / std::to_string(id) / "model.obj";
		}

		std::filesystem::path getFixedPlayerModelPath(const std::string& type, const int id)
		{
			const auto path = getPlayerModelPath(type, id);
			return std::filesystem::exists(path)
				? path
				: getPlayerModelPath(type, 0);
		}

		void loadPlayerModel(sus3d::Model** model, const std::string& type, const int id)
		{
			*model = BlockModelStorage::get()->loadAndParseMtl(getFixedPlayerModelPath(type, id));
		}

		void loadPlayerModels()
		{
			loadPlayerModel(&cube, "cube", GameManager::get()->getPlayerFrame());
			loadPlayerModel(&ship, "ship", GameManager::get()->getPlayerShip());
			loadPlayerModel(&ball, "ball", GameManager::get()->getPlayerBall());
			loadPlayerModel(&bird, "bird", GameManager::get()->getPlayerBird());
			loadPlayerModel(&dart, "dart", GameManager::get()->getPlayerDart());
			loadPlayerModel(&robot, "robot", GameManager::get()->getPlayerRobot());
			loadPlayerModel(&spider, "spider", GameManager::get()->getPlayerSpider());
			loadPlayerModel(&swing, "swing", GameManager::get()->getPlayerSwing());
			model = cube;
		}

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
		virtual void transform(GameObjectModel* gom) override
		{
			auto bCoordinate = BezierManager::transformIntoBezierCoordinate(
				bezier,
				gom->getPositionX(), gom->getPositionY(), gom->getPositionZ(),
				bezierSegmentCount, bezierSegmentMultiplier);
			gom->setPosition(bCoordinate.position);
			gom->setRotationY(360 - bCoordinate.rotation);
		}
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
		virtual void transform(GameObjectModel* gom) override
		{
			auto obj = gom->getGameObject();
			auto distance = std::abs(gameLayer->m_player1->m_position.x - obj->getPositionX());
			if (distance > maxRender) {
				gom->setVisible(false);
				gom->setOpacity(0);
			} else if (distance > startFade) {
				auto scale = gom->getScale();
				double tNormal = (distance - startFade) / (maxRender - startFade);
				gom->setScale(ease::easeNormal<glm::vec3>(easing, tNormal, scale, target));
			}
		}
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