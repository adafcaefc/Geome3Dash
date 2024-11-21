#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class ParticlePreviewLayer : public cocos2d::CCLayerColor {
public:
    static constexpr auto CLASS_NAME = "ParticlePreviewLayer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(ParticlePreviewLayer, cocos2d::CCLayerColor)
    
private:
    [[deprecated("ParticlePreviewLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static ParticlePreviewLayer* create(cocos2d::CCParticleSystemQuad* p0);
public:
    
private:
    [[deprecated("ParticlePreviewLayer::draw not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3d4c08
     * @note[short] MacOS (Intel): 0x464c10
     * @note[short] iOS: 0x2d1c18
     * @note[short] Android
     */
    virtual void draw();
public:
    
private:
    [[deprecated("ParticlePreviewLayer::visit not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3d4a80
     * @note[short] MacOS (Intel): 0x464a90
     * @note[short] iOS: 0x2d1b38
     * @note[short] Android
     */
    virtual void visit();
public:
    
private:
    [[deprecated("ParticlePreviewLayer::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(cocos2d::CCParticleSystemQuad* p0);
public:
    
private:
    [[deprecated("ParticlePreviewLayer::postVisit not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn postVisit();
public:
    
private:
    [[deprecated("ParticlePreviewLayer::preVisitWithClippingRect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn preVisitWithClippingRect(cocos2d::CCRect p0);
public:
};
