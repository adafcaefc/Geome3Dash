#pragma once

#include "AGomtSpline.h"

namespace g3d
{
	class PomtSpline : public AGomtSpline
	{
	protected:
		sus3d::Spline* spline;
		float* lengthScaleFactor;
	public:
		virtual void transform(GameObjectModel* gom) override;
		virtual ~PomtSpline() = default;
		PomtSpline(sus3d::Spline* spline, float* lengthScaleFactor)
			: spline(spline)
			, lengthScaleFactor(lengthScaleFactor)
		{

		}

		PomtSpline() {}
	};
}