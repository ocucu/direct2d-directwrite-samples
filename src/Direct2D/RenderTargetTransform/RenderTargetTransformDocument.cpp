#include "pch.h"
#include "RenderTargetTransformDocument.h"

#define ID_FIGURE_FIRST      ID_FIGURE_RECTANGLE
#define ID_FIGURE_LAST       ID_FIGURE_PICTURE

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Framework::CRenderTargetTransformDocument;

IMPLEMENT_DYNCREATE(CRenderTargetTransformDocument, CDemoDocument);

#pragma region Overridden
BOOL CRenderTargetTransformDocument::CreateD2DResources(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE_RET(pRenderTarget, FALSE);

    CD2DResourceFactory factory(pRenderTarget);
    VERIFY_BOOL_RET(factory.CreateBrush(RGB(64, 0, 0), m_pTextBrush), FALSE);
    VERIFY_BOOL_RET(factory.CreateBrush(RGB(0, 0, 128), m_pLineBrush), FALSE);

    CD2DPointF startPoint{ 0.f, m_sizeArrow.height / 2.f };
    CD2DPointF endPoint{ m_sizeArrow.width, m_sizeArrow.height / 2.f };
    VERIFY_BOOL_RET(factory.CreateBrush(startPoint, endPoint, RGB(255, 255, 32), RGB(32, 128, 255), m_pFillBrush), FALSE);
    VERIFY_BOOL_RET(factory.CreateArrowGeometry(m_sizeArrow, m_ArrowVeePos, m_pArrowGeometry), FALSE);
    VERIFY_BOOL_RET(factory.LoadD2DBitmap(IDB_PNG_ROSE, L"PNG", m_pPictureBitmap), FALSE);
    VERIFY_BOOL_RET(factory.LoadD2DBitmap(IDB_PNG_CENTER_ROTATE, L"PNG", m_pRotateCenterBitmap), FALSE);
    VERIFY_BOOL_RET(factory.LoadD2DBitmap(IDB_PNG_CENTER_SCLAE, L"PNG", m_pScaleCenterBitmap), FALSE);
    VERIFY_BOOL_RET(factory.LoadD2DBitmap(IDB_PNG_CENTER_SKEW, L"PNG", m_pSkewCenterBitmap), FALSE);

    return TRUE;
}
#pragma endregion

#pragma region Message handlers
BEGIN_MESSAGE_MAP(CRenderTargetTransformDocument, CDemoDocument)
    ON_UPDATE_COMMAND_UI_RANGE(ID_FIGURE_FIRST, ID_FIGURE_LAST, &CRenderTargetTransformDocument::OnFigureUpdateCommandUI)
    ON_COMMAND_RANGE(ID_FIGURE_FIRST, ID_FIGURE_LAST, &CRenderTargetTransformDocument::OnFigureCommand)
END_MESSAGE_MAP()

void CRenderTargetTransformDocument::OnFigureUpdateCommandUI(CCmdUI* pCmdUI)
{
    const UINT nID = pCmdUI->m_nID;
    const FigureId figureId = static_cast<FigureId>(nID - ID_FIGURE_FIRST + 1);
    pCmdUI->SetCheck(figureId == GetSampleFigureId());
}

void CRenderTargetTransformDocument::OnFigureCommand(UINT nID)
{
    SetSampleFigureId(static_cast<FigureId>(nID - ID_FIGURE_FIRST + 1));
}
#pragma endregion
