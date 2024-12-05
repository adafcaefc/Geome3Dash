#include "pch.h"

#include "AnimationGameObjectModelTransformer.h"
#include "GameObjectModel.h"

namespace g3d
{
	void AnimationGameObjectModelTransformer::transform(GameObjectModel* gom)
	{
		switch (gom->getGameObject()->m_objectID)
		{
			// do animations
		}
	}
}