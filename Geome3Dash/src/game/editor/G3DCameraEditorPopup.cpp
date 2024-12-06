#include "pch.h"

#include "game/editor/G3DCameraEditorPopup.h"
#include "game/component/G3DBaseNode.h"

#include "helper/OpenGLStateHelper.h"

#include "LevelDataManager.h"
#include "BlockModelStorage.h"

namespace g3d
{
	//CCSize G3DEditorPopup::popupPadding = { 20, 20 };

    static LevelData currentLevelData = LevelData::getDefault();

    //void G3DEditorPopup::addLabel(const char* text, const CCPoint& position) {
    //    constexpr const char* _font = "chatFont.fnt";
    //    // Create the label using the specified font and text
    //    auto label = CCLabelBMFont::create(text, _font);
    //    label->setScale(0.8f);  // Adjust the size of the label
    //    label->setPosition(position);  // Position the label at the desired location
    //    // Add the label to the popup layer
    //    //this->m_geodeScrollLayer->addChild(label);
    //}

    //void G3DEditorScene::loadModel()
    //{
    //    //auto bms = BlockModelStorage::get();
    //    //cube = bms->getModel(bms->getBP() / "player" / "cube" / "0" / "model.obj");
    //    //cube->setScale(glm::vec3(0.75));
    //    //spike = bms->getBlockModel(8);
    //    //spike->setScale(glm::vec3(0.75));
    //}

    void G3DCameraEditorScene::drawModel()
    {
        static std::chrono::steady_clock::time_point lastUpdate;
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedTime = now - lastUpdate;
        lastUpdate = now;
        double deltaTime = elapsedTime.count();

        cubePosition.x += deltaTime * 300;
        cubePosition.x = std::fmod(cubePosition.x, 1800);

        // Jumping logic

        static bool isJumping = false;
        static double jumpTime = 0.0;
        const double jumpDuration = 0.6;  // Jump duration in seconds
        const double jumpHeight = 65.0; // Height of the jump
        const double groundPositionY = 105.0; // Ground position
        static double initialRotationZ = 0.0; // Initial rotation at jump start

        // Handle jump logic
        if (!isJumping && cubePosition.x >= 840.0 && cubePosition.x < 900.0 + deltaTime * 300) {
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

        for (float i = -900.f; i < 2400.f; i += 30.f)
        {
            auto obj = blockObjs[i];
            obj->m_positionX = i;
            obj->m_positionY = spikePosition.y - 30.f;
            obj->setPosition(ccp(obj->m_positionX, obj->m_positionY));
        }

        for (int i = 0; i < spikeObjs.size(); i++)
        {
            auto obj = spikeObjs.at(i);
            obj->m_positionX = spikePosition.x + i * 30.f;
            obj->m_positionY = spikePosition.y;
            obj->setPosition(ccp(obj->m_positionX, obj->m_positionY));
        }

        playerObj->m_position = ccp(cubePosition.x, cubePosition.y);
        playerObj->setRotation(cubeRotationZ);
        playerObj->setPosition(playerObj->m_position);

        player1.render(shaderProgram, camera, light);
        for (auto& block : blocks) { block.render(shaderProgram, camera, light); }
    }

    void G3DCameraEditorScene::draw()
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

    G3DCameraEditorScene::~G3DCameraEditorScene()
    {

    }

    bool G3DCameraEditorScene::init(LevelEditorLayer* lel)
    {
        this->lel = lel;
        playerObj = PlayerObject::create(0, 0, lel, lel->m_objectLayer, false);

        auto gameLayer = CCLayer::create();
        gameLayer->setScale(0.2f);
        gameLayer->addChild(playerObj);
        gameLayer->setVisible(false);

        this->addChild(gameLayer);

        prepareSpline(lel, &currentLevelData.spline, &lengthScaleFactor);

        // don't forget to delete these
        static bool isEditing = false;
        splineTr = new SplineGameObjectTransformer(&currentLevelData.spline, &lengthScaleFactor);
        splinePlayerTr = new SplinePlayerObjectTransformer(&currentLevelData.spline, &lengthScaleFactor);
        splineCamTr = new SplineCameraPlayerObjectModelTransformer(
            &currentLevelData.spline,
            &currentLevelData.keyframe,
            &camera,
            &lengthScaleFactor,
            &isEditing);

        for (int i = 0; i < 3; i++)
        {
            spikeObjs.push_back(GameObject::createWithKey(8));
            gameLayer->addChild(spikeObjs.back());
            blocks.push_back(GameObjectModel(spikeObjs.back(), { splineTr }));
        }

        for (float i = -900.f; i < 2400.f; i += 30.f)
        {
            blockObjs[i] = GameObject::createWithKey(1);
            gameLayer->addChild(blockObjs[i]);
            blocks.push_back(GameObjectModel(blockObjs[i], { splineTr }));
        }

        player1 = PlayerObjectModel(playerObj, { splinePlayerTr, splineCamTr });

        shaderProgram = BlockModelStorage::get()->getBlockSP();

        return CCNode::init();
    }

    void G3DCameraEditorPopup::onClose(CCObject* ob)
    {
        setLevelData(lel, currentLevelData);
        geode::Popup<LevelEditorLayer*>::onClose(ob);
    }

    void G3DCameraEditorPopup::updateCamera()
    {
        if (m_spikeScene)
        {
            auto& cld = currentLevelData;
            cld.x = m_spikeScene->playerCameraOffset.x;
            cld.y = m_spikeScene->playerCameraOffset.y;
            cld.z = m_spikeScene->playerCameraOffset.z;
            cld.yaw = m_spikeScene->playerCameraYawOffset;
            cld.pitch = m_spikeScene->playerCameraPitchOffset;
            setStartingKeyframe(
                &cld,
                &cld.keyframe,
                m_spikeScene->lengthScaleFactor);
        }
    }

    void G3DCameraEditorPopup::updateState(G3DNumberSetting* invoker) 
    {
        updateCamera();
        for (auto& sett : m_settings) { sett->updateState(nullptr); }
    }

    bool G3DCameraEditorPopup::setup(LevelEditorLayer* plel)
    {
        lel = plel;

        currentLevelData = LevelData::getDefault();
        try {
            currentLevelData = getLevelData(lel);
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
            scrollBar, geode::Anchor::Center, ccp(layerBG->getContentWidth() / 2 + 10, 0));

        m_spikeScene = G3DCameraEditorScene::create(lel);
        this->m_mainLayer->addChild(m_spikeScene);

        layerBG->setPositionX(layerBG->getPositionX() + 90);
        scrollBar->setPositionX(scrollBar->getPositionX() + 90);

        m_spikeScene->playerCameraOffset = glm::vec3(
            currentLevelData.x,
            currentLevelData.y,
            currentLevelData.z);
        m_spikeScene->playerCameraYawOffset = currentLevelData.yaw;
        m_spikeScene->playerCameraPitchOffset = currentLevelData.pitch;

        this->updateState();

        return true;
    }

    void G3DCameraEditorPopup::scene(LevelEditorLayer* plel) 
    {
        const CCSize uiSize = CCDirector::sharedDirector()->getWinSize() - CCSize(60, 40);
        G3DCameraEditorPopup* instance = new G3DCameraEditorPopup();
        if (instance && instance->initAnchored(uiSize.width, uiSize.height, plel)) 
        {
            instance->m_noElasticity = true;
            instance->setID("g3d_editor_popup"_spr);
            instance->autorelease();
            instance->show();
        }
        else 
        {
            CC_SAFE_DELETE(instance);
        }
    }

    void G3DCameraEditorScene::onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) {
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

    void G3DCameraEditorScene::onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) {
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
                if (auto layer = dynamic_cast<G3DCameraEditorPopup*>(this->getParent()->getParent()))
                {
                    layer->updateState();
                }
            }
        }
    }

    void G3DCameraEditorScene::scrollWheel(float y, float x) {
        if (isPressingControl) {
            // Adjust the camera zoom level using the scroll wheel
            float zoomSensitivity = -0.128f;
            playerCameraOffset += camera.getFront() * y * zoomSensitivity;
            currentLevelData.x = playerCameraOffset.x;
            currentLevelData.y = playerCameraOffset.y;
            currentLevelData.z = playerCameraOffset.z;
            currentLevelData.yaw = playerCameraYawOffset;
            currentLevelData.pitch = playerCameraPitchOffset;
            if (auto layer = dynamic_cast<G3DCameraEditorPopup*>(this->getParent()->getParent())) {
                layer->updateState();
            }
        }
    }

    void G3DCameraEditorScene::onKey(enumKeyCodes key, bool pressed, bool holding) {
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