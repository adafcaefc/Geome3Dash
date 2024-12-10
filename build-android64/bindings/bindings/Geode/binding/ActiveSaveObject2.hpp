#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class ActiveSaveObject2 {
public:
    static constexpr auto CLASS_NAME = "ActiveSaveObject2";
    GameObject* m_gameObject;
    EasingType m_easingType;
};
