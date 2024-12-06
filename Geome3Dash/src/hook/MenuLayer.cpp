#include "pch.h"
#include "BlockModelStorage.h"
#include "game/planet/G3DPlanetLayer.h"

namespace g3d
{
    class $modify(MenuLayer) 
    {
        bool init() 
        {
            // load cache
            auto bms = BlockModelStorage::get();

            if (bms->shouldReloadShaders)
            {
                bms->reloadAllShaders();
                bms->shouldReloadShaders = false;
            }

            bms->getBlockModel(1);
            const auto modelPath = bms->getBP() / "planet" / "model";
            bms->getModelT<PlanetModel>(modelPath / "new_planet_textured.obj");
            bms->getModelT<PlanetModel>(modelPath / "planet_water.obj");
            bms->getModelT<CloudModel>(modelPath / "clouds.obj");

            if (!MenuLayer::init()) { return false; }

            return true;
        }
    };
}