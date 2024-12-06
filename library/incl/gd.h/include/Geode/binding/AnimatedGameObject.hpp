#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "EnhancedGameObject.hpp"
#include "AnimatedSpriteDelegate.hpp"
#include "SpritePartDelegate.hpp"

class AnimatedGameObject : public EnhancedGameObject, public AnimatedSpriteDelegate, public SpritePartDelegate {
public:
    static constexpr auto CLASS_NAME = "AnimatedGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(AnimatedGameObject, EnhancedGameObject)
    
private:
    [[deprecated("AnimatedGameObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static AnimatedGameObject* create(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x168658
     * @note[short] MacOS (Intel): 0x1a64b0
     * @note[short] Windows: 0x48b5e0
     * @note[short] iOS: 0x37cdc0
     * @note[short] Android
     */
    virtual void setOpacity(unsigned char p0);
    
private:
    [[deprecated("AnimatedGameObject::setChildColor not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16a064
     * @note[short] MacOS (Intel): 0x1a80d0
     * @note[short] iOS: 0x37de10
     * @note[short] Android
     */
    virtual void setChildColor(cocos2d::ccColor3B const& p0);
public:
    
private:
    [[deprecated("AnimatedGameObject::resetObject not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16a004
     * @note[short] MacOS (Intel): 0x1a8060
     * @note[short] iOS: 0x37ddb8
     * @note[short] Android
     */
    virtual void resetObject();
public:
    
private:
    [[deprecated("AnimatedGameObject::activateObject not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16855c
     * @note[short] MacOS (Intel): 0x1a63a0
     * @note[short] iOS: 0x37cce0
     * @note[short] Android
     */
    virtual void activateObject();
public:
    
private:
    [[deprecated("AnimatedGameObject::deactivateObject not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1685a0
     * @note[short] MacOS (Intel): 0x1a63e0
     * @note[short] iOS: 0x37cd24
     * @note[short] Android
     */
    virtual void deactivateObject(bool p0);
public:
    
private:
    [[deprecated("AnimatedGameObject::setObjectColor not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x168724
     * @note[short] MacOS (Intel): 0x1a6590
     * @note[short] iOS: 0x37ce8c
     * @note[short] Android
     */
    virtual void setObjectColor(cocos2d::ccColor3B const& p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x168758
     * @note[short] MacOS (Intel): 0x1a65c0
     * @note[short] Windows: 0x48b6f0
     * @note[short] iOS: 0x37cec0
     * @note[short] Android
     */
    virtual void animationFinished(char const* p0);

    /**
     * @note[short] MacOS (ARM): 0x169858
     * @note[short] MacOS (Intel): 0x1a7930
     * @note[short] Windows: 0x48c9d0
     * @note[short] iOS: 0x37d924
     * @note[short] Android
     */
    virtual void displayFrameChanged(cocos2d::CCObject* p0, gd::string p1);
    
private:
    [[deprecated("AnimatedGameObject::animationForID not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x169d08
     * @note[short] Android
     */
    TodoReturn animationForID(int p0, int p1);
public:
    
private:
    [[deprecated("AnimatedGameObject::getTweenTime not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getTweenTime(int p0, int p1);
public:
    
private:
    [[deprecated("AnimatedGameObject::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16773c
     * @note[short] MacOS (Intel): 0x1a5560
     * @note[short] Android
     */
    bool init(int p0);
public:
    
private:
    [[deprecated("AnimatedGameObject::playAnimation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playAnimation(int p0);
public:
    
private:
    [[deprecated("AnimatedGameObject::setupAnimatedSize not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn setupAnimatedSize(int p0);
public:
    
private:
    [[deprecated("AnimatedGameObject::setupChildSprites not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x167a68
     * @note[short] MacOS (Intel): 0x1a58c0
     * @note[short] Android
     */
    TodoReturn setupChildSprites();
public:
    
private:
    [[deprecated("AnimatedGameObject::updateChildSpriteColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateChildSpriteColor(cocos2d::ccColor3B p0);
public:
    
private:
    [[deprecated("AnimatedGameObject::updateObjectAnimation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateObjectAnimation();
public:
};
