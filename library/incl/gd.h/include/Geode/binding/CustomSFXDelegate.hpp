#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class CustomSFXDelegate {
public:
    static constexpr auto CLASS_NAME = "CustomSFXDelegate";
    
private:
    [[deprecated("CustomSFXDelegate::sfxObjectSelected not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void sfxObjectSelected(SFXInfoObject* p0);
public:
    
private:
    [[deprecated("CustomSFXDelegate::getActiveSFXID not implemented")]]
    /**
     * @note[short] Android
     */
    virtual int getActiveSFXID();
public:
    
private:
    [[deprecated("CustomSFXDelegate::overridePlaySFX not implemented")]]
    /**
     * @note[short] Android
     */
    virtual bool overridePlaySFX(SFXInfoObject* p0);
public:
};
