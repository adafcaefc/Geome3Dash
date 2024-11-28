#include "pch.h"

#include "LevelEditorGUI.h"

#include "LevelDataManager.h"

#include "Lib/imgui-cocos/imgui-cocos.hpp"

namespace g3d
{
    void setupImGui()
    {
        auto& io = ImGui::GetIO();
        io.ConfigWindowsMoveFromTitleBarOnly = true;
    }


    ImVec2 computeBezierPoint(const CubicBezier& bezier, float t) 
    {
        float u = 1.0f - t;
        float tt = t * t;
        float uu = u * u;
        float uuu = uu * u;
        float ttt = tt * t;

        float x = uuu * bezier.x0 + 3 * uu * t * bezier.cx1 + 3 * u * tt * bezier.cx2 + ttt * bezier.x1;
        float y = uuu * bezier.y0 + 3 * uu * t * bezier.cy1 + 3 * u * tt * bezier.cy2 + ttt * bezier.y1;

        return ImVec2(x, y);
    }

    void renderBezierEditor(CubicBezier& bezier) {

        static int selectedPoint = -1; // Index of the currently selected point
        static bool isDragging = false;
        ImGui::Begin("Bezier Curve Editor");

        ImVec2 canvasSize = ImVec2(400, 400);
        ImVec2 canvasPos = ImGui::GetCursorScreenPos();
        ImDrawList* drawList = ImGui::GetWindowDrawList();

        drawList->AddRectFilled(canvasPos, ImVec2(canvasPos.x + canvasSize.x, canvasPos.y + canvasSize.y), IM_COL32(50, 50, 50, 255));
        drawList->AddRect(canvasPos, ImVec2(canvasPos.x + canvasSize.x, canvasPos.y + canvasSize.y), IM_COL32(255, 255, 255, 255));

        ImVec2 offset = ImVec2(canvasPos.x + canvasSize.x * 0.1f, canvasPos.y + canvasSize.y * 0.1f);
        float scale = canvasSize.x * 0.8f;

        const int segments = 100;
        for (int i = 0; i < segments; ++i) 
        {
            float t0 = static_cast<float>(i) / segments;
            float t1 = static_cast<float>(i + 1) / segments;
            ImVec2 p0 = computeBezierPoint(bezier, t0);
            ImVec2 p1 = computeBezierPoint(bezier, t1);

            p0 = ImVec2(offset.x + p0.x * scale, offset.y + p0.y * scale);
            p1 = ImVec2(offset.x + p1.x * scale, offset.y + p1.y * scale);

            drawList->AddLine(p0, p1, IM_COL32(200, 100, 100, 255), 2.0f);
        }

        ImVec2 points[4] = 
        {
            ImVec2(offset.x + bezier.x0 * scale, offset.y + bezier.y0 * scale),
            ImVec2(offset.x + bezier.cx1 * scale, offset.y + bezier.cy1 * scale),
            ImVec2(offset.x + bezier.cx2 * scale, offset.y + bezier.cy2 * scale),
            ImVec2(offset.x + bezier.x1 * scale, offset.y + bezier.y1 * scale)
        };

        ImGui::PushClipRect(canvasPos, ImVec2(canvasPos.x + canvasSize.x, canvasPos.y + canvasSize.y), true);

        for (int i = 0; i < 4; ++i) 
        {
            drawList->AddCircleFilled(points[i], 5.0f, IM_COL32(255, 255, 0, 255));

            if (ImGui::IsMouseHoveringRect(canvasPos, ImVec2(canvasPos.x + canvasSize.x, canvasPos.y + canvasSize.y))) 
            {
                ImVec2 mousePos = ImGui::GetMousePos();
                float distance = std::hypot(points[i].x - mousePos.x, points[i].y - mousePos.y);

                if (distance < 10.0f && ImGui::IsMouseClicked(0)) 
                {
                    selectedPoint = i;
                    isDragging = true;
                    ImGui::SetNextFrameWantCaptureMouse(true); 
                }
            }
        }

        if (isDragging && selectedPoint != -1) 
        {
            if (ImGui::IsMouseDragging(0)) 
            {
                ImVec2 mousePos = ImGui::GetMousePos();
                float normalizedX = (mousePos.x - offset.x) / scale;
                float normalizedY = (mousePos.y - offset.y) / scale;

                switch (selectedPoint) 
                {
                case 0: bezier.x0 = normalizedX; bezier.y0 = normalizedY; break;
                case 1: bezier.cx1 = normalizedX; bezier.cy1 = normalizedY; break;
                case 2: bezier.cx2 = normalizedX; bezier.cy2 = normalizedY; break;
                case 3: bezier.x1 = normalizedX; bezier.y1 = normalizedY; break;
                }
            }
            else if (ImGui::IsMouseReleased(0)) 
            {
                isDragging = false;
                selectedPoint = -1;
                ImGui::SetNextFrameWantCaptureMouse(false);
            }
        }

        ImGui::PopClipRect();
        ImGui::End();
    }
        
    static LevelData currentLevelData; 

    void renderLevelDataEditor()
    {
        ImGui::Begin("Level Data Editor");

        GJBaseGameLayer* layer = nullptr;
        if (PlayLayer::get()) { layer = PlayLayer::get(); }
        else if (LevelEditorLayer::get()) { layer = LevelEditorLayer::get(); }
        if (layer)
        {
            try
            {
                if (ImGui::Button("Load Level Data")) { currentLevelData = getLevelData(layer); }
                if (ImGui::Button("Save Level Data")) { setLevelData(layer, currentLevelData); }
            }
            catch (...)
            {

            }
        }

        if (ImGui::Button("Reset Data")) 
        { 
            currentLevelData = LevelData::getDefault();
        }

        ImGui::Separator();

        // Edit Bezier curve fields
        ImGui::Text("Bezier Curve:");
        ImGui::InputDouble("Start X", &currentLevelData.bezierCurve.x0);
        ImGui::InputDouble("Start Y", &currentLevelData.bezierCurve.y0);
        ImGui::InputDouble("Control 1 X", &currentLevelData.bezierCurve.cx1);
        ImGui::InputDouble("Control 1 Y", &currentLevelData.bezierCurve.cy1);
        ImGui::InputDouble("Control 2 X", &currentLevelData.bezierCurve.cx2);
        ImGui::InputDouble("Control 2 Y", &currentLevelData.bezierCurve.cy2);
        ImGui::InputDouble("End X", &currentLevelData.bezierCurve.x1);
        ImGui::InputDouble("End Y", &currentLevelData.bezierCurve.y1);
        ImGui::InputDouble("Bezier Multiplier", &currentLevelData.bezierMultiplier);

        ImGui::Separator();

        ImGui::Text("Position:");
        ImGui::InputDouble("X", &currentLevelData.x);
        ImGui::InputDouble("Y", &currentLevelData.y);
        ImGui::InputDouble("Z", &currentLevelData.z);

        ImGui::Text("Rotation:");
        ImGui::InputDouble("Yaw", &currentLevelData.yaw);
        ImGui::InputDouble("Pitch", &currentLevelData.pitch);

        ImGui::Checkbox("Lock Camera", &currentLevelData.lock);

        ImGui::Separator();
        ImGui::Text("Camera Actions:");

        for (size_t i = 0; i < currentLevelData.actions.size(); ++i) 
        {
            ImGui::PushID(static_cast<int>(i)); 
            ImGui::Text("Action %d:", static_cast<int>(i + 1));
            CameraAction& action = currentLevelData.actions[i];

            ImGui::InputDouble("X##Action", &action.x);
            ImGui::InputDouble("Y##Action", &action.y);
            ImGui::InputDouble("Z##Action", &action.z);
            ImGui::InputDouble("Yaw##Action", &action.yaw);
            ImGui::InputDouble("Pitch##Action", &action.pitch);
            ImGui::InputDouble("Time##Action", &action.time);
            ImGui::InputDouble("TriggerAt##Action", &action.triggerAt);

            if (ImGui::Button("Remove Action")) 
            {
                currentLevelData.actions.erase(currentLevelData.actions.begin() + i);
                ImGui::PopID();
                break;
            }

            ImGui::Separator();
            ImGui::PopID();
        }

        if (ImGui::Button("Add Action")) { currentLevelData.actions.push_back({}); }

        ImGui::End();
    }

    bool isTabKeyPressed()
    {
        return (GetAsyncKeyState(VK_TAB) & 0x8000) != 0;
    }

    void renderImGui()
    {
        static bool showEditorWindow = false;
        static bool prevTabState = false;
        bool currentTabState = isTabKeyPressed();
        if (currentTabState && !prevTabState) { showEditorWindow = !showEditorWindow;  }
        prevTabState = currentTabState;
        if (showEditorWindow)
        {
            renderBezierEditor(currentLevelData.bezierCurve);
            renderLevelDataEditor();
        }
    }

    class $modify(PlayLayer)
    {
        bool init(GJGameLevel * level, bool useReplay, bool dontCreateObjects)
        {
            if (PlayLayer::init(level, useReplay, dontCreateObjects))
            {
                try
                {
                    currentLevelData = getLevelData(this);
                }
                catch (...)
                {

                }
                return true;
            }
            return false;
        }
    };

    class $modify(LevelEditorLayer)
    {
        bool init(GJGameLevel * p0, bool p1)
        {
            if (LevelEditorLayer::init(p0, p1))
            {
                try
                {
                    currentLevelData = getLevelData(this);
                }
                catch (...)
                {

                }
                return true;
            }
            return false;
        }
    };

    //class $modify(EditorPauseLayer)
    //{
    //    void onSave(cocos2d::CCObject * sender)
    //    {
    //    }
    //    void onSaveAndExit(cocos2d::CCObject* sender)
    //    {
    //    }
    //};

    $on_mod(Loaded) 
    {
        ImGuiCocos::get().setup(setupImGui).draw(renderImGui);
    }
}