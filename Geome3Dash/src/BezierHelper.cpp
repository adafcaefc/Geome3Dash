#include "pch.h"
#include "../pch.h"
#include "BezierHelper.h"

#include <cmath>
#include <vector>
#include <sstream>
#include <numbers>
#include <regex>

namespace g3d
{
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

    // Function to split the path data into tokens
    std::vector<std::string> tokenizePathData(const std::string& pathData) {
        std::vector<std::string> tokens;
        std::regex tokenRegex(R"([a-zA-Z]|-?\d*\.?\d+(?:e[-+]?\d+)?)");
        std::sregex_iterator begin(pathData.begin(), pathData.end(), tokenRegex);
        std::sregex_iterator end;

        for (auto it = begin; it != end; ++it) {
            tokens.push_back(it->str());
        }

        return tokens;
    }

    // Parse the SVG path data and extract cubic Bezier segments
    std::vector<CubicBezier> parseSVGPath(const std::string& svgString) {
        std::vector<CubicBezier> bezierSegments;

        // Load the SVG string into pugi::xml_document
        pugi::xml_document doc;
        pugi::xml_parse_result result = doc.load_string(svgString.c_str());

        if (!result) {
            std::cout << "Error loading SVG: " << result.description() << "\n";
            return bezierSegments;
        }

        // Find the <path> element
        pugi::xml_node pathNode = doc.child("svg").child("path");
        if (!pathNode) {
            std::cout << "No <path> element found in the SVG\n";
            return bezierSegments;
        }

        // Get the "d" attribute (path data)
        std::string pathData = pathNode.attribute("d").value();

        // Tokenize the path data
        auto tokens = tokenizePathData(pathData);
        if (tokens.empty()) {
            std::cout << "Path data is empty or invalid.\n";
            return bezierSegments;
        }

        double x0 = 0, y0 = 0; // Starting point
        size_t i = 0;

        while (i < tokens.size()) {
            std::string command = tokens[i++];
            if (command == "M") {
                // Move to command
                x0 = std::stod(tokens[i++]);
                y0 = std::stod(tokens[i++]);
            }
            else if (command == "C") {
                // Cubic Bezier curve
                double cx1 = std::stod(tokens[i++]);
                double cy1 = std::stod(tokens[i++]);
                double cx2 = std::stod(tokens[i++]);
                double cy2 = std::stod(tokens[i++]);
                double x1 = std::stod(tokens[i++]);
                double y1 = std::stod(tokens[i++]);

                bezierSegments.push_back({ x0, y0, cx1, cy1, cx2, cy2, x1, y1 });

                // Update the current point
                x0 = x1;
                y0 = y1;
            }
        }

        return bezierSegments;
    }
}