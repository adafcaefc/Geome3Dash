#include "Curve.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>

namespace sus3d
{
	Curve::Curve(
		const glm::vec3& p1, 
		const glm::vec3& m1,
		const glm::vec3& m2,
		const glm::vec3& p2)
		: p1(p1)
		, m1(m1)
		, m2(m2)
		, p2(p2)
	{
	
	};

	float Curve::length(int steps) 
	{
		float length = 0.f;
		glm::vec3 prevPoint = get(0.0f);
		for (int i = 1; i <= steps; i++) 
		{
			float t = i / float(steps);
			glm::vec3 currentPoint = get(t);
			length += glm::length(currentPoint - prevPoint);
			prevPoint = currentPoint;
		}
		return length;
	}

	glm::vec3 Curve::get(float t) 
	{
		auto a = lerp(p1, m1, t);
		auto b = lerp(m1, m2, t);
		auto c = lerp(m2, p2, t);
		auto d = lerp(a, b, t);
		auto e = lerp(b, c, t);
		auto P = lerp(d, e, t);
		return P;
	}

	glm::vec3 Curve::lerp(const glm::vec3& p0, const glm::vec3& p1, const float t) 
	{
		return glm::vec3(
			std::lerp(p0.x, p1.x, t), 
			std::lerp(p0.y, p1.y, t), 
			std::lerp(p0.z, p1.z, t));
	}

	glm::vec3 Curve::tangent(float t) 
	{
		float delta = 1e-4f;
		glm::vec3 p0 = get(std::fmax(0.0f, t - delta));
		glm::vec3 p1 = get(std::fmin(1.0f, t + delta));
		return glm::normalize(p1 - p0);
	}

	glm::vec3 Curve::normal(float t) 
	{
		glm::vec3 tangentVec = tangent(t);

		auto angle = std::lerp(p1NormalAngle, p2NormalAngle, t);

		glm::vec3 binormal = glm::normalize(glm::cross(tangentVec, glm::vec3(0.0f, 1.0f, 0.0f)));

		if (glm::length(binormal) < 1e-6f) 
		{
			binormal = glm::normalize(glm::cross(tangentVec, glm::vec3(1.0f, 0.0f, 0.0f)));
		}

		glm::vec3 baseNormal = glm::normalize(glm::cross(binormal, tangentVec));

		return glm::rotate(baseNormal, angle, tangentVec);
	}

	float Curve::closestParameter(const glm::vec3& point, const int steps) 
	{
		float minDistance = std::numeric_limits<float>::max();
		float closestT = 0.0f;
		for (int i = 0; i <= steps; ++i) 
		{
			float t = i / float(steps);
			float distance = glm::length(get(t) - point);
			if (distance < minDistance) 
			{
				minDistance = distance;
				closestT = t;
			}
		}
		return closestT;
	}
}