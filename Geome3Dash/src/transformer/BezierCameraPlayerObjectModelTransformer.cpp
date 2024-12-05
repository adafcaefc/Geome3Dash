#include "pch.h"

#include "BezierCameraPlayerObjectModelTransformer.h"
#include "game/playing/G3DPlayLayer.h"

namespace g3d
{
	void BezierCameraPlayerObjectModelTransformer::transform(GameObjectModel* gom)
	{
		if (auto pom = dynamic_cast<PlayerObjectModel*>(gom))
		{
			auto playerPos = pom->getPosition();
			auto newR = pom->getRotation();
			auto playerYaw = newR.y;
			auto playerYawR = -glm::radians(playerYaw);
			const auto playerCameraOffset = playLayer3d->playerCameraOffset;
			const auto playerCameraYawOffset = playLayer3d->playerCameraYawOffset;
			const auto playerCameraPitchOffset = playLayer3d->playerCameraPitchOffset;

			glm::vec3 rotatedOffset =
			{
				playerCameraOffset.x * std::cos(playerYawR) - playerCameraOffset.z * std::sin(playerYawR),
				playerCameraOffset.y,
				playerCameraOffset.x * std::sin(playerYawR) + playerCameraOffset.z * std::cos(playerYawR)
			};

			playLayer3d->camera.setPosition(playerPos + rotatedOffset);
			// Clamp pitch to prevent flipping
			playLayer3d->camera.setYaw(playerCameraYawOffset - playerYaw);
			auto pitch = std::clamp(static_cast<float>(playerCameraPitchOffset), -89.0f, 89.0f);
			playLayer3d->camera.setPitch(pitch);
		}
	}
}