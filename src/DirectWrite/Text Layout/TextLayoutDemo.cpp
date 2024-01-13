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
        DemoTextRangeFormat(pRenderTarget, textFormat, sizeMax);
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
void CTextLayoutDemo::DemoTextRangeFormat(CHwndRenderTarget* pRenderTarget, CD2DTextFormat& textFormat, const CD2DSizeF& sizeMax)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    VERIFY_D2D_RESOURCE(&textFormat);

    // get text block and text range brushes from document
    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    auto pTextBlockBrush = pDoc->GetTextBrush();
    VERIFY_D2D_RESOURCE(pTextBlockBrush);
    CString strText = pDoc->GetSampleText();
    auto pTextRangeBrush = pDoc->GetSolidColorBrush();
    VERIFY_D2D_RESOURCE(pTextRangeBrush);

    // create CD2DTextLayout object
    CD2DTextLayout textLayout(
        pRenderTarget,  // window render target
        strText,        // text to be drawn
        textFormat,     // text block format
        sizeMax         // the size of layout box
    );
    VERIFY_D2D_RESOURCE(&textLayout);

    const DWRITE_TEXT_RANGE& textRange = m_rangeFormatParams.GetTextRange();

    // set range font family name
    CString strFontFamily = m_rangeFormatParams.GetFontFamily();
    textLayout.SetFontFamilyName(strFontFamily, textRange);

    // get IDWriteTextLayout interface
    IDWriteTextLayout* pTextLayout = textLayout.Get();

    // set range font size in DIP
    FLOAT fontSize = m_rangeFormatParams.GetFontSize();
    pTextLayout->SetFontSize(fontSize, textRange);

    // set range font weight
    DWRITE_FONT_WEIGHT fontWeight = m_rangeFormatParams.GetFontWeight();
    pTextLayout->SetFontWeight(fontWeight, textRange);

    // set range font style
    DWRITE_FONT_STYLE fontStyle = m_rangeFormatParams.GetFontStyle();
    pTextLayout->SetFontStyle(fontStyle, textRange);

    // set range font stretch
    DWRITE_FONT_STRETCH fontStretch = m_rangeFormatParams.GetFontStretch();
    pTextLayout->SetFontStretch(fontStretch, textRange);

    // set range underline
    BOOL bUnderline = m_rangeFormatParams.GetUnderline();
    pTextLayout->SetUnderline(bUnderline, textRange);

    // set range strikethrough
    BOOL bStrikethrough = m_rangeFormatParams.GetStrikethrough();
    pTextLayout->SetStrikethrough(bStrikethrough, textRange);

    // set text range color
    D2D1_COLOR_F textRangeColor = m_rangeFormatParams.GetColor();
    pTextRangeBrush->SetColor(textRangeColor);
    pTextLayout->SetDrawingEffect(pTextRangeBrush->Get(), textRange);
    
    // draw text layout
    pRenderTarget->DrawTextLayout(CD2DPointF(), &textLayout, pTextBlockBrush);
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
