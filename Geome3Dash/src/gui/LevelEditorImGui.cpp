#include "pch.h"

#include "LevelEditorImGui.h"
#include "manager/LevelDataManager.h"
#include <imgui-cocos.hpp>

#ifdef GEODE_IS_WINDOWS
namespace g3d
{
    void setupImGui()
    {
        auto& io = ImGui::GetIO();
        io.ConfigWindowsMoveFromTitleBarOnly = true;
    }

    void renderImGui()
    {

    }

    $on_mod(Loaded) 
    {
        ImGuiCocos::get().setup(setupImGui).draw(renderImGui);
    }
}
#endif