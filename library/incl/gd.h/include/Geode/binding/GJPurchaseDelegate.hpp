#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJPurchaseDelegate {
public:
    static constexpr auto CLASS_NAME = "GJPurchaseDelegate";
    
private:
    [[deprecated("GJPurchaseDelegate::didPurchaseItem not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void didPurchaseItem(GJStoreItem* p0);
public:
};
