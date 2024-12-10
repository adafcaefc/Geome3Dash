#pragma once

#include "AG3DGameLayer.h"

namespace g3d
{
    class G3DCameraEditorScene : public AG3DGameLayer
    {
    protected:
        virtual void loadBlocks() override;
        virtual void loadPlayers() override;
        virtual void drawPlayers() override;

        void calculateJumpAndPos(float deltaTime);

        LevelEditorLayer* levelEditorLayer = nullptr;
        CCLayer* fakeGameLayer = nullptr;
        PlayerObject* playerObject = nullptr;

        double cubeRotationZ = 0;
        glm::vec3 cubePosition = glm::vec3(0, 105, 400);
        glm::vec3 spikePosition = glm::vec3(900, 105, 400);

        std::vector<GameObject*> spikeObjs;
        std::unordered_map<float, GameObject*> blockObjs;

        virtual bool setup(LevelEditorLayer* layer);

        virtual void update(float delta) override;

        static G3DCameraEditorScene* instance;

        virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) override;
        virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) override;
        virtual void scrollWheel(float y, float x) override;
        virtual void onKey(enumKeyCodes key, bool pressed, bool holding) override;
        
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