#include "pch.h"

#include "BezierHelper.h"

#include <cmath>
#include <vector>
#include <sstream>
#include <numbers>
#include <regex>

namespace g3d
{
    // Helper function to compute the distance between two points
    double distance(double x1, double y1, double x2, double y2) {
        return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

    // Function to compute cumulative arc lengths for uniform sampling
    void computeArcLengths(
        double x0, double y0,
        double cx1, double cy1,
        double cx2, double cy2,
        double x1, double y1,
        std::vector<double>& arcLengths,
        int segments)
    {
        arcLengths.clear();
        arcLengths.push_back(0.0);

        double prevX = x0, prevY = y0;
        for (int i = 1; i <= segments; ++i) {
            double t = static_cast<double>(i) / segments;
            double oneMinusT = 1.0 - t;

            double currX = std::pow(oneMinusT, 3) * x0
                + 3 * std::pow(oneMinusT, 2) * t * cx1
                + 3 * oneMinusT * std::pow(t, 2) * cx2
                + std::pow(t, 3) * x1;

            double currY = std::pow(oneMinusT, 3) * y0
                + 3 * std::pow(oneMinusT, 2) * t * cy1
                + 3 * oneMinusT * std::pow(t, 2) * cy2
                + std::pow(t, 3) * y1;

            arcLengths.push_back(arcLengths.back() + distance(prevX, prevY, currX, currY));
            prevX = currX;
            prevY = currY;
        }
    }

    // Function to evaluate Bézier curve at uniform intervals
    void evaluateCubicBezierUniform(
        double t,
        double x0, double y0,
        double cx1, double cy1,
        double cx2, double cy2,
        double x1, double y1,
        double& x, double& y, double& rotation,
        const std::vector<double>& arcLengths)
    {
        // Map t [0,1] to the cumulative arc length
        double targetLength = t * arcLengths.back();

        // Find the corresponding t using binary search
        auto it = std::lower_bound(arcLengths.begin(), arcLengths.end(), targetLength);
        int index = std::distance(arcLengths.begin(), it);
        if (index > 0) {
            double t0 = static_cast<double>(index - 1) / (arcLengths.size() - 1);
            double t1 = static_cast<double>(index) / (arcLengths.size() - 1);

            double l0 = arcLengths[index - 1];
            double l1 = arcLengths[index];

            t = t0 + (t1 - t0) * (targetLength - l0) / (l1 - l0);
        }

        // Evaluate position and rotation
        double oneMinusT = 1.0 - t;

        // Calculate x and y position
        x = std::pow(oneMinusT, 3) * x0
            + 3 * std::pow(oneMinusT, 2) * t * cx1
            + 3 * oneMinusT * std::pow(t, 2) * cx2
            + std::pow(t, 3) * x1;

        y = std::pow(oneMinusT, 3) * y0
            + 3 * std::pow(oneMinusT, 2) * t * cy1
            + 3 * oneMinusT * std::pow(t, 2) * cy2
            + std::pow(t, 3) * y1;

        // Calculate the derivative for rotation
        double dx = -3 * std::pow(oneMinusT, 2) * x0
            + 3 * (std::pow(oneMinusT, 2) - 2 * oneMinusT * t) * cx1
            + 3 * (2 * t * oneMinusT - std::pow(t, 2)) * cx2
            + 3 * std::pow(t, 2) * x1;

        double dy = -3 * std::pow(oneMinusT, 2) * y0
            + 3 * (std::pow(oneMinusT, 2) - 2 * oneMinusT * t) * cy1
            + 3 * (2 * t * oneMinusT - std::pow(t, 2)) * cy2
            + 3 * std::pow(t, 2) * y1;

        if (dx == 0.0 && dy == 0.0) {
            rotation = 0.0; // Default rotation if derivative is zero
        }
        else {
            rotation = std::atan2(dy, dx);
        }
    }


    // Function to evaluate a cubic Bezier curve at a given t (0 <= t <= 1)
    void evaluateCubicBezier(
        double t,
        double x0, double y0,
        double cx1, double cy1,
        double cx2, double cy2,
        double x1, double y1,
        double& x, double& y, double& rotation)
    {
        double oneMinusT = 1.0 - t;

        // Calculate x and y position
        x = std::pow(oneMinusT, 3) * x0
            + 3 * std::pow(oneMinusT, 2) * t * cx1
            + 3 * oneMinusT * std::pow(t, 2) * cx2
            + std::pow(t, 3) * x1;

        y = std::pow(oneMinusT, 3) * y0
            + 3 * std::pow(oneMinusT, 2) * t * cy1
            + 3 * oneMinusT * std::pow(t, 2) * cy2
            + std::pow(t, 3) * y1;

        // Calculate the derivative for rotation
        double dx = -3 * std::pow(oneMinusT, 2) * x0
            + 3 * (std::pow(oneMinusT, 2) - 2 * oneMinusT * t) * cx1
            + 3 * (2 * t * oneMinusT - std::pow(t, 2)) * cx2
            + 3 * std::pow(t, 2) * x1;

        double dy = -3 * std::pow(oneMinusT, 2) * y0
            + 3 * (std::pow(oneMinusT, 2) - 2 * oneMinusT * t) * cy1
            + 3 * (2 * t * oneMinusT - std::pow(t, 2)) * cy2
            + 3 * std::pow(t, 2) * y1;

        if (dx == 0.0 && dy == 0.0) {
            rotation = 0.0; // Default rotation if derivative is zero
        }
        else {
            rotation = std::atan2(dy, dx);
        }
    }
}