#pragma once

#include <vector>

#include "engine/sus3d/ShaderProgram.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Texture.h"
#include "engine/sus3d/Model.h"
#include "engine/sus3d/Scene.h"
#include "engine/sus3d/Shaders.h"

#include "delegate/CustomKeyboard.h"
#include "delegate/CustomMouse.h"
#include "delegate/CustomTouch.h"

#include "helper/CommonHelper.h"
#include "helper/OpenGLStateHelper.h"

#include "transformer/GomtAnimation.h"
#include "transformer/GomtFade.h"
#include "transformer/GomtSpline.h"
#include "transformer/PomtSpline.h"
#include "transformer/PomtSplineCamera.h"

#include "model/PlayerObjectModel.h"
#include "model/GroundObjectModel.h"

#include "manager/ModelManager.h"
#include "manager/LevelDataManager.h"

#include "impl/engine/CocosShaderProgram.h"

namespace g3d
{
    class G3DGameLayer : public CCNode
    {
    protected:
        GJBaseGameLayer* gameLayer;

        // models
        PlayerObjectModel player1;
        PlayerObjectModel player2;
        std::vector<GameObjectModel> blocks;

        sus3d::Camera camera;
        sus3d::Light light;

        // transformers
        GomtSpline splineTr;
        PomtSpline splinePlayerTr;
        PomtSplineCamera splineCamTr;

        // for spline
        float lengthScaleFactor;

        // level data
        LevelData levelData;

    public:
        virtual ~G3DGameLayer();

        virtual void loadPlayers();
        virtual void loadBlocks();

        virtual bool setup(GJBaseGameLayer* layer);

        virtual void drawPlayers();
        virtual void drawBlocks();

        virtual void draw() override;

        virtual void draw3d();
        virtual void saveOpenGL();
        virtual void loadOpenGL();

        static auto create(GJBaseGameLayer* layer) 
        {
            auto node = new G3DGameLayer;
            if (node->setup(layer)) { node->autorelease(); }
            else { CC_SAFE_DELETE(node); }
            return node;
        }

        friend class GomtSpline;
        friend class PomtSpline;
        friend class PomtSplineCamera;
    };
}