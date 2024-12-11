#pragma once

#include "helper/KeyframeData.h"

#include "engine/sus3d/spline/Spline.h"
#include "engine/sus3d/spline/Curve.h"

#include <glm/glm.hpp>

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

class GJBaseGameLayer;

namespace nlohmann
{
	NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(sus3d::Curve, p1, m1, p2, m2);
	NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(sus3d::Spline, segments);
}

namespace g3d
{
	class LevelData
	{
	public:
		double x, y, z;                      // Position
		double yaw, pitch;                   // Rotation
		bool lock;                           // Lock camera
		sus3d::Spline spline;                // Spline path
		KeyframeData keyframe;               // Keyframe

		static LevelData getDefault();

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(LevelData, keyframe, spline, x, y, z, yaw, pitch, lock);
	};

	void msgLevelEncode(GJBaseGameLayer* layer, const std::string& message);
	std::string msgLevelDecode(GJBaseGameLayer* layer);

	LevelData getLevelData(GJBaseGameLayer* layer);
	void setLevelData(GJBaseGameLayer* layer, const LevelData& data);
}