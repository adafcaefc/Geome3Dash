#pragma once

#include "AG3DGameLayer.h"

namespace g3d
{
    class G3DPlayLayer : public AG3DGameLayer
    {
    protected:
        GomtFade fadeTr;
        GomtAnimation animTr;

        GroundObjectModel ground;

        virtual void loadGround();
        virtual void drawGround();
        virtual void drawBlocks() override;

        virtual void loadBlocks() override;
        virtual void draw3d() override;
        virtual bool setup(PlayLayer* layer);

        static G3DPlayLayer* instance;

        virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) override {}
        virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) override {}
        virtual void scrollWheel(float y, float x) override {}
        virtual void onKey(enumKeyCodes key, bool pressed, bool holding) override {}

    public:
        static auto create(PlayLayer* layer)
        {
            auto node = new G3DPlayLayer;
            if (node->setup(layer)) { node->autorelease(); }
            else { CC_SAFE_DELETE(node); }
            return node;
        }
        ~G3DPlayLayer();
    };
}