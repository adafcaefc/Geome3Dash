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

	void PlanetStateManager::save()
	{
		try {
			nlohmann::json jsonData = *getInstance(); 
			std::string jsonMsg = jsonData.dump();
			const auto path = geode::Mod::get()->getSaveDir() / "G3DSaveData.json";
			std::ofstream outFile(path);
			if (outFile) { outFile << jsonMsg; }
		}
		catch (const std::exception& e) {

		}
	}

	void PlanetStateManager::load()
	{
		try {
			const auto path = geode::Mod::get()->getSaveDir() / "G3DSaveData.json";
			nlohmann::json jsonData;
			std::ifstream inFile(path);
			if (inFile) { inFile >> jsonData; }
			*getInstance() = jsonData;
		}
		catch (const std::exception& e) {

		}
	}


	PlanetStateManager* PlanetStateManager::getInstance() 
	{
		if (!instance) 
		{ 
			instance = new PlanetStateManager;
			load();
		}
		return instance;
	}

	PlanetStateManager* PlanetStateManager::instance = nullptr;
}
