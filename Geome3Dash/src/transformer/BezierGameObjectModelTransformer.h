#pragma once

#include "GameObjectModelTransformer.h"
#include "BezierManager.h"

namespace g3d
{
	class BezierGameObjectModelTransformer : public GameObjectModelTransformer
	{
	protected:
		CubicBezier bezier;
		double bezierSegmentMultiplier;
		int bezierSegmentCount;
	public:
		virtual void transform(GameObjectModel* gom) override;
		BezierGameObjectModelTransformer(
			const CubicBezier& bezier,
			const double bezierSegmentMultiplier,
			const int bezierSegmentCount)
			: bezier(bezier)
			, bezierSegmentMultiplier(bezierSegmentMultiplier)
			, bezierSegmentCount(bezierSegmentCount)
		{

		}
		virtual ~BezierGameObjectModelTransformer() = default;
	};
}