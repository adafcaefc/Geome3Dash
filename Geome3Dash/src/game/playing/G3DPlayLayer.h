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
#include "helper/BezierHelper.h"

#include "transformer/AnimationGameObjectModelTransformer.h"
#include "transformer/BezierCameraPlayerObjectModelTransformer.h"
#include "transformer/BezierGameObjectModelTransformer.h"
#include "transformer/FadeGameObjectModelTransformer.h"
#include "transformer/SplineCameraPlayerObjectModelTransformer.h"
#include "transformer/SplineGameObjectTransformer.h"
#include "transformer/SplinePlayerObjectTransformer.h"

#include "CameraAction.h"
#include "BezierManager.h"
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

        // !! moved to block storage !!
        //std::unordered_map<GameObject*, sus3d::Model*> blocks;
        //std::unordered_map<int, sus3d::Model*> blockModels;
        glm::vec3 playerCameraOffset;
        double playerCameraYawOffset;
        double playerCameraPitchOffset;
        CocosShaderProgram* shaderProgram;

        //CubicBezier bezier;
        //double bezierSegmentMultiplier = 3;
        //// to do: make this customisable
        //int bezierSegmentCount = 1000000;

        sus3d::Camera camera;
        sus3d::Light light;

        CameraActionHandler cameraActionHandler = CameraActionHandler(ease::InOutQuad::get());

        // updateCameraAction
        std::chrono::steady_clock::time_point lastUpdate;

        // transformers
        //BezierGameObjectModelTransformer* bezierTr;
        FadeGameObjectModelTransformer* fadeTr;
        AnimationGameObjectModelTransformer* animTr;
        //BezierCameraPlayerObjectModelTransformer* camTr;
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

        // mtl model path fix (model path must be absolute)
        // void parseMtlPath(const std::filesystem::path& mtl_path);
        // void loadObjectModels();
        // !! moved to block storage !!

        bool init();

        //void updateCamera();
        //void updateLight();
        //void updateBlock(GameObject* obj, sus3d::Model* model);
        //void updateCameraAction(const float currentXPosition);

        void drawPlayers();
        void drawBlocks();

        virtual void draw();

        virtual void onKey(enumKeyCodes key, bool pressed, bool holding);
        virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods);
        virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y);
        virtual void scrollWheel(float y, float x);

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