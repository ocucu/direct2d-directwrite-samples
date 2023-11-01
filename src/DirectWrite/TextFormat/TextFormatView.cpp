// File: TextFormatView.cpp - CTextFormatView class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "DemoTextFormat.h"
#include "TextFormatView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Framework::CTextFormatView;

IMPLEMENT_DYNCREATE(CTextFormatView, CDemoView)

#pragma region Overridden
void CTextFormatView::Draw(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    VERIFY_PTR(m_spDemo.get());
    m_spDemo->DrawDemo(pRenderTarget);
}

void CTextFormatView::OnInitialUpdate()
{
    // create the object which performs demo samples
    m_spDemo = std::make_unique<CDemoTextFormat>(this);
}

void CTextFormatView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
    UNREFERENCED_PARAMETER(pSender);
    VERIFY_PTR(m_spDemo.get());
    UpdateHint updateHint = static_cast<UpdateHint>(lHint);
    switch (updateHint)
    {
    case UpdateHint::demoDocumentChanged:
        Invalidate();
        break;
    case UpdateHint::fontChanged:
        m_spDemo->OnFontChanged(pHint);
        break;
    case UpdateHint::alignmentChanged:
        m_spDemo->OnAlignmentChanged(pHint);
        break;
    case UpdateHint::wordWrappingChanged:
        m_spDemo->OnWordWrappingChanged(pHint);
        break;
    case UpdateHint::trimmingChanged:
        m_spDemo->OnTrimmingChanged(pHint);
        break;
    case UpdateHint::directionChanged:
        m_spDemo->OnDirectionChanged(pHint);
        break;
    case UpdateHint::lineSpacingChanged:
        m_spDemo->OnLineSpacingChanged(pHint);
        break;
    case UpdateHint::tabStopChanged:
        m_spDemo->OnIncrementalTabStopChanged(pHint);
        break;
    default:
        ATLTRACE("Unhandled update hint value");
        break;
    }
}
#pragma endregion
