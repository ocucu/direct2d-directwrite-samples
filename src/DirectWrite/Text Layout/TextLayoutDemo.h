// File: TextLayoutDemo.h - CTextLayoutDemo class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Contains the drawing parameters and functions for Filter Effects demo samples 
// Note: Keep drawing stuff here, rather than in the view class.

#pragma once
#include "TextLayoutDocument.h"
#include "Parameters.h"

class CTextLayoutDemo : public CDemoDraw
{
public:
    CTextLayoutDemo(CDemoView* pView);

    // Overridden
    virtual void DrawDemo(CHwndRenderTarget* pRenderTarget) override;

    // Operations
    void OnRangeFormatChanged(CObject* pHint);
    void OnDrawingEffectsChanged(CObject* pHint);

private:
    // Demo functions
    void DemoTextRangeFormat(CHwndRenderTarget* pRenderTarget, CD2DTextFormat& textFormat);
    void DemoDrawingEffects(CHwndRenderTarget* pRenderTarget, CD2DTextFormat& textFormat);
    
    // Implementation
    void SelectSampleBrush(CD2DBrush*& pBrush);
    void FillTextLayoutBackground(CHwndRenderTarget* pRenderTarget, const CD2DSizeF& sizeMax);
    Framework::CTextLayoutDocument* GetDocument();

    // Data
    Parameters::CRangeFormatParameters m_rangeFormatParams;
    Parameters::CDrawingEffectsParameters m_drawingEffectsParams;
};

