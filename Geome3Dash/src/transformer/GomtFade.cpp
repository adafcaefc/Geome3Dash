#include "pch.h"

#include "GomtFade.h"
#include "model/GameObjectModel.h"

namespace g3d
{
	void GomtFade::transform(GameObjectModel* gom)
	{
		auto obj = gom->getGameObject();
		auto distance = std::abs(gameLayer->m_player1->m_position.x - obj->getPositionX());
		if (distance > maxRender) {
			gom->setVisible(false);
			gom->setOpacity(0);
		}
		else if (distance > startFade) {
			auto scale = gom->getScale();
			double tNormal = (distance - startFade) / (maxRender - startFade);
			gom->setScale(ease::easeNormal<glm::vec3>(easing, tNormal, scale, target));
		}
	}
}