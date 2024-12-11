#pragma once

#include <glm/glm.hpp>

namespace sus3d
{
	struct Curve
	{
		glm::vec3 p1;
		glm::vec3 m1;
		glm::vec3 m2;
		glm::vec3 p2;

		float p1NormalAngle = 0;
		float p2NormalAngle = 0;

		glm::vec3 lerp(const glm::vec3& p0, const glm::vec3& p1, const float t);

		glm::vec3 get(float t);
		glm::vec3 tangent(float t);
		glm::vec3 normal(float t);

		float length(int steps);

		float closestParameter(const glm::vec3& point, const int steps = 100);

		Curve(
			const glm::vec3& p1,
			const glm::vec3& m1,
			const glm::vec3& m2,
			const glm::vec3& p2);

		Curve() {}
	};
}