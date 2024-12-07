#include "pch.h"
#include "manager/ModelManager.h"
#include "manager/LevelDataManager.h"
#include "game/planet/G3DPlanetLayer.h"
#include "helper/CommonHelper.h"
#include "impl/engine/PlanetModel.h"
#include "impl/engine/CloudModel.h"

#include <Geode/modify/MenuLayer.hpp>

namespace g3d
{
    static void loadMusic(int id)
    {
        const auto downloaded = MusicDownloadManager::sharedState()->isSongDownloaded(id);
        if (!downloaded)
        {
            const auto name = fmt::format("{}.mp3", id);
            try {
                const auto from = geode::Mod::get()->getResourcesDir() / "music" / "level" / name;
                const auto to = utils::get_song_path() / name;
                std::filesystem::copy(from, to);
            }
            catch (...)
            {

            }
        }
    }

    class $modify(MenuLayer) 
    {
        bool init() 
        {
            auto bms = ModelManager::get();

            if (bms->shouldReloadShaders)
            {
                // reload shaders when going fullscreen (or vice-versa)
                bms->reloadAllShaders();
                bms->shouldReloadShaders = false;
            }

            bms->getBlockModel(1);
            const auto modelPath = bms->getBP() / "planet" / "model";
            bms->getModelT<PlanetModel>(modelPath / "new_planet_textured.obj");
            bms->getModelT<PlanetModel>(modelPath / "planet_water.obj");
            bms->getModelT<CloudModel>(modelPath / "clouds.obj");

            // hardcoded for glaciers edge
            loadMusic(1221653);

            if (!MenuLayer::init()) { return false; }

            return true;
        }
    };
}