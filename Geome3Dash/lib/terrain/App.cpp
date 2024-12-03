#include <string>
#include <iostream>
#include <algorithm>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

#include <glm/gtc/matrix_transform.hpp>

#include "utils/Logger.h"
#include "utils/Random.h"
#include "App.h"

#include "scene/Skybox.h"
#include "scene/ObjSingle.h"
#include "scene/ObjInstanced.h"
#include "scene/MirrorBox.h"
#include "scene/Fire.h"
#include "scene/Fountain.h"
#include "scene/Terrain.h"

// Public API
App::App(int winX, int winY, int argc)
{
    this->SetWindowSize(winX, winY);
    float topViewHeight = 5.f;
    this->CamTopView = new TopObjectViewer(topViewHeight);
    this->CamFirstPersion = new ObjectViewer();
    this->Camera = this->CamFirstPersion;
    this->loadSceneComponents();
}

// 1. Flat landscape, load obj file (Tree)
// 2. Switchable camera First Person, World View
// 3. Multiple shaders; 
// TODO: 3.1 Multiple Lighting, sun, torches
// 4. Sky box
// 5. Environment box on mirror cube
// TODO: 6. Depth cue (fog)
// TODO: 7. Bump mapping, light mapping, parralax mapping
// 8. Generated terrain
// 8.1 Particle systems, water, fire
// 9. Height mapping
// TODO: 10. Alpha blending 
// 11. Sounds
// TODO: 12. Collision detection

std::vector<InstanceParams*> App::MakeTreeInstances(int instanceCount, glm::vec3 location, glm::vec3 size, float minSize, int axisDir) {
    return MakeTreeInstances(instanceCount, location, size, glm::vec3(0), minSize, axisDir);
}

std::vector<InstanceParams*> App::MakeTreeInstances(int instanceCount, glm::vec3 location, glm::vec3 size, glm::vec3 rotate, float minSize, int axisDir) {
    glm::vec3 limitsMin = location;
    glm::vec3 limitsMax = size + location;

    std::vector<InstanceParams*> instanceList;
    const int MAX_ITERATIONS = 1000;
    static int RAND_SEED = 2;
    for (int i = 0; i < MAX_ITERATIONS; ++i)
    {
        const float randX = Random::randomFloatSeeded(limitsMin.x, limitsMax.x, RAND_SEED++);
        const float randZ = Random::randomFloatSeeded(limitsMin.z, limitsMax.z, RAND_SEED++);
        float randSize = Random::randomFloatSeeded(minSize, size.y, RAND_SEED++);
        if (axisDir == X_DOWN)
            randSize = Random::randomFloatSeeded(minSize, size.x, RAND_SEED++);
        if (axisDir == Z_DOWN)
            randSize = Random::randomFloatSeeded(minSize, size.z, RAND_SEED++);
        glm::vec3 location = GetGroundPos(randX, -randSize*0.05, randZ);
        bool isInWater = location.y < -0.2;
        if (isInWater)
            continue;
        bool reachedLimit = instanceList.size() > instanceCount;
        if (reachedLimit)
            break;
        InstanceParams* instance = new InstanceParams();
        instance->location = location;
        instance->scale = glm::vec3(randSize);
        instance->rotation = rotate;

        instanceList.push_back(instance);
    }
    return instanceList;
}

glm::vec3 App::GetGroundPos(float x, float yOff, float z) 
{
    float terrainHeight = this->terrain->CalculateTerrainHeight(x, z);
    return glm::vec3(x, terrainHeight + yOff, z);
}

void App::AddComp(SceneComponent* comp)
{
    this->sceneComponents.push_back(comp);
}

void App::loadSceneComponents() 
{
    glEnable(GL_DEPTH_TEST);
    // Terrain
    float mapSize = 150;
    glm::vec3 terrainSize = glm::vec3(mapSize,10,mapSize);
    glm::ivec3 terrainGrid = glm::ivec3(50,0,50);
    glm::vec3 terrainLocation = glm::vec3(0,1,0) - terrainSize*0.5f; 
    glm::vec3 treesLocation = terrainLocation;
    glm::vec3 treesSize1 = terrainSize;
    treesSize1.y = 8;
    glm::vec3 treesSize2 = terrainSize;
    treesSize2.y = 12;

    this->terrain = new Terrain(terrainLocation, terrainSize, terrainGrid);
    AddComp(this->terrain);
    // Player
    this->player = new Player(GetGroundPos(7.8, 1, -23.3), 87.1, 90);
    // Barrel Fire
    std::string dir1 = "./res/models/";
    glm::vec3 fireBarrelLocation = GetGroundPos(7.6+3,0,-20);
    glm::vec3 fireLocation = fireBarrelLocation;
    fireLocation.y += 0.9;
    AddComp(new ObjSingle(1, fireBarrelLocation, dir1 + "Barrel/Barrel02.obj", &this->Camera));
    AddComp(new Fire(1.5, 0.9, 500, fireLocation));
    // Barrel Fountain
    glm::vec3 fountainBarrelLocation = GetGroundPos(7.6-2,0,-20);
    glm::vec3 fountainLocation = fountainBarrelLocation;
    fountainLocation.y += 0.8;
    AddComp(new ObjSingle(1, fountainBarrelLocation, dir1 + "Barrel/Barrel02.obj", &this->Camera));
    AddComp(new Fountain(1.5, 0.9, 500, fountainLocation));
    // Trees
    AddComp(new ObjInstanced(MakeTreeInstances(50, treesLocation, treesSize1, 6, Y_DOWN), dir1 + "tree/PineTree03.obj", Y_DOWN));
    AddComp(new ObjInstanced(MakeTreeInstances(70, treesLocation, treesSize2, 6, Y_DOWN), dir1 + "pine/PineTransp.obj", Y_DOWN));
    // AddComp(new ObjInstanced(MakeTreeInstances(30, treesLocation, treesSize2, 6, Y_DOWN), dir1 + "winterTree/tree.obj", Y_DOWN));
    // AddComp(new ObjInstanced(MakeTreeInstances(80, treesLocation, treesSize2, glm::vec3(glm::radians(-90.f),0,0), 1, X_DOWN), dir1 + "spruce/Spruce.obj", X_DOWN));

    std::string cubeMapDir = "./res/skyboxes/hangingstone/";
    glm::vec3 mirrorLocation(0, -mapSize, 0);
    AddComp(new MirrorBox(mapSize, mirrorLocation, &this->Camera, cubeMapDir));
    // Skybox must be last
    AddComp(new Skybox(cubeMapDir));
}

void App::Render() 
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    this->player->Update(userInput);

    glm::vec3 playerLocation = this->player->GetLocation3();
    this->Camera->updateFromPlayer(
        playerLocation + glm::vec3(200.f, 0, 0),
        this->player->GetDirection3()
    );
    glm::mat4 view = this->Camera->getViewMtx();

    float terrainHeight = GetGroundPos(playerLocation.x, 1, playerLocation.z).y;
    if (terrainHeight < 1)
        terrainHeight = 1;
    this->player->UpdateYPos(terrainHeight);

    int numComponents = this->sceneComponents.size();
    for (int i = 0; i < numComponents; ++i)
    {
        this->sceneComponents.at(i)->render(view, projection);
    }
    glFlush();
}

void App::MouseBtn_callback(int button, int action)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
        userInput.rMousePressed = true;
    else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
        userInput.rMousePressed = false;
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
        userInput.lMousePressed = true;
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
        userInput.lMousePressed = false;               
}

void App::MouseMove_callback(double x, double y)
{
    userInput.update(x, y);
}

void App::Key_callback(int key, int action)
{
    bool repeatPress = action == GLFW_PRESS || action == GLFW_REPEAT;
    bool singlePress = action == GLFW_PRESS;

    switch(key)
    {
        case GLFW_KEY_UP:
            userInput.setUp(repeatPress);
            break;
        case GLFW_KEY_DOWN:
            userInput.setDown(repeatPress);
            break;
        case GLFW_KEY_LEFT:
            userInput.setLeft(repeatPress);
            break;
        case GLFW_KEY_RIGHT:
            userInput.setRight(repeatPress);
            break;
        case GLFW_KEY_MINUS:
        case GLFW_KEY_KP_SUBTRACT:
            this->CamTopView->zoomOut();
            break;
        case GLFW_KEY_EQUAL:
        case GLFW_KEY_KP_ADD:
            this->CamTopView->zoomIn();
            break;
        case GLFW_KEY_U:
            userInput.setTiltUp(repeatPress);
            break;
        case GLFW_KEY_D:
            userInput.setTiltDown(repeatPress);
            break;
    }

    if (singlePress)
    {
        if (key == GLFW_KEY_1)
            this->Camera = this->CamFirstPersion;
        if (key == GLFW_KEY_2)
            this->Camera = this->CamTopView;
    }
}

void App::SetWindowSize(int x, int y)
{
    this->winX = x;
    this->winY = y;
    this->updateProjection();
}

// Private methods

void App::updateProjection()
{
    const float aspect = static_cast<float>(this->winX) / this->winY;    
    const float fov = 75;
    projection = glm::perspective(glm::radians(fov), aspect, 0.005f, 1000.0f);
}
