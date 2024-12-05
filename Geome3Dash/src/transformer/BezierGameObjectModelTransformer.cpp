#include "pch.h"

#include "BezierGameObjectModelTransformer.h"
#include "GameObjectModel.h"

namespace g3d
{
	void BezierGameObjectModelTransformer::transform(GameObjectModel* gom)
	{
		auto bCoordinate = BezierManager::transformIntoBezierCoordinate(
			bezier,
			gom->getPositionX(), gom->getPositionY(), gom->getPositionZ(),
			bezierSegmentCount, bezierSegmentMultiplier);
		gom->setPosition(bCoordinate.position);
		gom->setRotationY(360 - bCoordinate.rotation);
	}
}