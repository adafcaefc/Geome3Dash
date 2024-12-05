#include "pch.h"

#include "SplineCameraPlayerObjectModelTransformer.h"
#include "PlayerObjectModel.h"
#include "game/playing/G3DPlayLayer.h"

namespace g3d
{
	void SplineCameraPlayerObjectModelTransformer::transform(GameObjectModel* gom)
	{
		if (auto pom = dynamic_cast<PlayerObjectModel*>(gom))
		{
			Spline* spline = &playLayer3d->levelData.spline;
			auto player = playLayer3d->playLayer->m_player1;
			auto playerDataStruct = spline->findClosestByLength(player->getPositionX() * playLayer3d->lengthScaleFactor);
			//auto cameraKeyframeData = cameraKeyframeBuffer->getInterpolatedCameraKeyframe(pl->m_player1->getPositionX());
			playLayer3d->camera.setPosition(playerDataStruct.value + (spline->normal(playerDataStruct.t) * playLayer3d->lengthScaleFactor * (player->getPositionY() - 110)) /*+ cameraKeyframeData->offset*/);
			playLayer3d->camera.setFront(spline->tangent(playerDataStruct.t)  /* + cameraKeyframeData->front*/);
		}
	}
}