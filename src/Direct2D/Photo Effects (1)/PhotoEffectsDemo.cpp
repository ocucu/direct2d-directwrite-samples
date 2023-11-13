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
    case SampleId::contrast:
        DrawContrastDemo(spDeviceContext, pBitmap);
        break;
    case SampleId::brightness:
        DrawBrightnessDemo(spDeviceContext, pBitmap);
        break;
    case SampleId::grayscale:
        DrawGrayscaleDemo(spDeviceContext, pBitmap);
        break;
    case SampleId::invert:
        DrawInvertDemo(spDeviceContext, pBitmap);
        break;
    case SampleId::sepia:
        DrawSepiaDemo(spDeviceContext, pBitmap);
        break;
    case SampleId::exposure:
        DrawExposureDemo(spDeviceContext, pBitmap);
        break;
    default:
        ATLTRACE("Unhandled SampleId");
        break;
    }
}
#pragma endregion

#pragma region Operations
void CPhotoEffectsDemo::OnContrastChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CContrastParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_contrastParams = *pParams;
    InvalidateView();
}

void CPhotoEffectsDemo::OnBrightnessChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CBrightnessParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_brightnessParams = *pParams;
    InvalidateView();
}

void CPhotoEffectsDemo::OnSepiaChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CSepiaParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_sepiaParams = *pParams;
    InvalidateView();
}

void CPhotoEffectsDemo::OnExposureChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CExposureParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_exposureParams = *pParams;
    InvalidateView();
}
#pragma endregion

#pragma region Implementation
void CPhotoEffectsDemo::SelectBitmap(CD2DBitmap*& pBitmap)
{
    CPhotoEffectsDocument* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    BitmapId bitmapId = pDoc->GetSampleBitmapId();
    switch (bitmapId)
    {
    case BitmapId::cat:
        pBitmap = pDoc->GetCatBitmap();
        break;
    case BitmapId::pencil:
        pBitmap = pDoc->GetPencilBitmap();
        break;
    case BitmapId::grayscale:
        pBitmap = pDoc->GetGrayscaleBitmap();
        break;
    default:
        ATLTRACE("Unhandled BitmapId");
    }
}

void CPhotoEffectsDemo::DrawOriginalBitmap(CHwndRenderTarget* pRenderTarget, CD2DBitmap* pBitmap)
{
    CD2DSizeF size = pBitmap->GetSize();
    CD2DRectF rect{ 0.f, 0.f, size.width, size.height };
    pRenderTarget->DrawBitmap(pBitmap, rect);
}

void CPhotoEffectsDemo::DrawContrastDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap)
{
    // create contrast effect
    CComPtr<ID2D1Effect> spEffect;
    spDeviceContext->CreateEffect(CLSID_D2D1Contrast, &spEffect);

    // set the input image
    spEffect->SetInput(0, pBitmap->Get());
    // set "contrast" property between -1.f and 1.f (default is 0.f)
    // note: it seems that it has no effect; just putting it on for testing. 
    FLOAT contrast = m_contrastParams.GetContrast();
    spEffect->SetValue(D2D1_CONTRAST_PROP_CONTRAST, contrast);

    // draw the image
    spDeviceContext->DrawImage(spEffect);
}

void CPhotoEffectsDemo::DrawBrightnessDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap)
{
    // create brightness effect
    CComPtr<ID2D1Effect> spEffect;
    spDeviceContext->CreateEffect(CLSID_D2D1Brightness, &spEffect);

    // set the input image
    spEffect->SetInput(0, pBitmap->Get());

    // set white point
    D2D1_VECTOR_2F whitePoint = m_brightnessParams.GetWhitePoint();
    spEffect->SetValue(D2D1_BRIGHTNESS_PROP_WHITE_POINT, whitePoint);

    // set black point
    D2D1_VECTOR_2F blackPoint = m_brightnessParams.GetBlackPoint();
    spEffect->SetValue(D2D1_BRIGHTNESS_PROP_BLACK_POINT, blackPoint);

    // draw the image
    spDeviceContext->DrawImage(spEffect);
}

void CPhotoEffectsDemo::DrawGrayscaleDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap)
{
    // create grayscale effect
    CComPtr<ID2D1Effect> spEffect;
    spDeviceContext->CreateEffect(CLSID_D2D1Grayscale, &spEffect);

    // set the input image
    spEffect->SetInput(0, pBitmap->Get());

    // draw the image
    spDeviceContext->DrawImage(spEffect);
}

void CPhotoEffectsDemo::DrawInvertDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap)
{
    // create invert effect
    CComPtr<ID2D1Effect> spEffect;
    spDeviceContext->CreateEffect(CLSID_D2D1Invert, &spEffect);

    // set the input image
    spEffect->SetInput(0, pBitmap->Get());

    // draw the image
    spDeviceContext->DrawImage(spEffect);
}

void CPhotoEffectsDemo::DrawSepiaDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap)
{
    // create sepia effect
    CComPtr<ID2D1Effect> spEffect;
    spDeviceContext->CreateEffect(CLSID_D2D1Sepia, &spEffect);

    // set the input image
    spEffect->SetInput(0, pBitmap->Get());

    // set intensity
    FLOAT intensity = m_sepiaParams.GetIntensity();
    spEffect->SetValue(D2D1_SEPIA_PROP_INTENSITY, intensity);

    // set alpha mode
    D2D1_ALPHA_MODE alphaMode = m_sepiaParams.GetAlphaMode();
    spEffect->SetValue(D2D1_SEPIA_PROP_ALPHA_MODE, alphaMode);

    // draw the image
    spDeviceContext->DrawImage(spEffect);
}

void CPhotoEffectsDemo::DrawExposureDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap)
{
    // create exposure effect
    CComPtr<ID2D1Effect> spEffect;
    spDeviceContext->CreateEffect(CLSID_D2D1Exposure, &spEffect);

    // set the input image
    spEffect->SetInput(0, pBitmap->Get());

    // set exposure value
    FLOAT value = m_exposureParams.GetValue();
    spEffect->SetValue(D2D1_EXPOSURE_PROP_EXPOSURE_VALUE, value);

    // draw the image
    spDeviceContext->DrawImage(spEffect);
}

CPhotoEffectsDocument* CPhotoEffectsDemo::GetDocument()
{
    return dynamic_cast<CPhotoEffectsDocument*> (GetDemoDocument());
}
#pragma endregion
