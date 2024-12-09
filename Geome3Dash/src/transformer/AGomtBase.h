#pragma once

namespace g3d
{
	class GameObjectModel;
	class AGomtBase
	{
	public:
		virtual void transform(GameObjectModel* gom) = 0;
		virtual ~AGomtBase() {}
		AGomtBase() {}
	};
}