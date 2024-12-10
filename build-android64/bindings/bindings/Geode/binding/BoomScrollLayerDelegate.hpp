#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class BoomScrollLayerDelegate {
public:
    static constexpr auto CLASS_NAME = "BoomScrollLayerDelegate";

    /**
     * @note[short] Android
     */
    virtual void scrollLayerScrollingStarted(BoomScrollLayer* p0);

    /**
     * @note[short] Android
     */
    virtual void scrollLayerScrolledToPage(BoomScrollLayer* p0, int p1);

    /**
     * @note[short] Android
     */
    virtual void scrollLayerMoved(cocos2d::CCPoint p0);

    /**
     * @note[short] Android
     */
    virtual void scrollLayerWillScrollToPage(BoomScrollLayer* p0, int p1);
};
