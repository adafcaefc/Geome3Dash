#include "pch.h"

#include "GomtAnimation.h"
#include "model/GameObjectModel.h"
#include "helper/spline/Spline.h"

namespace g3d
{
	void GomtAnimation::fixSawRotation(
		GameObjectModel* gom,
		const float rotation)
	{
		auto block = gom->getGameObject();
		const auto data = calculateSpline(
			spline,
			*lengthScaleFactor,
			block->m_positionX,
			block->m_positionY,
			rotation);
		gom->setRotation(data.rot);
	}

	void GomtAnimation::transform(GameObjectModel* gom)
	{
		auto block = gom->getGameObject();
		auto scale = gom->getScale();
		CCSprite* sawChild = nullptr;
		// do animations
		switch (block->m_objectID)
		{

		case 36:
		case 84:
		case 141:
		case 1022:
		case 1330:
		case 1333:
		case 1704:
		case 1751:
			// orbs
			gom->setScaleY(scale.y / block->m_scaleY * block->getScaleY());
			gom->setScaleZ(scale.z / block->m_scaleX * block->getScaleX());
			break;
		case 1705:
		case 1706:
		case 1707:
			sawChild = gom->getGameObject()->getChildByType<CCSprite>(0);
			if (sawChild) { fixSawRotation(gom, sawChild->getRotation()); }
		default:
			break;
		}
	}
}