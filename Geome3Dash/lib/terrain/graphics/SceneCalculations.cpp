#include <vector>
#include <string>
#include <cmath>
#include <glm/glm.hpp>

#include "graphics/SceneCalculations.h"
#include "graphics/ObjContainer.h"
#include "utils/Logger.h"

glm::vec3 CalculateBoundingBoxTotal(std::vector<ObjContainer*> objList) 
{
    glm::vec3 totalExtents(0);
    for (int i = 0; i < objList.size(); ++i)
    {
        glm::vec3 size = objList[i]->GetObjSize();
        totalExtents.x += size.x;
        if(size.y > totalExtents.y)        
            totalExtents.y = size.y;
        if(size.z > totalExtents.z)        
            totalExtents.z = size.z;
    }
    return totalExtents;
}

float CalculateTotalScale(std::vector<ObjContainer*> objList) 
{
    glm::vec3 totalExtents = CalculateBoundingBoxTotal(objList);
    float length = glm::length(totalExtents);
    float MAX_LENGTH = 4.f;    
    float scale = MAX_LENGTH / length;
    return scale;
}


