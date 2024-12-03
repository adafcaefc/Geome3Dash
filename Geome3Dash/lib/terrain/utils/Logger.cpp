#include <string>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "utils/Logger.h"
#include "graphics/ObjContainer.h"

void Print(std::string vecName, glm::mat4 mat) 
{
    std::cout << vecName << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            std::cout << mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Print(std::string vecName, glm::vec3 vec) 
{
    std::cout << vecName << vec.x << ", " << vec.y << ", " << vec.z << std::endl;
}

void Print(std::string vecName, glm::vec2 vec) 
{
    std::cout << vecName << vec.x << ", " << vec.y << std::endl;
}

void Print(std::string vecName, float vec) 
{
    std::cout << vecName << vec << std::endl;
}

void Print(std::string vecName) 
{
    std::cout << vecName << std::endl;
}

void PrintObjFileInfo(ObjContainer* newObj) 
{
    glm::vec3 offset = newObj->GetOffsetCenter();
    glm::vec3 size = newObj->GetObjSize();
    std::cout << "----------------------------------------------------- " << std::endl;
    std::cout << "   Reading obj file: " << newObj->FilePath << std::endl;
    std::cout << "----------------------------------------------------- " << std::endl;
    Print("     Obj Dimensions: ", size);
    Print("  Obj Offset Center: ", offset);
}
