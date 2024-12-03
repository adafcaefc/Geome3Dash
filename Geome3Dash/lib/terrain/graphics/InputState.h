/**
 A set of variables that records mouse activity.
 You can update the variables yourself or use the functions.
*/

#ifndef _INPUTSTATE_H_
#define _INPUTSTATE_H_

#include <glm/glm.hpp>
#include "utils/Logger.h"
#include <glm/gtc/matrix_transform.hpp>

enum keyMove {
    MOVE_LEFT,
    MOVE_LEFTFORWARD,
    MOVE_FORWARD,
    MOVE_RIGHTFORWARD,
    MOVE_RIGHT,
    MOVE_RIGHTBACKWARD,
    MOVE_BACKWARD,
    MOVE_LEFTBACKWARD,

    MOVE_TILTUP,
    MOVE_TILTDOWN,

    NOMOVE,
};

struct InputState
{    
    InputState(): 
        lMousePressed(false),
        rMousePressed(false),
        prevX(0), 
        prevY(0),
        deltaX(0), 
        deltaY(0) { }

    // Is the mouse button currently being held down?
    bool lMousePressed = false;
    bool rMousePressed = false;

    // Last known position of the cursor
    float prevX;
    float prevY;

    // Accumulated change in cursor position. 
    float deltaX;
    float deltaY;

    // Update cursor variables based on new position x,y
    void update(float x, float y)
    {
        float xDiff = x - prevX;
        float yDiff = y - prevY;
        deltaX += xDiff;
        deltaY += yDiff;
        prevX = x;
        prevY = y;
    };

    // Read off the accumulated motion and reset it
    void readDeltaAndReset(float *x, float *y)
    {
        *x = deltaX;
        *y = deltaY;
        deltaX = 0;
        deltaY = 0;
    };

    float GetRotationAngle() {
        float angle;
        if (stateLeft)
            angle = -1;
        else if (stateRight)
            angle = 1;
        else
            angle = 0;
        return angle;
    }

    glm::vec3 GetMoveDir() {
        glm::vec3 dir;
        if (stateUp)
            dir = glm::vec3(0,0,1);
        else if (stateDown)
            dir = glm::vec3(0,0,-1);
        else
            dir = glm::vec3(0,0,0);
        return dir;
    };

    int GetMove() {
        if (stateUp && stateLeft)
            return MOVE_LEFTFORWARD;
        if (stateDown && stateLeft)
            return MOVE_LEFTBACKWARD;

        if (stateUp && stateRight)
            return MOVE_RIGHTFORWARD;
        if (stateDown && stateRight)
            return MOVE_RIGHTBACKWARD;

        if (stateUp)
            return MOVE_FORWARD;
        if (stateDown)
            return MOVE_BACKWARD;
        if (stateLeft)
            return MOVE_LEFT;
        if (stateRight)
            return MOVE_RIGHT;

        if (stateTiltUp)
            return MOVE_TILTUP;
        if (stateTiltDown)
            return MOVE_TILTDOWN;

        return NOMOVE;
    };

    bool isMovePress() {
        return stateUp || stateDown || stateLeft || stateRight;
    };

    void setUp(bool state) {
        stateUp = state;
    };
    void setDown(bool state) {
        stateDown = state;
    };
    void setLeft(bool state) {
        stateLeft = state;
    };
    void setRight(bool state) {
        stateRight = state;
    };
    void setTiltUp(bool state) {
        stateTiltUp = state;
    };
    void setTiltDown(bool state) {
        stateTiltDown = state;
    };

private:
    bool stateUp = false;
    bool stateDown = false;
    bool stateLeft = false;
    bool stateRight = false;
    bool stateTiltUp = false;
    bool stateTiltDown = false;
};

#endif // _INPUTSTATE_H_
