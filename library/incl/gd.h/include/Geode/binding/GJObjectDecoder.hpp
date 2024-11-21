#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJObjectDecoder : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "GJObjectDecoder";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJObjectDecoder, cocos2d::CCNode)
    
private:
    [[deprecated("GJObjectDecoder::sharedDecoder not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x62d42c
     * @note[short] Android
     */
    static GJObjectDecoder* sharedDecoder();
public:
    
private:
    [[deprecated("GJObjectDecoder::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x62d4d4
     * @note[short] MacOS (Intel): 0x70e560
     * @note[short] iOS: 0x217784
     * @note[short] Android
     */
    virtual bool init();
public:

    /**
     * @note[short] MacOS (ARM): 0x62d4d8
     * @note[short] MacOS (Intel): 0x70e570
     * @note[short] Windows: 0x27c730
     * @note[short] iOS: 0x217788
     * @note[short] Android
     */
    virtual cocos2d::CCObject* getDecodedObject(int p0, DS_Dictionary* p1);
};
