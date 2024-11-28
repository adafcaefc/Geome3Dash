#include "pch.h"

#include "game/editor/G3DEditorPopup.h"
#include "game/G3DBaseNode.h"

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
        if (cube) { delete cube; }
        if (spike) { delete spike; }
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

    void G3DEditorPopup::updateState(NumberSettingNodeV3* invoker) 
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
        auto winSize = CCDirector::sharedDirector()->getWinSize();
        auto const layerSize = CCSize(250, 200);

        auto layerBG = CCLayerColor::create({ 0, 0, 0, 75 });
        layerBG->setContentSize(layerSize);
        layerBG->ignoreAnchorPointForPosition(false);
        m_mainLayer->addChildAtPosition(layerBG, geode::Anchor::Center);

        //auto searchContainer = CCMenu::create();
        //searchContainer->setContentSize({ layerSize.width, 30 });

        //m_searchInput = geode::TextInput::create((layerSize.width - 15) / .7f, "Search Settings...");
        //m_searchInput->setTextAlign(geode::TextInputAlign::Left);
        //m_searchInput->setScale(.7f);
        //m_searchInput->setCallback([this](auto const&) {
        //    //this->updateState();
        //    m_list->moveToTop();
        //    });
        //m_searchInput->setID("search-input");
        //searchContainer->addChildAtPosition(m_searchInput, geode::Anchor::Left, ccp(7.5f, 0), ccp(0, .5f));
        //layerBG->addChildAtPosition(searchContainer, geode::Anchor::Top, ccp(0, 0), ccp(.5f, 1));

        //auto searchClearSpr = GeodeSquareSprite::createWithSpriteFrameName("GJ_deleteIcon_001.png", nullptr, m_forceDisableTheme);
        //searchClearSpr->setScale(.45f);
        //m_searchClearBtn = CCMenuItemSpriteExtra::create(
        //    searchClearSpr, this, menu_selector(ModSettingsPopup::onClearSearch)
        //);
        //m_searchClearBtn->setID("clear-search-button");
        //searchContainer->addChildAtPosition(m_searchClearBtn, Anchor::Right, ccp(-20, 0));

        m_list = geode::ScrollLayer::create(layerSize /*- ccp(0, searchContainer->getContentHeight())*/);
        m_list->setTouchEnabled(true);

        NumberSettingNodeV3* node;
        node = NumberSettingNodeV3::create("Cam X", &currentLevelData.x, layerSize.width);
        m_settings.push_back(node);
        m_list->m_contentLayer->addChild(node);
        node = NumberSettingNodeV3::create("Cam Y", &currentLevelData.y, layerSize.width);
        m_settings.push_back(node);
        m_list->m_contentLayer->addChild(node);
        node = NumberSettingNodeV3::create("Cam Z", &currentLevelData.z, layerSize.width);
        m_settings.push_back(node);
        m_list->m_contentLayer->addChild(node);
        node = NumberSettingNodeV3::create("Cam Yaw", &currentLevelData.yaw, layerSize.width);
        m_settings.push_back(node);
        m_list->m_contentLayer->addChild(node);
        node = NumberSettingNodeV3::create("Cam Pitch", &currentLevelData.pitch, layerSize.width);
        m_settings.push_back(node);
        m_list->m_contentLayer->addChild(node);

        m_list->m_contentLayer->setLayout(
            geode::ColumnLayout::create()
            ->setAxisReverse(true)
            ->setAutoGrowAxis(m_list->getContentHeight())
            ->setCrossAxisOverflow(false)
            ->setAxisAlignment(geode::AxisAlignment::End)
            ->setGap(0)
        );
        m_list->moveToTop();
        const int buttonPriority = m_list->getTouchPriority() - 1;
        //searchContainer->setTouchPriority(buttonPriority);
        //m_mainLayer->addChildAtPosition(createGeodeListBorders(layerSize, m_forceDisableTheme), geode::Anchor::Center);


        layerBG->addChildAtPosition(m_list, geode::Anchor::BottomLeft);

        auto scrollBar = geode::Scrollbar::create(m_list);
        m_mainLayer->addChildAtPosition(
            scrollBar, geode::Anchor::Center, ccp(layerBG->getContentWidth() / 2 + 10, 0)
        );

        m_changeListener.bind([this](auto* ev) {
            this->updateState(ev->getNode());
            return geode::ListenerResult::Propagate;
            });
        this->updateState();

        m_spikeScene = G3DEditorScene::create();
        this->m_mainLayer->addChild(m_spikeScene);

        layerBG->setPositionX(layerBG->getPositionX() + 90);
        scrollBar->setPositionX(scrollBar->getPositionX() + 90);

        return true;

        //const CCSize uiSize = CCDirector::sharedDirector()->getWinSize() - G3DEditorPopup::popupPadding;
        //this->setTitle("Geome3Dash Level Editor");

        //// Set up scroll layer
        //auto scrollContentSize = CCSize(uiSize.width, uiSize.height); // Content size for scrolling
        //this->m_geodeScrollLayer = geode::ScrollLayer::create(scrollContentSize);
        //m_geodeScrollLayer->setPosition({
        //    m_bgSprite->getPositionX() - m_geodeScrollLayer->getScaledContentWidth() / 2, 
        //    m_bgSprite->getPositionY() - m_geodeScrollLayer->getScaledContentHeight() / 2 - 10.f });
        //m_geodeScrollLayer->m_contentLayer->setLayout(
        //    geode::ColumnLayout::create()
        //        ->setAxisReverse(true)
        //        ->setAxisAlignment(geode::AxisAlignment::End)
        //        ->setAutoGrowAxis(uiSize.height)
        //        ->setGap(5.0f));
        //this->m_mainLayer->addChild(this->m_geodeScrollLayer);
        //m_spikeScene = G3DEditorScene::create();

        //auto addCameraInput = [&](const char* label, double* value, CCPoint position) {
        //    auto labelNode = CCLabelBMFont::create(label, "chatFont.fnt");
        //    labelNode->setScale(0.8f);
        //    labelNode->setPosition(position);
        //    this->m_geodeScrollLayer->addChild(labelNode);

        //    auto input = CCTextInputNode::create(150.f, 30.f, std::to_string(*value).c_str(), 12.f, "chatFont.fnt");

        //    input->setAllowedChars("-.0123456789");
        //    input->setMaxLabelLength(10);
        //    input->setScale(0.8f);
        //    input->setPosition({ position.x + 150.0f, position.y });
        //    this->m_geodeScrollLayer->addChild(input, 5);

        //    auto inputBG = cocos2d::extension::CCScale9Sprite::create("square02_small.png", { 0.0f, 0.0f, 40.0f, 40.0f });
        //    inputBG->setContentSize({ 150.0f, 30.0f });
        //    inputBG->setPosition(input->getPosition());
        //    inputBG->setOpacity(100);
        //    this->m_geodeScrollLayer->addChild(inputBG, 4);

        //    //auto slider = Slider::create(m_geodeScrollLayer)
        //    //m_geodeScrollLayer->addChild(slider);
        //    };

        ////auto addCameraCheckbox = [&](const char* label, bool* value, CCPoint position) {
        ////    auto labelNode = CCLabelBMFont::create(label, "chatFont.fnt");
        ////    labelNode->setScale(0.8f);
        ////    labelNode->setPosition(position);
        ////    this->m_geodeScrollLayer->addChild(labelNode);

        ////    auto checkbox = CCCheckBox::create("checkbox_unchecked.png", "checkbox_checked.png");
        ////    checkbox->setPosition({ position.x + 150.0f, position.y });
        ////    checkbox->setSelected(*value);
        ////    checkbox->addEventListener([=](CCObject* sender, CheckBoxEventType type) {
        ////        *value = (type == CheckBoxEventType::SELECTED);
        ////        });
        ////    this->m_geodeScrollLayer->addChild(checkbox, 5);
        ////    };

        //// Camera Input Fields
        //float startY = scrollContentSize.height - 60;
        //float spacing = 42.0f;
        //addCameraInput("Position X:", &currentLevelData.x, { 50, startY });
        //addCameraInput("Position Y:", &currentLevelData.y, { 50, startY - spacing });
        //addCameraInput("Position Z:", &currentLevelData.z, { 50, startY - spacing * 2 });
        //addCameraInput("Yaw:", &currentLevelData.yaw, { 50, startY - spacing * 3 });
        //addCameraInput("Pitch:", &currentLevelData.pitch, { 50, startY - spacing * 4 });
        ////addCameraCheckbox("Lock Camera:", &currentLevelData.camera.lock, { 50, startY - spacing * 5 });

        //// Add Camera Preview Area on the Right (optional)
        //auto cameraPreviewArea = cocos2d::extension::CCScale9Sprite::create("square02_small.png", { 0.0f, 0.0f, 40.0f, 40.0f });
        //cameraPreviewArea->setContentSize({ uiSize.width / 3, uiSize.height - 80 });
        //cameraPreviewArea->setPosition({ uiSize.width - uiSize.width / 4, uiSize.height / 2 });
        //cameraPreviewArea->setOpacity(150);
        //this->m_mainLayer->addChild(cameraPreviewArea);


        //cameraPreviewArea->addChild(m_spikeScene);
        //cameraPreviewArea->setZOrder(100);

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
}