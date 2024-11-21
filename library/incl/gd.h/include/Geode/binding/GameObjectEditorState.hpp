#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GameObjectEditorState {
public:
    static constexpr auto CLASS_NAME = "GameObjectEditorState";
    
private:
    [[deprecated("GameObjectEditorState::loadValues not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn loadValues(GameObject* p0);
public:
};
