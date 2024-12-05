#include "pch.h"

#include "GameObjectModel.h"
#include "game/playing/G3DPlayLayer.h"

namespace g3d
{
	void BezierCameraPlayerObjectModelTransformer::transform(GameObjectModel* gom)
	{
		if (auto pom = dynamic_cast<PlayerObjectModel*>(gom))
		{
			auto playerPos = pom->getPosition();
			auto newR = pom->getRotation();
			auto playerYaw = newR.y;
			auto playerYawR = -glm::radians(playerYaw);
			const auto playerCameraOffset = playLayer3d->playerCameraOffset;
			const auto playerCameraYawOffset = playLayer3d->playerCameraYawOffset;
			const auto playerCameraPitchOffset = playLayer3d->playerCameraPitchOffset;

			glm::vec3 rotatedOffset =
			{
				playerCameraOffset.x * std::cos(playerYawR) - playerCameraOffset.z * std::sin(playerYawR),
				playerCameraOffset.y,
				playerCameraOffset.x * std::sin(playerYawR) + playerCameraOffset.z * std::cos(playerYawR)
			};

			playLayer3d->camera.setPosition(playerPos + rotatedOffset);
			// Clamp pitch to prevent flipping
			playLayer3d->camera.setYaw(playerCameraYawOffset - playerYaw);
			auto pitch = std::clamp(static_cast<float>(playerCameraPitchOffset), -89.0f, 89.0f);
			playLayer3d->camera.setPitch(pitch);
		}
	}

	void FadeGameObjectModelTransformer::transform(GameObjectModel* gom)
	{
		auto obj = gom->getGameObject();
		auto distance = std::abs(gameLayer->m_player1->m_position.x - obj->getPositionX());
		if (distance > maxRender) {
			gom->setVisible(false);
			gom->setOpacity(0);
		}
		else if (distance > startFade) {
			auto scale = gom->getScale();
			double tNormal = (distance - startFade) / (maxRender - startFade);
			gom->setScale(ease::easeNormal<glm::vec3>(easing, tNormal, scale, target));
		}
	}

	void BezierGameObjectModelTransformer::transform(GameObjectModel* gom)
	{
		auto bCoordinate = BezierManager::transformIntoBezierCoordinate(
			bezier,
			gom->getPositionX(), gom->getPositionY(), gom->getPositionZ(),
			bezierSegmentCount, bezierSegmentMultiplier);
		gom->setPosition(bCoordinate.position);
		gom->setRotationY(360 - bCoordinate.rotation);
	}

	void PlayerObjectModel::update()
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

	void PlayerObjectModel::loadPlayerModels()
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

	std::filesystem::path PlayerObjectModel::getPlayerModelPath(const std::string& type, const int id)
	{
		return BlockModelStorage::get()->getBP() / "player" / type / std::to_string(id) / "model.obj";
	}

	std::filesystem::path PlayerObjectModel::getFixedPlayerModelPath(const std::string& type, const int id)
	{
		const auto path = getPlayerModelPath(type, id);
		return std::filesystem::exists(path)
			? path
			: getPlayerModelPath(type, 0);
	}

	void PlayerObjectModel::loadPlayerModel(sus3d::Model** model, const std::string& type, const int id)
	{
		*model = BlockModelStorage::get()->loadAndParseMtl(getFixedPlayerModelPath(type, id));
	}

	void GameObjectModel::update()
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

	void GameObjectModel::applyTransformation()
	{
		for (auto& transformer : transformers) { transformer->transform(this); }
	}

	 void GameObjectModel::render(
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
}