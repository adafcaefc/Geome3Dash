#include "pch.h"

#include "CocosShaderProgram.h"

namespace g3d
{
    void CocosShaderProgram::setBasicUniforms() {
        auto screenSize = CCDirector::sharedDirector()->getWinSize();
        float screenWidth = screenSize.width;
        float screenHeight = screenSize.height;
        float time = CCDirector::sharedDirector()->getTotalFrames() * CCDirector::sharedDirector()->getAnimationInterval();

        setVec2("iResolution", glm::vec2(screenWidth, screenHeight));
        setFloat("iTime", time);
    }
}