#ifndef _SCENECALCULATIONS_H_
#define _SCENECALCULATIONS_H_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "graphics/ObjContainer.h"

glm::vec3 CalculateBoundingBoxTotal(std::vector<ObjContainer*> objList);
float CalculateTotalScale(std::vector<ObjContainer*> objList);
glm::vec3 GetRotatingPosition();

#endif
