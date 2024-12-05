#pragma once

#include <glm/glm.hpp>

#include <filesystem>

namespace sus3d
{
    class Model;
    class ShaderProgram;

    class Light {
    private:
        glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
    public:
        void setPosition(glm::vec3 position) { this->position = position; }
        glm::vec3 getPosition() const { return this->position; }
        void setColor(glm::vec3 color) { this->color = color; }
        glm::vec3 getColor() const { return this->color; }
    };

    class Camera {
    private:
        glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
        float yaw = -90.f;
        float pitch = 0.f;
        float fov = 45.f;

        void updateFront() {
            glm::vec3 newFront;
            newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
            newFront.y = sin(glm::radians(pitch));
            newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
            front = glm::normalize(newFront);
        }

        void updateYawAndPitch() {
            front = glm::normalize(front);
            pitch = glm::degrees(asin(front.y));
            yaw = glm::degrees(atan2(front.z, front.x));
        }
    public:
        void setPosition(glm::vec3 position) { this->position = position; }
        glm::vec3 getPosition() const { return this->position; }
        void setYaw(float yaw) { this->yaw = yaw; updateFront(); }
        float getYaw() const { return this->yaw; }
        void setPitch(float pitch) { this->pitch = pitch; updateFront(); }
        float getPitch() const { return this->pitch; }
        void setFov(float fov) { this->fov = fov; }
        float getFov() const { return this->fov; }
        glm::vec3 getFront() const { return front; }
        glm::vec3 getUp() const { return up; }
        glm::mat4 getViewMat() const;
        glm::mat4 getProjectionMat() const;
        void setFront(glm::vec3 front) { this->front = front; updateYawAndPitch(); }
    };
}