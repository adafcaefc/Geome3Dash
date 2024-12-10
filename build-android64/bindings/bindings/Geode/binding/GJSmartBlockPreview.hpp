#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJSmartBlockPreview : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "GJSmartBlockPreview";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJSmartBlockPreview, cocos2d::CCNode)

    /**
     * @note[short] Android
     */
    static GJSmartBlockPreview* create(gd::string p0);

    /**
     * @note[short] MacOS (ARM): 0x392550
     * @note[short] MacOS (Intel): 0x416ac0
     * @note[short] Android
     */
    TodoReturn addChance(int p0, int p1);

    /**
     * @note[short] Android
     */
    TodoReturn addCount(int p0);

    /**
     * @note[short] Android
     */
    TodoReturn addPreview(gd::string p0, gd::string p1, LevelEditorLayer* p2);

    /**
     * @note[short] Android
     */
    TodoReturn addTemplateGuide(gd::string p0, int p1);

    /**
     * @note[short] Android
     */
    TodoReturn addTemplateGuide(SmartPrefabResult p0, float p1);

    /**
     * @note[short] Android
     */
    TodoReturn createInfoLabel();

    /**
     * @note[short] Android
     */
    bool init(gd::string p0);

    /**
     * @note[short] Android
     */
    TodoReturn toggleSelectItem(bool p0);
};
