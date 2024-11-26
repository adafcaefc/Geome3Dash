#pragma once

namespace g3d
{
    struct CubicBezier {
        double x0, y0;  // Start point
        double cx1, cy1; // First control point
        double cx2, cy2; // Second control point
        double x1, y1;  // End point
        // Equality operator for comparison
        bool operator==(const CubicBezier& other) const {
            return x0 == other.x0 && y0 == other.y0 &&
                cx1 == other.cx1 && cy1 == other.cy1 &&
                cx2 == other.cx2 && cy2 == other.cy2 &&
                x1 == other.x1 && y1 == other.y1;
        }
    };

    struct CubicBezierHash {
        std::size_t operator()(const CubicBezier& bezier) const {
            std::size_t h1 = std::hash<double>{}(bezier.x0);
            std::size_t h2 = std::hash<double>{}(bezier.y0);
            std::size_t h3 = std::hash<double>{}(bezier.cx1);
            std::size_t h4 = std::hash<double>{}(bezier.cy1);
            std::size_t h5 = std::hash<double>{}(bezier.cx2);
            std::size_t h6 = std::hash<double>{}(bezier.cy2);
            std::size_t h7 = std::hash<double>{}(bezier.x1);
            std::size_t h8 = std::hash<double>{}(bezier.y1);

            // Combine the hash values
            std::size_t result = h1;
            result ^= h2 + 0x9e3779b9 + (result << 6) + (result >> 2);
            result ^= h3 + 0x9e3779b9 + (result << 6) + (result >> 2);
            result ^= h4 + 0x9e3779b9 + (result << 6) + (result >> 2);
            result ^= h5 + 0x9e3779b9 + (result << 6) + (result >> 2);
            result ^= h6 + 0x9e3779b9 + (result << 6) + (result >> 2);
            result ^= h7 + 0x9e3779b9 + (result << 6) + (result >> 2);
            result ^= h8 + 0x9e3779b9 + (result << 6) + (result >> 2);

            return result;
        }
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