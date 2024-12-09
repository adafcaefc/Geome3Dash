#pragma once

#include "game/play/G3DCameraKeyEditorScene.h"

namespace sus3d
{
	class Model;
	class ShaderProgram;
}

namespace g3d
{
	class G3DCameraKeyEditorLoader;
	class G3DCameraKeyEditorPopup 
		: public geode::Popup<G3DCameraKeyEditorLoader*>
	{
	protected:
		G3DCameraKeyEditorLoader* ckel;
		G3DCameraKeyEditorScene* scene;

		bool setup(G3DCameraKeyEditorLoader* cel) override;
	public:
		void onClose(CCObject* obj) override;

		static G3DCameraKeyEditorPopup* create(G3DCameraKeyEditorLoader* ckel);
	};
}