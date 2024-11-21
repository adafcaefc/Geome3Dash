#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class SpriteAnimationManager : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "SpriteAnimationManager";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(SpriteAnimationManager, cocos2d::CCNode)
    
private:
    [[deprecated("SpriteAnimationManager::animationFinished not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn animationFinished();
public:
    
private:
    [[deprecated("SpriteAnimationManager::callAnimationFinished not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn callAnimationFinished();
public:
    
private:
    [[deprecated("SpriteAnimationManager::createAnimations not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x62a3ac
     * @note[short] Android
     */
    TodoReturn createAnimations(gd::string p0);
public:
    
private:
    [[deprecated("SpriteAnimationManager::createWithOwner not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createWithOwner(CCAnimatedSprite* p0, gd::string p1);
public:
    
private:
    [[deprecated("SpriteAnimationManager::doCleanup not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn doCleanup();
public:
    
private:
    [[deprecated("SpriteAnimationManager::executeAnimation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn executeAnimation(gd::string p0);
public:
    
private:
    [[deprecated("SpriteAnimationManager::finishAnimation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn finishAnimation(gd::string p0);
public:
    
private:
    [[deprecated("SpriteAnimationManager::getAnimType not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getAnimType(gd::string p0);
public:
    
private:
    [[deprecated("SpriteAnimationManager::getPrio not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getPrio(gd::string p0);
public:
    
private:
    [[deprecated("SpriteAnimationManager::initWithOwner not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn initWithOwner(CCAnimatedSprite* p0, gd::string p1);
public:
    
private:
    [[deprecated("SpriteAnimationManager::loadAnimations not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x62b214
     * @note[short] Android
     */
    TodoReturn loadAnimations(gd::string p0);
public:
    
private:
    [[deprecated("SpriteAnimationManager::offsetCurrentAnimation not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x70e0d0
     * @note[short] Android
     */
    TodoReturn offsetCurrentAnimation(float p0);
public:

    /**
     * @note[short] Windows: 0x74420
     * @note[short] Android
     */
    void overridePrio();
    
private:
    [[deprecated("SpriteAnimationManager::playSound not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playSound(gd::string p0);
public:
    
private:
    [[deprecated("SpriteAnimationManager::playSoundForAnimation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playSoundForAnimation(gd::string p0);
public:
    
private:
    [[deprecated("SpriteAnimationManager::queueAnimation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn queueAnimation(gd::string p0);
public:
    
private:
    [[deprecated("SpriteAnimationManager::resetAnimState not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetAnimState();
public:
    
private:
    [[deprecated("SpriteAnimationManager::runAnimation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn runAnimation(gd::string p0);
public:
    
private:
    [[deprecated("SpriteAnimationManager::runQueuedAnimation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn runQueuedAnimation();
public:

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void stopAnimations();
    
private:
    [[deprecated("SpriteAnimationManager::storeAnimation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn storeAnimation(cocos2d::CCAnimate* p0, cocos2d::CCAnimate* p1, gd::string p2, int p3, spriteMode p4, cocos2d::CCSpriteFrame* p5);
public:
    
private:
    [[deprecated("SpriteAnimationManager::storeSoundForAnimation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn storeSoundForAnimation(cocos2d::CCString* p0, gd::string p1, float p2);
public:
    
private:
    [[deprecated("SpriteAnimationManager::switchToFirstFrameOfAnimation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn switchToFirstFrameOfAnimation(gd::string p0);
public:
    
private:
    [[deprecated("SpriteAnimationManager::updateAnimationSpeed not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x70cf30
     * @note[short] Android
     */
    TodoReturn updateAnimationSpeed(float p0);
public:
    CCAnimatedSprite* m_sprite;
    cocos2d::CCDictionary* m_animationDict1;
    cocos2d::CCDictionary* m_animationDict2;
    cocos2d::CCDictionary* m_animationDict3;
    gd::string m_queuedAnimation;
    float m_speed;
    cocos2d::CCDictionary* m_animationDict4;
    cocos2d::CCDictionary* m_animationDict5;
    gd::string m_currentAnimation;
    gd::string m_nextAnimation;
};
