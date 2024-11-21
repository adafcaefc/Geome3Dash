#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_createWithData
		#define GEODE_STATICS_createWithData
		GEODE_AS_STATIC_FUNCTION(createWithData) 
	#endif

	#ifndef GEODE_STATICS_getCString
		#define GEODE_STATICS_getCString
		GEODE_AS_STATIC_FUNCTION(getCString) 
	#endif

	#ifndef GEODE_STATICS_boolValue
		#define GEODE_STATICS_boolValue
		GEODE_AS_STATIC_FUNCTION(boolValue) 
	#endif

	#ifndef GEODE_STATICS_intValue
		#define GEODE_STATICS_intValue
		GEODE_AS_STATIC_FUNCTION(intValue) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_createWithData
		#define GEODE_CONCEPT_CHECK_createWithData
		GEODE_CONCEPT_FUNCTION_CHECK(createWithData) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getCString
		#define GEODE_CONCEPT_CHECK_getCString
		GEODE_CONCEPT_FUNCTION_CHECK(getCString) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_boolValue
		#define GEODE_CONCEPT_CHECK_boolValue
		GEODE_CONCEPT_FUNCTION_CHECK(boolValue) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_intValue
		#define GEODE_CONCEPT_CHECK_intValue
		GEODE_CONCEPT_FUNCTION_CHECK(intValue) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCString> : ModifyBase<ModifyDerive<Der, cocos2d::CCString>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCString>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCString>>::ModifyBase;
		using Base = cocos2d::CCString;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<unsigned char const*, unsigned long>::func(&cocos2d::CCString::createWithData)), Default, cocos2d::CCString, createWithData, unsigned char const*, unsigned long)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<>::func(&cocos2d::CCString::getCString)), Thiscall, cocos2d::CCString, getCString, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<>::func(&cocos2d::CCString::boolValue)), Thiscall, cocos2d::CCString, boolValue, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<>::func(&cocos2d::CCString::intValue)), Thiscall, cocos2d::CCString, intValue, )
		}
	};
}
