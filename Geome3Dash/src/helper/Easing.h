#pragma once

#include <glm/glm/glm.hpp>

#include <cmath>
#include <numbers>

namespace g3d
{
    namespace ease
    {
        class Base {
        public:
            virtual double calculate(double t, double b, double c, double d) const = 0;
            virtual ~Base() = default;
        };

        struct InOutQuad : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static InOutQuad* get();
        };

        struct InQuad : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static InQuad* get();
        };

        struct OutQuad : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static OutQuad* get();
        };

        struct InCubic : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static InCubic* get();
        };

        struct OutCubic : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static OutCubic* get();
        };

        struct InOutCubic : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static InOutCubic* get();
        };

        struct InQuart : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static InQuart* get();
        };

        struct OutQuart : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static OutQuart* get();
        };

        struct InOutQuart : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static InOutQuart* get();
        };

        struct InQuint : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static InQuint* get();
        };

        struct OutQuint : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static OutQuint* get();
        };

        struct InOutQuint : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static InOutQuint* get();
        };

        struct InSine : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static InSine* get();
        };

        struct OutSine : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static OutSine* get();
        };

        struct InOutSine : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static InOutSine* get();
        };

        struct InExpo : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static InExpo* get();
        };

        struct OutExpo : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static OutExpo* get();
        };

        struct InOutExpo : public Base {
            double calculate(double t, double b, double c, double d) const override;
            static InOutExpo* get();
        };


        template<typename VecType>
        VecType ease(Base* fn, double t, double d, const VecType& origin, const VecType& target)
        {
            VecType newVec;
            for (int i = 0; i < origin.length(); ++i)
            {
                newVec[i] = fn->calculate(t, origin[i], target[i] - origin[i], d);
            }
            return newVec;
        }

        template<typename VecType>
        VecType easeNormal(Base* fn, double t, const VecType& origin, const VecType& target)
        {
            return ease<VecType>(fn, t, 1.0, origin, target);
        }
    }
}