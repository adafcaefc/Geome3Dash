#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
    
	#ifndef GEODE_CONCEPT_CHECK_setPreviousPriority
		#define GEODE_CONCEPT_CHECK_setPreviousPriority
		GEODE_CONCEPT_FUNCTION_CHECK(setPreviousPriority) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getPreviousPriority
		#define GEODE_CONCEPT_CHECK_getPreviousPriority
		GEODE_CONCEPT_FUNCTION_CHECK(getPreviousPriority) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCTouchDelegate> : ModifyBase<ModifyDerive<Der, cocos2d::CCTouchDelegate>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTouchDelegate>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTouchDelegate>>::ModifyBase;
		using Base = cocos2d::CCTouchDelegate;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(cocos2d::CCTouchDelegate, setPreviousPriority, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(cocos2d::CCTouchDelegate, getPreviousPriority, )
		}
	};
}
