#pragma once

#include "AGomtBase.h"

namespace sus3d
{
	class Spline;
}

namespace g3d
{
	class AGomtSpline : public AGomtBase
	{
	protected:
		struct SplineCoord
		{
			glm::vec3 pos;
			glm::vec3 rot;
		};
	public:
		virtual ~AGomtSpline() = default;
		SplineCoord calculateSpline(
			sus3d::Spline* spline,
			const float lengthScaleFactor,
			const float x,
			const float y,
			const float rotation);
		AGomtSpline() {}
	};
}