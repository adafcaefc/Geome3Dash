#pragma once

#include <glm/glm.hpp>

#include <vector>
#include <string>

#include "spline/Curve.h"

namespace g3d
{
	class LevelData;
	class Spline;

	struct CameraKeyframe 
	{
		float playersXpos;
		glm::vec3 offset;
		glm::vec3 front;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(CameraKeyframe, playersXpos, offset, front);

		CameraKeyframe() {}
		CameraKeyframe(float playersXpos, glm::vec3 offset, glm::vec3 front) : playersXpos(playersXpos), offset(offset), front(front) {}
	};

	class KeyframeData {
	public:
		std::vector<CameraKeyframe> keyframes;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(KeyframeData, keyframes);

		void setKeyframe(float playersXpos, glm::vec3 offset, glm::vec3 front);

		void removeLastKeyframe();

		CameraKeyframe getInterpolatedCameraKeyframe(float playersXpos);

		glm::vec3 lerp(glm::vec3 p0, glm::vec3 p1, float t);

		KeyframeData() {}
		~KeyframeData();
	};

	// to do : move this into classes

	void setStartingKeyframe(
		LevelData* cld,
		KeyframeData* keyframeBuffer,
		const float lengthScaleFactor);

	void prepareSpline(
		GJBaseGameLayer* layer,
		Spline* spline,
		float* lengthScaleFactor);
}