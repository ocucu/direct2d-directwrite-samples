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

private:
    // Demo functions
    void DemoTextRangeFormat(CHwndRenderTarget* pRenderTarget, CD2DTextFormat& textFormat, const CD2DSizeF& sizeMax);
    
    // Implementation
    void FillTextLayoutBackground(CHwndRenderTarget* pRenderTarget, const CD2DSizeF& sizeMax);
    Framework::CTextLayoutDocument* GetDocument();

    // Data
    Parameters::CRangeFormatParameters m_rangeFormatParams;
};

