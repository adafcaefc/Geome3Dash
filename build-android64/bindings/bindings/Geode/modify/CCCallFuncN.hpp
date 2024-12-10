#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_create
		#define GEODE_STATICS_create
		GEODE_AS_STATIC_FUNCTION(create) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCCallFuncN> : ModifyBase<ModifyDerive<Der, cocos2d::CCCallFuncN>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCCallFuncN>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCCallFuncN>>::ModifyBase;
		using Base = cocos2d::CCCallFuncN;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<cocos2d::CCObject*, cocos2d::SEL_CallFuncN>::func(&cocos2d::CCCallFuncN::create)), Default, cocos2d::CCCallFuncN, create, cocos2d::CCObject*, cocos2d::SEL_CallFuncN)
		}
	};
}
