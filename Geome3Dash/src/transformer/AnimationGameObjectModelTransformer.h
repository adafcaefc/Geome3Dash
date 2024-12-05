#pragma once

#include "GameObjectModelTransformer.h"

namespace g3d
{
	class AnimationGameObjectModelTransformer : public GameObjectModelTransformer
	{
	public:
		virtual void transform(GameObjectModel* gom) override;
		virtual ~AnimationGameObjectModelTransformer() = default;
	};
}