#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class ExplodeItemSprite : public cocos2d::CCSprite {
public:
    static constexpr auto CLASS_NAME = "ExplodeItemSprite";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(ExplodeItemSprite, cocos2d::CCSprite)
    
private:
    [[deprecated("ExplodeItemSprite::create not implemented")]]
    /**
     * @note[short] Android
     */
    static ExplodeItemSprite* create();
public:
    
private:
    [[deprecated("ExplodeItemSprite::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1b8200
     * @note[short] MacOS (Intel): 0x202eb0
     * @note[short] iOS: 0x6132c
     * @note[short] Android
     */
    virtual bool init();
public:
    float m_unk1;
    float m_unk2;
    float m_unk3;
    float m_unk4;
    float m_unk5;
    cocos2d::CCParticleSystemQuad* m_unk6;
};
