#pragma once

#include "AGomtSpline.h"

namespace g3d
{
	class Spline;
	class GomtAnimation : public AGomtSpline
	{
	protected:
		Spline* spline;
		float* lengthScaleFactor;
		void animateRotationSaw(GameObjectModel* gom);
		void animateJumpRing(GameObjectModel* gom);
		void animateCoin(GameObjectModel* gom);
	public:
		virtual void transform(GameObjectModel* gom) override;
		virtual ~GomtAnimation() = default;

		GomtAnimation(
			Spline* spline,
			float* lcf)
			: spline(spline)
			, lengthScaleFactor(lcf)
		{

		}

		GomtAnimation() {}
	};
}