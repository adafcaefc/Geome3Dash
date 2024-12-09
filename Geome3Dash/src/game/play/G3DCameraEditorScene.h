#pragma once

#include "G3DGameLayer.h"

namespace g3d
{
    class G3DCameraEditorScene
        : public G3DGameLayer
        , public CustomKeyboardDelegate
        , public CustomMouseDelegate
        , public CustomTouchDelegate
    {
    protected:
        virtual void loadBlocks() override;
        virtual void loadPlayers() override;
        virtual void drawPlayers() override;

        virtual void calculateJumpAndPos();

        LevelEditorLayer* levelEditorLayer = nullptr;
        CCLayer* fakeGameLayer = nullptr;
        PlayerObject* playerObject = nullptr;

        bool isPressingControl = false;
        bool isRightClicking = false;
        bool isRightClickingGetPos = false;
        float lastMouseX = 0.0;
        float lastMouseY = 0.0;

        virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) override;
        virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) override;
        virtual void scrollWheel(float y, float x) override;
        virtual void onKey(enumKeyCodes key, bool pressed, bool holding) override;

        double cubeRotationZ = 0;
        glm::vec3 cubePosition = glm::vec3(0, 105, 400);
        glm::vec3 spikePosition = glm::vec3(900, 105, 400);

        std::vector<GameObject*> spikeObjs;
        std::unordered_map<float, GameObject*> blockObjs;

        virtual bool setup(LevelEditorLayer* layer);

        static G3DCameraEditorScene* instance;
        
    public:
        static auto create(LevelEditorLayer* layer)
        {
            auto node = new G3DCameraEditorScene;
            if (node->setup(layer)) { node->autorelease(); }
            else { CC_SAFE_DELETE(node); }
            return node;
        }
        ~G3DCameraEditorScene();
        friend class G3DCameraEditorPopup;
    };
}