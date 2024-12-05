#include "pch.h"

#include "GameObjectModel.h"

namespace g3d
{
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
		 if (this->opacity == 0.f || this->scale == glm::vec3(0.f)) { return; }

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