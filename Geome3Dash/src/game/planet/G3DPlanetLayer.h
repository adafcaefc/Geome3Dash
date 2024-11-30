#pragma once

#include "Delegate/CustomKeyboard.h"
#include "Delegate/CustomMouse.h"
#include "Delegate/CustomTouch.h"

#include "Engine/Sus3D/Model.h"

namespace g3d
{
    class PlanetModel : public sus3d::Model {
    public:
        ~PlanetModel() override = default;
        glm::mat4 prepareModelMatrix() override;
        static PlanetModel* create(const aiScene* scene, sus3d::ShaderProgram* shaderProgram);
    };

    class G3DBaseNode;
    class CocosShaderProgram;
    class G3DPlanetLayer
        : public CCLayer
        , public CustomKeyboardDelegate
        , public CustomMouseDelegate
        , public CustomTouchDelegate 
    {
        enum MusicType {
            Default,
            Plains,
            Ice,
            Desert
        };
        MusicType musicType = Default;
        void setMusicType(MusicType newMT) {
            if (newMT != musicType) {
                musicType = newMT;
                playNewSongType();
            }
        }

        void playNewSongType();
        void detectBiomeMusic();

        G3DBaseNode* layer3d;
        CocosShaderProgram* shaderProgram;
        PlanetModel* planetModel;
        PlanetModel* planetModelWater;
        PlanetModel* cloud;
        std::array<PlanetModel*, 19> clouds;

        bool isPressingControl = false;
        bool isRightClicking = false;
        bool isRightClickingGetPos = false;
        float lastMouseX = 0.0;
        float lastMouseY = 0.0;

        void updatePlanetRotation(const float delta);
        
        std::filesystem::path songPath;
        void playMusicDelayed(const float delta);

        virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods);
        virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y);
        virtual void scrollWheel(float y, float x);
        virtual void onKey(enumKeyCodes key, bool pressed, bool holding);
    private:
        bool init();
        virtual void draw() override;
        void onBack(CCObject*);
        virtual void keyBackClicked(void);
        virtual void onEnter() override;
    public:
        static bool insideThePlanetLayerFlag;
        static G3DPlanetLayer* create();
    };
}