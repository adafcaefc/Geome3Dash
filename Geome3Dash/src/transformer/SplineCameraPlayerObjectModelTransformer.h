#pragma once

#include "GameObjectModelTransformer.h"

namespace sus3d
{
	class Camera;
}

namespace g3d
{
	class CameraKeyframeBuffer;
	class G3DPlayLayer;
	class PlayerObjectModel;
	class Spline;
	class SplineCameraPlayerObjectModelTransformer : public GameObjectModelTransformer
	{
	public:
		Spline* spline;
		CameraKeyframeBuffer* buffer;
		sus3d::Camera* camera;
		float* lengthScaleFactor;
		bool* isEditing;
		virtual void transform(GameObjectModel* gom) override;
		SplineCameraPlayerObjectModelTransformer(
			Spline* spline,
			CameraKeyframeBuffer* buffer,
			sus3d::Camera* cam,
			float* lcf,
			bool* isEditing)
			: spline(spline)
			, buffer(buffer)
			, camera(cam)
			, lengthScaleFactor(lcf)
			, isEditing(isEditing)
		{

		}
		glm::vec3 getPlayerOrientedCameraFront(PlayerObjectModel* pom);
		glm::vec3 getPlayerOrientedCameraPosition(PlayerObjectModel* pom);
		virtual ~SplineCameraPlayerObjectModelTransformer() = default;
	};
}