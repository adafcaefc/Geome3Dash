#pragma once

#include <glm/glm/glm.hpp>

#include <cmath>
#include <numbers>

namespace sus3d
{
    namespace easing
    {
        struct Base
        {
            virtual double calculate(double t, double b, double c, double d) const = 0;
            virtual ~Base() = default;
        };

        struct EaseInOutQuad : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                t /= d / 2;
                if (t < 1) return c / 2 * t * t + b;
                t--;
                return -c / 2 * (t * (t - 2) - 1) + b;
            }
        };

        struct EaseInQuad : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                t /= d;
                return c * t * t + b;
            }
        };

        struct EaseOutQuad : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                t /= d;
                return -c * t * (t - 2) + b;
            }
        };

        struct EaseInCubic : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                t /= d;
                return c * t * t * t + b;
            }
        };

        struct EaseOutCubic : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                t = t / d - 1;
                return c * (t * t * t + 1) + b;
            }
        };

        struct EaseInOutCubic : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                t /= d / 2;
                if (t < 1) return c / 2 * t * t * t + b;
                t -= 2;
                return c / 2 * (t * t * t + 2) + b;
            }
        };

        struct EaseInQuart : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                t /= d;
                return c * t * t * t * t + b;
            }
        };

        struct EaseOutQuart : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                t = t / d - 1;
                return -c * (t * t * t * t - 1) + b;
            }
        };

        struct EaseInOutQuart : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                t /= d / 2;
                if (t < 1) return c / 2 * t * t * t * t + b;
                t -= 2;
                return -c / 2 * (t * t * t * t - 2) + b;
            }
        };

        struct EaseInQuint : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                t /= d;
                return c * t * t * t * t * t + b;
            }
        };

        struct EaseOutQuint : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                t = t / d - 1;
                return c * (t * t * t * t * t + 1) + b;
            }
        };

        struct EaseInOutQuint : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                t /= d / 2;
                if (t < 1) return c / 2 * t * t * t * t * t + b;
                t -= 2;
                return c / 2 * (t * t * t * t * t + 2) + b;
            }
        };

        struct EaseInSine : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                return -c * std::cos(t / d * (std::numbers::pi / 2)) + c + b;
            }
        };

        struct EaseOutSine : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                return c * sin(t / d * (std::numbers::pi / 2)) + b;
            }
        };

        struct EaseInOutSine : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                return -c / 2 * (std::cos(std::numbers::pi * t / d) - 1) + b;
            }
        };

        struct EaseInExpo : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                return (t == 0) ? b : c * std::pow(2, 10 * (t / d - 1)) + b;
            }
        };

        struct EaseOutExpo : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                return (t == d) ? b + c : c * (-std::pow(2, -10 * t / d) + 1) + b;
            }
        };

        struct EaseInOutExpo : public Base
        {
            double calculate(double t, double b, double c, double d) const override
            {
                if (t == 0) return b;
                if (t == d) return b + c;
                t /= d / 2;
                if (t < 1) return c / 2 * std::pow(2, 10 * (t - 1)) + b;
                t--;
                return c / 2 * (-std::pow(2, -10 * t) + 2) + b;
            }
        };

        namespace v
        {
            extern EaseInOutQuad easeInOutQuad;
            extern EaseInQuad easeInQuad;
            extern EaseOutQuad easeOutQuad;
            extern EaseInCubic easeInCubic;
            extern EaseOutCubic easeOutCubic;
            extern EaseInOutCubic easeInOutCubic;
            extern EaseInQuart easeInQuart;
            extern EaseOutQuart easeOutQuart;
            extern EaseInOutQuart easeInOutQuart;
            extern EaseInQuint easeInQuint;
            extern EaseOutQuint easeOutQuint;
            extern EaseInOutQuint easeInOutQuint;
            extern EaseInSine easeInSine;
            extern EaseOutSine easeOutSine;
            extern EaseInOutSine easeInOutSine;
            extern EaseInExpo easeInExpo;
            extern EaseOutExpo easeOutExpo;
            extern EaseInOutExpo easeInOutExpo;
        }

        template<typename T, typename VecType>
        VecType ease(double t, double d, const VecType& origin, const VecType& target)
        {
            static T easingFunction;
            VecType newVec;
            for (int i = 0; i < origin.length(); ++i)
            {
                newVec[i] = easingFunction.calculate(t, origin[i], target[i] - origin[i], d);
            }
            return newVec;
        }

        template<typename T, typename VecType>
        VecType easeNormal(double t, const VecType& origin, const VecType& target)
        {
            return ease<T, VecType>(t, 1.0, origin, target);
        }
    }
}