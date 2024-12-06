#include "pch.h"
#include "BlockModelStorage.h"
#include "game/planet/G3DPlanetLayer.h"
#include "helper/CommonHelper.h"

namespace g3d
{
    class $modify(MenuLayer) 
    {
        bool init() 
        {
            auto bms = BlockModelStorage::get();

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
            const auto downloaded = MusicDownloadManager::sharedState()->isSongDownloaded(1221653);
            if (!downloaded)
            {
                try {
                    const auto from = geode::Mod::get()->getResourcesDir() / "music" / "1221653.mp3";
                    const auto to = utils::get_song_path() / "1221653.mp3";
                    std::filesystem::copy(from, to);
                }
                catch (...)
                {

                }
            }

            if (!MenuLayer::init()) { return false; }

            return true;
        }
    };
}