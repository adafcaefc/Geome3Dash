#include "pch.h"
#include "game/planet/G3DPlanetLayer.h"

#include <Geode/modify/GameManager.hpp>

namespace g3d
{
    class $modify(GameManager) 
    {
        void returnToLastScene(GJGameLevel * p0) 
        {
            if (G3DPlanetLayer::insideThePlanetLayerFlag) 
            {
                CCDirector::sharedDirector()->popSceneWithTransition(0.3f, kPopTransitionFade);
            }
            else 
            {
                GameManager::returnToLastScene(p0);
            }
        }
    };
}