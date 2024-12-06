#include "pch.h"

#include "AnimationGameObjectModelTransformer.h"
#include "GameObjectModel.h"

namespace g3d
{
	void AnimationGameObjectModelTransformer::transform(GameObjectModel* gom)
	{
		// do animations
		switch (gom->getGameObject()->m_objectID)
		{
		case 142:
			break;
		default:
			break;
		}
	}
}