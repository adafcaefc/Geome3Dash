#include "pch.h"

#include "SplineCameraPlayerObjectModelTransformer.h"
#include "PlayerObjectModel.h"
#include "game/playing/G3DPlayLayer.h"

namespace g3d
{
	glm::vec3 SplineCameraPlayerObjectModelTransformer::getPlayerOrientedCameraFront(PlayerObjectModel* pom)
	{
		auto playerDataStruct = spline->findClosestByLength(pom->getPlayerObject()->getPositionX() * (*lengthScaleFactor));
		return spline->tangent(playerDataStruct.t);
	}

	glm::vec3 SplineCameraPlayerObjectModelTransformer::getPlayerOrientedCameraPosition(PlayerObjectModel* pom)
	{
		auto playerDataStruct = spline->findClosestByLength(pom->getPlayerObject()->getPositionX() * (*lengthScaleFactor));
		return playerDataStruct.value + (spline->normal(playerDataStruct.t) * (*lengthScaleFactor) * (pom->getPlayerObject()->getPositionY() - 110));

	}
	void SplineCameraPlayerObjectModelTransformer::transform(GameObjectModel* gom)
	{
		if (auto pom = dynamic_cast<PlayerObjectModel*>(gom))
		{
			if (!(*isEditing))
			{
				auto cameraState = buffer->getInterpolatedCameraKeyframe(pom->getPlayerObject()->getPositionX());
				camera->setPosition(getPlayerOrientedCameraPosition(pom) + cameraState.offset);
				camera->setFront(getPlayerOrientedCameraFront(pom) + cameraState.front);
			}
		}
	}
}