#pragma once

namespace g3d
{
	struct LevelProgress {
		int normal = 0;
		int practice = 0;
		bool alreadyShowedNextAnimation = false;

		LevelProgress(int normal, int practice) : normal(normal), practice(practice) {};
	};

	class PlanetStateManager {
		std::vector<LevelProgress*> levelProgresses;

		static PlanetStateManager* instance;
		void tryLoadSaveFile();


		void save() {
			//later
		}

	public:
		LevelProgress* getProgressByLevelID(int id) { return id >= 0 && id < 20 ? levelProgresses[id] : nullptr; }
		void setNormalProgressByLevelID(int id, int normal) {
			if (id < 0 || id > 19) return;
			levelProgresses[id]->normal = normal;
		}
		void setPracticeProgressByLevelID(int id, int practice) {
			if (id < 0 || id > 19) return;
			levelProgresses[id]->practice = practice;
		}
		void setNextAnimationStateByLevelID(int id, bool state) {
			if (id < 0 || id > 19) return;
			levelProgresses[id]->alreadyShowedNextAnimation = state;
		}
		void setProgressByLevelID(int id, LevelProgress* levelProgress) {
			if (id < 0 || id > 19) return;
			levelProgresses[id] = levelProgress;
		}


		static PlanetStateManager* getInstance();
	};
}