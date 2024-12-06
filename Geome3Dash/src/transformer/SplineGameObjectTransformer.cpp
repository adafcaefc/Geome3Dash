#include "pch.h"

#include "SplineGameObjectTransformer.h"
#include "GameObjectModel.h"

namespace g3d
{
	void SplineGameObjectTransformer::transform(GameObjectModel* gom)
	{
		auto block = gom->getGameObject();
		auto data = spline->findClosestByLength(block->m_positionX * (*lengthScaleFactor));

		auto pos = data.value;
		auto normal = glm::normalize(spline->normal(data.t));
		auto tangent = glm::normalize(spline->tangent(data.t));

		glm::vec3 side(1.f, 0.f, 0.f);
		float normalDeltaAngle = glm::radians(block->getRotation());

		glm::quat firstRotationQuat = glm::angleAxis(normalDeltaAngle, side);

		glm::vec3 binormal = glm::normalize(glm::cross(normal, tangent));
		glm::vec3 adjustedNormal = glm::normalize(glm::cross(tangent, binormal));

		glm::mat3 rotationMatrix(
			binormal,
			adjustedNormal,
			tangent);

		glm::quat rotationQuat = glm::quat_cast(rotationMatrix);
		glm::vec3 eulerDegrees = glm::degrees(glm::eulerAngles(rotationQuat * firstRotationQuat));

		gom->setPosition(pos + (normal * (*lengthScaleFactor) * (static_cast<float>(block->m_positionY) - 110)));
		gom->setRotation(eulerDegrees);
		gom->setScale(glm::vec3(
			0.5 * (block->m_startFlipX ? -1 : 1) * (*lengthScaleFactor) * 30,
			0.5 * (block->m_startFlipY ? -1 : 1) * (*lengthScaleFactor) * 30 * block->m_scaleY,
			0.5 * (block->m_startFlipX ? -1 : 1) * (*lengthScaleFactor) * 30 * block->m_scaleX));
	}
}