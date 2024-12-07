#pragma once


#include "helper/KeyframeData.h"
#include "helper/spline/Spline.h"

#include <nlohmann/json.hpp>

#include <glm/glm.hpp>

#include <string>
#include <vector>

class GJBaseGameLayer;

namespace g3d
{
	class LevelData
	{
	public:
		double x, y, z;                      // Position
		double yaw, pitch;                   // Rotation
		bool lock;                           // Lock camera
		Spline spline;                       // Spline path
		KeyframeData keyframe;       // Keyframe

		static LevelData getDefault();

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(LevelData, keyframe, spline, x, y, z, yaw, pitch, lock);
	};

	void msgLevelEncode(GJBaseGameLayer* layer, const std::string& message);
	std::string msgLevelDecode(GJBaseGameLayer* layer);

	LevelData getLevelData(GJBaseGameLayer* layer);
	void setLevelData(GJBaseGameLayer* layer, const LevelData& data);
}