#include "pch.h"

#include "AnimationGameObjectModelTransformer.h"
#include "GameObjectModel.h"

namespace g3d
{
	void AnimationGameObjectModelTransformer::transform(GameObjectModel* gom)
	{
		auto block = gom->getGameObject();
		auto scale = gom->getScale();
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
			gom->setScaleY(scale.y / block->m_scaleY * block->getScaleY());
			gom->setScaleZ(scale.z / block->m_scaleX * block->getScaleX());
			break;
		default:
			break;
		}
	}
}