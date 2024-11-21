#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "CCSpritePlus.hpp"

class CCSpritePart : public CCSpritePlus {
public:
    static constexpr auto CLASS_NAME = "CCSpritePart";
    GEODE_CUSTOM_CONSTRUCTOR_GD(CCSpritePart, CCSpritePlus)
    
private:
    [[deprecated("CCSpritePart::create not implemented")]]
    /**
     * @note[short] Android
     */
    static CCSpritePart* create(cocos2d::CCTexture2D* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x2f51d8
     * @note[short] MacOS (Intel): 0x362320
     * @note[short] Windows: 0x46a30
     * @note[short] iOS: 0x8375c
     * @note[short] Android
     */
    virtual void setVisible(bool p0);
    
private:
    [[deprecated("CCSpritePart::createWithSpriteFrameName not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createWithSpriteFrameName(char const* p0);
public:
    
private:
    [[deprecated("CCSpritePart::frameChanged not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn frameChanged(gd::string p0);
public:
    
private:
    [[deprecated("CCSpritePart::getBeingUsed not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getBeingUsed();
public:
    
private:
    [[deprecated("CCSpritePart::hideInactive not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn hideInactive();
public:
    
private:
    [[deprecated("CCSpritePart::markAsNotBeingUsed not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn markAsNotBeingUsed();
public:
    
private:
    [[deprecated("CCSpritePart::resetTextureRect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetTextureRect();
public:
    
private:
    [[deprecated("CCSpritePart::setBeingUsed not implemented")]]
    /**
     * @note[short] Android
     */
    void setBeingUsed(bool p0);
public:
    
private:
    [[deprecated("CCSpritePart::updateDisplayFrame not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateDisplayFrame(gd::string p0);
public:
    bool m_isBeingUsed;
    gd::string m_spriteFrameName;
    SpritePartDelegate* m_delegate;
};
