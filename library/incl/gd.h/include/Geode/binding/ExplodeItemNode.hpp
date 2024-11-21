#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class ExplodeItemNode : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "ExplodeItemNode";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(ExplodeItemNode, cocos2d::CCNode)
    
private:
    [[deprecated("ExplodeItemNode::create not implemented")]]
    /**
     * @note[short] Android
     */
    static ExplodeItemNode* create(cocos2d::CCRenderTexture* p0);
public:
    
private:
    [[deprecated("ExplodeItemNode::update not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1b7f14
     * @note[short] MacOS (Intel): 0x202b30
     * @note[short] iOS: 0x6105c
     * @note[short] Android
     */
    virtual void update(float p0);
public:
    
private:
    [[deprecated("ExplodeItemNode::createSprites not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createSprites(int p0, int p1, float p2, float p3, float p4, float p5, float p6, float p7, cocos2d::ccColor4F p8, cocos2d::ccColor4F p9, bool p10);
public:
    
private:
    [[deprecated("ExplodeItemNode::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(cocos2d::CCRenderTexture* p0);
public:
    cocos2d::CCRenderTexture* m_renderTexture;
    cocos2d::CCArray* m_sprites;
    float m_unk1;
    float m_unk2;
    bool m_unk3;
};
