#pragma once

#include "GameObjectModelTransformer.h"

namespace g3d
{
	class G3DPlayLayer;
	class BezierCameraPlayerObjectModelTransformer : public GameObjectModelTransformer
	{
	public:
		G3DPlayLayer* playLayer3d;
		virtual void transform(GameObjectModel* gom) override;
		BezierCameraPlayerObjectModelTransformer(G3DPlayLayer* playLayer3d)
			: playLayer3d(playLayer3d)
		{

		}
		virtual ~BezierCameraPlayerObjectModelTransformer() = default;
	};
}