// File: TextLayoutView.cpp - CTextLayoutView class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/ 
//         e-mail: ovidiu.cucu.mvp@gmail.com

#include "pch.h"
#include "TextLayoutDemo.h"
#include "TextLayoutView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Framework::CTextLayoutView;

IMPLEMENT_DYNCREATE(CTextLayoutView, CDemoView)

#pragma region Overridden
void CTextLayoutView::Draw(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    VERIFY_PTR(m_spDemo.get());
    m_spDemo->DrawDemo(pRenderTarget);
}

void CTextLayoutView::OnInitialUpdate()
{
    // create the object which performs demo samples
    m_spDemo = std::make_unique<CTextLayoutDemo>(this);
}

void CTextLayoutView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
    UNREFERENCED_PARAMETER(pSender);
    VERIFY_PTR(m_spDemo.get());
    UpdateHint updateHint = static_cast<UpdateHint>(lHint);
    switch (updateHint)
    {
    case UpdateHint::demoDocumentChanged:
        Invalidate();
        break;
    case UpdateHint::rangeFormatChanged:
        m_spDemo->OnRangeFormatChanged(pHint);
        break;
    case UpdateHint::drawingEffectsChanged:
        m_spDemo->OnDrawingEffectsChanged(pHint);
        break;
    case UpdateHint::inlineImagesChanged:
        m_spDemo->OnInlineImageChanged(pHint);
        break;
    default:
        ATLTRACE("Unhandled update hint value");
        break;
    }
}
#pragma endregion
