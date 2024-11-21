#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GameEffectsManager : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "GameEffectsManager";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GameEffectsManager, cocos2d::CCNode)
    
private:
    [[deprecated("GameEffectsManager::create not implemented")]]
    /**
     * @note[short] Android
     */
    static GameEffectsManager* create(PlayLayer* p0);
public:
    
private:
    [[deprecated("GameEffectsManager::addParticleEffect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addParticleEffect(cocos2d::CCParticleSystemQuad* p0, int p1);
public:
    
private:
    [[deprecated("GameEffectsManager::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(PlayLayer* p0);
public:
    
private:
    [[deprecated("GameEffectsManager::scaleParticle not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn scaleParticle(cocos2d::CCParticleSystemQuad* p0, float p1);
public:
};
