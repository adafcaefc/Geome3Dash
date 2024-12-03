#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "graphics/ObjContainer.h"

void Print(std::string vecName, glm::mat4 mat);
void Print(std::string vecName, glm::vec3 vec);
void Print(std::string vecName, glm::vec2 vec);
void Print(std::string vecName, float vec);
void Print(std::string vecName);
void PrintObjFileInfo(ObjContainer* newObj);

#endif