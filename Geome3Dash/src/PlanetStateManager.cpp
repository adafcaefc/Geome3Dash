#include "pch.h"
#include "PlanetStateManager.h"

namespace g3d
{
	//class G3DLevelDownloadDelegate : public LevelDownloadDelegate
	//{
	//protected:
	//	G3DLevelDownloadDelegate() {};
	//	LevelDownloadDelegate* m_originalDelegate = nullptr;
	//public:
	//	G3DLevelDownloadDelegate* get()
	//	{
	//		static G3DLevelDownloadDelegate instance;
	//		if (!m_originalDelegate)
	//		{
	//			m_originalDelegate = GameLevelManager::get()->m_levelDownloadDelegate;
	//		}
	//		return &instance;
	//	}
	//	virtual void levelDownloadFinished(GJGameLevel* level) override
	//	{
	//		m_originalDelegate->levelDownloadFinished(level);
	//		// my code
	//	}
	//	virtual void levelDownloadFailed(int code) override
	//	{
	//		m_originalDelegate->levelDownloadFailed(code);
	//		// my code
	//	}
	//};

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
