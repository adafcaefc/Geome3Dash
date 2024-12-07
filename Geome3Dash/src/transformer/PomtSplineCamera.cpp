#include "pch.h"

#include "PomtSplineCamera.h"
#include "model/PlayerObjectModel.h"
#include "game/play/G3DPlayLayer.h"

namespace g3d
{
	glm::vec3 PomtSplineCamera::getPlayerOrientedCameraFront(PlayerObjectModel* pom)
	{
		auto playerDataStruct = spline->findClosestByLength(pom->getPlayerObject()->getPositionX() * (*lengthScaleFactor));
		return spline->tangent(playerDataStruct.t);
	}

	glm::vec3 PomtSplineCamera::getPlayerOrientedCameraPosition(PlayerObjectModel* pom)
	{
		auto playerDataStruct = spline->findClosestByLength(pom->getPlayerObject()->getPositionX() * (*lengthScaleFactor));
		return playerDataStruct.value + (spline->normal(playerDataStruct.t) * (*lengthScaleFactor) * (pom->getPlayerObject()->getPositionY() - 110));

	}
	void PomtSplineCamera::transform(GameObjectModel* gom)
	{
		if (auto pom = dynamic_cast<PlayerObjectModel*>(gom))
		{
			if (!(*isEditing))
			{
				auto cameraState = buffer->getInterpolatedCameraKeyframe(pom->getPlayerObject()->getPositionX());
				camera->setPosition(getPlayerOrientedCameraPosition(pom) + cameraState.offset);
				camera->setFront(getPlayerOrientedCameraFront(pom) + cameraState.front);
				light->setPosition(camera->getPosition());
			}
		}
	}
}