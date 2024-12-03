#ifndef _OBJSINGLE_H_
#define _OBJSINGLE_H_

#include <string>
#include <glm/glm.hpp>
#include "graphics/ObjContainer.h"
#include "graphics/Shader.h"
#include "graphics/Viewer.h"
#include "scene/SceneComponent.h"

class ObjSingle : public SceneComponent
{
private:
    float scale;
    glm::vec3 location;
    const char* fname;
    Shader* shader;
    Viewer** camera;
    ObjContainer* objContainer;
public:
    ObjSingle(float scale, glm::vec3 location, std::string fname, Viewer** camera);
    void onSetup();
    void render(glm::mat4 viewMtx, glm::mat4 projectionMtx);
    void drawObject(ObjContainer* obj, Shader* shader);
};

#endif