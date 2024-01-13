// File: PhotoEffectsDemo.h - CPhotoEffectsDemo class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Contains the drawing parameters and functions for Photo Effects demo samples 
// Note: Keep drawing stuff here, rather than in the view class.

#pragma once
#include "PhotoEffectsDocument.h"
#include "Parameters.h"

class CPhotoEffectsDemo : public CDemoDraw
{
public:
    CPhotoEffectsDemo(CDemoView* pView);

    // Overridden
    virtual void DrawDemo(CHwndRenderTarget* pRenderTarget) override;

    // Operations
    void OnSharpenChanged(CObject* pHint);
    void OnStraightenChanged(CObject* pHint);
    void OnVignetteChanged(CObject* pHint);
    void OnHighlightsAndShadowsChanged(CObject* pHint);
    void OnTemperatureAndTintChanged(CObject* pHint);

private:
    // Demo functions
    void DemoSharpen(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap);
    void DemoStraighten(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap);
    void DemoVignette(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap);
    void DemoHighlightsAndShadows(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap);
    void DemoTemperatureAndTint(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap);
 
    // Implementation
    void SelectBitmap(CD2DBitmap*& pBitmap);
    void DrawOriginalBitmap(CHwndRenderTarget* pRenderTarget, CD2DBitmap* pBitmap);
    Framework::CPhotoEffectsDocument* GetDocument();

    // Data
    Parameters::CSharpenParameters m_sharpenParams;
    Parameters::CStraightenParameters m_straightenParams;
    Parameters::CVignetteParameters m_vignetteParams;
    Parameters::CHighlightsAndShadowsParameters m_highlightsAndShadowsParams;
    Parameters::CTemperatureAndTintParameters m_temperatureAndTintParams;
};

