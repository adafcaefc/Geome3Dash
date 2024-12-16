#include "pch.h"
#include <Geode/modify/GameManager.hpp>
#include "game/planet/G3DPlanetLayer.h"

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