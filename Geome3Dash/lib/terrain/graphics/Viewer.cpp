#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>

#include "graphics/Viewer.h"
#include <glm/gtc/matrix_transform.hpp>
#include "utils/Logger.h"

/**
 Assumes the current matrix has been calculated (usually in 
 update() or reset())
*/
glm::mat4 Viewer::getViewMtx()
{
    return viewMtx;
}

void ObjectViewer::updateFromPlayer(glm::vec3 location, glm::vec3 direction) 
{
    Position = location;
    viewMtx = glm::mat4(0);
    glm::vec3 up(0.0f, 1.0f, 0.0f);
    glm::vec3 target = location + direction;
    viewMtx = glm::lookAt(location, target, up);
}

// Overhead Viewer

TopObjectViewer::TopObjectViewer(float height)
{
    this->height = height;
}

void TopObjectViewer::updateFromPlayer(glm::vec3 location, glm::vec3 direction) 
{
    viewMtx = glm::mat4(0);
    glm::vec3 up = direction;
    glm::vec3 target(location + glm::vec3(0,-100,0)); // Always looking down
    glm::vec3 locationAbove = location + glm::vec3(0,this->height,0);
    Position = locationAbove;
    viewMtx = glm::lookAt(locationAbove, target, up);
}

void TopObjectViewer::zoomIn()
{
    this->height -= 0.2f;    
}

void TopObjectViewer::zoomOut()
{
    this->height += 0.2f;    
}
