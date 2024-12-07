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
    class G3DPlayLayer;
    class BezierCameraPlayerObjectModelTransformer;
    class G3DPlayLayer
        : public CCNode
        , public CustomKeyboardDelegate
        , public CustomTouchDelegate
        , public CustomMouseDelegate
    {
        PlayLayer* playLayer;

        PlayerObjectModel player1;
        PlayerObjectModel player2;
        GroundObjectModel ground;

        sus3d::Camera camera;
        sus3d::Light light;

        // transformers
        GomtFade* fadeTr;
        GomtAnimation* animTr;
        GomtSpline* splineTr;
        PomtSpline* splinePlayerTr;
        PomtSplineCamera* splineCamTr;

        // for spline
        float lengthScaleFactor;

        // level data
        LevelData levelData;

        // delegates
        bool isPressingControl = false;
        bool isRightClicking = false;
        bool isRightClickingGetPos = false;
        float lastMouseX = 0.0;
        float lastMouseY = 0.0;
    public:
        ~G3DPlayLayer();

        static G3DPlayLayer* instance;

        void loadPlayers();
        void loadBlocks();
        void loadGround();

        std::vector<GameObjectModel> blocks;

        bool init();

        void drawPlayers();
        void drawBlocks();
        void drawGround();

        virtual void draw();

        friend class BezierCameraPlayerObjectModelTransformer;
        friend class PomtSplineCamera;

    public:
        static auto create() {
            auto node = new G3DPlayLayer;
            instance = node;
            if (node->init()) {
                node->autorelease();
            }
            else {
                CC_SAFE_DELETE(node);
            }
            return node;
        }
    };
}