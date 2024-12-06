#pragma once

#include <Geode/ui/GeodeUI.hpp>
#include <Geode/ui/ScrollLayer.hpp>
#include <Geode/ui/Scrollbar.hpp>
#include <Geode/ui/TextInput.hpp>

#include "game/component/G3DNumberSetting.h"

#include "delegate/CustomKeyboard.h"
#include "delegate/CustomMouse.h"
#include "delegate/CustomTouch.h"

#include "helper/BezierHelper.h"

#include "engine/sus3d/ShaderProgram.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Texture.h"
#include "engine/sus3d/Model.h"
#include "engine/sus3d/Scene.h"
#include "engine/sus3d/Shaders.h"

#include "CocosShaderProgram.h"
#include "PlayerObjectModel.h"

#include "transformer/SplineCameraPlayerObjectModelTransformer.h"
#include "transformer/SplineGameObjectTransformer.h"
#include "transformer/SplinePlayerObjectTransformer.h"

namespace g3d
{
    class G3DCameraEditorScene 
        : public CCNode
        , public CustomKeyboardDelegate
        , public CustomMouseDelegate
        , public CustomTouchDelegate
    {
    public:
        sus3d::Camera camera;
        sus3d::Light light;
        glm::vec3 playerCameraOffset;
        double playerCameraYawOffset;
        double playerCameraPitchOffset;
        sus3d::ShaderProgram* shaderProgram;

        // don't forget fo free these or else memory leak
        glm::vec3 cubePosition = glm::vec3(0, 105, 400);
        double cubeRotationZ = 0;
        glm::vec3 spikePosition = glm::vec3(900, 105, 400);
        //sus3d::Model* cube;
        //sus3d::Model* spike;

        SplineGameObjectTransformer* splineTr;
        SplinePlayerObjectTransformer* splinePlayerTr;
        SplineCameraPlayerObjectModelTransformer* splineCamTr;

        LevelEditorLayer* lel;
        std::vector<GameObject*> spikeObjs;
        std::unordered_map<float, GameObject*> blockObjs;
        PlayerObject* playerObj;

        PlayerObjectModel player1;
        std::vector<GameObjectModel> blocks;

        float lengthScaleFactor;

        //void loadModel();
        void drawModel();

        virtual void draw() override;
        virtual bool init(LevelEditorLayer* lel);

        // delegates
        bool isPressingControl = false;
        bool isPressingShift = false;
        bool isRightClicking = false;
        bool isRightClickingGetPos = false;
        float lastMouseX = 0.0;
        float lastMouseY = 0.0;

        virtual void onKey(enumKeyCodes key, bool pressed, bool holding) override;
        virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) override;
        virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) override;
        virtual void scrollWheel(float y, float x) override;

        ~G3DCameraEditorScene();

        static auto create(LevelEditorLayer* lel) {
            auto node = new G3DCameraEditorScene;
            if (node->init(lel)) {
                node->autorelease();
            }
            else {
                CC_SAFE_DELETE(node);
            }
            return node;
        }
    };

    class G3DCameraEditorPopup : public geode::Popup<LevelEditorLayer*> 
    {
    public:
        static void scene(LevelEditorLayer* plel);
        void updateState(G3DNumberSetting* invoker = nullptr);
        void updateCamera();

    protected:
        bool setup(LevelEditorLayer*) override;
        //void addLabel(const char* text, const CCPoint& position);

        G3DCameraEditorScene* m_spikeScene;
        geode::ScrollLayer* m_list;
        geode::TextInput* m_searchInput;
        std::vector<geode::Ref<G3DNumberSetting>> m_settings;

        LevelEditorLayer* lel;

        virtual void onClose(CCObject*) override;

    private:
        //static CCSize popupPadding;

        G3DCameraEditorPopup()  { }
    };
}