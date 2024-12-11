#pragma once

#include "AGomtSpline.h"

namespace g3d
{
	class GomtSpline : public AGomtSpline
	{
	protected:
		sus3d::Spline* spline;
		float* lengthScaleFactor;
	public:
		virtual void transform(GameObjectModel* gom) override;
		virtual ~GomtSpline() = default;
		GomtSpline(sus3d::Spline* spline, float* lengthScaleFactor)
			: spline(spline)
			, lengthScaleFactor(lengthScaleFactor)
		{

		}
		GomtSpline() {}
	};
}