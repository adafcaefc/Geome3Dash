#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_addAction
		#define GEODE_STATICS_addAction
		GEODE_AS_STATIC_FUNCTION(addAction) 
	#endif

	#ifndef GEODE_STATICS_pauseTarget
		#define GEODE_STATICS_pauseTarget
		GEODE_AS_STATIC_FUNCTION(pauseTarget) 
	#endif

	#ifndef GEODE_STATICS_resumeTarget
		#define GEODE_STATICS_resumeTarget
		GEODE_AS_STATIC_FUNCTION(resumeTarget) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_addAction
		#define GEODE_CONCEPT_CHECK_addAction
		GEODE_CONCEPT_FUNCTION_CHECK(addAction) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_pauseTarget
		#define GEODE_CONCEPT_CHECK_pauseTarget
		GEODE_CONCEPT_FUNCTION_CHECK(pauseTarget) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_resumeTarget
		#define GEODE_CONCEPT_CHECK_resumeTarget
		GEODE_CONCEPT_FUNCTION_CHECK(resumeTarget) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCActionManager> : ModifyBase<ModifyDerive<Der, cocos2d::CCActionManager>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCActionManager>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCActionManager>>::ModifyBase;
		using Base = cocos2d::CCActionManager;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<cocos2d::CCAction*, cocos2d::CCNode*, bool>::func(&cocos2d::CCActionManager::addAction)), Thiscall, cocos2d::CCActionManager, addAction, cocos2d::CCAction*, cocos2d::CCNode*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<cocos2d::CCObject*>::func(&cocos2d::CCActionManager::pauseTarget)), Thiscall, cocos2d::CCActionManager, pauseTarget, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<cocos2d::CCObject*>::func(&cocos2d::CCActionManager::resumeTarget)), Thiscall, cocos2d::CCActionManager, resumeTarget, cocos2d::CCObject*)
		}
	};
}
