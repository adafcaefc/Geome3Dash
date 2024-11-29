#pragma once

#include <vector>

#include "helper/Easing.h"

namespace g3d
{
    struct CameraAction
    {
        double x, y, z;         // Position
        double yaw, pitch;      // Rotation
        double time;            // Duration of the action
        double triggerAt;       // Trigger when the x-position reaches this value
    };

    class CameraActionHandler
    {
    private:
        std::vector<CameraAction> actions; // List of actions
        double currentTime;                // Time tracker for animation
        size_t currentActionIndex;         // Current action being processed
        ease::Base* easing;       // Easing function used

        double interpolate(double start, double end, double progress);
    public:
        CameraActionHandler(ease::Base* easingP) : currentTime(0), currentActionIndex(0), easing(easingP) {}

        void addAction(const CameraAction& action) { actions.push_back(action); }
        double previousX = 0, previousY = 0, previousZ = 0, previousYaw = 0, previousPitch = 0;

        void update(double deltaTime, double currentXPosition,
            double& deltaX, double& deltaY, double& deltaZ,
            double& deltaYaw, double& deltaPitch);
    };
}