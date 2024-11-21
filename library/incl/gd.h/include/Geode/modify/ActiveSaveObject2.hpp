#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/ActiveSaveObject2.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
    

	template<class Der>
	struct ModifyDerive<Der, ActiveSaveObject2> : ModifyBase<ModifyDerive<Der, ActiveSaveObject2>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, ActiveSaveObject2>>;
		using ModifyBase<ModifyDerive<Der, ActiveSaveObject2>>::ModifyBase;
		using Base = ActiveSaveObject2;
        using Derived = Der;
		void apply() override {

		}
	};
}
