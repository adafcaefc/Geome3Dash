#pragma once

#include "delegate/CustomKeyboard.h"
#include "delegate/CustomMouse.h"
#include "delegate/CustomTouch.h"

namespace g3d
{
    class G3DBaseNode;
    class CocosShaderProgram;

    class G3DModelPreviewLayer 
        : public CCLayer
        , public CustomKeyboardDelegate
        , public CustomMouseDelegate
        , public CustomTouchDelegate 
    {
        G3DBaseNode* layer3d;
        CocosShaderProgram* shaderProgram;

        bool isPressingControl = false;
        bool isRightClicking = false;
        bool isRightClickingGetPos = false;
        float lastMouseX = 0.0;
        float lastMouseY = 0.0;

        virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods);
        virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y);
        virtual void scrollWheel(float y, float x);
        virtual void onKey(enumKeyCodes key, bool pressed, bool holding);
    private:
        bool init();
        virtual void draw();
        void onBack(CCObject*);
        virtual void keyBackClicked(void);

        std::optional<std::string> openModelSelectModal();
        void onSelectModel(CCObject*);
    public:
        static G3DModelPreviewLayer* create();
    };
}
