#pragma once

namespace g3d
{
	class LevelProgress 
	{
	public:
		int normal = 0;
		int practice = 0;
		LevelProgress(int normal, int practice) 
			: normal(normal)
			, practice(practice) {}
		LevelProgress() {}
		NLOHMANN_DEFINE_TYPE_INTRUSIVE(LevelProgress, normal, practice);
	};

	class PlanetStateManager 
	{
		static PlanetStateManager* instance;
	public:
		std::unordered_map<int, LevelProgress> currentProgress;
		static PlanetStateManager* getInstance();
		static void load();
		static void save();
		NLOHMANN_DEFINE_TYPE_INTRUSIVE(PlanetStateManager, currentProgress);
	};
}