#ifndef _SCENE_COMPONENT_H_
#define _SCENE_COMPONENT_H_

#include <glm/glm.hpp>

enum alignment 
{
    ALIGN_BOTTOM,
    ALIGN_TOP
};

// Repsonsible For Tracking the players movements
class SceneComponent 
{
protected:
    glm::vec3 camPos;
    
public:
    virtual void onSetup() = 0;
    virtual void render(glm::mat4 viewMtx, glm::mat4 projectionMtx) = 0;
    void setCamPosition(glm::vec3 camPos);

    static const int FLOAT_SIZE = sizeof(float);
};

#endif