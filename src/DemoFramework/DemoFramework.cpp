// DemoFramework.cpp : Defines the initialization routines for DemoFramework.DLL.
//

#include "pch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE DemoFrameworkDLL = { NULL, NULL };

extern "C" int APIENTRY DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    int nRet = 1;
    UNREFERENCED_PARAMETER(lpReserved);
    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
        ATLTRACE("DemoFramework.DLL Initializing...\n");
        if (!AfxInitExtensionModule(DemoFrameworkDLL, hInstance))
            nRet = 0;
        else
            new CDynLinkLibrary(DemoFrameworkDLL);
        break;
    case DLL_PROCESS_DETACH:
        ATLTRACE("DemoFramework.DLL Terminating...\n");
        AfxTermExtensionModule(DemoFrameworkDLL);
        break;
    }
    return nRet;
}


