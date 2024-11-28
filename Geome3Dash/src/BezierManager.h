#pragma once

#include "Helper/BezierHelper.h"

namespace g3d
{
    struct BezierCoordinate
    {
        glm::vec3 position;
        double rotation;
    };

    struct BezierManager
    {
        static void computeBezierCoordinateSegments(const CubicBezier& segment, const int segmentCount);
        static BezierCoordinate transformIntoBezierCoordinate(
            const CubicBezier& segment,
            double x, double y, double z,
            const int segmentCount, const double segmentMultiplier);
        static BezierCoordinate transformMultiIntoBezierCoordinate(
            const std::vector<CubicBezier>& segments,
            double x, double y, double z,
            const int segmentCount, const double segmentMultiplier);
        static void clearCache();
        static constexpr double SCARY_CONSTANT_THAT_I_DONT_WANNA_TOUCH = 0.46080857142;
    };
}