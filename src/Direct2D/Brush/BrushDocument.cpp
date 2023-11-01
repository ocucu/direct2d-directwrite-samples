#include "pch.h"
#include "BrushDocument.h"

#define ID_FIGURE_FIRST         ID_FIGURE_NONE
#define ID_FIGURE_LAST          ID_FIGURE_ELLIPSE
#define ID_BITMAP_FIRST         ID_BITMAP_COLORMATRIX
#define ID_BITMAP_LAST          ID_BITMAP_MFCICON

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Framework::CBrushDocument;

IMPLEMENT_DYNCREATE(CBrushDocument, CDemoDocument);

#pragma region Overridden
BOOL CBrushDocument::CreateD2DResources(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE_RET(pRenderTarget, FALSE);
    CD2DResourceFactory factory(pRenderTarget);
    VERIFY_BOOL_RET(factory.LoadD2DBitmap(IDB_PNG_COLOR_MATRIX, L"PNG", m_pColorMatrixBitmap), FALSE);
    VERIFY_BOOL_RET(factory.LoadD2DBitmap(IDB_PNG_CAT, L"PNG", m_pCatBitmap), FALSE);
    VERIFY_BOOL_RET(factory.LoadD2DBitmap(IDB_PNG_MFC_ICON, L"PNG", m_pMFCIconBitmap), FALSE);
    VERIFY_BOOL_RET(factory.CreateBrush(RGB(255, 255, 255), m_pDrawInfoBrush, 200), FALSE);
    return TRUE;
}
#pragma endregion

#pragma region Message handlers
BEGIN_MESSAGE_MAP(CBrushDocument, CDemoDocument)
    ON_UPDATE_COMMAND_UI_RANGE(ID_FIGURE_FIRST, ID_FIGURE_LAST, &CBrushDocument::OnFigureUpdateCommandUI)
    ON_COMMAND_RANGE(ID_FIGURE_FIRST, ID_FIGURE_LAST, &CBrushDocument::OnFigureCommand)
    ON_UPDATE_COMMAND_UI_RANGE(ID_BITMAP_FIRST, ID_BITMAP_LAST, &CBrushDocument::OnBitmapUpdateCommandUI)
    ON_COMMAND_RANGE(ID_BITMAP_FIRST, ID_BITMAP_LAST, &CBrushDocument::OnBitmapCommand)
END_MESSAGE_MAP()

void CBrushDocument::OnFigureUpdateCommandUI(CCmdUI* pCmdUI)
{
    const UINT nID = pCmdUI->m_nID;
    const FigureId figureId = static_cast<FigureId>(nID - ID_FIGURE_FIRST + 1);
    pCmdUI->SetCheck(figureId == GetSampleFigureId());
}

void CBrushDocument::OnFigureCommand(UINT nID)
{
    SetSampleFigureId(static_cast<FigureId>(nID - ID_FIGURE_FIRST + 1));
}

void CBrushDocument::OnBitmapUpdateCommandUI(CCmdUI* pCmdUI)
{
    const UINT nID = pCmdUI->m_nID;
    const BitmapId bitmapId = static_cast<BitmapId>(nID - ID_BITMAP_FIRST + 1);
    pCmdUI->SetCheck(bitmapId == GetSampleBitmapId());
    // enable only for bitmap brush sample
    auto pFrame = dynamic_cast<CDemoFrame*>(AfxGetMainWnd());
    BOOL bEnable = pFrame && (SampleId::bitmapBrush == pFrame->GetActivePaneId());
    pCmdUI->Enable(bEnable);
}

void CBrushDocument::OnBitmapCommand(UINT nID)
{
    SetSampleBitmapId(static_cast<BitmapId>(nID - ID_BITMAP_FIRST + 1));
}

#pragma endregion
