#pragma once

namespace g3d
{
	class GameObjectModel;
	class GameObjectModelTransformer
	{
	public:
		virtual void transform(GameObjectModel* gom) = 0;
		virtual ~GameObjectModelTransformer() {}
	};
}