// File: PhotoEffectsDemo.h - CPhotoEffectsDemo class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Contains the drawing parameters and functions for Brush Transforms demo samples 
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
    void OnContrastChanged(CObject* pHint);
    void OnBrightnessChanged(CObject* pHint);
    void OnSepiaChanged(CObject* pHint);
    void OnExposureChanged(CObject* pHint);

private:
    // Implementation
    void SelectBitmap(CD2DBitmap*& pBitmap);
    void DrawOriginalBitmap(CHwndRenderTarget* pRenderTarget, CD2DBitmap* pBitmap);
    void DrawContrastDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap);
    void DrawBrightnessDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap);
    void DrawGrayscaleDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap);
    void DrawInvertDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap);
    void DrawSepiaDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap);
    void DrawExposureDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap);
 
    Framework::CPhotoEffectsDocument* GetDocument();

    // Data
    Parameters::CContrastParameters m_contrastParams;
    Parameters::CBrightnessParameters m_brightnessParams;
    Parameters::CSepiaParameters m_sepiaParams;
    Parameters::CExposureParameters m_exposureParams;
    
};

