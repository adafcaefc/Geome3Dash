#include <cmath>
#include "scene/Fountain.h"
#include "utils/Logger.h"
#include "utils/Random.h"

#define M_PI 3.14159265359

Fountain::Fountain(float fountainHeight, float fountainWidth, int particleCount, glm::vec3 location)
{
    this->particleCount = particleCount;
    this->fountainHeight = fountainHeight;
    this->fountainWidth = fountainWidth;    
    this->location = location;
    this->onSetup();    
}

void Fountain::onSetup() {
    float cubeVertices[] = {
        // positions          // normals
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };
    // cube VAO
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &cubeVBO);
    glBindVertexArray(cubeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), &cubeVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * SceneComponent::FLOAT_SIZE, (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * SceneComponent::FLOAT_SIZE, (void*)(3 * SceneComponent::FLOAT_SIZE));

    this->shader = new Shader("res/shaders/fire.vert","res/shaders/fire.frag");
    this->particles = new FountainParticle[particleCount];
}

void Fountain::render(glm::mat4 viewMtx, glm::mat4 projectionMtx) {
    // Set common uniforms
    this->shader->use();
    shader->setMat4("view", viewMtx);
    shader->setMat4("projection", projectionMtx);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glm::mat4 modelM;
    // Move to side
    modelM = glm::mat4(1.f);
    modelM = glm::translate(modelM, this->location);
    shader->setMat4("model", modelM);
    // Draw fountain
    float initScale = 0.1;
    static double time = 0;
    time++;
    float x = time/30;
    float currentHeight = this->fountainHeight * (1 + 0.05*Random::wave2(x));
    float currentWidth = this->fountainWidth * (1 + 0.05*Random::wave2(x));
    for (int i = 0; i < this->particleCount; ++i)
    {
        FountainParticle *p = &this->particles[i];
        p->age = p->age + 1;
        if (p->age == p->life)
            p->respawn();

        float percentAge = static_cast<float>(p->age) / static_cast<float>(p->life);
        float percentHeight = sin(percentAge * M_PI);
        float particleScale = initScale * (1-percentAge);

        float yLoc = currentHeight * percentHeight;
        float maxRadius = currentWidth * percentAge;
        float xLoc = p->initx * maxRadius;
        float zLoc = p->initz * maxRadius;
        glm::mat4 varianceM(1.0f);
        varianceM = glm::translate(varianceM, glm::vec3(xLoc, yLoc, zLoc));
        varianceM = glm::scale(varianceM, glm::vec3(particleScale));
        float randAngle = M_PI * p->variance;
        varianceM = glm::rotate(varianceM, randAngle, glm::vec3(randAngle, randAngle, randAngle));
        shader->setMat4("variance", varianceM);

        // Calculate randomish colour
        float percentFromCenter = glm::length(glm::vec2(xLoc, zLoc)) / maxRadius;
        glm::vec3 darkBlue = glm::vec3(0.05, 0.05, 0.4);
        glm::vec3 white = glm::vec3(1);
        glm::vec3 blue = glm::vec3(0.02, 0.02, 1);
        glm::vec3 colour;
        colour = glm::mix(white, darkBlue, 0.1*percentHeight + 0.1*p->temperature + 0.8*percentFromCenter);
        colour = glm::mix(colour, blue, 0.8*percentHeight + 0.2*percentAge);
        shader->setVec3("colour", colour);
        this->drawObject();
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Fountain::drawObject() 
{
    // cubes
    glBindVertexArray(cubeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}

