// File: DemoTextFormat.h - CDemoTextFormat class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Contains the drawing parameters and functions for Text Format demo samples 
// Note: drawing stuff is kept here, rather than in the view class.

#pragma once
#include "TextFormatDocument.h"
#include "Parameters.h"

class CDemoTextFormat final : public CDemoDraw
{
public:
    CDemoTextFormat(CDemoView* pView);

    // Overridden
    virtual void DrawDemo(CHwndRenderTarget* pRenderTarget) override;

    // Operations
    void OnFontChanged(CObject* pHint);
    void OnAlignmentChanged(CObject* pHint);
    void OnWordWrappingChanged(CObject* pHint);
    void OnTrimmingChanged(CObject* pHint);
    void OnDirectionChanged(CObject* pHint);
    void OnLineSpacingChanged(CObject* pHint);
    void OnIncrementalTabStopChanged(CObject* pHint);

private:
    // Demo functions
    void DemoTextAndParagraphAlignment(IDWriteTextFormat* pTextFormat);
    void DemoWordWrapping(IDWriteTextFormat* pTextFormat);
    void DemoTrimming(IDWriteTextFormat* pTextFormat);
    void DemoFlowAndReadingDirection(IDWriteTextFormat* pTextFormat);
    void DemoLineSpacing(IDWriteTextFormat* pTextFormat);
    void DemoIncrementalTabStop(IDWriteTextFormat* pTextFormat);

    // Implementation
    void SetTextFormat(CD2DTextFormat& textFormat);
    void FillTextBoxBackground(CHwndRenderTarget* pRenderTarget, CD2DRectF& rect);
    void CalculateTextBoxRectangle(CHwndRenderTarget* pRenderTarget, CD2DRectF& rect);
    void DrawTabStopLines(CHwndRenderTarget* pRenderTarget, CD2DTextFormat& textFormat, CD2DBrush* pBrush, CD2DRectF& rect);
    Framework::CTextFormatDocument* GetDocument();

    // Data
    Parameters::CAlignmentParameters m_alignmentParams;
    Parameters::CDirectionParameters m_directionParams;
    Parameters::CFontParameters m_fontParams;
    Parameters::CLineSpacingParameters m_lineSpacingParams;
    Parameters::CTabStopParameters m_tabStopParams;
    Parameters::CTrimmingParameters m_trimingParams;
    Parameters::CWordWrappingParameters m_wordWrappingParams;

    // text block margins relative to render targt area
    const FLOAT m_textBoxMargin{ 10.f };
};

