#include "pch.h"
#include "src/Geome3DashEntry.h"

static DWORD WINAPI mainThread(LPVOID lpParam)
{
    g3d::entry::setupLibraries();
    g3d::entry::setupHooks();
    return 0;
}

BOOL APIENTRY DllMain(
    HMODULE hModule,
    DWORD dwReason,
    LPVOID lpReserved)
{
    DWORD dwThreadId = NULL;
    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
        ::CreateThread(NULL, 0, mainThread, hModule, 0, &dwThreadId);
        ::DisableThreadLibraryCalls(hModule);
        break;

    case DLL_THREAD_ATTACH:
        break;

    case DLL_THREAD_DETACH:
        break;

    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

