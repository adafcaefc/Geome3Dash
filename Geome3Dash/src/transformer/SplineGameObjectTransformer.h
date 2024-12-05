#pragma once

#include "GameObjectModelTransformer.h"
#include "helper/spline/Spline.h"

namespace g3d
{
	class SplineGameObjectTransformer : public GameObjectModelTransformer
	{
	protected:
		Spline* spline;
		float* lengthScaleFactor;
	public:
		virtual void transform(GameObjectModel* gom) override;
		virtual ~SplineGameObjectTransformer() = default;
		SplineGameObjectTransformer(Spline* spline, float* lengthScaleFactor)
			: spline(spline)
			, lengthScaleFactor(lengthScaleFactor)
		{

		}
	};
}