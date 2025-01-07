#include "pch.h"

#include "PlayerObjectModel.h"

namespace g3d
{
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
			if (playerObject->m_isOnGround) {
				robotJump->resetAnimation();
				model = robot;
			}
			else {
				robotJump->setLoop(false);
				model = robotJump;
			}
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
		loadPlayerModel(&swing, "swing", GameManager::get()->getPlayerSwing());
		loadAnimatedPlayerModel(&robot, "robot", GameManager::get()->getPlayerRobot());
		loadAnimatedPlayerModel(&robotJump, "robotjump", GameManager::get()->getPlayerRobot());
		loadAnimatedPlayerModel(&spider, "spider", GameManager::get()->getPlayerSpider());
		model = cube;
	}

	std::filesystem::path PlayerObjectModel::getPlayerModelPath(const std::string& type, const int id)
	{
		return ModelManager::get()->getBP() / "player" / type / std::to_string(id) / "model.obj";
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
		*model = ModelManager::get()->getModel(getFixedPlayerModelPath(type, id));
	}

	std::filesystem::path PlayerObjectModel::getAnimatedPlayerModelPath(const std::string& type, const int id)
	{
		return ModelManager::get()->getABP() / "player" / type / std::to_string(id);
	}

	std::filesystem::path PlayerObjectModel::getAnimatedFixedPlayerModelPath(const std::string& type, const int id)
	{
		const auto path = getAnimatedPlayerModelPath(type, id);
		return std::filesystem::exists(path / "fps.txt")
			? path
			: getAnimatedPlayerModelPath(type, 0);
	}

	void PlayerObjectModel::loadAnimatedPlayerModel(AnimatedModel** model, const std::string& type, const int id)
	{
		// *model = AnimatedModel::create(getAnimatedPlayerModelPath(type, id), this->playerObject);
		// temporary 0 cuz its broken idk why
		// you would want to put id instead of 0
		*model = AnimatedModel::create(getAnimatedPlayerModelPath(type, 0), this->playerObject);
	}
}