#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class MusicArtistObject : public cocos2d::CCObject {
public:
    static constexpr auto CLASS_NAME = "MusicArtistObject";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(MusicArtistObject, cocos2d::CCObject)
    
private:
    [[deprecated("MusicArtistObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static MusicArtistObject* create(int p0, gd::string p1, gd::string p2, gd::string p3);
public:
    
private:
    [[deprecated("MusicArtistObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(int p0, gd::string p1, gd::string p2, gd::string p3);
public:
};
