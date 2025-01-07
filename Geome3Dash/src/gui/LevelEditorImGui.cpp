#include "pch.h"

#include "LevelEditorImGui.h"
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
        //ImGui::Begin("Test");
        //ImGui::End();
    }

    $on_mod(Loaded) 
    {
        ImGuiCocos::get().setup(setupImGui).draw(renderImGui);
    }
}