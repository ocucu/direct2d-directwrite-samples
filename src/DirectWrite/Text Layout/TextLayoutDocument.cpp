// File: TextLayoutDocument.cpp - CTextLayoutDocument class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/ 
//         e-mail: ovidiu.cucu.mvp@gmail.com

#include "pch.h"
#include "TextLayoutDocument.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Framework::CTextLayoutDocument;

IMPLEMENT_DYNCREATE(CTextLayoutDocument, CDemoDocument);

#pragma region Overridden
BOOL CTextLayoutDocument::CreateD2DResources(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE_RET(pRenderTarget, FALSE);

    CD2DResourceFactory factory(pRenderTarget);
    factory.CreateBrush(RGB(0, 0, 64), m_pTextBrush);
    VERIFY_D2D_RESOURCE_RET(m_pTextBrush, FALSE);

    factory.CreateBrush(RGB(64, 128, 255), m_pBackgroundBrush);
    VERIFY_D2D_RESOURCE_RET(m_pTextBrush, FALSE);
    m_pBackgroundBrush->SetOpacity(0.1f);

    return TRUE;
}
#pragma endregion
