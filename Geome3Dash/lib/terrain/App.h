#ifndef __APP_H_
#define __APP_H_

#include <glm/glm.hpp>

#include <vector>
#include "graphics/Shader.h"
#include "graphics/Viewer.h"
#include "scene/SceneComponent.h"
#include "scene/Terrain.h"
#include "scene/Player.h"
#include "scene/ObjInstanced.h"

/*
 The App class is Repsonsible Composing the program and 
 Drawing the scene
 */
class App {
public:
    App(int winX, int winY, int argc);

    void Render();
    void Key_callback(int key, int action);
    void MouseBtn_callback(int button, int action);
    void MouseMove_callback(double x, double y);
    void SetWindowSize(int x, int y);

    Player* player;


private:
    int winX, winY;

    std::vector<SceneComponent*> sceneComponents;
    Terrain* terrain;


    InputState userInput;

    void loadSceneComponents();
    
    glm::mat4 projection;
    void updateProjection();

    glm::vec3 GetGroundPos(float x, float yOff, float z);
    std::vector<InstanceParams*> MakeTreeInstances(int instanceCount, glm::vec3 location, glm::vec3 size, float minSize, int axisDir);
    std::vector<InstanceParams*> MakeTreeInstances(int instanceCount, glm::vec3 location, glm::vec3 size, glm::vec3 rotate, float minSize, int axisDir);
    void AddComp(SceneComponent* comp);

    Viewer *Camera;
    ObjectViewer *CamFirstPersion;
    TopObjectViewer *CamTopView;
};

#endif
