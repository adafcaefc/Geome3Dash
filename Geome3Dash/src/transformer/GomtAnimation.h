#pragma once

#include "AGomtSpline.h"

namespace sus3d 
{
	class Spline;
}

namespace g3d
{
	class GomtAnimation : public AGomtSpline
	{
	protected:
		sus3d::Spline* spline;
		float* lengthScaleFactor;
		void animateRotationSaw(GameObjectModel* gom);
		void animateJumpRing(GameObjectModel* gom);
		void animateCoin(GameObjectModel* gom);
	public:
		virtual void transform(GameObjectModel* gom) override;
		virtual ~GomtAnimation() = default;

		GomtAnimation(
			sus3d::Spline* spline,
			float* lcf)
			: spline(spline)
			, lengthScaleFactor(lcf)
		{

		}

		GomtAnimation() {}
	};
}