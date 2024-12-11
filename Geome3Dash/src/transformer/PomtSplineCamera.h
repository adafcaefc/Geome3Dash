#pragma once

#include "AGomtBase.h"

namespace sus3d
{
	class Camera;
	class Light;
	class Spline;
}

namespace g3d
{
	class KeyframeData;
	class G3DPlayLayer;
	class PlayerObjectModel;
	class PomtSplineCamera : public AGomtBase
	{
	public:
		sus3d::Spline* spline;
		KeyframeData* buffer;
		sus3d::Camera* camera;
		sus3d::Light* light;
		float* lengthScaleFactor;
		bool* isEditing;
		
		virtual void transform(GameObjectModel* gom) override;

		glm::vec3 getPlayerOrientedCameraFront(PlayerObjectModel* pom);
		glm::vec3 getPlayerOrientedCameraPosition(PlayerObjectModel* pom);

		PomtSplineCamera(
			sus3d::Spline* spline,
			KeyframeData* keyframeData,
			sus3d::Camera* sceneCam,
			sus3d::Light* sceneLight,
			float* scaleFactor,
			bool* freezeCamera)
			: spline(spline)
			, buffer(keyframeData)
			, camera(sceneCam)
			, light(sceneLight)
			, lengthScaleFactor(scaleFactor)
			, isEditing(freezeCamera)
		{

		}

		PomtSplineCamera() {}

		virtual ~PomtSplineCamera() = default;
	};
}