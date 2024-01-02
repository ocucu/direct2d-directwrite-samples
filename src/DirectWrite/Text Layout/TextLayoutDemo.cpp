// File: TextLayoutDemo.cpp - CTextLayoutDemo class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/ 
//         e-mail: ovidiu.cucu.mvp@gmail.com 

#include "pch.h"
#include "TextLayoutDemo.h"

using Framework::CTextLayoutDocument;
using namespace Parameters;

CTextLayoutDemo::CTextLayoutDemo(CDemoView* pView)
    : CDemoDraw(pView)
{
}

#pragma region Overridden
void CTextLayoutDemo::DrawDemo(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(10.f, 10.f));

    const CD2DSizeF& sizeMax = m_rangeFormatParams.GetMaxSize();
    FillTextLayoutBackground(pRenderTarget, sizeMax);

    // create CD2DTextFormat object 
    CD2DTextFormat textFormat(
        pRenderTarget,  // window render target
        L"Arial",       // font family name
        24.f);          // font size in DIP (1/96 inch)

    SampleId sampleId = GetDemoFrame()->GetActivePaneId();
    switch (sampleId)
    {
    case SampleId::rangeFormat:
        DrawRangeFormatDemo(pRenderTarget, textFormat, sizeMax);
        break;
    default:
        ATLTRACE("Unhandled SampleId");
        break;
    }
}
#pragma endregion

#pragma region Operations
void CTextLayoutDemo::OnRangeFormatChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CRangeFormatParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_rangeFormatParams = *pParams;
    InvalidateView();
}
#pragma endregion

#pragma region Implementation
void CTextLayoutDemo::DrawRangeFormatDemo(CHwndRenderTarget* pRenderTarget, CD2DTextFormat& textFormat, const CD2DSizeF& sizeMax)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    VERIFY_D2D_RESOURCE(&textFormat);

    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    auto pTextBrush = pDoc->GetTextBrush();
    VERIFY_D2D_RESOURCE(pTextBrush);
    CString strText = pDoc->GetSampleText();

    CD2DTextLayout textLayout(
        pRenderTarget,  // window render target
        strText,        // text to be drawn
        textFormat,     // CD2DTextFormat object
        sizeMax         // the size of layout box
    );

    VERIFY_D2D_RESOURCE(&textLayout);

    const DWRITE_TEXT_RANGE& textRange = m_rangeFormatParams.GetTextRange();
    CString strFontFamily = m_rangeFormatParams.GetFontFamily();
    textLayout.SetFontFamilyName(strFontFamily, textRange);

    IDWriteTextLayout* pTextLayout = textLayout.Get();

    FLOAT fontSize = m_rangeFormatParams.GetFontSize();
    pTextLayout->SetFontSize(fontSize, textRange);

    DWRITE_FONT_WEIGHT fontWeight = m_rangeFormatParams.GetFontWeight();
    pTextLayout->SetFontWeight(fontWeight, textRange);

    DWRITE_FONT_STYLE fontStyle = m_rangeFormatParams.GetFontStyle();
    pTextLayout->SetFontStyle(fontStyle, textRange);

    DWRITE_FONT_STRETCH fontStretch = m_rangeFormatParams.GetFontStretch();
    pTextLayout->SetFontStretch(fontStretch, textRange);

    BOOL bUnderline = m_rangeFormatParams.GetUnderline();
    pTextLayout->SetUnderline(bUnderline, textRange);

    BOOL bStrikethrough = m_rangeFormatParams.GetStrikethrough();
    pTextLayout->SetStrikethrough(bStrikethrough, textRange);

    pRenderTarget->DrawTextLayout(CD2DPointF(), &textLayout, pTextBrush);
}

void CTextLayoutDemo::FillTextLayoutBackground(CHwndRenderTarget* pRenderTarget, const CD2DSizeF& sizeMax)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    CD2DSolidColorBrush* pBrush = GetDocument()->GetBackgroundBrush();
    VERIFY_D2D_RESOURCE(pBrush);

    CD2DRectF rect{ 0.f, 0.f, sizeMax.width, sizeMax.height };
    pRenderTarget->FillRectangle(rect, pBrush);
}

CTextLayoutDocument* CTextLayoutDemo::GetDocument()
{
    return dynamic_cast<CTextLayoutDocument*> (GetDemoDocument());
}
#pragma endregion
