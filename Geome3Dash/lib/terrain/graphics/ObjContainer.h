#ifndef _OBJ_CONTAINER_
#define _OBJ_CONTAINER_

#include <vector>

#include <glm/glm.hpp>
#include "graphics/Shape.h"
#include "graphics/Shader.h"

class ObjContainer
{

public:
    ObjContainer(char* objFilePath);
    ~ObjContainer();

    float GetBiggestLength();
    glm::vec3 GetOffsetCenter();
    glm::vec3 GetObjSize();

    char* FilePath;
    std::vector<Shape> shapes;

private:
    void loadModel(char* filePath);
    int loadTexture(std::string diffuse_texname);

    glm::vec3 maxExtents;
    glm::vec3 minExtents;

    void checkMaxExtents(float x, float y, float z);
    void checkMinExtents(float x, float y, float z);

    glm::vec3 objSize;
};

#endif