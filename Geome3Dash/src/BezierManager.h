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
        static void clearCache();
    };
}