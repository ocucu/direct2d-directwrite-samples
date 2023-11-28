// File: FilterEffectsView.cpp - CFilterEffectsView class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/ 
//         e-mail: ovidiu.cucu.mvp@gmail.com

#include "pch.h"
#include "FilterEffectsDemo.h"
#include "FilterEffectsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Framework::CFilterEffectsView;

IMPLEMENT_DYNCREATE(CFilterEffectsView, CDemoView)

#pragma region Overridden
void CFilterEffectsView::Draw(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    VERIFY_PTR(m_spDemo.get());
    m_spDemo->DrawDemo(pRenderTarget);
}

void CFilterEffectsView::OnInitialUpdate()
{
    // create the object which performs demo samples
    m_spDemo = std::make_unique<CFilterEffectsDemo>(this);
}

void CFilterEffectsView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
    UNREFERENCED_PARAMETER(pSender);
    VERIFY_PTR(m_spDemo.get());
    UpdateHint updateHint = static_cast<UpdateHint>(lHint);
    switch (updateHint)
    {
    case  UpdateHint::gaussianBlurChanged:
        m_spDemo->OnGaussianBlurChanged(pHint);
        break;
    case UpdateHint::directionalBlurChanged:
        m_spDemo->OnDirectionalBlurChanged(pHint);
        break;
    case UpdateHint::edgeDetectionChanged:
        m_spDemo->OnEdgeDetectionChanged(pHint);
        break;
    case UpdateHint::morphologyChanged:
        m_spDemo->OnMorphologyChanged(pHint);
        break;
    default:
        ATLTRACE("Unhandled update hint value");
        break;
    }
}
#pragma endregion
