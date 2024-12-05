#pragma once

#include "GameObjectModelTransformer.h"

namespace g3d
{
	class G3DPlayLayer;
	class SplineCameraPlayerObjectModelTransformer : public GameObjectModelTransformer
	{
	public:
		G3DPlayLayer* playLayer3d;
		virtual void transform(GameObjectModel* gom) override;
		SplineCameraPlayerObjectModelTransformer(G3DPlayLayer* playLayer3d)
			: playLayer3d(playLayer3d)
		{

		}
		virtual ~SplineCameraPlayerObjectModelTransformer() = default;
	};
}