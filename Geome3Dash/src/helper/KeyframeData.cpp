#include "pch.h"

#include "KeyframeData.h"
#include "manager/LevelDataManager.h"
#include "engine/sus3d/Scene.h"

namespace g3d
{
    void KeyframeData::setKeyframe(float playersXpos, glm::vec3 offset, glm::vec3 front) {
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

    void KeyframeData::removeLastKeyframe() {
        if (keyframes.size()) { keyframes.pop_back(); }
    }

    CameraKeyframe KeyframeData::getInterpolatedCameraKeyframe(float playersXpos) {
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

    glm::vec3 KeyframeData::lerp(glm::vec3 p0, glm::vec3 p1, float t) {
        return glm::vec3(std::lerp(p0.x, p1.x, t), std::lerp(p0.y, p1.y, t), std::lerp(p0.z, p1.z, t));
    }

    KeyframeData::~KeyframeData() {
    }

    void setStartingKeyframe(
        LevelData* cld,
        KeyframeData* keyframeBuffer, 
        const float lengthScaleFactor)
    {
        sus3d::Camera fakeCamera;
        fakeCamera.setPitch(cld->pitch);
        fakeCamera.setYaw(cld->yaw);
        fakeCamera.setPosition(glm::vec3(cld->x, cld->y, cld->z));
        const auto kfcopy = keyframeBuffer->keyframes;
        keyframeBuffer->keyframes.clear();
        for (auto& kf : kfcopy)
        {
            if (kf.playersXpos != 0.f) { keyframeBuffer->keyframes.push_back(kf); }
        }
        keyframeBuffer->setKeyframe(0, fakeCamera.getPosition() * glm::vec3(lengthScaleFactor * 20), fakeCamera.getFront());
    }

    void prepareSpline(
        GJBaseGameLayer* layer, 
        Spline* spline,
        float* lengthScaleFactor)
    {
        float levelLength = 0;
        CCObject* obj;
        CCARRAY_FOREACH(layer->m_objects, obj)
        {
            if (auto block = dynamic_cast<GameObject*>(obj))
            {
                levelLength = std::max(block->getPositionX(), levelLength);
            }
        }
        *lengthScaleFactor = spline->length(10000) / levelLength;
        spline->updateParameterList();
    }
}