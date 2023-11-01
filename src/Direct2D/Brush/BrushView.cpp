// File: BrushView.cpp - CBrushView class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "BrushDemo.h"
#include "BrushView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Framework::CBrushView;

IMPLEMENT_DYNCREATE(CBrushView, CDemoView)

#pragma region Overridden
void CBrushView::ClearBackground(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    if (!m_pBackgroundBrush)
    {
        m_pBackgroundBrush = new CD2DBitmapBrush(pRenderTarget, IDB_PNG_GRAY_MATRIX, L"PNG");
        m_pBackgroundBrush->Create(pRenderTarget);
        VERIFY_D2D_RESOURCE(m_pBackgroundBrush);
        m_pBackgroundBrush->SetExtendModeX(D2D1_EXTEND_MODE_WRAP);
        m_pBackgroundBrush->SetExtendModeY(D2D1_EXTEND_MODE_WRAP);
    }
    CD2DSizeF size = pRenderTarget->GetSize();
    pRenderTarget->FillRectangle(CD2DRectF(0.f, 0.f, size.width, size.height), m_pBackgroundBrush);
}

void CBrushView::Draw(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    VERIFY_PTR(m_spDemo.get());
    m_spDemo->DrawDemo(pRenderTarget);
}

void CBrushView::OnInitialUpdate()
{
    // create the object which performs demo samples
    m_spDemo = std::make_unique<CBrushDemo>(this);
}

void CBrushView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
    UNREFERENCED_PARAMETER(pSender);
    VERIFY_PTR(m_spDemo.get());
    UpdateHint updateHint = static_cast<UpdateHint>(lHint);
    switch (updateHint)
    {
    case UpdateHint::demoDocumentChanged:
        Invalidate();
        break;
    case UpdateHint::solidColorBrushChanged:
        m_spDemo->OnSolidColorBrushChanged(pHint);
        break;
    case UpdateHint::bitmapBrushChanged:
        m_spDemo->OnBitmapBrushChanged(pHint);
        break;
    case UpdateHint::linearGradientBrushChanged:
        m_spDemo->OnLinearGradientBrushChanged(pHint);
        break;
    case UpdateHint::radialGradientBrushChanged:
        m_spDemo->OnRadialGradiontBrushChanged(pHint);
        break;
    default:
        ATLTRACE("Unhandled update hint value");
        break;
    }
}
#pragma endregion
