#pragma once

#include "G3DGameLayer.h"

namespace g3d
{
    class G3DPlayLayer : public G3DGameLayer
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