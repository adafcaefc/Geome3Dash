#include "pch.h"
#include "PlanetStateManager.h"

namespace g3d
{
	void PlanetStateManager::tryLoadSaveFile() {
		// use cc dictionary maybe?
		// or save it to a json file?
		// I can't really decide...
		// yeah I will go with json I think...
		for (int i = 0; i < 20; i++)
			levelProgresses.push_back(new LevelProgress(0, 0));

	}

	PlanetStateManager* PlanetStateManager::getInstance() {
		if (!instance) {
			instance = new PlanetStateManager;
			instance->tryLoadSaveFile();
		}
		return instance;
	}

	PlanetStateManager* PlanetStateManager::instance = nullptr;
}
