// File: BrushTransformView.cpp - CBrushTransformView class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "BrushTransformDemo.h"
#include "BrushTransformView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Framework::CBrushTransformView;

IMPLEMENT_DYNCREATE(CBrushTransformView, CDemoView)

#pragma region Overridden
void CBrushTransformView::Draw(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    VERIFY_PTR(m_spDemo.get());
    m_spDemo->DrawDemo(pRenderTarget);
}

void CBrushTransformView::OnInitialUpdate()
{
    // create the object which performs demo samples
    m_spDemo = std::make_unique<CBrushTransformDemo>(this);
}

void CBrushTransformView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
    UNREFERENCED_PARAMETER(pSender);
    VERIFY_PTR(m_spDemo.get());
    UpdateHint updateHint = static_cast<UpdateHint>(lHint);
    switch (updateHint)
    {
    case UpdateHint::demoDocumentChanged:
        Invalidate();
        break;
    case UpdateHint::translationChanged:
        m_spDemo->OnTranslationChanged(pHint);
        break;
    case UpdateHint::rotationChanged:
        m_spDemo->OnRotationChanged(pHint);
        break;
    case UpdateHint::scaleChanged:
        m_spDemo->OnScaleChanged(pHint);
        break;
    case UpdateHint::skewChanged:
        m_spDemo->OnSkewChanged(pHint);
        break;
    default:
        ATLTRACE("Unhandled update hint value");
        break;
    }
}
#pragma endregion
