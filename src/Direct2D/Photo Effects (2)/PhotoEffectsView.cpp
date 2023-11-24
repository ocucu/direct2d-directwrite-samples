// File: PhotoEffectsView.cpp - CPhotoEffectsView class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "PhotoEffectsDemo.h"
#include "PhotoEffectsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Framework::CPhotoEffectsView;

IMPLEMENT_DYNCREATE(CPhotoEffectsView, CDemoView)

#pragma region Overridden
void CPhotoEffectsView::Draw(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    VERIFY_PTR(m_spDemo.get());
    m_spDemo->DrawDemo(pRenderTarget);
}

void CPhotoEffectsView::OnInitialUpdate()
{
    // create the object which performs demo samples
    m_spDemo = std::make_unique<CPhotoEffectsDemo>(this);
}

void CPhotoEffectsView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
    UNREFERENCED_PARAMETER(pSender);
    VERIFY_PTR(m_spDemo.get());
    UpdateHint updateHint = static_cast<UpdateHint>(lHint);
    switch (updateHint)
    {
    case UpdateHint::demoDocumentChanged:
        Invalidate();
        break;
    case UpdateHint::sharpenChanged:
        m_spDemo->OnSharpenChanged(pHint);
        break;
    case  UpdateHint::straightenChanged:
        m_spDemo->OnStraightenChanged(pHint);
        break;
    case UpdateHint::vignetteChanged:
        m_spDemo->OnVignetteChanged(pHint);
        break;
    case UpdateHint::highlightsAndShadowsChanged:
        m_spDemo->OnHighlightsAndShadowsChanged(pHint);
        break;
    case UpdateHint::temperatureAndTintChanged:
        m_spDemo->OnTemperatureAndTintChanged(pHint);
        break;
    default:
        ATLTRACE("Unhandled update hint value");
        break;
    }
}
#pragma endregion
