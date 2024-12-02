#include "pch.h"

#include "game/editor/G3DEditorPopup.h"
#include "game/component/G3DBaseNode.h"

#include "helper/OpenGLStateHelper.h"

#include "LevelDataManager.h"

namespace g3d
{
	//CCSize G3DEditorPopup::popupPadding = { 20, 20 };

    static LevelData currentLevelData = LevelData::getDefault();

    void G3DEditorPopup::addLabel(const char* text, const CCPoint& position) {
        constexpr const char* _font = "chatFont.fnt";

        // Create the label using the specified font and text
        auto label = CCLabelBMFont::create(text, _font);
        label->setScale(0.8f);  // Adjust the size of the label
        label->setPosition(position);  // Position the label at the desired location

        // Add the label to the popup layer
       //this->m_geodeScrollLayer->addChild(label);
    }

    void G3DEditorScene::loadModel()
    {
        auto vertexShader = sus3d::Shader::createWithString(sus3d::shaders::vertexShaderSource, sus3d::ShaderType::kVertexShader);
        auto fragmentShader = sus3d::Shader::createWithString(sus3d::shaders::fragmentShaderSource, sus3d::ShaderType::kFragmentShader);

        shaderProgram = CocosShaderProgram::create(vertexShader, fragmentShader);

        delete vertexShader;
        delete fragmentShader;

        auto playerDir = geode::Mod::get()->getResourcesDir() / "model3d" / "player" / "cube" / "0" / "model.obj";
        cube = G3DBaseNode::loadModelMtl<sus3d::Model>(playerDir, shaderProgram);
        cube->setScale(glm::vec3(0.75));

        auto spikeDir = geode::Mod::get()->getResourcesDir() / "model3d" / "object" / "8" / "model.obj";
        spike = G3DBaseNode::loadModelMtl<sus3d::Model>(spikeDir, shaderProgram);
        spike->setScale(glm::vec3(0.75));
    }

    void G3DEditorScene::drawModel()
    {
        static std::chrono::steady_clock::time_point lastUpdate;
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedTime = now - lastUpdate;
        lastUpdate = now;
        double deltaTime = elapsedTime.count();

        cubePosition.x += deltaTime * 300;
        cubePosition.x = std::fmod(cubePosition.x, 1500);

        // Jumping logic

        static bool isJumping = false;
        static double jumpTime = 0.0;
        const double jumpDuration = 0.6;  // Jump duration in seconds
        const double jumpHeight = 80.0; // Height of the jump
        const double groundPositionY = 105.0; // Ground position
        static double initialRotationZ = 0.0; // Initial rotation at jump start

        // Handle jump logic
        if (!isJumping && cubePosition.x >= 630.0 && cubePosition.x < 700.0 + deltaTime * 300) {
            isJumping = true;
            jumpTime = 0.0; // Reset jump timer
            initialRotationZ = cubeRotationZ; // Store the initial rotation
        }

        if (isJumping) {
            // Increment jump time
            jumpTime += deltaTime;

            // Compute normalized time (0 to 1)
            double t = jumpTime / jumpDuration;

            // Clamp t to prevent overshooting
            if (t > 1.0) {
                t = 1.0;
                isJumping = false; // End jump when time exceeds duration
            }

            // Parabolic motion for jump height
            cubePosition.y = groundPositionY + jumpHeight * (1.0 - 4.0 * (t - 0.5) * (t - 0.5));

            // Interpolate rotation for the arc (180 degrees over the jump)
            cubeRotationZ = initialRotationZ + t * 180.0;

            if (!isJumping) {
                // Snap rotation to the nearest 90 degrees when landing
                cubeRotationZ = std::round(cubeRotationZ / 90.0) * 90.0;

                // Reset to ground position
                cubePosition.y = groundPositionY;
            }
        }

        // End jumping logic


        playerCameraOffset = glm::vec3(currentLevelData.x, currentLevelData.y, currentLevelData.z);
        playerCameraPitchOffset = currentLevelData.pitch;
        playerCameraYawOffset = currentLevelData.yaw;
        

        cube->setPosition(cubePosition / glm::vec3(20));
        cube->setRotationZ(360 - cubeRotationZ);

        camera.setPitch(playerCameraPitchOffset);
        camera.setYaw(playerCameraYawOffset);
        camera.setPosition(cube->getPosition() + playerCameraOffset);
        light.setPosition(camera.getPosition());

        cube->render(
            camera.getViewMat(),
            light.getPosition(),
            light.getColor(),
            camera.getPosition(),
            camera.getProjectionMat());

        spike->setPosition(spikePosition / glm::vec3(20));
        spike->render(
            camera.getViewMat(),
            light.getPosition(),
            light.getColor(),
            camera.getPosition(),
            camera.getProjectionMat());

        spikePosition.x += 30;
        spike->setPosition(spikePosition / glm::vec3(20));
        spike->render(
            camera.getViewMat(),
            light.getPosition(),
            light.getColor(),
            camera.getPosition(),
            camera.getProjectionMat());

        spikePosition.x += 30;
        spike->setPosition(spikePosition / glm::vec3(20));
        spike->render(
            camera.getViewMat(),
            light.getPosition(),
            light.getColor(),
            camera.getPosition(),
            camera.getProjectionMat());

        spikePosition.x -= 60;
    }

    void G3DEditorScene::draw()
    {
        CCNode::draw();

        OpenGLStateHelper::saveState();
        glEnable(GL_BLEND);
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_DEPTH_TEST);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        drawModel();

        glDisable(GL_DEPTH_TEST);
        OpenGLStateHelper::pushState();
    }

    G3DEditorScene::~G3DEditorScene()
    {

    }

    bool G3DEditorScene::init()
    {
        loadModel();
        return CCNode::init();
    }

    void G3DEditorPopup::onClose(CCObject* ob)
    {
        setLevelData(LevelEditorLayer::get(), currentLevelData);
        geode::Popup<>::onClose(ob);
    }

    void G3DEditorPopup::updateState(G3DNumberSetting* invoker) 
    {
        for (auto& sett : m_settings) { sett->updateState(nullptr); }
    }

    bool G3DEditorPopup::setup()
    {
        currentLevelData = LevelData::getDefault();
        try {
            currentLevelData = getLevelData(LevelEditorLayer::get());
        }
        catch (...) {

        }
        setTitle("Geome3Dash Camera Editor");
        //auto winSize = CCDirector::sharedDirector()->getWinSize();
        auto const layerSize = CCSize(250, 200);

        auto layerBG = CCLayerColor::create({ 0, 0, 0, 75 });
        layerBG->setContentSize(layerSize);
        layerBG->ignoreAnchorPointForPosition(false);
        m_mainLayer->addChildAtPosition(layerBG, geode::Anchor::Center);

        m_list = geode::ScrollLayer::create(layerSize /*- ccp(0, searchContainer->getContentHeight())*/);
        m_list->setTouchEnabled(true);

        G3DNumberSetting* node;

        // "Cam X" Setting
        node = G3DNumberSetting::create("Cam X", &currentLevelData.x, layerSize.width);
        m_settings.push_back(node);
        m_list->m_contentLayer->addChild(node);
        node->m_impl_modDescription = "Controls the X axis (horizontal movement) of the camera.";

        // "Cam Y" Setting
        node = G3DNumberSetting::create("Cam Y", &currentLevelData.y, layerSize.width);
        m_settings.push_back(node);
        m_list->m_contentLayer->addChild(node);
        node->m_impl_modDescription = "Controls the Y axis (vertical movement) of the camera.";

        // "Cam Z" Setting
        node = G3DNumberSetting::create("Cam Z", &currentLevelData.z, layerSize.width);
        m_settings.push_back(node);
        m_list->m_contentLayer->addChild(node);
        node->m_impl_modDescription = "Controls the Z axis (depth or forward/backward movement) of the camera.";

        // "Cam Yaw" Setting
        node = G3DNumberSetting::create("Cam Yaw", &currentLevelData.yaw, layerSize.width);
        m_settings.push_back(node);
        m_list->m_contentLayer->addChild(node);
        node->m_impl_modDescription = "Controls the yaw (horizontal rotation) of the camera.";

        // "Cam Pitch" Setting
        node = G3DNumberSetting::create("Cam Pitch", &currentLevelData.pitch, layerSize.width);
        m_settings.push_back(node);
        m_list->m_contentLayer->addChild(node);
        node->m_impl_modDescription = "Controls the pitch (vertical tilt) of the camera.";

        m_list->m_contentLayer->setLayout(
            geode::ColumnLayout::create()
            ->setAxisReverse(true)
            ->setAutoGrowAxis(m_list->getContentHeight())
            ->setCrossAxisOverflow(false)
            ->setAxisAlignment(geode::AxisAlignment::End)
            ->setGap(0)
        );
        m_list->moveToTop();
        //const int buttonPriority = m_list->getTouchPriority() - 1;
        //searchContainer->setTouchPriority(buttonPriority);
        //m_mainLayer->addChildAtPosition(createGeodeListBorders(layerSize, m_forceDisableTheme), geode::Anchor::Center);

        layerBG->addChildAtPosition(m_list, geode::Anchor::BottomLeft);

        auto scrollBar = geode::Scrollbar::create(m_list);
        m_mainLayer->addChildAtPosition(
            scrollBar, geode::Anchor::Center, ccp(layerBG->getContentWidth() / 2 + 10, 0)
        );

        this->updateState();

        m_spikeScene = G3DEditorScene::create();
        this->m_mainLayer->addChild(m_spikeScene);

        layerBG->setPositionX(layerBG->getPositionX() + 90);
        scrollBar->setPositionX(scrollBar->getPositionX() + 90);

        return true;
    }

    void G3DEditorPopup::scene() {
        const CCSize uiSize = CCDirector::sharedDirector()->getWinSize() - CCSize(60, 40);

        G3DEditorPopup* instance = new G3DEditorPopup();

        if (instance && instance->initAnchored(uiSize.width, uiSize.height)) {
            instance->m_noElasticity = true;
            instance->setID("g3d_editor_popup"_spr);
            instance->autorelease();
            instance->show();
        }
        else {
            CC_SAFE_DELETE(instance);
        }
    }

    void G3DEditorScene::onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) {
        if (button == GLFW_MOUSE_BUTTON_RIGHT) {
            if (action == GLFW_PRESS) {
                isRightClicking = true;
                isRightClickingGetPos = false;
            }
            else if (action == GLFW_RELEASE) {
                isRightClicking = false;
            }
        }
    }

    void G3DEditorScene::onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) {
        if (isRightClicking) {
            if (!isRightClickingGetPos) {
                lastMouseX = static_cast<float>(x);
                lastMouseY = static_cast<float>(y);
                isRightClickingGetPos = true;
            }
            else {
                float deltaX = static_cast<float>(x) - lastMouseX;
                float deltaY = static_cast<float>(y) - lastMouseY;
                if (isPressingControl) {
                    float sensitivity = 0.032f;
                    playerCameraOffset += camera.getUp() * deltaY * sensitivity;
                    playerCameraOffset += glm::normalize(glm::cross(camera.getFront(), camera.getUp())) * deltaX * -sensitivity;
                }
                else {
                    float sensitivity = 0.05f;
                    playerCameraYawOffset -= deltaX * sensitivity;
                    playerCameraPitchOffset -= deltaY * sensitivity;
                }
                lastMouseX = static_cast<float>(x);
                lastMouseY = static_cast<float>(y);

                currentLevelData.x = playerCameraOffset.x;
                currentLevelData.y = playerCameraOffset.y;
                currentLevelData.z = playerCameraOffset.z;
                currentLevelData.yaw = playerCameraYawOffset;
                currentLevelData.pitch = playerCameraPitchOffset;
                if (auto layer = dynamic_cast<G3DEditorPopup*>(this->getParent()->getParent()))
                {
                    layer->updateState();
                }
            }
        }
    }

    void G3DEditorScene::scrollWheel(float y, float x) {
        if (isPressingControl) {
            // Adjust the camera zoom level using the scroll wheel
            float zoomSensitivity = -0.128f;
            playerCameraOffset += camera.getFront() * y * zoomSensitivity;
            currentLevelData.x = playerCameraOffset.x;
            currentLevelData.y = playerCameraOffset.y;
            currentLevelData.z = playerCameraOffset.z;
            currentLevelData.yaw = playerCameraYawOffset;
            currentLevelData.pitch = playerCameraPitchOffset;
            if (auto layer = dynamic_cast<G3DEditorPopup*>(this->getParent()->getParent())) {
                layer->updateState();
            }
        }
    }

    void G3DEditorScene::onKey(enumKeyCodes key, bool pressed, bool holding) {
        switch (key) {
        case KEY_Control:
            isPressingControl = pressed;
            break;
        case KEY_Shift:
            isPressingShift = pressed;
            break;
        default:
            break;
        }
    }
}