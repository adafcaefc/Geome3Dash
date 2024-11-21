#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_attachWithIME
		#define GEODE_STATICS_attachWithIME
		GEODE_AS_STATIC_FUNCTION(attachWithIME) 
	#endif

	#ifndef GEODE_STATICS_detachWithIME
		#define GEODE_STATICS_detachWithIME
		GEODE_AS_STATIC_FUNCTION(detachWithIME) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_attachWithIME
		#define GEODE_CONCEPT_CHECK_attachWithIME
		GEODE_CONCEPT_FUNCTION_CHECK(attachWithIME) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_detachWithIME
		#define GEODE_CONCEPT_CHECK_detachWithIME
		GEODE_CONCEPT_FUNCTION_CHECK(detachWithIME) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_deleteForward
		#define GEODE_CONCEPT_CHECK_deleteForward
		GEODE_CONCEPT_FUNCTION_CHECK(deleteForward) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCIMEDelegate> : ModifyBase<ModifyDerive<Der, cocos2d::CCIMEDelegate>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCIMEDelegate>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCIMEDelegate>>::ModifyBase;
		using Base = cocos2d::CCIMEDelegate;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(reinterpret_cast<uintptr_t>(GetProcAddress(GetModuleHandleA("libcocos2d.dll"), "??1CCIMEDelegate@cocos2d@@UAE@XZ")), Thiscall, cocos2d::CCIMEDelegate)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<>::func(&cocos2d::CCIMEDelegate::attachWithIME)), Thiscall, cocos2d::CCIMEDelegate, attachWithIME, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<>::func(&cocos2d::CCIMEDelegate::detachWithIME)), Thiscall, cocos2d::CCIMEDelegate, detachWithIME, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(cocos2d::CCIMEDelegate, deleteForward, )
		}
	};
}
