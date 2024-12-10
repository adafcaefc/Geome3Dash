#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class CCCounterLabel : public cocos2d::CCLabelBMFont {
public:
    static constexpr auto CLASS_NAME = "CCCounterLabel";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(CCCounterLabel, cocos2d::CCLabelBMFont)

    /**
     * @note[short] Android
     */
    static CCCounterLabel* create(int p0, char const* p1, FormatterType p2);

    /**
     * @note[short] Android
     */
    TodoReturn calculateStepSize(int p0);

    /**
     * @note[short] Android
     */
    TodoReturn disableCounter();

    /**
     * @note[short] Android
     */
    TodoReturn enableCounter();

    /**
     * @note[short] Android
     */
    TodoReturn fastUpdateCounter();

    /**
     * @note[short] Android
     */
    TodoReturn getTargetCount();

    /**
     * @note[short] Android
     */
    bool init(int p0, char const* p1, FormatterType p2);

    /**
     * @note[short] Android
     */
    void setTargetCount(int p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateCounter(float p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateString();
};
