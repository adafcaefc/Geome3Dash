#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class CCSpritePlus : public cocos2d::CCSprite {
public:
    static constexpr auto CLASS_NAME = "CCSpritePlus";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(CCSpritePlus, cocos2d::CCSprite)
    
private:
    [[deprecated("CCSpritePlus::createWithSpriteFrame not implemented")]]
    /**
Creates a sprite by a given sprite frame

 @param frame the frame to give to the specific sprite

 @return CCSpritePlus object and returns null if initialization fai     * @note[short] Android
     */
    static CCSpritePlus* createWithSpriteFrame(cocos2d::CCSpriteFrame* frame);
public:
    
private:
    [[deprecated("CCSpritePlus::createWithSpriteFrameName not implemented")]]
    /**
Creates a sprite by a given sprite's frame name

 @param frame the frame or filename to give to the specific sprite

 @return CCSpritePlus object and returns null if initialization fai     * @note[short] Android
     */
    static CCSpritePlus* createWithSpriteFrameName(char const* frame);
public:

    /**
Sets X's scale on itself and it's followers

 @param fScaleX the scale of X to s     * @note[short] MacOS (ARM): 0x3de1dc
     * @note[short] MacOS (Intel): 0x46f000
     * @note[short] Windows: 0x481d0
     * @note[short] iOS: 0x1b9fb4
     * @note[short] Android
     */
    virtual void setScaleX(float fScaleX);

    /**
Sets Y's scale on itself and it's followers

 @param fScaleY the scale of Y to s     * @note[short] MacOS (ARM): 0x3de258
     * @note[short] MacOS (Intel): 0x46f080
     * @note[short] Windows: 0x48250
     * @note[short] iOS: 0x1ba030
     * @note[short] Android
     */
    virtual void setScaleY(float fScaleY);

    /**
Sets the Scale of itself and it's followers

 @param fScale the scale value to s     * @note[short] MacOS (ARM): 0x3de2d4
     * @note[short] MacOS (Intel): 0x46f100
     * @note[short] Windows: 0x482e0
     * @note[short] iOS: 0x1ba0ac
     * @note[short] Android
     */
    virtual void setScale(float fScale);

    /**
Sets the position where the sprite will be at and it's followers

 @param pos the position to place to the sprite and it's followe     * @note[short] MacOS (ARM): 0x3ddeac
     * @note[short] MacOS (Intel): 0x46ec60
     * @note[short] Windows: 0x47dd0
     * @note[short] iOS: 0x1b9c84
     * @note[short] Android
     */
    virtual void setPosition(cocos2d::CCPoint const& pos);

    /**
Sets the sprite's given rotation and it's followers

 @param fRotation the rotation value to s     * @note[short] MacOS (ARM): 0x3ddf20
     * @note[short] MacOS (Intel): 0x46ece0
     * @note[short] Windows: 0x47e60
     * @note[short] iOS: 0x1b9cf8
     * @note[short] Android
     */
    virtual void setRotation(float fRotation);

    /**
Sets the sprite's given rotation of X and it's followers

 @param fRotationX the rotation of X to se     * @note[short] MacOS (ARM): 0x3ddf94
     * @note[short] MacOS (Intel): 0x46ed60
     * @note[short] Windows: 0x47ef0
     * @note[short] iOS: 0x1b9d6c
     * @note[short] Android
     */
    virtual void setRotationX(float fRotationX);

    /**
Sets the sprite's given rotation of Y and it's followers

 @param fRotationY the roation of Y to s     * @note[short] MacOS (ARM): 0x3de008
     * @note[short] MacOS (Intel): 0x46ede0
     * @note[short] Windows: 0x47f80
     * @note[short] iOS: 0x1b9de0
     * @note[short] Android
     */
    virtual void setRotationY(float p0);

    /**
Initalizes the sprite using a texture

 @param texture the texture to initalize the sprite with

 @return true if initalization succeede     * @note[short] MacOS (ARM): 0x3dde98
     * @note[short] MacOS (Intel): 0x46ec40
     * @note[short] Windows: 0x47db0
     * @note[short] iOS: 0x1b9c70
     * @note[short] Android
     */
    virtual bool initWithTexture(cocos2d::CCTexture2D* texture);

    /**
Initalizes the sprite with a frame name

 @param frame the frame to initalize the sprite with

 @return true if initalization succeed     * @note[short] MacOS (ARM): 0x3dde8c
     * @note[short] MacOS (Intel): 0x46ec20
     * @note[short] Windows: 0x47da0
     * @note[short] iOS: 0x1b9c64
     * @note[short] Android
     */
    virtual bool initWithSpriteFrameName(char const* p0);

    /**
Sets flipX to itself and it's followers

 @param flipX the direction that the sprite should be flipped      * @note[short] MacOS (ARM): 0x3de07c
     * @note[short] MacOS (Intel): 0x46ee60
     * @note[short] Windows: 0x48010
     * @note[short] iOS: 0x1b9e54
     * @note[short] Android
     */
    virtual void setFlipX(bool flipX);

    /**
Sets flipY to itself and it's followers

 @param flipY the direction that the sprite should be flipped      * @note[short] MacOS (ARM): 0x3de12c
     * @note[short] MacOS (Intel): 0x46ef30
     * @note[short] Windows: 0x480f0
     * @note[short] iOS: 0x1b9f04
     * @note[short] Android
     */
    virtual void setFlipY(bool flipY);
    
private:
    [[deprecated("CCSpritePlus::addFollower not implemented")]]
    /**
Adds a follower to the sprite

 @param follower Something that will follow this spri     * @note[short] MacOS (Intel): 0x46f180
     * @note[short] Android
     */
    void addFollower(cocos2d::CCNode* follower);
public:
    
private:
    [[deprecated("CCSpritePlus::followSprite not implemented")]]
    /**
Attaches a sprite to the sprite. and other way around

 you can think of this as attaching 2 lego blocks together and letting

 it drag along.

 @param sprite the sprite to attach to the main sprite and vice ver     * @note[short] Android
     */
    void followSprite(CCSpritePlus* sprite);
public:
    
private:
    [[deprecated("CCSpritePlus::getFollower not implemented")]]
    /**
Obtains the first following sprite if it has a follower on hand

 @return nullptr if there is no follower avalib     * @note[short] Android
     */
    CCSpritePlus* getFollower();
public:

    /**
Removes a specific following sprite from this sprite.

 @param sprite follower sprite that will be remove     * @note[short] Windows: 0x48370
     * @note[short] Android
     */
    void removeFollower(cocos2d::CCNode* sprite);
    
private:
    [[deprecated("CCSpritePlus::stopFollow not implemented")]]
    /**
Stops this child sprite from following it's given pare     * @note[short] Android
     */
    void stopFollow();
public:
    cocos2d::CCArray* m_followers;
    CCSpritePlus* m_followingSprite;
    bool m_hasFollower;
    bool m_propagateScaleChanges;
    bool m_propagateFlipChanges;
    GEODE_PAD(1);
};
