#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJMPDelegate {
public:
    static constexpr auto CLASS_NAME = "GJMPDelegate";
    
private:
    [[deprecated("GJMPDelegate::joinLobbyFinished not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void joinLobbyFinished(int p0);
public:
    
private:
    [[deprecated("GJMPDelegate::joinLobbyFailed not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void joinLobbyFailed(int p0, GJMPErrorCode p1);
public:
    
private:
    [[deprecated("GJMPDelegate::didUploadMPComment not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void didUploadMPComment(int p0);
public:
    
private:
    [[deprecated("GJMPDelegate::updateComments not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void updateComments();
public:
};
