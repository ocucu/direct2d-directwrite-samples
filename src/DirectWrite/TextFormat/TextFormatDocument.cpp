#include "pch.h"
#include "TextFormatDocument.h"

using Framework::CTextFormatDocument;
IMPLEMENT_DYNCREATE(CTextFormatDocument, CDemoDocument)

#pragma region Overridden
BOOL CTextFormatDocument::CreateD2DResources(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE_RET(pRenderTarget, FALSE);

    CD2DResourceFactory factory(pRenderTarget);
    factory.CreateBrush(RGB(0, 0, 128), m_pTextBrush);
    VERIFY_D2D_RESOURCE_RET(m_pTextBrush, FALSE);

    factory.CreateBrush(RGB(64, 128, 255), m_pBackgroundBrush);
    VERIFY_D2D_RESOURCE_RET(m_pTextBrush, FALSE);
    m_pBackgroundBrush->SetOpacity(0.1f);

    return TRUE;
}
#pragma endregion


