#pragma once

#include <Geode/ui/GeodeUI.hpp>

namespace g3d
{
    class G3DProgressBar;
    class G3DPlanetLayer;

    class G3DPlanetPopup : public geode::Popup<int> {
    protected:
        G3DPlanetLayer* parentLayer;
        G3DProgressBar* normalBar;
        G3DProgressBar* practiceBar;
        GJGameLevel* level;
        int levelID;
        bool openOnce = false;
        static bool isOpened;
        bool setup(int levelID) override;
        void onPlayLevel(CCObject*);
        void onClose(cocos2d::CCObject* obj) override;
        virtual void onEnter() override;

    public:
        static bool checkIsOpened() { return isOpened; }

        static void tryOpen(int levelID, G3DPlanetLayer* parentLayer);
    };
}

