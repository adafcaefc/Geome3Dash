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
}