#include "pch.h"

#include "game/planet/G3DPlanetLayer.h"
#include "game/planet/G3DPlanetPopup.h"
#include "game/component/G3DBaseNode.h"
#include "game/component/G3DFragmentShaderLayer.h"

#include "manager/PlanetStateManager.h"

#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Shaders.h"
#include "engine/sus3d/Model.h"
#include "engine/sus3d/Mesh.h"

#include "helper/OpenGLStateHelper.h"
#include "helper/Easing.h"

#include "impl/engine/CocosShaderProgram.h"
#include "impl/engine/CloudMesh.h"
#include "impl/engine/CloudModel.h"
#include "impl/engine/PlanetModel.h"

namespace g3d
{
    void G3DRegionNameOverlay::show(const std::string& region, const std::string& music)
    {
        m_musicTitle->setString(music.c_str());
        m_regionTitle->setString(region.c_str());
        show(m_musicTitle);
        show(m_regionTitle);
    }

    G3DRegionNameOverlay* G3DRegionNameOverlay::create()
    {
        auto ret = new G3DRegionNameOverlay();
        if (ret && ret->init())
        {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }

    bool G3DRegionNameOverlay::init()
    {
        if (!CCNode::init()) { return false; }

        this->setAnchorPoint({ 0.5, 0 });
        this->setContentSize({ 400, 75 });
        this->setScale(.5f);

        m_regionTitle = CCLabelBMFont::create("", "bigFont.fnt");
        m_regionTitle->setAnchorPoint({ .0f, .5f });
        this->addChildAtPosition(m_regionTitle, geode::Anchor::Center);

        m_musicTitle = CCLabelBMFont::create("", "goldFont.fnt");
        m_musicTitle->setAnchorPoint({ .0f, .5f });
        this->addChildAtPosition(m_musicTitle, geode::Anchor::Center, ccp(0, -30));

        this->setPosition(ccp(15, 15));
        this->setScale(0.4f);

        return true;
    }

    void G3DPlanetLayer::onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) {
        if (G3DPlanetPopup::checkIsOpened()) { return; }
        if (button == GLFW_MOUSE_BUTTON_LEFT) {
            if (action == GLFW_PRESS) {
                isRightClicking = true;
                isRightClickingGetPos = false;
            }
            else if (action == GLFW_RELEASE) {
                isRightClicking = false;

                auto selected = layer3d->getObjectIDByMousePosition();

                if (selected.first == 0 && selected.second >= 982 && selected.second <= 1061) 
                {
                    int levelID = (selected.second - 982) / 4;
                    int keyLevelID = levelID + 900000000;
                    int maxI = 0;
                    for (int i = 0; i < 19; i++)
                    {
                        if (PlanetStateManager::getInstance()->currentProgress[900000000 + i].normal != 100) { break; }
                        maxI = i + 1;
                    }
                    if (levelID <= maxI) { G3DPlanetPopup::tryOpen(keyLevelID, this); }
                }
            }
        }
    }

    void G3DPlanetLayer::updatePlanetRotation(const float delta) 
    {
        if (!insideThePlanetLayerFlag) { return; }

        // Store previous scales
        static glm::vec3 previousWaterScale = planetWaterModel->getScale();
        static glm::vec3 previousPlanetScale = planetModel->getScale();

        // Set target scales
        const glm::vec3 waterTargetScale = glm::vec3(1.001f);
        const glm::vec3 planetTargetScale = glm::vec3(1.0f);

        // Calculate scale differences
        float waterScaleDiff = glm::length(previousWaterScale - waterTargetScale);
        float planetScaleDiff = glm::length(previousPlanetScale - planetTargetScale);

        // Threshold for triggering animation
        constexpr float threshold = 0.2f;

        // Static animation state
        static bool isAnimating = false;
        static double timeElapsed = 0.0;
        constexpr double duration = 1.25; // Animation duration

        // Trigger animation if the scale difference exceeds the threshold
        if (!isAnimating && (waterScaleDiff > threshold || planetScaleDiff > threshold)) {
            isAnimating = true;
            timeElapsed = 0.0; // Reset animation timer
        }

        // Perform animation if active
        if (isAnimating) {
            timeElapsed += delta;
            if (timeElapsed <= duration) {
                double t = timeElapsed / duration;
                planetWaterModel->setScale(
                    ease::ease<glm::vec3>(ease::InOutCubic::get(), t, duration, previousWaterScale, waterTargetScale)
                );
                planetModel->setScale(
                    ease::ease<glm::vec3>(ease::InOutCubic::get(), t, duration, previousPlanetScale, planetTargetScale)
                );
            }
            else {
                // Animation complete, set to final target scales
                planetWaterModel->setScale(waterTargetScale);
                planetModel->setScale(planetTargetScale);
                isAnimating = false; // End animation
            }
        }

        // Update previous scales for the next frame
        previousWaterScale = planetWaterModel->getScale();
        previousPlanetScale = planetModel->getScale();

        float sensitivityX = 0.004662f;
        float sensitivityY = 0.003665f;
        float sensitivityZ = 0.009160f;

        glm::quat rotationX = glm::angleAxis(delta * sensitivityX, glm::vec3(1.0f, 0.0f, 0.0f));
        glm::quat rotationY = glm::angleAxis(delta * sensitivityY, glm::vec3(0.0f, 1.0f, 0.0f));
        glm::quat rotationZ = glm::angleAxis(delta * sensitivityZ, glm::vec3(0.0f, 0.0f, 1.0f));
        glm::quat currentRotation = glm::quat(glm::vec3(
            glm::radians(planetModel->getRotationX()),
            glm::radians(planetModel->getRotationY()),
            glm::radians(planetModel->getRotationZ())
        ));

        glm::quat newRotation = rotationZ * rotationY * rotationX * currentRotation;
        glm::vec3 eulerAngles = glm::eulerAngles(newRotation);

        planetModel->setRotationX(glm::degrees(eulerAngles.x));
        planetModel->setRotationY(glm::degrees(eulerAngles.y));
        planetModel->setRotationZ(glm::degrees(eulerAngles.z));
        planetWaterModel->setRotationX(glm::degrees(eulerAngles.x));
        planetWaterModel->setRotationY(glm::degrees(eulerAngles.y));
        planetWaterModel->setRotationZ(glm::degrees(eulerAngles.z));
        cloudModel->setRotationX(glm::degrees(eulerAngles.x));
        cloudModel->setRotationY(glm::degrees(eulerAngles.y));
        cloudModel->setRotationZ(glm::degrees(eulerAngles.z));
    }

    void G3DPlanetLayer::detectBiomeMusic()
    {
        if (layer3d->camera.getPosition().z > 30) { return setMusicType(MusicType::Default); }

        glm::quat currentRotation = glm::quat(glm::vec3(
            glm::radians(planetModel->getRotationX()),
            glm::radians(planetModel->getRotationY()),
            glm::radians(planetModel->getRotationZ())));

        glm::vec3 iceVector(0.0f, 1.0f, 0.0f);
        glm::vec3 worldIceVector = currentRotation * iceVector;
        float iceDotProduct = glm::dot(glm::normalize(worldIceVector), glm::normalize(layer3d->camera.getFront()));
        float iceAngle = glm::degrees(glm::acos(iceDotProduct));

        glm::vec3 desertVector(0.4f, 0.0f, 1.0f);
        glm::vec3 worldDesertVector = currentRotation * desertVector;
        float desertDotProduct = glm::dot(glm::normalize(worldDesertVector), glm::normalize(layer3d->camera.getFront()));
        float desertAngle = glm::degrees(glm::acos(desertDotProduct));

        if (iceAngle < 45.0f || iceAngle > 135.0f) { setMusicType(MusicType::Ice); }
        else if (desertAngle < 30.f) { setMusicType(MusicType::Desert); }
        else { setMusicType(MusicType::Plains); }
    }

    void G3DPlanetLayer::playNewSongType() 
    {
        songPath = geode::Mod::get()->getResourcesDir() / "music";
        switch (musicType) 
        {
        case MusicType::Plains:
            if (overlay) { overlay->show("The Whispering Wilds", "A145 - A Newborn Spirit"); }
            songPath = songPath / "A145 - A Newborn Spirit.mp3";
            break;
        case MusicType::Ice:
            if (overlay) { overlay->show("The Glacial Heights", "A145 - Each Other's Backs"); }
            songPath = songPath / "A145 - Each Other's Backs.mp3";
            break;
        case MusicType::Desert:
            if (overlay) { overlay->show("The Sunken Sands", "A145 - On Top Of The Desert"); }
            songPath = songPath / "A145 - On Top Of The Desert.mp3";
            break;
        case MusicType::Default:
        default:
            if (overlay) { overlay->show("The Nebula Drift", "A145 - That One Talks"); }
            songPath = songPath / "A145 - That One Talks.mp3";
            break;
        }
        FMODAudioEngine::get()->fadeOutMusic(1.f, 0);

        this->schedule(schedule_selector(G3DPlanetLayer::playMusicDelayed), 0, 0, 1.f);
    }

    void G3DPlanetLayer::playMusicDelayed(const float delta)
    {
        FMODAudioEngine::get()->playMusic(songPath.string(), true, 1.f, 0);
    }

    void G3DPlanetLayer::onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) 
    {
        if (G3DPlanetPopup::checkIsOpened()) { return; }
        if (isRightClicking) 
        {
            if (!isRightClickingGetPos) 
            {
                lastMouseX = static_cast<float>(x);
                lastMouseY = static_cast<float>(y);
                isRightClickingGetPos = true;
            }
            else 
            {
                float deltaX = static_cast<float>(x) - lastMouseX;
                float deltaY = static_cast<float>(y) - lastMouseY;

                float sensitivity = 0.005f;

                glm::quat rotationX = glm::angleAxis(deltaY * sensitivity, glm::vec3(1.0f, 0.0f, 0.0f));
                glm::quat rotationY = glm::angleAxis(deltaX * sensitivity, glm::vec3(0.0f, 1.0f, 0.0f));
                glm::quat currentRotation = glm::quat(glm::vec3(
                    glm::radians(planetModel->getRotationX()),
                    glm::radians(planetModel->getRotationY()),
                    glm::radians(planetModel->getRotationZ())
                ));

                glm::quat newRotation = rotationY * rotationX * currentRotation;
                glm::vec3 eulerAngles = glm::eulerAngles(newRotation);

                planetModel->setRotationX(glm::degrees(eulerAngles.x));
                planetModel->setRotationY(glm::degrees(eulerAngles.y));
                planetModel->setRotationZ(glm::degrees(eulerAngles.z));
                planetWaterModel->setRotationX(glm::degrees(eulerAngles.x));
                planetWaterModel->setRotationY(glm::degrees(eulerAngles.y));
                planetWaterModel->setRotationZ(glm::degrees(eulerAngles.z));
                cloudModel->setRotationX(glm::degrees(eulerAngles.x));
                cloudModel->setRotationY(glm::degrees(eulerAngles.y));
                cloudModel->setRotationZ(glm::degrees(eulerAngles.z));

                detectBiomeMusic();

                lastMouseX = static_cast<float>(x);
                lastMouseY = static_cast<float>(y);
            }
        }
    }

    void G3DPlanetLayer::scrollWheel(float y, float x)
    {
        float zoomSensitivity = 0.128f;
        layer3d->camera.setPosition(layer3d->camera.getPosition() + glm::vec3(0, 0, y * zoomSensitivity));

        if (layer3d->camera.getPosition().z < 10) layer3d->camera.setPosition(glm::vec3(layer3d->camera.getPosition().x, layer3d->camera.getPosition().y, 10));
        if (layer3d->camera.getPosition().z > 50) layer3d->camera.setPosition(glm::vec3(layer3d->camera.getPosition().x, layer3d->camera.getPosition().y, 50));

        detectBiomeMusic();
    }

    void G3DPlanetLayer::onKey(enumKeyCodes key, bool pressed, bool holding) 
    {
        switch (key)
        {
        case KEY_Control:
            isPressingControl = pressed;
            break;
        //case KEY_Escape:
        //    onBack(this);
        //    break;
        default:
            break;
        }
    }

    bool G3DPlanetLayer::init() 
    {
        insideThePlanetLayerFlag = true;

        FMODAudioEngine::get()->fadeOutMusic(3.f, 0);

        CCLayer::init();

        setKeyboardEnabled(true);


        auto bms = ModelManager::get();

        const auto planetPath = bms->getBP() / "planet";
        const auto shaderPath = planetPath / "shader";
        const auto modelPath = planetPath / "model";

        layer3d = G3DPlanetBaseNode::create();
        layer3d->light.setPosition(glm::vec3(0, 50, 1000));
        layer3d->setZOrder(10);

        planetModel = bms->getModelT<PlanetModel>(modelPath / "new_planet_textured.obj");
        planetWaterModel = bms->getModelT<PlanetModel>(modelPath / "planet_water.obj");
        cloudModel = bms->getModelT<CloudModel>(modelPath / "clouds.obj");

        // probably should put this in constructor but too lazy rn
        layer3d->planetLayer = this;

        this->addChild(layer3d);
        layer3d->camera.setPosition(glm::vec3(0, 0, 29));

        auto size = CCDirector::sharedDirector()->getWinSize();

        auto testLayer = G3DFragmentShaderLayer::create(shaderPath / "space.fsh");
        //auto testLayer = FragmentShaderLayer::create("./water.fsh");
        this->addChild(testLayer);

        auto bg = CCSprite::create("GJ_gradientBG.png");
        bg->setScaleX(size.width / bg->getContentSize().width);
        bg->setScaleY(size.height / bg->getContentSize().height);
        bg->setColor({ 0, 75, 110 });
        bg->setZOrder(-5);

        bg->setPosition(size / 2);

        this->addChild(bg);

        auto backButtonSprite = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
        auto backButton = CCMenuItemSpriteExtra::create(backButtonSprite, this, menu_selector(G3DPlanetLayer::onBack));
        auto backButtonMenu = CCMenu::create();
        backButtonMenu->setPosition(25, size.height - 25);
        backButtonMenu->addChild(backButton);
        backButtonMenu->setZOrder(11);
        this->addChild(backButtonMenu);

        this->schedule(schedule_selector(G3DPlanetLayer::updatePlanetRotation));

        overlay = G3DRegionNameOverlay::create();
        this->addChild(overlay);
        overlay->setZOrder(11);

        // for object id calculation
        layer3d->models.push_back(planetModel);

        playNewSongType();

        return true;
    }

    void G3DPlanetLayer::onEnter() 
    {
        CCLayer::onEnter();
        for (size_t i = 0; i < cloudModel->meshes.size(); i++) 
        {
            size_t realMeshId = cloudModel->meshes.size() - 1u -i;
            if (i == 0) 
            {
                cloudModel->meshes[realMeshId]->setVisible(0);
                continue;
            }

            auto pms = PlanetStateManager::getInstance();

            const auto percentage = pms->currentProgress[900000000 + static_cast<int>(i) - 1].normal;

            cloudModel->meshes[realMeshId]->setVisible(percentage == 100 ? 0 : 1);
        }
    }

    void G3DPlanetLayer::onBack(CCObject*) 
    {
        keyBackClicked();
    }

    void G3DPlanetLayer::keyBackClicked(void) 
    {
        insideThePlanetLayerFlag = false;

        GameManager::get()->fadeInMenuMusic();

        CCDirector::sharedDirector()->popSceneWithTransition(0.3f, PopTransition::kPopTransitionFade);
    }

    G3DPlanetLayer* G3DPlanetLayer::create() {
        auto node = new G3DPlanetLayer;
        if (node->init()) {
            node->autorelease();
        }
        else {
            CC_SAFE_DELETE(node);
        }
        return node;
    }

    void G3DPlanetBaseNode::draw()
    {
        CCNode::draw();
        OpenGLStateHelper::saveState();
        glEnable(GL_BLEND);
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_DEPTH_TEST);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glm::mat4 view = camera.getViewMat();
        glm::mat4 projection = camera.getProjectionMat();

        auto bms = ModelManager::get();

        planetLayer->planetModel->render(
            bms->getBlockSP(),
            view, 
            light.getPosition(), 
            light.getColor(), 
            camera.getPosition(), 
            projection);

        planetLayer->planetWaterModel->render(
            bms->getWaterSP(),
            view, 
            light.getPosition(), 
            light.getColor(), 
            camera.getPosition(), 
            projection);

        // probably nobody will know how to use this but I like to tweak the clouds so much
        // so tldr
        // opacityBase - opacityScale
        // sizeBase + sizeScale
        // why? idk but it is how it works
        float sizeBase = 0.80f;
        float sizeScale = 0.2f;
        float opacityBase = 1.0f;
        float opacityScale = 1.0f;

        int fSteps = 0;
        // set steps so it doesn't lag
        if (camera.getPosition().z > 30) {
            fSteps = 15;
        }
        else if (camera.getPosition().z > 27) {
            fSteps = 14;
        }
        else if (camera.getPosition().z > 26) {
            fSteps = 13;
        }
        else if (camera.getPosition().z > 25) {
            fSteps = 12;
        }
        else if (camera.getPosition().z > 24) {
            fSteps = 11;
        }
        else if (camera.getPosition().z > 23) {
            fSteps = 10;
        }
        else if (camera.getPosition().z > 22) {
            fSteps = 9;
        }
        else {
            fSteps = 6;
        }

        if (geode::Mod::get()->getSettingValue<bool>("disable-cloud"))
        {
            fSteps = 1;
            sizeBase = 0.85f;
        }

        for (int i = 0; i < fSteps; i++) 
        {
            // easing stuff I don't care
            planetLayer->cloudModel->setCloudOpacity(std::clamp(opacityBase - ease::easeFloat(ease::InCubic::get(), i, fSteps, 0.f, opacityScale), 0.0, 1.0));
            if (geode::Mod::get()->getSettingValue<bool>("disable-cloud"))
            {
                planetLayer->cloudModel->setCloudOpacity(4.f);
            }
            planetLayer->cloudModel->setScale(
                glm::vec3(ease::easeFloat(ease::InCubic::get(), i, fSteps, 0.f, sizeScale) + sizeBase) * planetLayer->planetModel->getScale());
            planetLayer->cloudModel->render(
                bms->getCloudSP(),
                view, 
                light.getPosition(), 
                light.getColor(), 
                camera.getPosition(), 
                projection);
        }

        planetLayer->cloudModel->setCloudOpacity(1.0f);

        glDisable(GL_DEPTH_TEST);
        OpenGLStateHelper::pushState();
    }

    G3DPlanetBaseNode* G3DPlanetBaseNode::create() {
        auto node = new G3DPlanetBaseNode;
        if (node && node->init()) {
            node->autorelease();
        }
        else {
            CC_SAFE_DELETE(node);
        }
        return node;
    }

    bool G3DPlanetLayer::insideThePlanetLayerFlag = false;
}