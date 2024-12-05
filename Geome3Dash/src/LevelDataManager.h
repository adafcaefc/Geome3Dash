#pragma once

#include "CameraAction.h"

#include "helper/CameraKeyframeBuffer.h"
#include "helper/BezierHelper.h"
#include "helper/spline/Spline.h"

#include <nlohmann/json.hpp>

#include <glm/glm.hpp>

#include <string>
#include <vector>

class GJBaseGameLayer;

namespace g3d
{
	struct CameraActionLD : public CameraAction
	{
		NLOHMANN_DEFINE_TYPE_INTRUSIVE(CameraActionLD, x, y, z, yaw, pitch, time, triggerAt);
	};
	
	struct CubicBezierLD : public CubicBezier
	{
		NLOHMANN_DEFINE_TYPE_INTRUSIVE(CubicBezier, x0, y0, cx1, cy1, cx2, cy2, x1, y1);
	};

	struct LevelData
	{
		//CubicBezierLD bezierCurve;           // Bezier values
		//double bezierMultiplier;             // Path size
		//std::vector<CameraActionLD> actions; // Camera actions

		double x, y, z;                      // Position
		double yaw, pitch;                   // Rotation
		bool lock;                           // Lock camera
		Spline spline;                       // Spline path
		CameraKeyframeBuffer keyframe;       // Keyframe

		static LevelData getDefault();

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(LevelData, keyframe, spline, x, y, z, yaw, pitch, lock);
	};

	void msgLevelEncode(GJBaseGameLayer* layer, const std::string& message);
	std::string msgLevelDecode(GJBaseGameLayer* layer);

	LevelData getLevelData(GJBaseGameLayer* layer);
	void setLevelData(GJBaseGameLayer* layer, const LevelData& data);
}