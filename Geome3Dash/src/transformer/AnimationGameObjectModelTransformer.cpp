#include "pch.h"

#include "AnimationGameObjectModelTransformer.h"
#include "GameObjectModel.h"

namespace g3d
{
	void AnimationGameObjectModelTransformer::fixSawRotation(
		GameObjectModel* gom,
		const float rotation)
	{
		auto block = gom->getGameObject();
		auto data = spline->findClosestByLength(block->m_positionX * (*lengthScaleFactor));

		auto pos = data.value;
		auto normal = glm::normalize(spline->normal(data.t));
		auto tangent = glm::normalize(spline->tangent(data.t));

		glm::vec3 side(1.f, 0.f, 0.f);
		float normalDeltaAngle = glm::radians(rotation);

		glm::quat firstRotationQuat = glm::angleAxis(normalDeltaAngle, side);

		glm::vec3 binormal = glm::normalize(glm::cross(normal, tangent));
		glm::vec3 adjustedNormal = glm::normalize(glm::cross(tangent, binormal));

		glm::mat3 rotationMatrix(
			binormal,
			adjustedNormal,
			tangent);

		glm::quat rotationQuat = glm::quat_cast(rotationMatrix);
		glm::vec3 eulerDegrees = glm::degrees(glm::eulerAngles(rotationQuat * firstRotationQuat));

		gom->setRotation(eulerDegrees);
	}

	void AnimationGameObjectModelTransformer::transform(GameObjectModel* gom)
	{
		auto block = gom->getGameObject();
		auto scale = gom->getScale();
		CCSprite* sawChild = nullptr;
		// do animations
		switch (block->m_objectID)
		{

		case 36:
		case 84:
		case 141:
		case 1022:
		case 1330:
		case 1333:
		case 1704:
		case 1751:
			// orbs
			gom->setScaleY(scale.y / block->m_scaleY * block->getScaleY());
			gom->setScaleZ(scale.z / block->m_scaleX * block->getScaleX());
			break;
		case 1705:
		case 1706:
		case 1707:
			sawChild = gom->getGameObject()->getChildByType<CCSprite>(0);
			if (sawChild) { fixSawRotation(gom, sawChild->getRotation()); }
		default:
			break;
		}
	}
}