#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "GameObject.hpp"

class TextGameObject : public GameObject {
public:
    static constexpr auto CLASS_NAME = "TextGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(TextGameObject, GameObject)

    /**
     * @note[short] Windows: 0x1a4530
     * @note[short] Android
     */
    static TextGameObject* create(cocos2d::CCTexture2D* p0);
    
private:
    [[deprecated("TextGameObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4ef584
     * @note[short] MacOS (Intel): 0x5b92a0
     * @note[short] iOS: 0x264288
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("TextGameObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4ef6f0
     * @note[short] MacOS (Intel): 0x5b93d0
     * @note[short] iOS: 0x2643c8
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:
    
private:
    [[deprecated("TextGameObject::updateTextKerning not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4ef2d0
     * @note[short] MacOS (Intel): 0x5b9020
     * @note[short] iOS: 0x263fd0
     * @note[short] Android
     */
    virtual void updateTextKerning(int p0);
public:
    
private:
    [[deprecated("TextGameObject::getTextKerning not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4efef4
     * @note[short] MacOS (Intel): 0x5b9d90
     * @note[short] iOS: 0x264718
     * @note[short] Android
     */
    virtual int getTextKerning();
public:
    
private:
    [[deprecated("TextGameObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(cocos2d::CCTexture2D* p0);
public:

    /**
     * @note[short] MacOS (Intel): 0x5b9030
     * @note[short] Windows: 0x1a4620
     * @note[short] Android
     */
    void updateTextObject(gd::string p0, bool p1);
    gd::string m_text;
    int m_kerning;
};
