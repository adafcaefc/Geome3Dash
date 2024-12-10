#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJBigSprite : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "GJBigSprite";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJBigSprite, cocos2d::CCNode)

    /**
     * @note[short] Android
     */
    static GJBigSprite* create();

    /**
     * @note[short] MacOS (ARM): 0x204a04
     * @note[short] MacOS (Intel): 0x257ec0
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] Android
     */
    TodoReturn finishedLoadingSpriteAsync(cocos2d::CCObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn loadSpriteAsync(gd::string p0, int p1);

    /**
     * @note[short] Android
     */
    TodoReturn unloadAll();

    /**
     * @note[short] Android
     */
    TodoReturn unloadSprite(gd::string p0, int p1);

    /**
     * @note[short] Android
     */
    TodoReturn updateSpriteVisibility();
};
