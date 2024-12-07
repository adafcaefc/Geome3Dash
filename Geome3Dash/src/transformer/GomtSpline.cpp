#include "pch.h"

#include "GomtSpline.h"
#include "GameObjectModel.h"

namespace g3d
{
	void GomtSpline::transform(GameObjectModel* gom)
	{
		auto block = gom->getGameObject();
		const auto data = calculateSpline(
			spline,
			*lengthScaleFactor,
			block->m_positionX,
			block->m_positionY,
			block->getRotation());
		gom->setPosition(data.pos);
		gom->setRotation(data.rot);
		gom->setScale(glm::vec3(
			0.5 * (block->m_startFlipX ? -1 : 1) * (*lengthScaleFactor) * 30,
			0.5 * (block->m_startFlipY ? -1 : 1) * (*lengthScaleFactor) * 30 * block->m_scaleY,
			0.5 * (block->m_startFlipX ? -1 : 1) * (*lengthScaleFactor) * 30 * block->m_scaleX));
	}
}