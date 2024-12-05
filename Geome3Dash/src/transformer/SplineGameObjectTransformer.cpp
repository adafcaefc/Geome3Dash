#include "pch.h"

#include "SplineGameObjectTransformer.h"
#include "GameObjectModel.h"

namespace g3d
{
	void SplineGameObjectTransformer::transform(GameObjectModel* gom)
	{
		auto playerDataStruct = spline->findClosestByLength(gom->getGameObject()->getPositionX() * lengthScaleFactor);
		auto normal = glm::normalize(spline->normal(playerDataStruct.t));
		auto tangent = glm::normalize(spline->tangent(playerDataStruct.t));

		glm::vec3 side(1.f, 0.f, 0.f);
		float normalDeltaAngle = glm::radians(gom->getGameObject()->getRotation());

		glm::quat firstRotationQuat = glm::angleAxis(normalDeltaAngle, side);

		glm::vec3 binormal = glm::normalize(glm::cross(normal, tangent));
		glm::vec3 adjustedNormal = glm::normalize(glm::cross(tangent, binormal));


		glm::mat3 rotationMatrix(
			binormal,
			adjustedNormal,
			tangent
		);

		glm::quat rotationQuat = glm::quat_cast(rotationMatrix);
		glm::vec3 eulerDegrees = glm::degrees(glm::eulerAngles(rotationQuat * firstRotationQuat));

		// what if mini?
		gom->setRotation(eulerDegrees);
		gom->setScale(glm::vec3(
			0.5 * lengthScaleFactor * 30, 
			0.5 * lengthScaleFactor * 30, 
			0.5 * lengthScaleFactor * 30));

		gom->setPosition(glm::vec3(playerDataStruct.value
			+ (spline->normal(playerDataStruct.t)
			* lengthScaleFactor
			* (gom->getGameObject()->getPositionY() - 110))));
	}
}