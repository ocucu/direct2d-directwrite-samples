// File: RenderTargetTransformDemo.h - CRenderTargetTransformDemo class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Contains the drawing parameters and functions for Render Target Transforms demo samples 
// Note: Keep drawing stuff here, rather than in the view class.

#pragma once
#include "RenderTargetTransformDocument.h"
#include "Parameters.h"

class CRenderTargetTransformDemo : public CDemoDraw
{
public:
    CRenderTargetTransformDemo(CDemoView* pView);

    // Overridden
    virtual void DrawDemo(CHwndRenderTarget* pRenderTarget) override;

    // Operations
    void OnTranslationChanged(CObject* pHint);
    void OnRotationChanged(CObject* pHint);
    void OnScaleChanged(CObject* pHint);
    void OnSkewChanged(CObject* pHint);

private:
    // Demo functions
    void DemoTranslation(CHwndRenderTarget* pRenderTarget);
    void DemoRotation(CHwndRenderTarget* pRenderTarget);
    void DemoScale(CHwndRenderTarget* pRenderTarget);
    void DemoSkew(CHwndRenderTarget* pRenderTarget);

    // Implementation
    void DrawDemoFigure(CHwndRenderTarget* pRenderTarget, FLOAT opacity = 1.f);
    void DrawDemoRectangle(CHwndRenderTarget* pRenderTarget, FLOAT opacity);
    void DrawDemoArrow(CHwndRenderTarget* pRenderTarget, FLOAT opacity);
    void DrawDemoPicture(CHwndRenderTarget* pRenderTarget, FLOAT opacity);
    void DrawCenter(CHwndRenderTarget* pRenderTarget, const CD2DPointF& center, CD2DBitmap* pBitmap);
    void DrawInfoText(CHwndRenderTarget* pRenderTarget);
    D2D1_MATRIX_3X2_F TranslationToCenter(CHwndRenderTarget* pRenderTarget, const CD2DRectF& rectFigure);

    Framework::CRenderTargetTransformDocument* GetDocument();

    // Data
    Parameters::CTranslationParameters m_translationParams;
    Parameters::CScaleParameters m_scaleParams;
    Parameters::CRotationParameters m_rotationParams;
    Parameters::CSkewParmeters m_skewParams;

    // drawing attributes
    const CD2DRectF m_rectangle{ 0.f, 0.f, 240.f, 180.f };
    const CD2DSizeF m_sizeCenterBitmap{ 24.f, 24.f };
};

