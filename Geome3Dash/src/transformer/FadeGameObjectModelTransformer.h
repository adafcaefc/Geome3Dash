#pragma once

#include "GameObjectModelTransformer.h"

#include "helper/Easing.h"

namespace g3d
{
	class FadeGameObjectModelTransformer : public GameObjectModelTransformer
	{
	protected:
		GJBaseGameLayer* gameLayer;
		double maxRender;
		double startFade;
		ease::Base* easing;
		glm::vec3 target;
	public:
		double getMaxRender() { return maxRender; }
		virtual void transform(GameObjectModel* gom) override;
		FadeGameObjectModelTransformer(
			GJBaseGameLayer* layer,
			double maxR, 
			double startF,
			ease::Base* easeFunc, 
			const glm::vec3& tgt)
			: gameLayer(layer)
			, maxRender(maxR)
			, startFade(startF)
			, easing(easeFunc)
			, target(tgt) 
		{
		
		}

		virtual ~FadeGameObjectModelTransformer() = default;
	};
}