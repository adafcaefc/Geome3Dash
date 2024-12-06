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

#include "transformer/AnimationGameObjectModelTransformer.h"
#include "transformer/FadeGameObjectModelTransformer.h"
#include "transformer/SplineCameraPlayerObjectModelTransformer.h"
#include "transformer/SplineGameObjectTransformer.h"
#include "transformer/SplinePlayerObjectTransformer.h"

#include "CocosShaderProgram.h"
#include "PlayerObjectModel.h"
#include "LevelDataManager.h"

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

        CocosShaderProgram* shaderProgram;

        sus3d::Camera camera;
        sus3d::Light light;

        // transformers
        FadeGameObjectModelTransformer* fadeTr;
        AnimationGameObjectModelTransformer* animTr;
        SplineGameObjectTransformer* splineTr;
        SplinePlayerObjectTransformer* splinePlayerTr;
        SplineCameraPlayerObjectModelTransformer* splineCamTr;

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

        void loadShader();
        void loadPlayers();
        void loadBlocks();

        std::vector<GameObjectModel> blocks;

        bool init();

        void drawPlayers();
        void drawBlocks();

        virtual void draw();

        friend class BezierCameraPlayerObjectModelTransformer;
        friend class SplineCameraPlayerObjectModelTransformer;

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