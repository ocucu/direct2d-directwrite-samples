// File: PhotoEffectsDemo.cpp - CPhotoEffectsDemo class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "PhotoEffectsDemo.h"

using Framework::CPhotoEffectsDocument;
using namespace Parameters;

CPhotoEffectsDemo::CPhotoEffectsDemo(CDemoView* pView)
    : CDemoDraw(pView)
{
}

#pragma region Overridden
void CPhotoEffectsDemo::DrawDemo(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);

    // select and draw the original bitmap
    CD2DBitmap* pBitmap{ NULL };
    SelectBitmap(pBitmap);
    VERIFY_D2D_RESOURCE(pBitmap);
    DrawOriginalBitmap(pRenderTarget, pBitmap);

    // translate the render target in order to draw at the right of original bitmap
    CD2DSizeF size = pBitmap->GetSize();
    D2D1_MATRIX_3X2_F matrix = D2D1::Matrix3x2F::Translation(size.width, 0);
    pRenderTarget->SetTransform(matrix);

    // get ID2D1DeviceContext interface
    CComQIPtr<ID2D1DeviceContext> spDeviceContext = *pRenderTarget;

    SampleId sampleId = GetDemoFrame()->GetActivePaneId();
    switch (sampleId)
    {
    case SampleId::sharpen:
        DrawSharpenDemo(spDeviceContext, pBitmap);
        break;
    case SampleId::straighten:
        DrawStraightenDemo(spDeviceContext, pBitmap);
        break;
    case SampleId::vignette:
        DrawVignetteDemo(spDeviceContext, pBitmap);
        break;
    case SampleId::highlightsAndShadows:
        DrawHighlightsAndShadowsDemo(spDeviceContext, pBitmap);
        break;
    case SampleId::temperatureAndTint:
        DrawTemperatureAndTintDemo(spDeviceContext, pBitmap);
        break;
    default:
        ATLTRACE("Unhandled SampleId");
        break;
    }
}
#pragma endregion

#pragma region Operations
void CPhotoEffectsDemo::OnSharpenChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CSharpenParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_sharpenParams = *pParams;
    InvalidateView();
}

void CPhotoEffectsDemo::OnStraightenChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CStraightenParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_straightenParams = *pParams;
    InvalidateView();
}

void CPhotoEffectsDemo::OnVignetteChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CVignetteParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_vignetteParams = *pParams;
    InvalidateView();
}

void CPhotoEffectsDemo::OnHighlightsAndShadowsChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CHighlightsAndShadowsParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_highlightsAndShadowsParams = *pParams;
    InvalidateView();
}

void CPhotoEffectsDemo::OnTemperatureAndTintChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CTemperatureAndTintParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_temperatureAndTintParams = *pParams;
    InvalidateView();
}
#pragma endregion

#pragma region Implementation
void CPhotoEffectsDemo::SelectBitmap(CD2DBitmap*& pBitmap)
{
    CPhotoEffectsDocument* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    pBitmap = pDoc->GetBitmap();
}

void CPhotoEffectsDemo::DrawOriginalBitmap(CHwndRenderTarget* pRenderTarget, CD2DBitmap* pBitmap)
{
    CD2DSizeF size = pBitmap->GetSize();
    CD2DRectF rect{ 0.f, 0.f, size.width, size.height };
    pRenderTarget->DrawBitmap(pBitmap, rect);
}

void CPhotoEffectsDemo::DrawSharpenDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap)
{
    // create sharpen effect
    CComPtr<ID2D1Effect> spEffect;
    spDeviceContext->CreateEffect(CLSID_D2D1Sharpen, &spEffect);

    // set the input image
    spEffect->SetInput(0, pBitmap->Get());

    // set "sharpness" property between 0.f and 10.f (default is 0.f)
    FLOAT sharpness = m_sharpenParams.GetSharpness();
    spEffect->SetValue(D2D1_SHARPEN_PROP_SHARPNESS, sharpness);

    // set "threshold" property between 0.f and 1.f (default is 0.f)
    FLOAT threshold = m_sharpenParams.GetThreshold();
    spEffect->SetValue(D2D1_SHARPEN_PROP_THRESHOLD, threshold);

    // draw the image
    spDeviceContext->DrawImage(spEffect);
}

void CPhotoEffectsDemo::DrawStraightenDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap)
{
    // create straighten effect
    CComPtr<ID2D1Effect> spEffect;
    spDeviceContext->CreateEffect(CLSID_D2D1Straighten, &spEffect);

    // set the input image
    spEffect->SetInput(0, pBitmap->Get());

    // set "angle" property between -45.f and 45.f (default is 0.f)
    FLOAT angle = m_straightenParams.GetAngle();
    spEffect->SetValue(D2D1_STRAIGHTEN_PROP_ANGLE, angle);

    // set "maintain size" property (default value is FALSE)
    BOOL bMaintainSize = m_straightenParams.GetMaintainSize();
    spEffect->SetValue(D2D1_STRAIGHTEN_PROP_MAINTAIN_SIZE, bMaintainSize);

    // set "scale mode" property
    D2D1_STRAIGHTEN_SCALE_MODE scaleMode = m_straightenParams.GetScaleMode();
    spEffect->SetValue(D2D1_STRAIGHTEN_PROP_SCALE_MODE, scaleMode);

    // draw the image
    spDeviceContext->DrawImage(spEffect);
}

void CPhotoEffectsDemo::DrawVignetteDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap)
{
    // create vignette effect
    CComPtr<ID2D1Effect> spEffect;
    spDeviceContext->CreateEffect(CLSID_D2D1Vignette, &spEffect);

    // set the input image
    spEffect->SetInput(0, pBitmap->Get());

    // set "color" property (default "black", opacity 1.f)
    D2D1::ColorF color = m_vignetteParams.GetColor();
    spEffect->SetValue(D2D1_VIGNETTE_PROP_COLOR, color);

    // set "transition size" property between 0.f and 1.f (default 0.1f)
    FLOAT transitionSize = m_vignetteParams.GetTransitionSize();
    spEffect->SetValue(D2D1_VIGNETTE_PROP_TRANSITION_SIZE, transitionSize);

    // set "strength" property between 0.f and 1.f (default 0.5f)
    FLOAT strength = m_vignetteParams.GetStrength();
    spEffect->SetValue(D2D1_VIGNETTE_PROP_STRENGTH, strength);

    // draw the image
    spDeviceContext->DrawImage(spEffect);
}

void CPhotoEffectsDemo::DrawHighlightsAndShadowsDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap)
{
    // create highlights and shadows effect
    CComPtr<ID2D1Effect> spEffect;
    spDeviceContext->CreateEffect(CLSID_D2D1HighlightsShadows, &spEffect);

    // set the input image
    spEffect->SetInput(0, pBitmap->Get());

    // set "highlights" property between -1.f and 1.f (default 0.f)
    FLOAT highlights = m_highlightsAndShadowsParams.GetHighlights();
    spEffect->SetValue(D2D1_HIGHLIGHTSANDSHADOWS_PROP_HIGHLIGHTS, highlights);

    // set "shadows" property between -1.f and 1.f (default 0.f)
    FLOAT shadows = m_highlightsAndShadowsParams.GetShadows();
    spEffect->SetValue(D2D1_HIGHLIGHTSANDSHADOWS_PROP_SHADOWS, shadows);

    // set "clarity" property between -1.f and 1.f (default 0.f)
    FLOAT clarity = m_highlightsAndShadowsParams.GetClarity();
    spEffect->SetValue(D2D1_HIGHLIGHTSANDSHADOWS_PROP_CLARITY, clarity);

    // set "input gamma" property (defult D2D1_HIGHLIGHTSANDSHADOWS_INPUT_GAMMA_SRGB) 
    D2D1_HIGHLIGHTSANDSHADOWS_INPUT_GAMMA inputGamma = m_highlightsAndShadowsParams.GetInputGamma();
    spEffect->SetValue(D2D1_HIGHLIGHTSANDSHADOWS_PROP_INPUT_GAMMA, inputGamma);

    // set "mask blur radius" property between 0.f and 10.f (default 1.2f)
    FLOAT maskBlurRadius = m_highlightsAndShadowsParams.GetMaskBlurRadius();
    spEffect->SetValue(D2D1_HIGHLIGHTSANDSHADOWS_PROP_MASK_BLUR_RADIUS, maskBlurRadius);

    // draw the image
    spDeviceContext->DrawImage(spEffect);

}

void CPhotoEffectsDemo::DrawTemperatureAndTintDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap)
{
    // create temperature and tint effect
    CComPtr<ID2D1Effect> spEffect;
    spDeviceContext->CreateEffect(CLSID_D2D1TemperatureTint, &spEffect);

    // set the input image
    spEffect->SetInput(0, pBitmap->Get());

    // set "temperature" property between -1,f and 1,f (default is 0.f)
    FLOAT temperature = m_temperatureAndTintParams.GetTemperature();
    spEffect->SetValue(D2D1_TEMPERATUREANDTINT_PROP_TEMPERATURE, temperature);

    // set "tint" property between -1,f and 1,f (default is 0.f)
    FLOAT tint = m_temperatureAndTintParams.GetTint();
    spEffect->SetValue(D2D1_TEMPERATUREANDTINT_PROP_TINT, tint);

    // draw the image
    spDeviceContext->DrawImage(spEffect);
}

CPhotoEffectsDocument* CPhotoEffectsDemo::GetDocument()
{
    return dynamic_cast<CPhotoEffectsDocument*> (GetDemoDocument());
}
#pragma endregion
