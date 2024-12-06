#include "pch.h"
#include "BlockModelStorage.h"
#include "game/planet/G3DPlanetLayer.h"
#include "game/component/G3DRainixPopup.h"

namespace g3d
{
    class $modify(MenuGameLayer) 
    {
        void resetPlayer()
        {
            bool alreadyShowPopup = geode::Mod::get()->getSavedValue<bool>("already-show-welcome-popup");
            //std::cout << m_deltaCount << '\n';
            //alreadyShowPopup = false;
            if (!alreadyShowPopup && m_deltaCount > 1.f)
            {
                static std::vector<std::string> vstrings = {
                    "<cy>WELCOME TO GEOME3DASH</c>",
                    "",
                    "This mod brings your GD experience into the third dimension.",
                    "Created in just <cr>2 weeks</c>, this is an early beta release.",
                    "The Story Mode is <co>incomplete</c>, but updates are on the way!",
                    "<cy>Acknowledgments:</c>",
                    "<cr>A145</c> - massive support, beta-testing, and music contributions",
                    "<cg>Weebify, Lexi, Albert</c> - dedicated beta-testers",
                    "Enjoy the beta and stay tuned for more updates!"
                };
                G3DRainixPopup::scene(vstrings, this);
                geode::Mod::get()->setSavedValue<bool>("already-show-welcome-popup", true);
            }
            MenuGameLayer::resetPlayer();
        }
    };
}