#include "scene/ObjInstanced.h"
#include "utils/Logger.h"

ObjInstanced::ObjInstanced(std::vector<InstanceParams*> instanceList, std::string fname, int downAxis)
{
    this->instanceList = instanceList;
    this->fname = fname.c_str();
    this->downAxis = downAxis;
    this->onSetup();
}

void ObjInstanced::onSetup() {
    this->objContainer = new ObjContainer((char*) this->fname);
    this->shader = new Shader("res/shaders/objinstanced.vert","res/shaders/objinstanced.frag");
}

void ObjInstanced::render(glm::mat4 viewMtx, glm::mat4 projectionMtx) {
    // Set common uniforms
    this->shader->use();
    shader->setMat4("view", viewMtx);
    shader->setMat4("projection", projectionMtx);

    ObjContainer* obj = this->objContainer;
    // Align to top or bottom
    float align = 1; // align bottom = 1, align top = -1
    glm::vec3 objSize = obj->GetObjSize();
    float objHeight = objSize.y;
    if (this->downAxis == X_DOWN)
        objHeight = objSize.x;
    if (this->downAxis == Z_DOWN)
        objHeight = objSize.z;
    // Set model matrix
    glm::mat4 modelM(1.f);
    modelM = glm::translate(modelM, -obj->GetOffsetCenter());
    modelM = glm::translate(modelM, glm::vec3(0, align * objHeight/2, 0));
    shader->setMat4("model", modelM);
    // Draw object
    int count = this->instanceList.size();
    for (int i = 0; i < count; ++i)
    {
        InstanceParams* instance = this->instanceList.at(i);
        float normalizeScale = instance->scale.y / objHeight;
        // Set world matrix
        glm::mat4 world(1.f);
        world = glm::translate(world, instance->location);
        world = glm::scale(world, glm::vec3(normalizeScale));
        world = glm::rotate(world, instance->rotation.x, glm::vec3(1,0,0));
        world = glm::rotate(world, instance->rotation.y, glm::vec3(0,1,0));
        world = glm::rotate(world, instance->rotation.z, glm::vec3(0,0,1));
        shader->setMat4("world", world);
        // draw 
        this->drawObject(obj, this->shader);
    }
}

void ObjInstanced::drawObject(ObjContainer* obj, Shader* shader) 
{
    int numShapes = obj->shapes.size();
    for (int i = 0; i < numShapes; ++i)
    {
        Shape currentShape = obj->shapes[i];
        shader->setInt("material.texture", 0);
        shader->EnableTexture(currentShape.textureDiffuseId);
        currentShape.DrawShape();
    }
}

