#pragma once

#include "game/component/G3DNumberSetting.h"
#include "game/play/G3DCameraEditorScene.h"

#include "delegate/CustomKeyboard.h"
#include "delegate/CustomMouse.h"
#include "delegate/CustomTouch.h"
#include "delegate/CustomTouch.h"

#include "engine/sus3d/ShaderProgram.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Texture.h"
#include "engine/sus3d/Model.h"
#include "engine/sus3d/Scene.h"
#include "engine/sus3d/Shaders.h"

#include "model/PlayerObjectModel.h"

#include "transformer/GomtSpline.h"
#include "transformer/PomtSpline.h"
#include "transformer/PomtSplineCamera.h"

#include "impl/engine/CocosShaderProgram.h"

namespace g3d
{
    class G3DCameraEditorPopup;
    class G3DNumberSettingCamera : public G3DNumberSetting 
    {
        friend class G3DCameraEditorPopup;
        G3DCameraEditorPopup* m_cameraEditorPopup;
    public:
        // Override the init method to take an additional G3DCameraEditorPopup parameter
        bool init(const char* displayName, double* ptrValue, float width, G3DCameraEditorPopup* cameraEditorPopup) {
            if (!G3DNumberSetting::init(displayName, ptrValue, width)) {
                return false;
            }

            m_cameraEditorPopup = cameraEditorPopup;
            return true;
        }

        // Override the updateState method to call G3DCameraEditorPopup::updateState
        void updateState(CCNode* invoker) override;

        // Factory method
        static G3DNumberSettingCamera* create(const char* displayName, double* ptrValue, float width, G3DCameraEditorPopup* cameraEditorPopup) {
            auto ret = new G3DNumberSettingCamera();
            if (ret && ret->init(displayName, ptrValue, width, cameraEditorPopup)) {
                ret->autorelease();
                return ret;
            }
            CC_SAFE_DELETE(ret);
            return nullptr;
        }
    };

    class G3DCameraEditorPopup : public geode::Popup<LevelEditorLayer*> 
    {
    public:
        friend class G3DNumberSettingCamera;
        static void scene(LevelEditorLayer* plel);
        void updateState(G3DNumberSetting* invoker = nullptr);
        void updateCamera();

    protected:
        bool setup(LevelEditorLayer*) override;
        //void addLabel(const char* text, const CCPoint& position);

        G3DCameraEditorScene* m_spikeScene = nullptr;
        geode::ScrollLayer* m_list = nullptr;
        geode::TextInput* m_searchInput = nullptr;
        std::vector<geode::Ref<G3DNumberSetting>> m_settings;

        LevelEditorLayer* lel;

        virtual void onClose(CCObject*) override;

    private:
        //static CCSize popupPadding;

        G3DCameraEditorPopup()  { }
    };
}