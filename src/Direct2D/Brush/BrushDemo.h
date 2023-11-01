// File: BrushDemo.h - CBrushDemo class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Contains the drawing parameters and functions for Render Target Transforms demo samples 
// Note: Keep drawing stuff here, rather than in the view class.

#pragma once
#include "BrushDocument.h"
#include "Parameters.h"

class CBrushDemo : public CDemoDraw
{
public:
    CBrushDemo(CDemoView* pView);

    // Overridden
    virtual void DrawDemo(CHwndRenderTarget* pRenderTarget) override;

    // Operations
    void OnSolidColorBrushChanged(CObject* pHint);
    void OnBitmapBrushChanged(CObject* pHint);
    void OnLinearGradientBrushChanged(CObject* pHint);
    void OnRadialGradiontBrushChanged(CObject* pHint);

private:
    // Implementation
    void DrawSolidColorBrushDemo(CHwndRenderTarget* pRenderTarget);
    void DrawBitmapBrushDemo(CHwndRenderTarget* pRenderTarget);
    void DrawLinearGradientBrushDemo(CHwndRenderTarget* pRenderTarget);
    void DrawRadialGradientBrushDemo(CHwndRenderTarget* pRenderTarget);
    void FillDemo(CHwndRenderTarget* pRenderTarget, CD2DBrush& brush);
    void FillDemoRenderTarget(CHwndRenderTarget* pRenderTarget, CD2DBrush& brush);
    void FillDemoRectangle(CHwndRenderTarget* pRenderTarget, CD2DBrush& brush);
    void FillDemoEllipse(CHwndRenderTarget* pRenderTarget, CD2DBrush& brush);
    void DrawInfoText(CHwndRenderTarget* pRenderTarget, const CString& strText);

    Framework::CBrushDocument* GetDocument();

    // Data
    // brush parameters
    Parameters::CSolidColorBrushParameters m_solidColorBrushParams;
    Parameters::CBitmapBrushParameters m_bitmapBrushParams;
    Parameters::CLinearGradientBrushParameters m_linearGradientBrushParams;
    Parameters::CRadialGradientBrushParameters m_radialGradientBrushParams;

    const CD2DRectF m_fillRectangle{ 30.f, 35.f, 436.f, 360.f };
};

