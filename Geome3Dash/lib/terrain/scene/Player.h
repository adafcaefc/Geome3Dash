#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <glm/gtc/matrix_transform.hpp>
#include "graphics/InputState.h"

// Repsonsible For Tracking the players movements
class Player {
private:
    float turnIncrement;
    float initPan;
    float initTilt;
    glm::vec3 initLocation;

    float pan; 
    float tilt;

    float GetPlayerHeight();

    void PanLeft();
    void PanRight();
    void TiltUp();
    void TiltDown();

    float getTurnIncrement();
    float getMoveIncrement();

    void resetAcceleration();

    float incrementMove;
    float incrementTurn;

public:
    glm::vec3 location;

    void MoveStraight(int dir);

    Player(glm::vec3 location, float pan, float tilt);
    void Reset();
    void Update(InputState userInput);

    void UpdateYPos(float y);
    glm::vec3 GetLocation3();
    glm::vec3 GetDirection3();
    float GetPan();
    float GetTilt();
};

#endif