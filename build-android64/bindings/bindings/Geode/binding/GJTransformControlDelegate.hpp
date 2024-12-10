#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJTransformControlDelegate {
public:
    static constexpr auto CLASS_NAME = "GJTransformControlDelegate";

    /**
     * @note[short] Android
     */
    virtual void transformScaleXChanged(float p0);

    /**
     * @note[short] Android
     */
    virtual void transformScaleYChanged(float p0);

    /**
     * @note[short] Android
     */
    virtual void transformScaleXYChanged(float p0, float p1);

    /**
     * @note[short] Android
     */
    virtual void transformRotationXChanged(float p0);

    /**
     * @note[short] Android
     */
    virtual void transformRotationYChanged(float p0);

    /**
     * @note[short] Android
     */
    virtual void transformRotationChanged(float p0);

    /**
     * @note[short] Android
     */
    virtual void transformResetRotation();

    /**
     * @note[short] Android
     */
    virtual void transformRestoreRotation();

    /**
     * @note[short] Android
     */
    virtual void transformSkewXChanged(float p0);

    /**
     * @note[short] Android
     */
    virtual void transformSkewYChanged(float p0);

    /**
     * @note[short] Android
     */
    virtual void transformChangeBegin();

    /**
     * @note[short] Android
     */
    virtual void transformChangeEnded();

    /**
     * @note[short] Android
     */
    virtual void updateTransformControl();

    /**
     * @note[short] Android
     */
    virtual void anchorPointMoved(cocos2d::CCPoint p0);

    /**
     * @note[short] Android
     */
    virtual cocos2d::CCNode* getTransformNode();

    /**
     * @note[short] Android
     */
    virtual cocos2d::CCLayer* getUI();
};
