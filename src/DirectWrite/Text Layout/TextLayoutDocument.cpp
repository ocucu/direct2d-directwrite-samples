// File: TextLayoutDocument.cpp - CTextLayoutDocument class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/ 
//         e-mail: ovidiu.cucu.mvp@gmail.com

#include "pch.h"
#include "TextLayoutDocument.h"

#define ID_BRUSHTYPE_FIRST      ID_BRUSHTYPE_SOLIDCOLOR
#define ID_BRUSHTYPE_LAST       ID_BRUSHTYPE_BITMAP

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

    factory.CreateBrush(RGB(0, 0, 0), m_pSolidColorBrush);
    VERIFY_D2D_RESOURCE_RET(m_pSolidColorBrush, FALSE);

    CD2DPointF startPont{ 0.f, 0.f };
    CD2DPointF endPoint{ 100.f, 100.f };
    factory.CreateBrush(startPont, endPoint, RGB(255, 0, 0), RGB(0, 0, 255), m_pGradientBrush);
    VERIFY_D2D_RESOURCE_RET(m_pGradientBrush, FALSE);

    factory.LoadD2DBitmapBrush(IDB_PNG_PINE_LUMBER, L"PNG", m_pBitmapBrush);
    VERIFY_D2D_RESOURCE_RET(m_pBitmapBrush, FALSE);

    factory.CreateBrush(RGB(64, 128, 255), m_pBackgroundBrush);
    VERIFY_D2D_RESOURCE_RET(m_pTextBrush, FALSE);
    m_pBackgroundBrush->SetOpacity(0.1f);

    return TRUE;
}
#pragma endregion

#pragma region Message handlers
BEGIN_MESSAGE_MAP(CTextLayoutDocument, CDemoDocument)
    ON_UPDATE_COMMAND_UI_RANGE(ID_BRUSHTYPE_FIRST, ID_BRUSHTYPE_LAST, &CTextLayoutDocument::OnBrushTypeUpdateCommandUI)
    ON_COMMAND_RANGE(ID_BRUSHTYPE_FIRST, ID_BRUSHTYPE_LAST, &CTextLayoutDocument::OnBrushTypeCommand)
END_MESSAGE_MAP()

void CTextLayoutDocument::OnBrushTypeUpdateCommandUI(CCmdUI* pCmdUI)
{
    const UINT nID = pCmdUI->m_nID;
    const BrushTypeId brushTypeId = static_cast<BrushTypeId>(nID - ID_BRUSHTYPE_FIRST + 1);
    pCmdUI->SetCheck(brushTypeId == GetSampleBrushTypeId());
    // enable only for drawing effects sample
    auto pFrame = dynamic_cast<CDemoFrame*>(AfxGetMainWnd());
    BOOL bEnable = pFrame && (SampleId::drawingEffects == pFrame->GetActivePaneId());
    pCmdUI->Enable(bEnable);
}

void CTextLayoutDocument::OnBrushTypeCommand(UINT nID)
{
    SetSampleBrushTypeId(static_cast<BrushTypeId>(nID - ID_BRUSHTYPE_FIRST + 1));
}
#pragma endregion
