#pragma once

#include "Curve.h"

#include <vector>

namespace sus3d
{
	class Spline 
	{
	public:
		struct ParameterData 
		{
			float t;
			glm::vec3 value;
			float l;
			ParameterData(float t, glm::vec3 value, float l) : t(t), value(value), l(l) {};
		};

		std::vector<Curve> segments;

		std::vector<ParameterData> parameterList;
		bool parameterListShouldBeUpdated = true;

		void updateParameterList(int points = 10000);

		std::vector<glm::vec3> getAllPoints();
		int getPointsCount();

		void editPointSymmetricCenterFix(int pointIndex, glm::vec3 position);
		void editPointSymmetric(int pointIndex, glm::vec3 position);
		void editPoint(int pointIndex, glm::vec3 position);

		void addSegment(const Curve& curve);
		void removeLastSegment();

		ParameterData findClosestByLength(float l);
		float length(int stepsProCurve);

		glm::vec3 get(float t);
		glm::vec3 tangent(float t);
		glm::vec3 normal(float t);

		Spline() {}

		void addNewCurveToSpline()
		{
			auto p1 = this->segments.back().p2;
			auto m1 = this->segments.back().p2 * 2.f - this->segments.back().m2;
			auto m2 = this->segments.back().p2 * 2.f - this->segments.back().m1;
			auto p2 = this->segments.back().p2 * 2.f - this->segments.back().p1;
			this->addSegment(Curve(p1, m1, m2, p2));
		}
	};
}