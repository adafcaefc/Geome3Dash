#include "pch.h"

#include "PomtSpline.h"
#include "model/PlayerObjectModel.h"

namespace g3d
{
	void PomtSpline::transform(GameObjectModel* gom)
	{
		if (auto pom = dynamic_cast<PlayerObjectModel*>(gom))
		{
			auto player = pom->getPlayerObject();
			const auto data = calculateSpline(
				spline,
				*lengthScaleFactor,
				player->m_position.x,
				player->m_position.y,
				player->getRotation());
			pom->setPosition(data.pos);
			pom->setRotation(data.rot);
			float scale = pom->getPlayerObject()->getScale();
			gom->setScale(glm::vec3(
				0.5 * (player->m_startFlipX ? -1 : 1) * (*lengthScaleFactor) * 30,
				0.5 * (player->m_isUpsideDown ? -1 : 1) * (*lengthScaleFactor) * 30 * scale,
				0.5 * (*lengthScaleFactor) * 30 * scale));
		}
	}
}