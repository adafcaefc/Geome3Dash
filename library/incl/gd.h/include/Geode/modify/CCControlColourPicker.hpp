#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos-ext.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_colourPicker
		#define GEODE_STATICS_colourPicker
		GEODE_AS_STATIC_FUNCTION(colourPicker) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_colourPicker
		#define GEODE_CONCEPT_CHECK_colourPicker
		GEODE_CONCEPT_FUNCTION_CHECK(colourPicker) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::extension::CCControlColourPicker> : ModifyBase<ModifyDerive<Der, cocos2d::extension::CCControlColourPicker>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::extension::CCControlColourPicker>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::extension::CCControlColourPicker>>::ModifyBase;
		using Base = cocos2d::extension::CCControlColourPicker;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<>::func(&cocos2d::extension::CCControlColourPicker::colourPicker)), Default, cocos2d::extension::CCControlColourPicker, colourPicker, )
		}
	};
}
