#pragma once

#include "AGomtSpline.h"

namespace g3d
{
	class GomtSpline : public AGomtSpline
	{
	protected:
		Spline* spline;
		float* lengthScaleFactor;
	public:
		virtual void transform(GameObjectModel* gom) override;
		virtual ~GomtSpline() = default;
		GomtSpline(Spline* spline, float* lengthScaleFactor)
			: spline(spline)
			, lengthScaleFactor(lengthScaleFactor)
		{

		}
		GomtSpline() {}
	};
}