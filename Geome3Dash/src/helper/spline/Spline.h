#pragma once

#include "Curve.h"

namespace g3d
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

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(Spline, segments);

		std::vector<ParameterData> parameterList;
		bool parameterListShouldBeUpdated = true;

		void updateParameterList(int points = 10000);

		int getPointsCount();

		std::vector<glm::vec3> getAllPoints();

		void editPointSymmetricCenterFix(int pointIndex, glm::vec3 position);
		void editPointSymmetric(int pointIndex, glm::vec3 position);
		void editPoint(int pointIndex, glm::vec3 position);

		void addSegment(const Curve& curve);
		void removeLastSegment();

		ParameterData findClosestByLength(float l);

		glm::vec3 get(float t);
		glm::vec3 tangent(float t);
		glm::vec3 normal(float t);

		float length(int stepsProCurve);

		Spline() {}
	};

	// adaf additions
	inline void addNewCurveToSpline(Spline* spline)
	{
		auto p1 = spline->segments.back().p2;
		auto m1 = spline->segments.back().p2 * 2.f - spline->segments.back().m2;
		auto m2 = spline->segments.back().p2 * 2.f - spline->segments.back().m1;
		auto p2 = spline->segments.back().p2 * 2.f - spline->segments.back().p1;
		spline->addSegment(Curve(p1, m1, m2, p2));
	}
}