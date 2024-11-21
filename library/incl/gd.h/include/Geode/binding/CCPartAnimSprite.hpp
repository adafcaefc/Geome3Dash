#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class CCPartAnimSprite : public cocos2d::CCSprite {
public:
    static constexpr auto CLASS_NAME = "CCPartAnimSprite";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(CCPartAnimSprite, cocos2d::CCSprite)
    
private:
    [[deprecated("CCPartAnimSprite::setScaleX not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2f4b18
     * @note[short] MacOS (Intel): 0x361ca0
     * @note[short] iOS: 0x833f0
     * @note[short] Android
     */
    virtual void setScaleX(float p0);
public:
    
private:
    [[deprecated("CCPartAnimSprite::setScaleY not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2f4b40
     * @note[short] MacOS (Intel): 0x361cc0
     * @note[short] iOS: 0x83418
     * @note[short] Android
     */
    virtual void setScaleY(float p0);
public:
    
private:
    [[deprecated("CCPartAnimSprite::setScale not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2f4af0
     * @note[short] MacOS (Intel): 0x361c80
     * @note[short] iOS: 0x833c8
     * @note[short] Android
     */
    virtual void setScale(float p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x2f4e04
     * @note[short] MacOS (Intel): 0x361f30
     * @note[short] Windows: 0x468a0
     * @note[short] iOS: 0x83604
     * @note[short] Android
     */
    virtual void setOpacity(unsigned char p0);

    /**
     * @note[short] MacOS (ARM): 0x2f4b68
     * @note[short] MacOS (Intel): 0x361ce0
     * @note[short] Windows: 0x466f0
     * @note[short] iOS: 0x83440
     * @note[short] Android
     */
    virtual void setBlendFunc(cocos2d::_ccBlendFunc p0);
    
private:
    [[deprecated("CCPartAnimSprite::setDisplayFrame not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2f46bc
     * @note[short] MacOS (Intel): 0x361840
     * @note[short] iOS: 0x83094
     * @note[short] Android
     */
    virtual void setDisplayFrame(cocos2d::CCSpriteFrame* p0);
public:
    
private:
    [[deprecated("CCPartAnimSprite::isFrameDisplayed not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2f4814
     * @note[short] MacOS (Intel): 0x3619b0
     * @note[short] iOS: 0x831c0
     * @note[short] Android
     */
    virtual bool isFrameDisplayed(cocos2d::CCSpriteFrame* p0);
public:
    
private:
    [[deprecated("CCPartAnimSprite::displayFrame not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2f482c
     * @note[short] MacOS (Intel): 0x3619d0
     * @note[short] iOS: 0x831d8
     * @note[short] Android
     */
    virtual cocos2d::CCSpriteFrame* displayFrame();
public:
    
private:
    [[deprecated("CCPartAnimSprite::changeTextureOfID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn changeTextureOfID(char const* p0, char const* p1);
public:
    
private:
    [[deprecated("CCPartAnimSprite::countParts not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn countParts();
public:
    
private:
    [[deprecated("CCPartAnimSprite::createWithAnimDesc not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createWithAnimDesc(char const* p0, cocos2d::CCTexture2D* p1, bool p2);
public:
    
private:
    [[deprecated("CCPartAnimSprite::dirtify not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn dirtify();
public:
    
private:
    [[deprecated("CCPartAnimSprite::getSpriteForKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getSpriteForKey(char const* p0);
public:
    
private:
    [[deprecated("CCPartAnimSprite::initWithAnimDesc not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn initWithAnimDesc(char const* p0, cocos2d::CCTexture2D* p1, bool p2);
public:

    /**
     * @note[short] Windows: 0x467c0
     * @note[short] Android
     */
    void setColor(cocos2d::ccColor3B p0);
    
private:
    [[deprecated("CCPartAnimSprite::setFlipX not implemented")]]
    /**
     * @note[short] Android
     */
    void setFlipX(bool p0);
public:
    
private:
    [[deprecated("CCPartAnimSprite::setFlipY not implemented")]]
    /**
     * @note[short] Android
     */
    void setFlipY(bool p0);
public:
    
private:
    [[deprecated("CCPartAnimSprite::transformSprite not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn transformSprite(SpriteDescription* p0);
public:
    
private:
    [[deprecated("CCPartAnimSprite::tweenSpriteTo not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn tweenSpriteTo(SpriteDescription* p0, float p1);
public:
    
private:
    [[deprecated("CCPartAnimSprite::tweenToFrame not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn tweenToFrame(cocos2d::CCSpriteFrame* p0, float p1);
public:
    cocos2d::CCDictionary* m_spritePartIDs;
    cocos2d::CCSpriteFrame* m_spriteFrame;
    bool m_hasChanged;
    cocos2d::CCSize m_unkSize;
    cocos2d::CCArray* m_spriteParts;
};
