#include "pch.h"

#include "SplinePlayerObjectTransformer.h"
#include "PlayerObjectModel.h"

namespace g3d
{
	void SplinePlayerObjectTransformer::transform(GameObjectModel* gom)
	{
		if (auto pom = dynamic_cast<PlayerObjectModel*>(gom))
		{
			auto player = pom->getPlayerObject();
			auto data = spline->findClosestByLength(player->m_position.x * (*lengthScaleFactor));

			auto pos = data.value;
			auto normal = glm::normalize(spline->normal(data.t));
			auto tangent = glm::normalize(spline->tangent(data.t));

			glm::vec3 side(1.f, 0.f, 0.f);
			float normalDeltaAngle = glm::radians(player->getRotation());

			glm::quat firstRotationQuat = glm::angleAxis(normalDeltaAngle, side);

			glm::vec3 binormal = glm::normalize(glm::cross(normal, tangent));
			glm::vec3 adjustedNormal = glm::normalize(glm::cross(tangent, binormal));

			glm::mat3 rotationMatrix(
				binormal,
				adjustedNormal,
				tangent);

			glm::quat rotationQuat = glm::quat_cast(rotationMatrix);
			glm::vec3 eulerDegrees = glm::degrees(glm::eulerAngles(rotationQuat * firstRotationQuat));

			float scale = pom->getPlayerObject()->getScale();

			gom->setPosition(pos + (normal * (*lengthScaleFactor) * (player->m_position.y - 110)));
			gom->setRotation(eulerDegrees);
			gom->setScale(glm::vec3(
				0.5 * (player->m_startFlipX ? -1 : 1) * (*lengthScaleFactor) * 30,
				0.5 * (player->m_isUpsideDown ? -1 : 1) * (*lengthScaleFactor) * 30 * scale,
				0.5 * (*lengthScaleFactor) * 30 * scale));
		}
	}
}