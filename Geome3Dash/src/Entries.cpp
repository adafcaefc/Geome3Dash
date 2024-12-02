#include "pch.h"

#include "Entries.h"

namespace g3d
{
    namespace entry
    {
        void setupLibraries()
        {
            // setup delayloaded dlls
            const auto path = geode::Mod::get()->getResourcesDir() / "binaries" / "win";
            const auto pugi = path / "pugixml.dll";
            const auto assimp = path / "assimp-vc143-mt.dll";
            LoadLibraryA(pugi.string().c_str());
            LoadLibraryA(assimp.string().c_str());
        }

        void setupHooks()
        {
            auto mod = geode::Mod::get();
            for (auto& hook : mod->getHooks()) { if (!hook->isEnabled()) { auto result = hook->enable(); } }
        }
    }
}