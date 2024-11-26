#pragma once
#include <vector>

#include "3SusEngine/ShaderProgram.h"
#include "3SusEngine/Shader.h"
#include "3SusEngine/Mesh.h"
#include "3SusEngine/Texture.h"
#include "3SusEngine/Model.h"
#include "3SusEngine/ShaderScene.h"
#include "3SusEngine/BasicShaders.h"

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
        Model* cube;
        Model* ship;
        Model* ball;
        Model* bird;
        Model* dart;
        Model* robot;
        Model* spider;
        Model* swing;

        G3DPlayLayer* playLayer3D;

        std::filesystem::path getPlayerModelPath(const std::string& type, const int id);
        std::filesystem::path getFixedPlayerModelPath(const std::string& type, const int id);
        void loadPlayerModel(Model** model, const std::string& type, const int id);
        void loadPlayerModels();

    public:
        friend class G3DPlayLayer;

        PlayerObject* playerObject;
        Model* player;

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
        Model* bg;

        G3DPlayerObject player1;
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
        void updateBlock(GameObject* obj, Model* model);
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