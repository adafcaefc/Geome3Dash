#pragma once

#include <glm/glm.hpp>

#include <vector>
#include <string>

namespace g3d
{
	struct CameraKeyframe {
		float playersXpos;
		glm::vec3 offset;
		glm::vec3 front;

		CameraKeyframe() {}
		CameraKeyframe(float playersXpos, glm::vec3 offset, glm::vec3 front) : playersXpos(playersXpos), offset(offset), front(front) {}
	};

	class CameraKeyframeBuffer {
	public:
		std::vector<CameraKeyframe> keyframes;

		void setKeyframe(float playersXpos, glm::vec3 offset, glm::vec3 front);

		void removeLastKeyframe();

		CameraKeyframe getInterpolatedCameraKeyframe(float playersXpos);

		glm::vec3 lerp(glm::vec3 p0, glm::vec3 p1, float t);

		CameraKeyframeBuffer() {}
		~CameraKeyframeBuffer();
	};
}