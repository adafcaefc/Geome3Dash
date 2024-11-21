#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "TableViewCell.hpp"

class OptionsCell : public TableViewCell {
public:
    static constexpr auto CLASS_NAME = "OptionsCell";
    GEODE_CUSTOM_CONSTRUCTOR_GD(OptionsCell, TableViewCell)

    /**
     * @note[short] MacOS (Intel): 0x232740
     * @note[short] Windows: 0xb49f0
     * @note[short] Android
     */
    void loadFromObject(OptionsObject* p0);
    
private:
    [[deprecated("OptionsCell::onToggleOption not implemented")]]
    /**
     * @note[short] Android
     */
    void onToggleOption(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("OptionsCell::updateBGColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateBGColor(int p0);
public:
};
