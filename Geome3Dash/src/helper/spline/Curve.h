#pragma once

#include <nlohmann/json.hpp>
#include <glm/glm.hpp>

namespace nlohmann {
	template <>
	struct adl_serializer<glm::vec3> {
		static void to_json(json& j, const glm::vec3& vec) {
			j = json{ {"x", vec.x}, {"y", vec.y}, {"z", vec.z} };
		}
		static void from_json(const json& j, glm::vec3& vec) {
			j.at("x").get_to(vec.x);
			j.at("y").get_to(vec.y);
			j.at("z").get_to(vec.z);
		}
	};
}

namespace g3d
{
	struct Curve 
	{
		glm::vec3 p1;
		glm::vec3 m1;
		glm::vec3 m2;
		glm::vec3 p2;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(Curve, p1, m1, p2, m2);

		float p1NormalAngle = 0;
		float p2NormalAngle = 0;

		Curve(glm::vec3 p1, glm::vec3 m1, glm::vec3 m2, glm::vec3 p2);
		Curve() {}

		glm::vec3 lerp(glm::vec3 p0, glm::vec3 p1, float t);

		glm::vec3 get(float t);
		glm::vec3 tangent(float t);
		glm::vec3 normal(float t);

		float length(int steps);

		float closestParameter(glm::vec3 point, int steps = 100);
	};
}