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
    
private:
    [[deprecated("GJTransformControlDelegate::transformScaleXChanged not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void transformScaleXChanged(float p0);
public:
    
private:
    [[deprecated("GJTransformControlDelegate::transformScaleYChanged not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void transformScaleYChanged(float p0);
public:
    
private:
    [[deprecated("GJTransformControlDelegate::transformScaleXYChanged not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void transformScaleXYChanged(float p0, float p1);
public:
    
private:
    [[deprecated("GJTransformControlDelegate::transformRotationXChanged not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void transformRotationXChanged(float p0);
public:
    
private:
    [[deprecated("GJTransformControlDelegate::transformRotationYChanged not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void transformRotationYChanged(float p0);
public:
    
private:
    [[deprecated("GJTransformControlDelegate::transformRotationChanged not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void transformRotationChanged(float p0);
public:
    
private:
    [[deprecated("GJTransformControlDelegate::transformResetRotation not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void transformResetRotation();
public:
    
private:
    [[deprecated("GJTransformControlDelegate::transformRestoreRotation not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void transformRestoreRotation();
public:
    
private:
    [[deprecated("GJTransformControlDelegate::transformSkewXChanged not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void transformSkewXChanged(float p0);
public:
    
private:
    [[deprecated("GJTransformControlDelegate::transformSkewYChanged not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void transformSkewYChanged(float p0);
public:
    
private:
    [[deprecated("GJTransformControlDelegate::transformChangeBegin not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void transformChangeBegin();
public:
    
private:
    [[deprecated("GJTransformControlDelegate::transformChangeEnded not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void transformChangeEnded();
public:
    
private:
    [[deprecated("GJTransformControlDelegate::updateTransformControl not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void updateTransformControl();
public:
    
private:
    [[deprecated("GJTransformControlDelegate::anchorPointMoved not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void anchorPointMoved(cocos2d::CCPoint p0);
public:
    
private:
    [[deprecated("GJTransformControlDelegate::getTransformNode not implemented")]]
    /**
     * @note[short] Android
     */
    virtual cocos2d::CCNode* getTransformNode();
public:
    
private:
    [[deprecated("GJTransformControlDelegate::getUI not implemented")]]
    /**
     * @note[short] Android
     */
    virtual cocos2d::CCLayer* getUI();
public:
};
