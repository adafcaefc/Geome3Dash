#include "pch.h"
#include "BlockModelsStorage.h"
#include "game/planet/G3DPlanetLayer.h"

namespace g3d
{
    class $modify(MenuLayer) {
        bool init() {
            // load cache
            auto bms = BlockModelsStorage::getInstance();
            auto model = bms->getBlockModel(1);
            const auto planetPath = geode::Mod::get()->getResourcesDir() / "model3d" / "planet";
            const auto modelPath = planetPath / "model";
            bms->getModelT<PlanetModel>(modelPath / "new_planet_textured.obj");
            bms->getModelT<PlanetModel>(modelPath / "planet_water.obj");
            bms->getModelT<CloudModel>(modelPath / "clouds.obj");
            if (!MenuLayer::init()) { return false; }
            //AllocConsole();
            //freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
            return true;
        }
    };
}