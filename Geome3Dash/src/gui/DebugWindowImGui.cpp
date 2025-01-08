#include "pch.h"

#include "DebugWindowImGui.h"
#include "manager/LevelDataManager.h"
#include "lib/imgui-cocos/imgui-cocos.hpp"

namespace g3d
{
    void setupImGui()
    {
        auto& io = ImGui::GetIO();
        io.ConfigWindowsMoveFromTitleBarOnly = true;
    }

    void renderImGui()
    {
        // for debugging only
        // should I make a settings for this?
        //if (PlayLayer::get())
        //{
        //    ImGui::Begin("Test");
        //    auto player = PlayLayer::get()->m_player1;
        //    ImGui::Text("m_currentRobotAnimation -> %s", player->m_currentRobotAnimation.c_str());
        //    ImGui::Text("m_wasRobotJump          -> %i", player->m_wasRobotJump);
        //    ImGui::Text("m_isOnGround            -> %i", player->m_isOnGround);
        //    ImGui::End();
        //}
    }

    $on_mod(Loaded) 
    {
        ImGuiCocos::get().setup(setupImGui).draw(renderImGui);
    }
}