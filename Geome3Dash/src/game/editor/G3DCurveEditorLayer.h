#pragma once

#include "delegate/CustomKeyboard.h"
#include "delegate/CustomMouse.h"
#include "delegate/CustomTouch.h"

namespace sus3d
{
	class Model;
	class ShaderProgram;
}

namespace g3d
{
	class G3DBaseNode;
	class Spline;

	class G3DCurveEditorLayer 
		: public CCLayer
		, public CustomKeyboardDelegate
		, public CustomMouseDelegate
		, public CustomTouchDelegate 
	{
		G3DBaseNode* layer3d;
		sus3d::Model* pointModel;

		LevelEditorLayer* lel;

		CCSprite* bg;

		float levelLength = 0;

		int selected = -1;

		bool isPressingControl = false;
		bool isPressingShift = false;
		bool isRightClicking = false;
		bool isRightClickingGetPos = false;
		float lastMouseX = 0.0;
		float lastMouseY = 0.0;

		virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods);
		virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y);
		virtual void scrollWheel(float y, float x);
		virtual void onKey(enumKeyCodes key, bool pressed, bool holding);

		virtual bool init(LevelEditorLayer* lel);
		virtual void draw();

		void updateLevel();

		void onAddSegment(CCObject*);
		void onRemoveSegment(CCObject*);

	public:
		Spline* spline;
		void show() {

			CCObject* obj;
			CCARRAY_FOREACH(lel->getChildren(), obj) {
				auto node = static_cast<CCNode*>(obj);
				node->setVisible(0);
			}
			this->setVisible(1);
			updateLevel();
		}
		void hide(CCObject*) {
			CCObject* obj;
			CCARRAY_FOREACH(lel->getChildren(), obj) {
				auto node = static_cast<CCNode*>(obj);
				node->setVisible(1);
			}
			this->setVisible(0);
		}

		static G3DCurveEditorLayer* create(LevelEditorLayer* lel);
	};
}