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

	class CameraKeyframeBuffer {
	public:
		std::vector<CameraKeyframe> keyframes;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(CameraKeyframeBuffer, keyframes);

		void setKeyframe(float playersXpos, glm::vec3 offset, glm::vec3 front);

		void removeLastKeyframe();

		CameraKeyframe getInterpolatedCameraKeyframe(float playersXpos);

		glm::vec3 lerp(glm::vec3 p0, glm::vec3 p1, float t);

		CameraKeyframeBuffer() {}
		~CameraKeyframeBuffer();
	};

	void setStartingKeyframe(
		LevelData* cld,
		CameraKeyframeBuffer* keyframeBuffer,
		const float lengthScaleFactor);

	void prepareSpline(
		GJBaseGameLayer* layer,
		Spline* spline,
		float* lengthScaleFactor);
}