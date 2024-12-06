#pragma once

#include "GameObjectModelTransformer.h"

namespace g3d
{
	class Spline;
	class AnimationGameObjectModelTransformer : public GameObjectModelTransformer
	{
	protected:
		Spline* spline;
		float* lengthScaleFactor;
		void fixSawRotation(GameObjectModel* gom, const float rotation);
	public:
		virtual void transform(GameObjectModel* gom) override;
		virtual ~AnimationGameObjectModelTransformer() = default;

		AnimationGameObjectModelTransformer(
			Spline* spline,
			float* lcf)
			: spline(spline)
			, lengthScaleFactor(lcf)
		{

		}
	};
}