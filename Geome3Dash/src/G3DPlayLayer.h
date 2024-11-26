#pragma once
#include <vector>

#include "Sus3D/ShaderProgram.h"
#include "Sus3D/Shader.h"
#include "Sus3D/Mesh.h"
#include "Sus3D/Texture.h"
#include "Sus3D/Model.h"
#include "Sus3D/Scene.h"
#include "Sus3D/Shaders.h"

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
    class G3DPlayLayer;
    class G3DPlayerObject
    {
    private:
        sus3d::Model* cube;
        sus3d::Model* ship;
        sus3d::Model* ball;
        sus3d::Model* bird;
        sus3d::Model* dart;
        sus3d::Model* robot;
        sus3d::Model* spider;
        sus3d::Model* swing;

        G3DPlayLayer* playLayer3D;

        std::filesystem::path getPlayerModelPath(const std::string& type, const int id);
        std::filesystem::path getFixedPlayerModelPath(const std::string& type, const int id);
        void loadPlayerModel(sus3d::Model** model, const std::string& type, const int id);
        void loadPlayerModels();

    public:
        friend class G3DPlayLayer;

        PlayerObject* playerObject;
        sus3d::Model* player;

        G3DPlayerObject() {}

        void init(G3DPlayLayer* playLayer3DP, PlayerObject* playerObjectP);

        void updateModel();
        void drawModel();
    };

    class G3DPlayLayer
        : public CCNode
        , public CustomKeyboardDelegate
        , public CustomTouchDelegate
        , public CustomMouseDelegate
    {
        G3DPlayerObject player1;
        //PlayerObject3D* player2; // not yet implemented!

        std::unordered_map<GameObject*, sus3d::Model*> blocks;
        std::unordered_map<int, sus3d::Model*> blockModels;
        glm::vec3 playerCameraOffset;
        double playerCameraYawOffset;
        double playerCameraPitchOffset;
        sus3d::ShaderProgram* shaderProgram;

        sus3d::Camera camera;
        sus3d::Light light;

        CameraActionHandler cameraActionHandler;

        double bezierSegmentMultiplier = 0.6;
        int bezierSegmentCount = 1000000;

        // updateCameraAction
        std::chrono::steady_clock::time_point lastUpdate;

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

        // mtl model path fix (model path must be absolute)
        void parseMtlPath(const std::filesystem::path& mtl_path);
        void loadObjectModels();

        bool init();

        void updatePlayers();
        void updateCamera();
        void updateLight();
        void updateBlock(GameObject* obj, sus3d::Model* model);
        void updateCameraAction(const float currentXPosition);

        void drawPlayers();
        void drawBlocks();

        virtual void draw();

        virtual void onKey(enumKeyCodes key, bool pressed, bool holding);
        virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods);
        virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y);
        virtual void scrollWheel(float y, float x);

        friend class G3DPlayerObject;

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