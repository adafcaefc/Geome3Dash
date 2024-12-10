#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/ActiveSaveObject1.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
    

	template<class Der>
	struct ModifyDerive<Der, ActiveSaveObject1> : ModifyBase<ModifyDerive<Der, ActiveSaveObject1>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, ActiveSaveObject1>>;
		using ModifyBase<ModifyDerive<Der, ActiveSaveObject1>>::ModifyBase;
		using Base = ActiveSaveObject1;
        using Derived = Der;
		void apply() override {

		}
	};
}
