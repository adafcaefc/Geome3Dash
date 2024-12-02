#pragma once

namespace g3d
{
	class Curve;

	struct Spline {
		struct ParameterData {
			float t;
			glm::vec3 value;
			float l;
			ParameterData(float t, glm::vec3 value, float l) : t(t), value(value), l(l) {};
		};

		std::vector<Curve*> segments;
		std::vector<ParameterData> parameterList;
		bool parameterListShouldBeUpdated = true;

		void updateParameterList(int points = 10000);

		int getPointsCount();

		std::vector<glm::vec3> getAllPoints();

		void editPointSymmetricCenterFix(int pointIndex, glm::vec3 position);
		void editPointSymmetric(int pointIndex, glm::vec3 position);
		void editPoint(int pointIndex, glm::vec3 position);

		void addSegment(Curve* curve);
		void removeLastSegment();

		ParameterData findClosestByLength(float l);

		glm::vec3 get(float t);
		glm::vec3 tangent(float t);
		glm::vec3 normal(float t);

		float length(int stepsProCurve);
	};
}