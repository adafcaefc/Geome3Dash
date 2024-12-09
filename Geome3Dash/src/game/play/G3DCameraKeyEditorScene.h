#pragma once

#include "G3DGameLayer.h"

namespace g3d
{
    class G3DCameraKeyEditorScene 
        : public G3DGameLayer
        , public CustomKeyboardDelegate
        , public CustomMouseDelegate
        , public CustomTouchDelegate
    {
    protected:
        LevelEditorLayer* levelEditorLayer = nullptr;

        bool isEditing = false;
        bool isPressingControl = false;
        bool isRightClicking = false;
        bool isRightClickingGetPos = false;
        float lastMouseX = 0.0;
        float lastMouseY = 0.0;

        virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) override;
        virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) override;
        virtual void scrollWheel(float y, float x) override;
        virtual void onKey(enumKeyCodes key, bool pressed, bool holding) override;

        void onAdd(CCObject*);
        void onRemoveLast(CCObject*);

        virtual bool setup(LevelEditorLayer* layer);

        static G3DCameraKeyEditorScene* instance;
    public:
        static auto create(LevelEditorLayer* layer)
        {
            auto node = new G3DCameraKeyEditorScene;
            if (node->setup(layer)) { node->autorelease(); }
            else { CC_SAFE_DELETE(node); }
            return node;
        }
        ~G3DCameraKeyEditorScene();
        friend class G3DCameraKeyEditorPopup;
    };
}