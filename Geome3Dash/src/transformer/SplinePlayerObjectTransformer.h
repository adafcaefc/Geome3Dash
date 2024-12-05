#pragma once

#include "GameObjectModelTransformer.h"
#include "helper/spline/Spline.h"

namespace g3d
{
	class SplinePlayerObjectTransformer : public GameObjectModelTransformer
	{
	protected:
		Spline* spline;
		float* lengthScaleFactor;
	public:
		virtual void transform(GameObjectModel* gom) override;
		virtual ~SplinePlayerObjectTransformer() = default;
		SplinePlayerObjectTransformer(Spline* spline, float* lengthScaleFactor)
			: spline(spline)
			, lengthScaleFactor(lengthScaleFactor)
		{

		}
	};
}