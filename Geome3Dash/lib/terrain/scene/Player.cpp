#include <cmath>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "scene/Player.h"
#include "utils/Logger.h"
#include "utils/Time.h"

Player::Player(glm::vec3 location, float pan, float tilt)
{
    this->initLocation = location;
    this->initPan = pan;
    this->initTilt = tilt;
    this->Reset();
}

void Player::Reset() {
    this->location = this->initLocation;//glm::vec3(0, 1.f, -5.f);
    this->pan = this->initPan;//90;
    this->tilt = this->initTilt;//90;
}

void Player::Update(InputState userInput) 
{
    int dir = userInput.GetMove();
    switch (dir) 
    {
        case MOVE_FORWARD:
            MoveStraight(MOVE_FORWARD);
            break;
        case MOVE_BACKWARD:
            MoveStraight(MOVE_BACKWARD);
            break;
        case MOVE_LEFT:
            PanLeft();
            break;
        case MOVE_RIGHT:
            PanRight();
            break;
        case MOVE_TILTUP:
            TiltUp();
            break;
        case MOVE_TILTDOWN:
            TiltDown();
            break;
        case MOVE_LEFTFORWARD:
            PanLeft();
            MoveStraight(MOVE_FORWARD);
            break;
        case MOVE_LEFTBACKWARD:
            PanLeft();
            MoveStraight(MOVE_BACKWARD);
            break;
        case MOVE_RIGHTFORWARD:
            PanRight();
            MoveStraight(MOVE_FORWARD);
            break;
        case MOVE_RIGHTBACKWARD:
            PanRight();
            MoveStraight(MOVE_BACKWARD);
            break;
        case NOMOVE:
            resetAcceleration();
            break;
    }
}

void Player::MoveStraight(int moveDir) 
{
    float incr = this->getMoveIncrement();
    glm::vec3 playerDir = this->GetDirection3();
    glm::vec3 playerLoc = this->GetLocation3();
    if (moveDir == MOVE_FORWARD)
        this->location += playerDir * incr;
    if (moveDir == MOVE_BACKWARD)
        this->location -= playerDir * incr;
}

float Player::GetPlayerHeight()
{
    static double startTime = Time::getTimeNow();
    double nowTime = startTime - Time::getTimeNow();
    return 1+0.04f*sin(nowTime);
}

void Player::resetAcceleration() 
{
    this->incrementMove = 0;
    this->incrementTurn = 0;
}

float Player::getMoveIncrement() 
{
    static float incrementMax = 0.15f;
    static float incrementStep = 0.02f;
    if (incrementMove < incrementMax)
        incrementMove += incrementStep;
    else
        incrementMove = incrementMax;
    return incrementMove;
}

float Player::getTurnIncrement() 
{
    static float incrementMax = 2.f;
    static float incrementStep = 0.1f;
    if (incrementTurn < incrementMax)
        incrementTurn += incrementStep;
    else
        incrementTurn = incrementMax;
    return incrementTurn;
}

// Move commands
void Player::PanLeft()
{
    this->pan -= this->getTurnIncrement();
    if (this->pan <= 0)
        this->pan = 360;
}
void Player::PanRight()
{
    this->pan += this->getTurnIncrement();
    if (this->pan >= 360)
        this->pan = 0;
}
void Player::TiltUp()
{
    this->tilt -= this->getTurnIncrement();
    if (this->tilt <= 30)
        this->tilt = 30;
}
void Player::TiltDown()
{
    this->tilt += this->getTurnIncrement();
    if (this->tilt >= 150)
        this->tilt = 150;
}

void Player::UpdateYPos(float y) 
{
    this->location.y = y;
}

// Getters
glm::vec3 Player::GetLocation3()
{
    return this->location;
}

glm::vec3 Player::GetDirection3()
{
    float pan = glm::radians(this->GetPan());
    float tilt = glm::radians(this->GetTilt());

    float camX = sin(tilt)*cos(pan);
    float camY = cos(tilt);
    float camZ = sin(tilt)*sin(pan);

    return glm::vec3(camX, camY, camZ);
}

float Player::GetPan()
{
    return this->pan;
}

float Player::GetTilt()
{
    return this->tilt;
}
