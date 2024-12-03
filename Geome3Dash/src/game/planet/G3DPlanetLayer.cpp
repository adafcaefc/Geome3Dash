#include "pch.h"

#include "game/planet/G3DPlanetLayer.h"
#include "game/planet/G3DPlanetPopup.h"
#include "game/component/G3DBaseNode.h"
#include "game/component/G3DFragmentShaderLayer.h"

#include "CocosShaderProgram.h"
#include "PlanetStateManager.h"

#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Shaders.h"
#include "engine/sus3d/Model.h"
#include "engine/sus3d/Mesh.h"

#include "helper/OpenGLStateHelper.h"
#include "helper/Easing.h"

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

                if (selected.first == 0 && selected.second >= 982 && selected.second <= 1061) {

                    // we totally should prefix this level id like for real it might clash with something
                    // prefix with like   444630000 + id
                    // max int is        2147483647
                    int levelID = (selected.second - 982) / 4;

                    for (size_t meshIndex = 0; meshIndex < layer3d->models[0]->meshes.size(); meshIndex++) {
                        if (meshIndex == levelID * 4 + 982 || meshIndex == levelID * 4 + 983 || meshIndex == levelID * 4 + 984 || meshIndex == levelID * 4 + 985)
                            layer3d->models[0]->meshes[meshIndex]->setCustomKa(glm::vec3(1, 0, 0));
                        else
                            layer3d->models[0]->meshes[meshIndex]->disableKa();
                    }

                    int maxI = 0;
                    for (int i = 0; i < 20; i++)
                    {
                        if (PlanetStateManager::getInstance()->getProgressByLevelID(i)->normal != 100) { break; }
                        maxI = i;
                    }

                    if (levelID <= maxI + 1) { G3DPlanetPopup::tryOpen(levelID, this); }
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
        constexpr double duration = 1.0; // Animation duration

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

    void G3DPlanetLayer::detectBiomeMusic() {
        if (layer3d->camera.getPosition().z > 30) { return setMusicType(MusicType::Default); }

        glm::quat currentRotation = glm::quat(glm::vec3(
            glm::radians(planetModel->getRotationX()),
            glm::radians(planetModel->getRotationY()),
            glm::radians(planetModel->getRotationZ())
        ));

        glm::vec3 iceVector(0.0f, 1.0f, 0.0f);
        glm::vec3 worldIceVector = currentRotation * iceVector;
        float iceDotProduct = glm::dot(glm::normalize(worldIceVector), glm::normalize(layer3d->camera.getFront()));
        float iceAngle = glm::degrees(glm::acos(iceDotProduct));

        glm::vec3 desertVector(0.4f, 0.0f, 1.0f);
        glm::vec3 worldDesertVector = currentRotation * desertVector;
        float desertDotProduct = glm::dot(glm::normalize(worldDesertVector), glm::normalize(layer3d->camera.getFront()));
        float desertAngle = glm::degrees(glm::acos(desertDotProduct));

        std::cout << desertAngle << std::endl;
        if (iceAngle < 45.0f || iceAngle > 135.0f) {
            setMusicType(MusicType::Ice);
        }
        else if (desertAngle < 30.f) {
            setMusicType(MusicType::Desert);
        }
        else {
            setMusicType(MusicType::Plains);
        }
    }

    void G3DPlanetLayer::playNewSongType() {
        songPath = geode::Mod::get()->getResourcesDir() / "music";
        switch (musicType) {
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


    void G3DPlanetLayer::onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) {
        if (G3DPlanetPopup::checkIsOpened()) return;
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

                }
                else {
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
                }

                lastMouseX = static_cast<float>(x);
                lastMouseY = static_cast<float>(y);
            }
        }
    }

    void G3DPlanetLayer::scrollWheel(float y, float x) {
        float zoomSensitivity = 0.128f;
        layer3d->camera.setPosition(layer3d->camera.getPosition() + glm::vec3(0, 0, y * zoomSensitivity));
        if (layer3d->camera.getPosition().z < 10) layer3d->camera.setPosition(glm::vec3(layer3d->camera.getPosition().x, layer3d->camera.getPosition().y, 10));
        if (layer3d->camera.getPosition().z > 50) layer3d->camera.setPosition(glm::vec3(layer3d->camera.getPosition().x, layer3d->camera.getPosition().y, 50));

        detectBiomeMusic();
    }

    void G3DPlanetLayer::onKey(enumKeyCodes key, bool pressed, bool holding) {
        switch (key) {
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

    bool G3DPlanetLayer::init() {
        insideThePlanetLayerFlag = true;
        FMODAudioEngine::get()->fadeOutMusic(3.f, 0);
        CCLayer::init();

        setKeyboardEnabled(true);

        OpenGLStateHelper::saveState();
        auto vertexShader = sus3d::Shader::createWithString(sus3d::shaders::vertexShaderSource, sus3d::ShaderType::kVertexShader);
        auto fragmentShader = sus3d::Shader::createWithString(sus3d::shaders::fragmentShaderSource, sus3d::ShaderType::kFragmentShader);
        shaderProgram = CocosShaderProgram::create(vertexShader, fragmentShader);
        delete vertexShader;
        delete fragmentShader;

        const auto planetPath = geode::Mod::get()->getResourcesDir() / "model3d" / "planet";
        const auto shaderPath = planetPath / "shader";
        const auto modelPath = planetPath / "model";

        auto vertexShader2 = sus3d::Shader::createWithString(sus3d::shaders::vertexShaderSource, sus3d::ShaderType::kVertexShader);
        auto fragmentShader2 = sus3d::Shader::createWithFile(shaderPath / "water2.fsh", sus3d::ShaderType::kFragmentShader);
        shaderProgram2 = CocosShaderProgram::create(vertexShader2, fragmentShader2);
        delete vertexShader2;
        delete fragmentShader2;

        auto vertexShader3 = sus3d::Shader::createWithFile(shaderPath / "cloud.vsh", sus3d::ShaderType::kVertexShader);
        auto fragmentShader3 = sus3d::Shader::createWithFile(shaderPath / "cloud.fsh", sus3d::ShaderType::kFragmentShader);
        shaderProgram3 = CocosShaderProgram::create(vertexShader3, fragmentShader3);
        delete vertexShader3;
        delete fragmentShader3;
        OpenGLStateHelper::pushState();

        layer3d = G3DPlanetBaseNode::create();
        layer3d->light.setPosition(glm::vec3(0, 50, 1000));
        layer3d->setZOrder(10);

        auto bms = BlockModelsStorage::getInstance();

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
        this->addChild(backButtonMenu);


        this->schedule(schedule_selector(G3DPlanetLayer::updatePlanetRotation));

        overlay = G3DRegionNameOverlay::create();
        this->addChild(overlay);
        overlay->setZOrder(11);

        playNewSongType();

        return true;
    }

    void G3DPlanetLayer::onEnter() {
        CCLayer::onEnter();
        for (size_t i = 0; i < cloudModel->meshes.size(); i++) {
            size_t realMeshId = cloudModel->meshes.size() - 1u -i;
            if (i == 0) {
                cloudModel->meshes[realMeshId]->setVisible(0);
                continue;
            }

            cloudModel->meshes[realMeshId]->setVisible(
                (PlanetStateManager::getInstance()->getProgressByLevelID(i - 1)->normal == 100)
                ? 0 : 1);
        }
    }

    void G3DPlanetLayer::onBack(CCObject*) {
        keyBackClicked();
    }

    void G3DPlanetLayer::keyBackClicked(void) {
        insideThePlanetLayerFlag = false;

        GameManager::get()->fadeInMenuMusic();

        CCDirector::sharedDirector()->popSceneWithTransition(0.3f, PopTransition::kPopTransitionFade);
    }

    void G3DPlanetLayer::draw() {
        CCLayer::draw();
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

    bool G3DPlanetLayer::insideThePlanetLayerFlag = false;

    glm::mat4 PlanetModel::prepareModelMatrix() {
        glm::mat4 model = glm::mat4(1.0f); // Start with an identity matrix

        // Apply translation
        model = glm::translate(model, position);

        // Apply rotations (Z, Y, X in this order)
        if (rotation.z != 0.0f)  // Only apply rotation if non-zero
            model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));  // Rotate around Z axis

        if (rotation.y != 0.0f)  // Only apply rotation if non-zero
            model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));  // Rotate around Y axis

        if (rotation.x != 0.0f)  // Only apply rotation if non-zero
            model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));  // Rotate around X axis

        // Apply scaling
        model = glm::scale(model, scale);

        return model;
    }

    bool CloudModel::init(const aiScene* scene) {

        for (unsigned int i = 0; i < scene->mNumMeshes; ++i) {
            sus3d::Mesh* mesh = CloudMesh::create(scene->mMeshes[i], scene->mMaterials[scene->mMeshes[i]->mMaterialIndex]);
            meshes.push_back(mesh);
        }

        return true;
    }

    static glm::vec3 calculateNormal(aiMesh* mesh, aiFace& face) {
        aiVector3D v0 = mesh->mVertices[face.mIndices[0]];
        aiVector3D v1 = mesh->mVertices[face.mIndices[1]];
        aiVector3D v2 = mesh->mVertices[face.mIndices[2]];

        glm::vec3 edge1(v1.x - v0.x, v1.y - v0.y, v1.z - v0.z);
        glm::vec3 edge2(v2.x - v0.x, v2.y - v0.y, v2.z - v0.z);

        glm::vec3 normal = glm::normalize(glm::cross(edge1, edge2));
        return normal;
    }

    static glm::vec3 calculateCentroid(aiMesh* mesh, aiFace& face) {
        aiVector3D v0 = mesh->mVertices[face.mIndices[0]];
        aiVector3D v1 = mesh->mVertices[face.mIndices[1]];
        aiVector3D v2 = mesh->mVertices[face.mIndices[2]];

        glm::vec3 centroid = glm::vec3(
            (v0.x + v1.x + v2.x) / 3.0f,
            (v0.y + v1.y + v2.y) / 3.0f,
            (v0.z + v1.z + v2.z) / 3.0f
        );
        return centroid;
    }

    bool CloudMesh::init(aiMesh* mesh, aiMaterial* material) {
        for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
            vertices.push_back(mesh->mVertices[i].x);
            vertices.push_back(mesh->mVertices[i].y);
            vertices.push_back(mesh->mVertices[i].z);

            if (mesh->mTextureCoords[0]) {
                vertices.push_back(mesh->mTextureCoords[0][i].x);
                vertices.push_back(mesh->mTextureCoords[0][i].y);
            }
            else {
                vertices.push_back(0.0f);
                vertices.push_back(0.0f);
            }

            vertices.push_back(mesh->mNormals[i].x);
            vertices.push_back(mesh->mNormals[i].y);
            vertices.push_back(mesh->mNormals[i].z);
        }

        glm::vec3 sphereCenter(0.0f, 0.0f, 0.0f);

        for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
            aiFace face = mesh->mFaces[i];
            glm::vec3 normal = calculateNormal(mesh, face);
            glm::vec3 centroid = calculateCentroid(mesh, face);

            glm::vec3 centerDirection = glm::normalize(sphereCenter - centroid);

            // Compare face normal with the direction to the center
            float dot = glm::dot(normal, centerDirection);

            if (std::abs(dot) < 0.9f) { // Face points towards the center
                continue; // Skip this face
            }

            for (unsigned int j = 0; j < face.mNumIndices; j++) {
                indices.push_back(face.mIndices[j]);
            }
        }

        initBuffers(material);


        return true;
    }

    void CloudMesh::render(sus3d::ShaderProgram* shaderProgram) const 
    {
        // custom renderer just to set the d value
        if (visible) 
        {
            glBindVertexArray(VAO);
            glEnable(GL_DEPTH_TEST);
            glEnable(GL_BLEND);
            glEnable(GL_BLEND_COLOR);
            if (useTexture)
                glBindTexture(GL_TEXTURE_2D, texture);
            shaderProgram->setInt("isTexture", int(useTexture));
            shaderProgram->setVec3("Ka", isCustomKa ? customKa : Ka);
            shaderProgram->setVec3("Kd", isCustomKd ? customKd : Kd);
            shaderProgram->setVec3("Ks", isCustomKs ? customKs : Ks);
            shaderProgram->setFloat("shininess", 32);
            shaderProgram->setFloat("d", (isCustomD ? customD : d) * opacityModifier);
            glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, NULL);
            glBindVertexArray(0);
            glDisable(GL_DEPTH_TEST);
            glDisable(GL_BLEND);
            glDisable(GL_BLEND_COLOR);
        }
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

        planetLayer->planetModel->render(
            planetLayer->shaderProgram, 
            view, 
            light.getPosition(), 
            light.getColor(), 
            camera.getPosition(), 
            projection);

        planetLayer->planetWaterModel->render(
            planetLayer->shaderProgram2, 
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

        for (int i = 0; i < fSteps; i++) {
            planetLayer->cloudModel->setCloudOpacity(std::clamp(opacityBase - ease::easeFloat(ease::InCubic::get(), i, fSteps, 0.f, opacityScale), 0.0, 1.0));
            planetLayer->cloudModel->setScale(
                glm::vec3(ease::easeFloat(ease::InCubic::get(), i, fSteps, 0.f, sizeScale) + sizeBase) * planetLayer->planetModel->getScale());
            planetLayer->cloudModel->render(
                planetLayer->shaderProgram3, 
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

    void CloudModel::setCloudOpacity(const float op)
    {
        for (auto& mesh : meshes)
        {
            if (auto cloudMesh = dynamic_cast<CloudMesh*>(mesh))
            {
                cloudMesh->opacityModifier = op;
            }
        }
    }

    PlanetModel* PlanetModel::create(const aiScene* scene) {
        PlanetModel* ret = new PlanetModel();

        if (!ret || !ret->init(scene)) {
            delete ret; 
            return nullptr;
        }

        return ret;
    }

    CloudModel* CloudModel::create(const aiScene* scene) {
        CloudModel* ret = new CloudModel();

        if (!ret || !ret->init(scene)) {
            delete ret;
            return nullptr;
        }

        return ret;
    }

    CloudMesh* CloudMesh::create(aiMesh* mesh, aiMaterial* material) {
        auto ret = new CloudMesh();
        if (!ret || !ret->init(mesh, material)) {
            delete ret;
            return nullptr;
        }
        return ret;
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
}