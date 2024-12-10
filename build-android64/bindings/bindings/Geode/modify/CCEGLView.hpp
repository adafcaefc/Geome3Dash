#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_swapBuffers
		#define GEODE_STATICS_swapBuffers
		GEODE_AS_STATIC_FUNCTION(swapBuffers) 
	#endif

	#ifndef GEODE_STATICS_end
		#define GEODE_STATICS_end
		GEODE_AS_STATIC_FUNCTION(end) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_swapBuffers
		#define GEODE_CONCEPT_CHECK_swapBuffers
		GEODE_CONCEPT_FUNCTION_CHECK(swapBuffers) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_end
		#define GEODE_CONCEPT_CHECK_end
		GEODE_CONCEPT_FUNCTION_CHECK(end) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_toggleFullScreen
		#define GEODE_CONCEPT_CHECK_toggleFullScreen
		GEODE_CONCEPT_FUNCTION_CHECK(toggleFullScreen) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_pollEvents
		#define GEODE_CONCEPT_CHECK_pollEvents
		GEODE_CONCEPT_FUNCTION_CHECK(pollEvents) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setupWindow
		#define GEODE_CONCEPT_CHECK_setupWindow
		GEODE_CONCEPT_FUNCTION_CHECK(setupWindow) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWCharCallback
		#define GEODE_CONCEPT_CHECK_onGLFWCharCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWCharCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWCursorEnterFunCallback
		#define GEODE_CONCEPT_CHECK_onGLFWCursorEnterFunCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWCursorEnterFunCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWDeviceChangeFunCallback
		#define GEODE_CONCEPT_CHECK_onGLFWDeviceChangeFunCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWDeviceChangeFunCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWError
		#define GEODE_CONCEPT_CHECK_onGLFWError
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWError) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWKeyCallback
		#define GEODE_CONCEPT_CHECK_onGLFWKeyCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWKeyCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWMouseCallBack
		#define GEODE_CONCEPT_CHECK_onGLFWMouseCallBack
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWMouseCallBack) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWMouseMoveCallBack
		#define GEODE_CONCEPT_CHECK_onGLFWMouseMoveCallBack
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWMouseMoveCallBack) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWMouseScrollCallback
		#define GEODE_CONCEPT_CHECK_onGLFWMouseScrollCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWMouseScrollCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWWindowIconifyFunCallback
		#define GEODE_CONCEPT_CHECK_onGLFWWindowIconifyFunCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWWindowIconifyFunCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWWindowPosCallback
		#define GEODE_CONCEPT_CHECK_onGLFWWindowPosCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWWindowPosCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWWindowSizeFunCallback
		#define GEODE_CONCEPT_CHECK_onGLFWWindowSizeFunCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWWindowSizeFunCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWframebuffersize
		#define GEODE_CONCEPT_CHECK_onGLFWframebuffersize
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWframebuffersize) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCEGLView> : ModifyBase<ModifyDerive<Der, cocos2d::CCEGLView>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCEGLView>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCEGLView>>::ModifyBase;
		using Base = cocos2d::CCEGLView;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<>::func(&cocos2d::CCEGLView::swapBuffers)), Default, cocos2d::CCEGLView, swapBuffers, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<>::func(&cocos2d::CCEGLView::end)), Default, cocos2d::CCEGLView, end, )
		}
	};
}
