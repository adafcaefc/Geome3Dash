#ifndef _FIRE_H_
#define _FIRE_H_

#include <glm/glm.hpp>
#include "graphics/ObjContainer.h"
#include "graphics/Shader.h"
#include "scene/SceneComponent.h"
#include "utils/Random.h"

struct FireParticle
{
private:
    const int minLife = 30;
    const int maxLife = 100;
    const float minSpeed = 1;
    const float maxSpeed = 2;

public:
    int life = 10;
    int age = 0;
    float speed = 0;
    float temperature = 0;
    float initx = 0;
    float initz = 0;
    float variance = 0;

    void respawn() {
        this->life = Random::randomFloat(this->minLife, this->maxLife);
        this->age = Random::randomFloat(0, this->life);
        this->speed = Random::randomFloat(this->minSpeed, this->maxSpeed);
        this->temperature = Random::randomFloat(0, 1);
        this->initx = Random::randomFloat(-1, 1);
        this->initz = Random::randomFloat(-1, 1);
        this->variance = Random::randomFloat(-1, 1);
    }
    int maxDist = this->maxLife * this->maxSpeed;
};

class Fire : public SceneComponent
{
private:
    float scale;
    glm::vec3 location;
    Shader* shader;
    unsigned int cubeVAO, cubeVBO;
    FireParticle* particles;
    int particleCount;
    float fireHeight = 1;
    float fireWidth = 1;

public:
    Fire(float fireHeight, float fireWidth, int particleCount, glm::vec3 location);
    void onSetup();
    void render(glm::mat4 viewMtx, glm::mat4 projectionMtx);
    void drawObject();
};

#endif