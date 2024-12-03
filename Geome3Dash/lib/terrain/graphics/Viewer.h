
/**
 Some viewer classes representing cameras that fixate on an object.
 All viewers inherit from a base Viewer class.
 See model-view.cpp for example usage.
 Anthony Dick
*/

#ifndef _VIEWER_H_
#define _VIEWER_H_

#include "graphics/InputState.h"
#include <glm/glm.hpp>

/**
 The base Viewer class stores a current view transformation.
 It is initialised by providing an initial camera position.
 Assumes we are always looking at the origin.
 It is updated in response to user input or it can be reset.
 Method orthogonaliseViewMtx() can be used to correct drift if needed.
*/
class Viewer 
{
protected:
    glm::mat4 viewMtx;

public:
    virtual void updateFromPlayer(glm::vec3 location, glm::vec3 direction) = 0;
    glm::mat4 getViewMtx();
    glm::vec3 Position;
};


class ObjectViewer : public Viewer
{
private:
    float velocity;
public:
    void updateFromPlayer(glm::vec3 location, glm::vec3 direction);
};


class TopObjectViewer : public Viewer
{
private:
    float height;
public:
    void zoomIn();
    void zoomOut();
    TopObjectViewer(float height);
    void updateFromPlayer(glm::vec3 location, glm::vec3 direction);
};







#endif // VIEWER_H
