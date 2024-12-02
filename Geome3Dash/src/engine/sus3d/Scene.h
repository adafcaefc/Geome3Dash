#pragma once

#include <glm/glm.hpp>

#include <filesystem>

namespace sus3d
{
    class Model;
    class ShaderProgram;

    struct Light {
    private:
        glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
    public:
        void setPosition(glm::vec3 position) { this->position = position; }
        glm::vec3 getPosition() { return this->position; }
        void setColor(glm::vec3 color) { this->color = color; }
        glm::vec3 getColor() { return this->color; }
    };

    struct Camera {
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
    public:
        void setPosition(glm::vec3 position) { this->position = position; }
        glm::vec3 getPosition() { return this->position; }
        void setYaw(float yaw) { this->yaw = yaw; updateFront(); }
        float getYaw() { return this->yaw; }
        void setPitch(float pitch) { this->pitch = pitch; updateFront(); }
        float getPitch() { return this->pitch; }
        void setFov(float fov) { this->fov = fov; }
        float getFov() { return this->fov; }
        glm::vec3 getFront() { return front; }
        glm::vec3 getUp() { return up; }
        glm::mat4 getViewMat();
        glm::mat4 getProjectionMat();
    };
}