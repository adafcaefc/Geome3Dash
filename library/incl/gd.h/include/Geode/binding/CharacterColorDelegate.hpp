#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class CharacterColorDelegate {
public:
    static constexpr auto CLASS_NAME = "CharacterColorDelegate";
    
private:
    [[deprecated("CharacterColorDelegate::playerColorChanged not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void playerColorChanged();
public:
    
private:
    [[deprecated("CharacterColorDelegate::showUnlockPopup not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void showUnlockPopup(int p0, UnlockType p1);
public:
};
