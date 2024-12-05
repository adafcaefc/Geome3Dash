#include "pch.h"

#include "CameraKeyframeBuffer.h"

namespace g3d
{
    void CameraKeyframeBuffer::setKeyframe(float playersXpos, glm::vec3 offset, glm::vec3 front) {
        for (size_t i = 0; i < keyframes.size(); i++) {
            if (keyframes[i].playersXpos > playersXpos) {
                keyframes.insert(keyframes.begin() + i, CameraKeyframe(playersXpos, offset, front));
                return;
            }
            else if (keyframes[i].playersXpos == playersXpos) {
                keyframes[i].offset = offset;
                keyframes[i].front = front;
                return;
            }
        }
        keyframes.push_back(CameraKeyframe(playersXpos, offset, front));
    }

    void CameraKeyframeBuffer::removeLastKeyframe() {
        keyframes.pop_back();
    }

    CameraKeyframe CameraKeyframeBuffer::getInterpolatedCameraKeyframe(float playersXpos) {
        if (keyframes.empty()) return CameraKeyframe();

        if (playersXpos <= keyframes.front().playersXpos) {
            return CameraKeyframe(
                playersXpos,
                keyframes.front().offset,
                keyframes.front().front
            );
        }

        if (playersXpos >= keyframes.back().playersXpos) {
            return CameraKeyframe(
                playersXpos,
                keyframes.back().offset,
                keyframes.back().front
            );
        }

        CameraKeyframe* startKeyframe = nullptr;
        CameraKeyframe* endKeyframe = nullptr;

        for (size_t i = 0; i < keyframes.size() - 1; ++i) {
            if (keyframes[i].playersXpos <= playersXpos && playersXpos <= keyframes[i + 1].playersXpos) {
                startKeyframe = &keyframes[i];
                endKeyframe = &keyframes[i + 1];
                break;
            }
        }

        if (!startKeyframe || !endKeyframe) return CameraKeyframe();//sus

        float t = (playersXpos - startKeyframe->playersXpos) / (endKeyframe->playersXpos - startKeyframe->playersXpos);

        return CameraKeyframe(
            playersXpos,
            lerp(startKeyframe->offset, endKeyframe->offset, t),
            lerp(startKeyframe->front, endKeyframe->front, t)
        );
    }

    glm::vec3 CameraKeyframeBuffer::lerp(glm::vec3 p0, glm::vec3 p1, float t) {
        return glm::vec3(std::lerp(p0.x, p1.x, t), std::lerp(p0.y, p1.y, t), std::lerp(p0.z, p1.z, t));
    }

    CameraKeyframeBuffer::~CameraKeyframeBuffer() {
    }
}