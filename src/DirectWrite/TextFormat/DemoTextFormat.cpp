// File: DemoTextFormat.cpp - CDemoTextFormat class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "DemoTextFormat.h"

using Framework::CTextFormatDocument;
using namespace Parameters;

CDemoTextFormat::CDemoTextFormat(CDemoView* pView)
    : CDemoDraw(pView)
{
}

#pragma region Overridden
void CDemoTextFormat::DrawDemo(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);

    CString strFontFamily = m_fontParams.GetFontFamily();
    FLOAT fontSize = m_fontParams.GetFontSize();
    DWRITE_FONT_WEIGHT fontWeight  = m_fontParams.GetFontWeight();
    DWRITE_FONT_STYLE fontStyle = m_fontParams.GetFontStyle();
    DWRITE_FONT_STRETCH fontStretch = m_fontParams.GetFontStretch();

    // create CD2DTextFormat object with given font parameters 
    CD2DTextFormat textFormat(
        pRenderTarget,      // window render target
        strFontFamily,      // font family name
        fontSize,           // font size in DIP (1/96 inch)
        fontWeight,         // font weight (normal, bold, etc.)
        fontStyle,          // font style (normal, oblique or italic)
        fontStretch);       // font stretch 

    VERIFY_D2D_RESOURCE(&textFormat);

    // set additional text format parameters
    SetTextFormat(textFormat);

    // get the sample text and calculate the text box rectangle
    CString strText = GetDemoDocument()->GetSampleText();
    CD2DRectF rect;
    CalculateTextBoxRectangle(pRenderTarget, rect);
    FillTextBoxBackground(pRenderTarget, rect);

    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    auto pTextBrush = pDoc->GetTextBrush();
    VERIFY_D2D_RESOURCE(pTextBrush);

    if (GetDemoFrame()->GetActivePaneId() == SampleId::tabStop)
    {
        // draw vertical lines to better illustrate the tab stop positions
        DrawTabStopLines(pRenderTarget, textFormat, pTextBrush, rect);
    }

    // finally, draw the text
    pRenderTarget->DrawText(strText, rect, pTextBrush, &textFormat);
}
#pragma endregion

#pragma region Operations
void CDemoTextFormat::OnFontChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CFontParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_fontParams = *pParams;
    if (pParams->GetRedrawFlag())
        InvalidateView();
}

void CDemoTextFormat::OnAlignmentChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CAlignmentParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_alignmentParams = *pParams;
    if (pParams->GetRedrawFlag())
        InvalidateView();
}

void CDemoTextFormat::OnWordWrappingChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CWordWrappingParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_wordWrappingParams = *pParams;
    if (pParams->GetRedrawFlag())
        InvalidateView();
}

void CDemoTextFormat::OnTrimmingChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CTrimmingParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_trimingParams = *pParams;
    if (pParams->GetRedrawFlag())
        InvalidateView();
}

void CDemoTextFormat::OnDirectionChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CDirectionParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_directionParams = *pParams;
    if (pParams->GetRedrawFlag())
        InvalidateView();

}

void CDemoTextFormat::OnLineSpacingChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CLineSpacingParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_lineSpacingParams = *pParams;
    if (pParams->GetRedrawFlag())
        InvalidateView();

}

void CDemoTextFormat::OnIncrementalTabStopChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CTabStopParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_tabStopParams = *pParams;
    if (pParams->GetRedrawFlag())
        InvalidateView();
}
#pragma endregion

#pragma region Implementation
void CDemoTextFormat::SetTextFormat(CD2DTextFormat& textFormat)
{
    VERIFY_D2D_RESOURCE(&textFormat);

    // get a pointer to IDWriteTextFormat interface
    IDWriteTextFormat* pTextFormat = textFormat.Get();
    VERIFY_PTR(pTextFormat);

    SetTextAndParagraphAlignment(pTextFormat);
    SetWordWrapping(pTextFormat);
    SetTrimming(pTextFormat);
    SetFlowAndReadingDirection(pTextFormat);
    SetLineSpacing(pTextFormat);
    SetIncrementalTabStop(pTextFormat);
}

void CDemoTextFormat::SetTextAndParagraphAlignment(IDWriteTextFormat* pTextFormat)
{
    DWRITE_TEXT_ALIGNMENT textAlignment = m_alignmentParams.GetTextAlignment();
    DWRITE_PARAGRAPH_ALIGNMENT paragraphAlignment = m_alignmentParams.GetParagraphAlignment();
    pTextFormat->SetTextAlignment(textAlignment);
    pTextFormat->SetParagraphAlignment(paragraphAlignment);
}

void CDemoTextFormat::SetWordWrapping(IDWriteTextFormat* pTextFormat)
{
    DWRITE_WORD_WRAPPING wordWrapping = m_wordWrappingParams.GetWordWrapping();
    pTextFormat->SetWordWrapping(wordWrapping);
}

void CDemoTextFormat::SetTrimming(IDWriteTextFormat* pTextFormat)
{
    // get a poiter to DirectWrite factory
    IDWriteFactory* pDirectWriteFactory = AfxGetD2DState()->GetWriteFactory();
    VERIFY_PTR(pDirectWriteFactory);
    // create ellipsis trimming sign
    CComPtr<IDWriteInlineObject> spInlineObject;
    VERIFY_HR(pDirectWriteFactory->CreateEllipsisTrimmingSign(pTextFormat, &spInlineObject));

    // finally, set trimming
    DWRITE_TRIMMING trimming = m_trimingParams.GetTrimming();
    pTextFormat->SetTrimming(&trimming, spInlineObject);
}

void CDemoTextFormat::SetFlowAndReadingDirection(IDWriteTextFormat* pTextFormat)
{
    DWRITE_FLOW_DIRECTION flowDirection = m_directionParams.GetFlowDirection();
    DWRITE_READING_DIRECTION readingDirection = m_directionParams.GetReadingDirection();
    pTextFormat->SetFlowDirection(flowDirection);
    pTextFormat->SetReadingDirection(readingDirection);
}

void CDemoTextFormat::SetLineSpacing(IDWriteTextFormat* pTextFormat)
{
    DWRITE_LINE_SPACING_METHOD lineSpacingMethod = m_lineSpacingParams.GetMethod();
    FLOAT baseline = m_fontParams.GetFontSize();
    FLOAT lineSpacing = baseline * m_lineSpacingParams.GetFactor();
    pTextFormat->SetLineSpacing(lineSpacingMethod, lineSpacing, baseline);
}

void CDemoTextFormat::SetIncrementalTabStop(IDWriteTextFormat* pTextFormat)
{
    TAB_STOP_METHOD tabStopMethod = m_tabStopParams.GetTabStopMethod();
    if (TAB_STOP_METHOD_DEFAULT == tabStopMethod)
        return; // let DirectWrite set incremental tab stops distance (i.e. font size * 4) 

    // otherwise, set a fixed distance given by m_tabStopDistance value
    FLOAT distance = m_tabStopParams.GetTabStopDistance();
    pTextFormat->SetIncrementalTabStop(distance);
}

void CDemoTextFormat::FillTextBoxBackground(CHwndRenderTarget* pRenderTarget, CD2DRectF& rect)
{
    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    auto pBackgroundBrush = pDoc->GetBackgroundBrush();
    VERIFY_D2D_RESOURCE(pBackgroundBrush);
    pRenderTarget->FillRectangle(rect, pBackgroundBrush);
}

void CDemoTextFormat::CalculateTextBoxRectangle(CHwndRenderTarget* pRenderTarget, CD2DRectF& rect)
{
    CD2DSizeF size = pRenderTarget->GetSize();
    rect.left = rect.top = m_textBoxMargin;
    rect.right = size.width - m_textBoxMargin;
    rect.bottom = size.height - m_textBoxMargin;
}

void CDemoTextFormat::DrawTabStopLines(CHwndRenderTarget* pRenderTarget, CD2DTextFormat& textFormat, CD2DBrush* pBrush, CD2DRectF& rect)
{
    VERIFY_D2D_RESOURCE(&textFormat);
    VERIFY_D2D_RESOURCE(pBrush);

    const FLOAT oldOpacity = pBrush->GetOpacity();
    pBrush->SetOpacity(0.15f);
    const FLOAT incrementalTabStop = textFormat.Get()->GetIncrementalTabStop();
    const FLOAT width = rect.right - rect.left;
    const FLOAT height = rect.bottom - rect.top;
    FLOAT tabStop = incrementalTabStop;
    while (tabStop < width)
    {
        CD2DPointF from{ rect.left + tabStop, rect.top };
        CD2DPointF to{ rect.left + tabStop, rect.bottom };
        pRenderTarget->DrawLine(from, to, pBrush);
        tabStop += incrementalTabStop;
    }
    pBrush->SetOpacity(oldOpacity); // restore the initial brush opacity
}

CTextFormatDocument* CDemoTextFormat::GetDocument()
{
    return dynamic_cast<CTextFormatDocument*>(GetDemoDocument());
}
#pragma endregion
