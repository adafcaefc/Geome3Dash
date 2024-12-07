#pragma once

#include "AGomtSpline.h"

namespace g3d
{
	class PomtSpline : public AGomtSpline
	{
	protected:
		Spline* spline;
		float* lengthScaleFactor;
	public:
		virtual void transform(GameObjectModel* gom) override;
		virtual ~PomtSpline() = default;
		PomtSpline(Spline* spline, float* lengthScaleFactor)
			: spline(spline)
			, lengthScaleFactor(lengthScaleFactor)
		{

		}
	};
}