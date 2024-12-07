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

	void GroundObjectModel::render(
		sus3d::ShaderProgram* shaderProgram,
		const sus3d::Camera& camera,
		const sus3d::Light& light)
	{
		const auto scaleX = gameObject->m_scaleX;
		const auto scaleY = gameObject->m_scaleY;
		gameObject->m_scaleX = groundSize / 30.f;
		gameObject->m_scaleY = groundSize / 30.f;
		enableColor();

		GameObjectModel::render(shaderProgram, camera, light);
		disableColor();
	}
}