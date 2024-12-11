#include "pch.h"

#include "AGomtSpline.h"
#include "engine/sus3d/spline/Spline.h"

namespace g3d
{
	AGomtSpline::SplineCoord AGomtSpline::calculateSpline(
		sus3d::Spline* spline,
		const float lengthScaleFactor, 
		const float x,
		const float y,
		const float rotation)
	{
		auto data = spline->findClosestByLength(x * lengthScaleFactor);

		auto pos = data.value;
		auto normal = glm::normalize(spline->normal(data.t));
		auto tangent = glm::normalize(spline->tangent(data.t));

		glm::vec3 side(1.f, 0.f, 0.f);
		float normalDeltaAngle = glm::radians(rotation);

		glm::quat firstRotationQuat = glm::angleAxis(normalDeltaAngle, side);

		glm::vec3 binormal = glm::normalize(glm::cross(normal, tangent));
		glm::vec3 adjustedNormal = glm::normalize(glm::cross(tangent, binormal));

		glm::mat3 rotationMatrix(
			binormal,
			adjustedNormal,
			tangent);

		glm::quat rotationQuat = glm::quat_cast(rotationMatrix);
		glm::vec3 eulerDegrees = glm::degrees(glm::eulerAngles(rotationQuat * firstRotationQuat));

		return SplineCoord
		{
			pos + (normal * (lengthScaleFactor) * (static_cast<float>(y) - 110.f)),
			eulerDegrees
		};
	}
}