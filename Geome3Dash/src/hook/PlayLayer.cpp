#include "pch.h"
#include "game/planet/G3DPlanetLayer.h"
#include "PlanetStateManager.h"
#include "game/playing/G3DPlayLayer.h"

namespace g3d
{
    class $modify(PlayLayer)
    {
        struct Fields
        {
            G3DPlayLayer* playLayer3D = nullptr;
        };

        void destroyPlayer(PlayerObject * p0, GameObject * p1) {
            if (G3DPlanetLayer::insideThePlanetLayerFlag) {
                auto percent = this->getCurrentPercentInt();
                if (this->m_isPracticeMode) {
                    PlanetStateManager::getInstance()->setPracticeProgressByLevelID(this->m_level->m_levelID, percent);
                }
                else {
                    PlanetStateManager::getInstance()->setNormalProgressByLevelID(this->m_level->m_levelID, percent);
                }
            }
            PlayLayer::destroyPlayer(p0, p1);
        }
        void levelComplete() {
            if (G3DPlanetLayer::insideThePlanetLayerFlag) {
                if (this->m_isPracticeMode) {
                    PlanetStateManager::getInstance()->setPracticeProgressByLevelID(this->m_level->m_levelID, 100);
                }
                else {
                    PlanetStateManager::getInstance()->setNormalProgressByLevelID(this->m_level->m_levelID, 100);
                }
            }
            PlayLayer::levelComplete();
        }

        void resetLevel()
        {
            const auto enabled = !geode::Mod::get()->getSettingValue<bool>("disable-general-3d");
            if (enabled || G3DPlanetLayer::insideThePlanetLayerFlag)
            {
                if (!m_fields->playLayer3D)
                {
                    m_fields->playLayer3D = G3DPlayLayer::create();
                    m_fields->playLayer3D->setZOrder(9);
                    this->addChild(m_fields->playLayer3D);
                }
            }
            PlayLayer::resetLevel();
        }
    };

}