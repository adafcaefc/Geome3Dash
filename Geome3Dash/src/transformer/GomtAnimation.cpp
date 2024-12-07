#include "pch.h"

#include "GomtAnimation.h"
#include "model/GameObjectModel.h"
#include "helper/spline/Spline.h"

namespace g3d
{
	void GomtAnimation::animateRotationSaw(GameObjectModel* gom)
	{
		auto block = gom->getGameObject();
		auto sawChild = block->getChildByType<CCSprite>(0);
		if (sawChild) 
		{ 
			const auto data = calculateSpline(
				spline,
				*lengthScaleFactor,
				block->m_positionX,
				block->m_positionY,
				sawChild->getRotation());
			gom->setRotation(data.rot);
		}
	}
	void GomtAnimation::animateJumpRing(GameObjectModel* gom)
	{
		auto block = gom->getGameObject();
		auto scale = gom->getScale();
		gom->setScaleX(scale.y / block->m_scaleY * block->getScaleY());
		gom->setScaleY(scale.y / block->m_scaleY * block->getScaleY());
		gom->setScaleZ(scale.z / block->m_scaleX * block->getScaleX());
	}

	void GomtAnimation::transform(GameObjectModel* gom)
	{
		switch (gom->getGameObject()->m_objectID)
		{

		case 36:
		case 84:
		case 141:
		case 1022:
		case 1330:
		case 1333:
		case 1704:
		case 1751:
			animateJumpRing(gom);
			break;
		case 1705:
		case 1706:
		case 1707:
			animateRotationSaw(gom);
			break;
		default:
			break;
		}
	}
}