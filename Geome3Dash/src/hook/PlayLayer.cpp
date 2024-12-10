#include "pch.h"
#include "game/planet/G3DPlanetLayer.h"
#include "game/play/G3DPlayLayer.h"
#include "manager/PlanetStateManager.h"

#include <Geode/modify/PlayLayer.hpp>

namespace g3d
{
    class $modify(PlayLayer)
    {
        struct Fields
        {
            G3DPlayLayer* playLayer3D = nullptr;
            PlanetStateManager* psm = PlanetStateManager::getInstance();
        };

        void destroyPlayer(PlayerObject * p0, GameObject * p1) {
            // if (G3DPlanetLayer::insideThePlanetLayerFlag) {
            //     auto percent = this->getCurrentPercentInt();
            //     if (this->m_isPracticeMode) {
            //         if (m_fields->psm->currentProgress[this->m_level->m_levelID].practice < percent) {
            //             m_fields->psm->currentProgress[this->m_level->m_levelID].practice = percent;
            //             PlanetStateManager::save();
            //         }
            //     }
            //     else {
            //         if (m_fields->psm->currentProgress[this->m_level->m_levelID].normal < percent) {
            //             m_fields->psm->currentProgress[this->m_level->m_levelID].normal = percent;
            //             PlanetStateManager::save();
            //         }
            //     }
            // }
            PlayLayer::destroyPlayer(p0, p1);
        }
        void levelComplete() {
            // if (G3DPlanetLayer::insideThePlanetLayerFlag) {
            //     if (this->m_isPracticeMode) {
            //         m_fields->psm->currentProgress[this->m_level->m_levelID].practice = 100;
            //         PlanetStateManager::save();
            //     }
            //     else {
            //         m_fields->psm->currentProgress[this->m_level->m_levelID].normal = 100;
            //         PlanetStateManager::save();
            //     }
            // }
            PlayLayer::levelComplete();
        }

        void resetLevel()
        {
            const auto enabled = !geode::Mod::get()->getSettingValue<bool>("disable-general-3d");
            if (enabled || G3DPlanetLayer::insideThePlanetLayerFlag)
            {
                if (!m_fields->playLayer3D)
                {
                    m_fields->playLayer3D = G3DPlayLayer::create(this);
                    m_fields->playLayer3D->setZOrder(9);
                    this->addChild(m_fields->playLayer3D);
                }
            }
            PlayLayer::resetLevel();
        }
    };

}