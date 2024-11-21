#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class ListButtonBarDelegate {
public:
    static constexpr auto CLASS_NAME = "ListButtonBarDelegate";
    
private:
    [[deprecated("ListButtonBarDelegate::listButtonBarSwitchedPage not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void listButtonBarSwitchedPage(ListButtonBar* p0, int p1);
public:
};
