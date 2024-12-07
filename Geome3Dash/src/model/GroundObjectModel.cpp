#include "pch.h"

#include "GroundObjectModel.h"

namespace g3d
{
	void GroundObjectModel::loadGroundModel()
	{
		auto mm = ModelManager::get();
		const auto gIdStr = std::to_string(groundId);
		this->model = mm->getModel(mm->getBP() / "environment" / "ground" / gIdStr / "model.obj");
	}

	void GroundObjectModel::enableColor()
	{
		if (auto gsprites = gameLayer->getChildByIDRecursive("ground-sprites"))
		{
			if (auto grounds = gsprites->getChildByType<CCSprite>(0))
			{
				if (auto ground = grounds->getChildByType<CCSprite>(0))
				{
					auto color = ground->getColor();
					for (auto& mesh : this->model->meshes)
					{
						mesh->setCustomKa(glm::vec3(color.r, color.g, color.b) * glm::vec3(1.f / 255.f));
					}
				}
			}
		}
	}

	void GroundObjectModel::disableColor()
	{
		for (auto& mesh : this->model->meshes)
		{
			mesh->disableKa();
		}
	}

	void GroundObjectModel::update()
	{
		// do nothing, don't fetch any data
		// it's ground I use the gameObject as a template
	}

	void GroundObjectModel::render(
		sus3d::ShaderProgram* shaderProgram,
		const sus3d::Camera& camera,
		const sus3d::Light& light)
	{
		const auto groundScale = groundSize / 30.f;
		const auto scaleX = gameObject->m_scaleX;
		const auto scaleY = gameObject->m_scaleY;
		gameObject->m_scaleX = groundScale;
		gameObject->m_scaleY = groundScale;
		this->scale = glm::vec3(groundScale);

		const auto posX = gameObject->m_positionX;
		const auto posY = gameObject->m_positionY;
		gameObject->m_positionY = groundSize * 0.5f;
		this->position.y = gameObject->m_positionY;

		const auto rot = gameObject->getRotation();
		gameObject->setRotation(0.f);
		this->rotation = glm::vec3(0.f);

		enableColor();

		const auto gpos = gameLayer->m_player1->m_position.x;
		const auto gspan = groundSize * groundCount;
		for (float mypos = 0.f; mypos < gpos + gspan; mypos += groundSize)
		{
			if (mypos < gpos - gspan * 0.5f) { continue; }
			gameObject->m_positionX = mypos;
			this->position.x = gameObject->m_positionX;
			GameObjectModel::render(shaderProgram, camera, light);
		}
		
		disableColor();

		gameObject->m_scaleX = scaleX;
		gameObject->m_scaleY = scaleY;
		gameObject->m_positionX = posX;
		gameObject->m_positionY = posY;
		gameObject->setRotation(rot);
	}
}