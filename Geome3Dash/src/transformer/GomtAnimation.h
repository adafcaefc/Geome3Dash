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
		void fixSawRotation(GameObjectModel* gom, const float rotation);
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
	};
}