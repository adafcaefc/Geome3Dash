#pragma once

namespace g3d
{
    struct CubicBezier {
        double x0, y0;  // Start point
        double cx1, cy1; // First control point
        double cx2, cy2; // Second control point
        double x1, y1;  // End point
    };

    void evaluateCubicBezier(
        double t,
        double x0, double y0,
        double cx1, double cy1,
        double cx2, double cy2,
        double x1, double y1,
        double& x, double& y, double& rotation);

    std::vector<CubicBezier> parseSVGPath(const std::string& svgString);
    std::vector<std::string> tokenizePathData(const std::string& pathData);

    void computeArcLengths(
        double x0, double y0,
        double cx1, double cy1,
        double cx2, double cy2,
        double x1, double y1,
        std::vector<double>& arcLengths,
        int segments);

    void evaluateCubicBezierUniform(
        double t,
        double x0, double y0,
        double cx1, double cy1,
        double cx2, double cy2,
        double x1, double y1,
        double& x, double& y, double& rotation,
        const std::vector<double>& arcLengths);
}