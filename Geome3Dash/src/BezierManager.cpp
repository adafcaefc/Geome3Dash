#include "pch.h"

#include "BezierManager.h"

#include <numeric>
#include <vector>
#include <unordered_map>

namespace g3d
{
    std::size_t hashCubicBezier(const CubicBezier& bezier)
    {
        return std::hash<double>{}(bezier.x0) ^
            (std::hash<double>{}(bezier.y0) << 1) ^
            (std::hash<double>{}(bezier.cx1) << 2) ^
            (std::hash<double>{}(bezier.cy1) << 3) ^
            (std::hash<double>{}(bezier.cx2) << 4) ^
            (std::hash<double>{}(bezier.cy2) << 5) ^
            (std::hash<double>{}(bezier.x1) << 6) ^
            (std::hash<double>{}(bezier.y1) << 7);
    }

    static std::unordered_map<size_t, std::pair<std::vector<double>, double>> arcLengths;

    void BezierManager::clearCache() { arcLengths.clear(); }

    void BezierManager::computeBezierCoordinateSegments(const CubicBezier& segment, const int segmentCount)
    {
        const auto chash = hashCubicBezier(segment);
        if (arcLengths.find(chash) == arcLengths.end())
        {
            arcLengths[chash] = std::pair<std::vector<double>, double>();
            computeArcLengths(
                segment.x0, segment.y0,
                segment.cx1, segment.cy1,
                segment.cx2, segment.cy2,
                segment.x1, segment.y1,
                arcLengths.at(chash).first, segmentCount);
            arcLengths.at(chash).second = std::accumulate(
                arcLengths.at(chash).first.begin(),
                arcLengths.at(chash).first.end(),
                0.0);
        }
    }

    BezierCoordinate BezierManager::transformIntoBezierCoordinate(
        const CubicBezier& segment,
        double x, double y, double z,
        const int segmentCount, const double segmentMultiplier)
    {
        const auto chash = hashCubicBezier(segment);
        computeBezierCoordinateSegments(segment, segmentCount);

        double t = x / arcLengths.at(chash).second * SCARY_CONSTANT_THAT_I_DONT_WANNA_TOUCH * static_cast<double>(segmentCount) * segmentMultiplier;
        CubicBezier segmentCopy = segment;

        if (t > 1)
        {
            double mrt = std::fmod(t, 1.0);
            double art = t - mrt;
            t = mrt;
            double tmpx1 = art * (segment.x1 - segment.x0);
            double tmpy1 = art * (segment.y1 - segment.y0);
            segmentCopy =
            {
                tmpx1 + segment.x0, tmpy1 + segment.y0,
                tmpx1 + segment.cx1, tmpy1 + segment.cy1,
                tmpx1 + segment.cx2, tmpy1 + segment.cy2,
                tmpx1 + segment.x1, tmpy1 + segment.y1,
            };
        }

        // First, we need to evaluate the Bezier curve for X and Z axis
        double bezierX = 0.0, bezierZ = 0.0, rotationY = 0.0;

        const auto chashcopy = hashCubicBezier(segmentCopy);

        computeBezierCoordinateSegments(segmentCopy, segmentCount);
        evaluateCubicBezierUniform(
            t,
            segmentCopy.x0, segmentCopy.y0,
            segmentCopy.cx1, segmentCopy.cy1,
            segmentCopy.cx2, segmentCopy.cy2,
            segmentCopy.x1, segmentCopy.y1,
            bezierX, bezierZ, rotationY,
            arcLengths.at(chashcopy).first);

        return { glm::vec3(bezierX / segmentMultiplier, y, bezierZ / segmentMultiplier), glm::degrees(rotationY) };  // Since y is not involved in the Bezier curve transformation, it remains unchanged
    }


    BezierCoordinate BezierManager::transformMultiIntoBezierCoordinate(
        const std::vector<CubicBezier>& segments,
        double x, double y, double z,
        const int segmentCount, const double segmentMultiplier)
    {
        const auto chash = hashCubicBezier(segment);
        computeBezierCoordinateSegments(segment, segmentCount);
       
        double t = x / arcLengths.at(chash).second * SCARY_CONSTANT_THAT_I_DONT_WANNA_TOUCH * static_cast<double>(segmentCount) * segmentMultiplier;
        CubicBezier segmentCopy = segment;

        if (t > 1)
        {
            double mrt = std::fmod(t, 1.0);
            double art = t - mrt;
            t = mrt;
            double tmpx1 = art * (segment.x1 - segment.x0);
            double tmpy1 = art * (segment.y1 - segment.y0);
            segmentCopy =
            {
                tmpx1 + segment.x0, tmpy1 + segment.y0,
                tmpx1 + segment.cx1, tmpy1 + segment.cy1,
                tmpx1 + segment.cx2, tmpy1 + segment.cy2,
                tmpx1 + segment.x1, tmpy1 + segment.y1,
            };
        }

        // First, we need to evaluate the Bezier curve for X and Z axis
        double bezierX = 0.0, bezierZ = 0.0, rotationY = 0.0;

        const auto chashcopy = hashCubicBezier(segmentCopy);

        computeBezierCoordinateSegments(segmentCopy, segmentCount);
        evaluateCubicBezierUniform(
            t,
            segmentCopy.x0, segmentCopy.y0,
            segmentCopy.cx1, segmentCopy.cy1,
            segmentCopy.cx2, segmentCopy.cy2,
            segmentCopy.x1, segmentCopy.y1,
            bezierX, bezierZ, rotationY,
            arcLengths.at(chashcopy).first);

        return { glm::vec3(bezierX / segmentMultiplier, y, bezierZ / segmentMultiplier), glm::degrees(rotationY) };  // Since y is not involved in the Bezier curve transformation, it remains unchanged
    }
}