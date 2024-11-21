#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GauntletSprite : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "GauntletSprite";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GauntletSprite, cocos2d::CCNode)

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     GauntletSprite();

    /**
     * @note[short] MacOS (ARM): 0x3115c8
     * @note[short] MacOS (Intel): 0x381250
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static GauntletSprite* create(GauntletType gauntletType, bool locked);

    /**
     * @note[short] MacOS (ARM): 0x311fe8
     * @note[short] MacOS (Intel): 0x381b50
     * @note[short] Windows: 0x1f4fe0
     * @note[short] Android
     */
    void addLockedSprite();
    
private:
    [[deprecated("GauntletSprite::addNormalSprite not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x311eec
     * @note[short] MacOS (Intel): 0x381a80
     * @note[short] Android
     */
    void addNormalSprite();
public:
    
private:
    [[deprecated("GauntletSprite::colorForType not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::ccColor3B colorForType(GauntletType p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x311e44
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    bool init(GauntletType gauntletType, bool locked);
    
private:
    [[deprecated("GauntletSprite::luminanceForType not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x381e40
     * @note[short] Android
     */
    float luminanceForType(GauntletType p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x311d70
     * @note[short] MacOS (Intel): 0x381930
     * @note[short] Windows: 0x1f5310
     * @note[short] Android
     */
    void toggleLockedSprite(bool p0);
    GauntletType m_gauntletType;
};
