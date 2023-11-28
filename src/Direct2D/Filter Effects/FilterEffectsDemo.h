// File: FilterEffectsDemo.h - CFilterEffectsDemo class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Contains the drawing parameters and functions for Filter Effects demo samples 
// Note: Keep drawing stuff here, rather than in the view class.

#pragma once
#include "FilterEffectsDocument.h"
#include "Parameters.h"

class CFilterEffectsDemo : public CDemoDraw
{
public:
    CFilterEffectsDemo(CDemoView* pView);

    // Overridden
    virtual void DrawDemo(CHwndRenderTarget* pRenderTarget) override;

    // Operations
    void OnGaussianBlurChanged(CObject* pHint);
    void OnDirectionalBlurChanged(CObject* pHint);
    void OnEdgeDetectionChanged(CObject* pHint);
    void OnMorphologyChanged(CObject* pHint);

private:
    // Implementation
    void SelectBitmap(CD2DBitmap*& pBitmap);
    void DrawOriginalBitmap(CHwndRenderTarget* pRenderTarget, CD2DBitmap* pBitmap);
    void DrawGaussianBlurDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap);
    void DrawDirectionalBlurDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap);
    void DrawEdgeDetectDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap);
    void DrawMorphologyDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap);
 
    Framework::CFilterEffectsDocument* GetDocument();

    // Data
    Parameters::CGaussianBlurParameters m_gaussianBlurParams;
    Parameters::CDirectionalBlurParameters m_directionalBlurParams;
    Parameters::CEdgeDetectionParameters m_edgeDetectionParams;
    Parameters::CMorphologyParameters m_morphologyParams;
};

