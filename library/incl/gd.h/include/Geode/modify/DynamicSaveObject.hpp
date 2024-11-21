#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/DynamicSaveObject.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
    

	template<class Der>
	struct ModifyDerive<Der, DynamicSaveObject> : ModifyBase<ModifyDerive<Der, DynamicSaveObject>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, DynamicSaveObject>>;
		using ModifyBase<ModifyDerive<Der, DynamicSaveObject>>::ModifyBase;
		using Base = DynamicSaveObject;
        using Derived = Der;
		void apply() override {

		}
	};
}
