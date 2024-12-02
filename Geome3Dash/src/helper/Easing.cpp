#include "Easing.h"

namespace g3d
{
    namespace ease
    {
        // Method implementations for InOutQuad
        double InOutQuad::calculate(double t, double b, double c, double d) const {
            t /= d / 2;
            if (t < 1) return c / 2 * t * t + b;
            t--;
            return -c / 2 * (t * (t - 2) - 1) + b;
        }

        // Method implementations for InQuad
        double InQuad::calculate(double t, double b, double c, double d) const {
            t /= d;
            return c * t * t + b;
        }

        // Method implementations for OutQuad
        double OutQuad::calculate(double t, double b, double c, double d) const {
            t /= d;
            return -c * t * (t - 2) + b;
        }

        double InCubic::calculate(double t, double b, double c, double d) const {
            t /= d;
            return c * t * t * t + b;
        }

        double OutCubic::calculate(double t, double b, double c, double d) const {
            t = t / d - 1;
            return c * (t * t * t + 1) + b;
        }

        double InOutCubic::calculate(double t, double b, double c, double d) const {
            t /= d / 2;
            if (t < 1) return c / 2 * t * t * t + b;
            t -= 2;
            return c / 2 * (t * t * t + 2) + b;
        }

        // InQuart
        double InQuart::calculate(double t, double b, double c, double d) const {
            t /= d;
            return c * t * t * t * t + b;
        }

        // OutQuart
        double OutQuart::calculate(double t, double b, double c, double d) const {
            t = t / d - 1;
            return -c * (t * t * t * t - 1) + b;
        }

        // InOutQuart
        double InOutQuart::calculate(double t, double b, double c, double d) const {
            t /= d / 2;
            if (t < 1) return c / 2 * t * t * t * t + b;
            t -= 2;
            return -c / 2 * (t * t * t * t - 2) + b;
        }

        // InQuint
        double InQuint::calculate(double t, double b, double c, double d) const {
            t /= d;
            return c * t * t * t * t * t + b;
        }

        // OutQuint
        double OutQuint::calculate(double t, double b, double c, double d) const {
            t = t / d - 1;
            return c * (t * t * t * t * t + 1) + b;
        }

        // InOutQuint
        double InOutQuint::calculate(double t, double b, double c, double d) const {
            t /= d / 2;
            if (t < 1) return c / 2 * t * t * t * t * t + b;
            t -= 2;
            return c / 2 * (t * t * t * t * t + 2) + b;
        }

        // InSine
        double InSine::calculate(double t, double b, double c, double d) const {
            return -c * std::cos(t / d * (std::numbers::pi / 2)) + c + b;
        }

        // OutSine
        double OutSine::calculate(double t, double b, double c, double d) const {
            return c * sin(t / d * (std::numbers::pi / 2)) + b;
        }

        // InOutSine
        double InOutSine::calculate(double t, double b, double c, double d) const {
            return -c / 2 * (std::cos(std::numbers::pi * t / d) - 1) + b;
        }

        // InExpo
        double InExpo::calculate(double t, double b, double c, double d) const {
            return (t == 0) ? b : c * std::pow(2, 10 * (t / d - 1)) + b;
        }

        // OutExpo
        double OutExpo::calculate(double t, double b, double c, double d) const {
            return (t == d) ? b + c : c * (-std::pow(2, -10 * t / d) + 1) + b;
        }

        // InOutExpo
        double InOutExpo::calculate(double t, double b, double c, double d) const {
            if (t == 0) return b;
            if (t == d) return b + c;
            t /= d / 2;
            if (t < 1) return c / 2 * std::pow(2, 10 * (t - 1)) + b;
            t--;
            return c / 2 * (-std::pow(2, -10 * t) + 2) + b;
        }

        InOutQuad* InOutQuad::get() {
            static InOutQuad instance;
            return &instance;
        }

        InQuad* InQuad::get() {
            static InQuad instance;
            return &instance;
        }

        OutQuad* OutQuad::get() {
            static OutQuad instance;
            return &instance;
        }

        InCubic* InCubic::get() {
            static InCubic instance;
            return &instance;
        }

        OutCubic* OutCubic::get() {
            static OutCubic instance;
            return &instance;
        }

        InOutCubic* InOutCubic::get() {
            static InOutCubic instance;
            return &instance;
        }

        InQuart* InQuart::get() {
            static InQuart instance;
            return &instance;
        }

        OutQuart* OutQuart::get() {
            static OutQuart instance;
            return &instance;
        }

        InOutQuart* InOutQuart::get() {
            static InOutQuart instance;
            return &instance;
        }

        InQuint* InQuint::get() {
            static InQuint instance;
            return &instance;
        }

        OutQuint* OutQuint::get() {
            static OutQuint instance;
            return &instance;
        }

        InOutQuint* InOutQuint::get() {
            static InOutQuint instance;
            return &instance;
        }

        InSine* InSine::get() {
            static InSine instance;
            return &instance;
        }

        OutSine* OutSine::get() {
            static OutSine instance;
            return &instance;
        }

        InOutSine* InOutSine::get() {
            static InOutSine instance;
            return &instance;
        }

        InExpo* InExpo::get() {
            static InExpo instance;
            return &instance;
        }

        OutExpo* OutExpo::get() {
            static OutExpo instance;
            return &instance;
        }

        InOutExpo* InOutExpo::get() {
            static InOutExpo instance;
            return &instance;
        }
    }
}
