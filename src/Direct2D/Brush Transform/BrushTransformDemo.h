// File: BrushTransformDemo.h - CBrushTransformDemo class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Contains the drawing parameters and functions for Brush Transforms demo samples 
// Note: Keep drawing stuff here, rather than in the view class.

#pragma once
#include "BrushTransformDocument.h"
#include "Parameters.h"

class CBrushTransformDemo : public CDemoDraw
{
public:
    CBrushTransformDemo(CDemoView* pView);

    // Overridden
    virtual void DrawDemo(CHwndRenderTarget* pRenderTarget) override;

    // Operations
    void OnTranslationChanged(CObject* pHint);
    void OnRotationChanged(CObject* pHint);
    void OnScaleChanged(CObject* pHint);
    void OnSkewChanged(CObject* pHint);

private:
    // Implementation
    void SelectBrush(CD2DBrush*& pBrush);
    void ApplyTranslationTransform(CD2DBrush*& pBrush);
    void ApplyRotationTransform(CD2DBrush*& pBrush);
    void ApplyScaleTransform(CD2DBrush*& pBrush);
    void ApplySkewTransform(CD2DBrush*& pBrush);
    Framework::CBrushTransformDocument* GetDocument();

    // Data
    Parameters::CTranslationParameters m_translationParams;
    Parameters::CScaleParameters m_scaleParams;
    Parameters::CRotationParameters m_rotationParams;
    Parameters::CSkewParmeters m_skewParams;
};

