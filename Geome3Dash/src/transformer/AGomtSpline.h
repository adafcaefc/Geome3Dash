#pragma once

#include "AGomtBase.h"

namespace g3d
{
	class Spline;
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
		virtual SplineCoord AGomtSpline::calculateSpline(
			Spline* spline,
			const float lengthScaleFactor,
			const float x,
			const float y,
			const float rotation);
	};
}