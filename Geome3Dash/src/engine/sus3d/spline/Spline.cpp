#include "Spline.h"

#include <algorithm>

namespace sus3d
{
	constexpr float SUS3D_SPLINE_MIN_LENGTH = 0.000001f;

	void Spline::updateParameterList(int points) 
	{
		if (!parameterListShouldBeUpdated) { return; }
		parameterListShouldBeUpdated = false;
		parameterList.clear();

		float maxT = segments.size() * 1.0f - SUS3D_SPLINE_MIN_LENGTH;
		float tStep = maxT / points;

		float lengthCounter = 0.f;

		for (float t = 0.f; t < maxT; t += tStep) 
		{
			glm::vec3 value = get(t);
			float deltaLength = 0.f;
			if (parameterList.size() != 0) 
			{
				deltaLength = glm::length(value - parameterList.back().value);
			}
			lengthCounter += deltaLength;
			parameterList.push_back(ParameterData(t, value, lengthCounter));
		}
	}

	int Spline::getPointsCount() 
	{
		return static_cast<int>(segments.size()) * 3 + 1;
	}

	std::vector<glm::vec3> Spline::getAllPoints() 
	{
		std::vector<glm::vec3> ret;
		for (int i = 0; i < segments.size(); i++) 
		{
			ret.push_back(segments[i].p1);
			ret.push_back(segments[i].m1);
			ret.push_back(segments[i].m2);
		}
		ret.push_back(segments.back().p2);
		return ret;
	}

	void Spline::editPointSymmetricCenterFix(int pointIndex, glm::vec3 position) 
	{
		if (pointIndex == 0) 
		{
			auto deltaP1 = position - segments[0].p1;
			segments[0].p1 = position;
			segments[0].m1 += deltaP1;
			parameterListShouldBeUpdated = true;
			return;
		}
		else if (pointIndex == getPointsCount() - 1) 
		{
			auto deltaP1 = position - segments.back().p2;
			segments.back().p2 = position;
			segments.back().m2 += deltaP1;
			parameterListShouldBeUpdated = true;
			return;
		}
		else if (pointIndex == 1) 
		{
			segments[0].m1 = position;
			parameterListShouldBeUpdated = true;
			return;
		}
		else if (pointIndex == getPointsCount() - 2) 
		{
			segments.back().m2 = position;
			parameterListShouldBeUpdated = true;
			return;
		}

		int segmentIndex = static_cast<int>(std::floor(pointIndex / 3));
		int offset = pointIndex % 3;
		auto deltaP1 = position - segments[segmentIndex].p1;
		switch (offset) 
		{
		case 0:
			segments[segmentIndex].p1 = position;
			segments[segmentIndex - 1].p2 = position;
			segments[segmentIndex].m1 += deltaP1;
			segments[segmentIndex - 1].m2 += deltaP1;
			break;
		case 1:
			segments[segmentIndex].m1 = position;
			segments[segmentIndex - 1].m2 = 2.f * segments[segmentIndex].p1 - segments[segmentIndex].m1;
			break;
		case 2:
			segments[segmentIndex].m2 = position;
			segments[segmentIndex + 1].m1 = 2.f * segments[segmentIndex + 1].p1 - segments[segmentIndex].m2;
			break;
		}
		parameterListShouldBeUpdated = true;
	}

	void Spline::editPointSymmetric(int pointIndex, glm::vec3 position) 
	{
		if (pointIndex == 0) 
		{
			segments[0].p1 = position;
			parameterListShouldBeUpdated = true;
			return;
		}
		else if (pointIndex == getPointsCount() - 1) 
		{
			segments.back().p2 = position;
			parameterListShouldBeUpdated = true;
			return;
		}
		else if (pointIndex == 1)
		{
			segments[0].m1 = position;
			parameterListShouldBeUpdated = true;
			return;
		}
		else if (pointIndex == getPointsCount() - 2)
		{
			segments.back().m2 = position;
			parameterListShouldBeUpdated = true;
			return;
		}

		int segmentIndex = static_cast<int>(std::floor(pointIndex / 3));
		int offset = pointIndex % 3;
		switch (offset) 
		{
		case 0:
			segments[segmentIndex].p1 = position;
			segments[segmentIndex - 1].p2 = position;
			break;
		case 1:
			segments[segmentIndex].m1 = position;
			segments[segmentIndex - 1].m2 = 2.f * segments[segmentIndex].p1 - segments[segmentIndex].m1;
			break;
		case 2:
			segments[segmentIndex].m2 = position;
			segments[segmentIndex + 1].m1 = 2.f * segments[segmentIndex + 1].p1 - segments[segmentIndex].m2;
			break;
		}
		parameterListShouldBeUpdated = true;
	}

	void Spline::editPoint(int pointIndex, glm::vec3 position) 
	{
		if (pointIndex == 0)
		{
			segments[0].p1 = position;
			parameterListShouldBeUpdated = true;
			return;
		}
		else if (pointIndex == getPointsCount() - 1)
		{
			segments.back().p2 = position;
			parameterListShouldBeUpdated = true;
			return;
		}

		int segmentIndex = static_cast<int>(std::floor(pointIndex / 3));
		int offset = pointIndex % 3;
		switch (offset) {
		case 0:
			segments[segmentIndex].p1 = position;
			segments[segmentIndex - 1].p2 = position;
			break;
		case 1:
			segments[segmentIndex].m1 = position;
			break;
		case 2:
			segments[segmentIndex].m2 = position;
			break;
		}
		parameterListShouldBeUpdated = true;
	}

	void Spline::addSegment(const Curve& curve) 
	{
		segments.push_back(curve);
		parameterListShouldBeUpdated = true;
	}

	void Spline::removeLastSegment() 
	{
		if (segments.size() == 0) { return; }
		segments.pop_back();
		parameterListShouldBeUpdated = true;
	}

	float Spline::length(int stepsProCurve) 
	{
		float totalLength = 0;
		for (int i = 0; i < segments.size(); i++) 
		{
			totalLength += segments[i].length(stepsProCurve);
		}

		return totalLength;
	}

	Spline::ParameterData Spline::findClosestByLength(float l)
	{
		auto it = std::lower_bound(
			parameterList.begin(), parameterList.end(), 
			l, [](const ParameterData& cp, float l) { return cp.l < l; });

		if (it == parameterList.end()) 
		{
			return parameterList.back();
		}
		if (it == parameterList.begin()) 
		{
			return *it;
		}

		auto before = std::prev(it);
		return (std::abs(it->l - l) < std::abs(before->l - l)) ? *it : *before;
	}

	glm::vec3 Spline::get(float t) 
	{
		if (segments.empty()) return glm::vec3(0.0f);

		t = std::clamp(t, 0.f, static_cast<float>(segments.size()) - SUS3D_SPLINE_MIN_LENGTH);

		size_t segmentIndex = static_cast<size_t>(t);
		float localT = t - segmentIndex;
		return segments[segmentIndex].get(localT);
	}

	glm::vec3 Spline::tangent(float t) 
	{
		if (segments.empty()) { return glm::vec3(0.0f); }

		t = std::clamp(t, 0.f, static_cast<float>(segments.size()) - SUS3D_SPLINE_MIN_LENGTH);

		size_t segmentIndex = static_cast<size_t>(t);
		float localT = t - segmentIndex;
		return segments[segmentIndex].tangent(localT);
	}

	glm::vec3 Spline::normal(float t) 
	{
		if (segments.empty()) { return glm::vec3(0.0f); }

		t = std::clamp(t, 0.f, static_cast<float>(segments.size()) - SUS3D_SPLINE_MIN_LENGTH);

		size_t segmentIndex = static_cast<size_t>(t);
		float localT = t - segmentIndex;
		return segments[segmentIndex].normal(localT);
	}
}