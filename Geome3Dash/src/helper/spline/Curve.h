#pragma once

namespace g3d
{
	struct Curve {
		glm::vec3 p1;
		glm::vec3 m1;
		glm::vec3 m2;
		glm::vec3 p2;

		float p1NormalAngle = 0;
		float p2NormalAngle = 0;

		Curve(glm::vec3 p1, glm::vec3 m1, glm::vec3 m2, glm::vec3 p2);

		glm::vec3 lerp(glm::vec3 p0, glm::vec3 p1, float t);

		glm::vec3 get(float t);
		glm::vec3 tangent(float t);
		glm::vec3 normal(float t);

		float length(int steps);

		float closestParameter(glm::vec3 point, int steps = 100);
	};
}