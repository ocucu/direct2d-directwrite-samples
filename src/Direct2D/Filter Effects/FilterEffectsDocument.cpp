// File: FilterEffectsDocument.cpp - CFilterEffectsDocument class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/ 
//         e-mail: ovidiu.cucu.mvp@gmail.com

#include "pch.h"
#include "FilterEffectsDocument.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Framework::CFilterEffectsDocument;

IMPLEMENT_DYNCREATE(CFilterEffectsDocument, CDemoDocument);

#pragma region Overridden
BOOL CFilterEffectsDocument::CreateD2DResources(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE_RET(pRenderTarget, FALSE);

    CD2DResourceFactory factory(pRenderTarget);
    VERIFY_BOOL_RET(factory.LoadD2DBitmap(IDB_PNG_AVOCADO, L"PNG", m_pBitmap), FALSE);

    return TRUE;
}
#pragma endregion
