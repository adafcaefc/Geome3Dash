#pragma once
#include <vector>

#include "3SusEngine/ShaderProgram.h"
#include "3SusEngine/Shader.h"
#include "3SusEngine/Mesh.h"
#include "3SusEngine/Texture.h"
#include "3SusEngine/Model.h"
#include "3SusEngine/ShaderScene.h"

#include "Delegate/CustomKeyboard.h"
#include "Delegate/CustomMouse.h"
#include "Delegate/CustomTouch.h"

#include "Helper/CommonHelper.h"
#include "Helper/OpenGLStateHelper.h"
#include "Helper/BezierHelper.h"

#include "CameraAction.h"
#include "BezierManager.h"

namespace g3d
{
    class PlayLayer3D;
    class PlayerObject3D
    {
    private:
        Model* cube;
        Model* ship;
        Model* ball;
        Model* bird;
        Model* dart;
        Model* robot;
        Model* spider;
        Model* swing;

        PlayLayer3D* playLayer3D;

        std::filesystem::path getPlayerModelPath(const std::string& type, const int id);
        std::filesystem::path getFixedPlayerModelPath(const std::string& type, const int id);
        void loadPlayerModel(Model** model, const std::string& type, const int id);
        void loadPlayerModels();

    public:
        friend class PlayLayer3D;

        PlayerObject* playerObject;
        Model* player;

        PlayerObject3D() {}

        void init(PlayLayer3D* playLayer3DP, PlayerObject* playerObjectP);

        void updateModel();
        void drawModel();
    };

    class PlayLayer3D
        : public CCNode
        , public CustomKeyboardDelegate
        , public CustomTouchDelegate
        , public CustomMouseDelegate
    {
        Model* bg;

        PlayerObject3D player1;
        //PlayerObject3D* player2; // not yet implemented!

        std::unordered_map<GameObject*, Model*> blocks;
        std::unordered_map<int, Model*> blockModels;
        glm::vec3 playerCameraOffset;
        double playerCameraYawOffset;
        double playerCameraPitchOffset;
        g3d::ShaderProgram* shaderProgram;

        Camera camera;
        Light light;

        CameraActionHandler cameraActionHandler;

        double bezierSegmentMultiplier = 5.0;
        int bezierSegmentCount = 100000;

        // updateCameraAction
        std::chrono::steady_clock::time_point lastUpdate;

        // delegates
        bool isPressingControl = false;
        bool isRightClicking = false;
        bool isRightClickingGetPos = false;
        float lastMouseX = 0.0;
        float lastMouseY = 0.0;
    public:
        ~PlayLayer3D();

        static PlayLayer3D* instance;

        void loadShader();
        void loadPlayers();

        // mtl model path fix (model path must be absolute)
        void parseMtlPath(const std::filesystem::path& mtl_path);
        void loadObjectModels();

        bool init();

        void updatePlayers();
        void updateCamera();
        void updateLight();
        void updateBlock(GameObject* obj, Model* model);
        void updateCameraAction(const float currentXPosition);

        void drawPlayers();
        void drawBlocks();

        virtual void draw();

        virtual void onKey(enumKeyCodes key, bool pressed, bool holding);
        virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods);
        virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y);
        virtual void scrollWheel(float y, float x);

        friend class PlayerObject3D;

    public:
        static auto create() {
            auto node = new PlayLayer3D;
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