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
    class AG3DGameLayer 
        : public CCNode
        , public CustomKeyboardDelegate
        , public CustomMouseDelegate
        , public CustomTouchDelegate
    {
    protected:
        GJBaseGameLayer* gameLayer;

        // models
        PlayerObjectModel player1;
        PlayerObjectModel player2;
        std::vector<GameObjectModel> blocks;

        // scene
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

        // inputs
        bool isPressingControl = false;
        bool isRightClicking = false;
        bool isRightClickingGetPos = false;
        float lastMouseX = 0.f;
        float lastMouseY = 0.f;

        // delegates
        virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) override = 0;
        virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) override = 0;
        virtual void scrollWheel(float y, float x) override = 0;
        virtual void onKey(enumKeyCodes key, bool pressed, bool holding) override = 0;

    public:
        virtual ~AG3DGameLayer();

        virtual void loadPlayers();
        virtual void loadBlocks();

        virtual bool setup(GJBaseGameLayer* layer);

        virtual void drawPlayers();
        virtual void drawBlocks();

        virtual void draw() override;

        virtual void draw3d();
        virtual void saveOpenGL();
        virtual void loadOpenGL();

        friend class GomtSpline;
        friend class PomtSpline;
        friend class PomtSplineCamera;
    };
}