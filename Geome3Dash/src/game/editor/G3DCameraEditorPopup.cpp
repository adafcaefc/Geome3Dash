#include "pch.h"

#include "game/editor/G3DCameraEditorPopup.h"
#include "game/component/G3DBaseNode.h"

#include "helper/OpenGLStateHelper.h"

#include "manager/ModelManager.h"
#include "manager/LevelDataManager.h"

namespace g3d
{
    void G3DCameraEditorPopup::onClose(CCObject* ob)
    {
        setLevelData(lel, m_spikeScene->levelData);
        geode::Popup<LevelEditorLayer*>::onClose(ob);
    }

    void G3DCameraEditorPopup::updateCamera()
    {
        if (m_spikeScene)
        {
            setStartingKeyframe(
                &m_spikeScene->levelData,
                &m_spikeScene->levelData.keyframe,
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

        m_spikeScene = G3DCameraEditorScene::create(lel);
        this->m_mainLayer->addChild(m_spikeScene);

        setTitle("Geome3Dash Camera Editor");
        //auto winSize = CCDirector::sharedDirector()->getWinSize();
        auto const layerSize = CCSize(250, 200);

        auto layerBG = CCLayerColor::create({ 0, 0, 0, 75 });
        layerBG->setContentSize(layerSize);
        layerBG->ignoreAnchorPointForPosition(false);
        m_mainLayer->addChildAtPosition(layerBG, geode::Anchor::Center);

        m_list = geode::ScrollLayer::create(layerSize /*- ccp(0, searchContainer->getContentHeight())*/);
        m_list->setTouchEnabled(true);

        G3DNumberSettingCamera* node;

        // "Cam X" Setting
        node = G3DNumberSettingCamera::create("Cam X", &m_spikeScene->levelData.x, layerSize.width, this);
        m_settings.push_back(node);
        m_list->m_contentLayer->addChild(node);
        node->m_impl_modDescription = "Controls the X axis (horizontal movement) of the camera.";

        // "Cam Y" Setting
        node = G3DNumberSettingCamera::create("Cam Y", &m_spikeScene->levelData.y, layerSize.width, this);
        m_settings.push_back(node);
        m_list->m_contentLayer->addChild(node);
        node->m_impl_modDescription = "Controls the Y axis (vertical movement) of the camera.";

        // "Cam Z" Setting
        node = G3DNumberSettingCamera::create("Cam Z", &m_spikeScene->levelData.z, layerSize.width, this);
        m_settings.push_back(node);
        m_list->m_contentLayer->addChild(node);
        node->m_impl_modDescription = "Controls the Z axis (depth or forward/backward movement) of the camera.";

        // "Cam Yaw" Setting
        node = G3DNumberSettingCamera::create("Cam Yaw", &m_spikeScene->levelData.yaw, layerSize.width, this);
        m_settings.push_back(node);
        m_list->m_contentLayer->addChild(node);
        node->m_impl_modDescription = "Controls the yaw (horizontal rotation) of the camera.";

        // "Cam Pitch" Setting
        node = G3DNumberSettingCamera::create("Cam Pitch", &m_spikeScene->levelData.pitch, layerSize.width, this);
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

        layerBG->addChildAtPosition(m_list, geode::Anchor::BottomLeft);

        auto scrollBar = geode::Scrollbar::create(m_list);
        m_mainLayer->addChildAtPosition(
            scrollBar, geode::Anchor::Center, ccp(layerBG->getContentWidth() / 2 + 10, 0));

        layerBG->setPositionX(layerBG->getPositionX() + 90);
        scrollBar->setPositionX(scrollBar->getPositionX() + 90);

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
            instance->setID("g3d-editor-popup"_spr);
            instance->autorelease();
            instance->show();
        }
        else
        {
            CC_SAFE_DELETE(instance);
        }
    }

    void G3DNumberSettingCamera::updateState(CCNode* invoker)
    {
        G3DNumberSetting::updateState(invoker);
        if (m_cameraEditorPopup)
        {
            m_cameraEditorPopup->updateCamera();
        }
    }
}