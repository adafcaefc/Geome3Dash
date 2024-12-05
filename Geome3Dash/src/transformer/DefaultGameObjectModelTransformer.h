#pragma once

#include "GameObjectModelTransformer.h"

namespace g3d
{
	class DefaultGameObjectModelTransformer : public GameObjectModelTransformer
	{
	public:
		virtual void transform(GameObjectModel* gom) override {};
		virtual ~DefaultGameObjectModelTransformer() = default;
	};
}