// File: FilterEffectsDemo.cpp - CFilterEffectsDemo class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/ 
//         e-mail: ovidiu.cucu.mvp@gmail.com 

#include "pch.h"
#include "FilterEffectsDemo.h"

using Framework::CFilterEffectsDocument;
using namespace Parameters;

CFilterEffectsDemo::CFilterEffectsDemo(CDemoView* pView)
    : CDemoDraw(pView)
{
}

#pragma region Overridden
void CFilterEffectsDemo::DrawDemo(CHwndRenderTarget* pRenderTarget)
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
    case SampleId::gaussianBlur:
        DrawGaussianBlurDemo(spDeviceContext, pBitmap);
        break;
    case SampleId::directionalBlur:
        DrawDirectionalBlurDemo(spDeviceContext, pBitmap);
        break;
    case SampleId::edgeDetection:
        DrawEdgeDetectDemo(spDeviceContext, pBitmap);
        break;
    case SampleId::morphology:
        DrawMorphologyDemo(spDeviceContext, pBitmap);
        break;
    default:
        ATLTRACE("Unhandled SampleId");
        break;
    }
}
#pragma endregion

#pragma region Operations
void CFilterEffectsDemo::OnGaussianBlurChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CGaussianBlurParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_gaussianBlurParams = *pParams;
    InvalidateView();
}

void CFilterEffectsDemo::OnDirectionalBlurChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CDirectionalBlurParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_directionalBlurParams = *pParams;
    InvalidateView();
}

void CFilterEffectsDemo::OnEdgeDetectionChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CEdgeDetectionParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_edgeDetectionParams = *pParams;
    InvalidateView();
}

void CFilterEffectsDemo::OnMorphologyChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CMorphologyParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_morphologyParams = *pParams;
    InvalidateView();
}
#pragma endregion

#pragma region Implementation
void CFilterEffectsDemo::SelectBitmap(CD2DBitmap*& pBitmap)
{
    CFilterEffectsDocument* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    pBitmap = pDoc->GetBitmap();
}

void CFilterEffectsDemo::DrawOriginalBitmap(CHwndRenderTarget* pRenderTarget, CD2DBitmap* pBitmap)
{
    CD2DSizeF size = pBitmap->GetSize();
    CD2DRectF rect{ 0.f, 0.f, size.width, size.height };
    pRenderTarget->DrawBitmap(pBitmap, rect);
}

void CFilterEffectsDemo::DrawGaussianBlurDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap)
{
    // create Gaussian Blur effect
    CComPtr<ID2D1Effect> spEffect;
    spDeviceContext->CreateEffect(CLSID_D2D1GaussianBlur, &spEffect);

    // set the input image
    spEffect->SetInput(0, pBitmap->Get());

    // set "standard deviation" property between 0.f and 20.f (default is 3.0f)
    FLOAT standardDeviation = m_gaussianBlurParams.GetStandardDeviation();
    spEffect->SetValue(D2D1_GAUSSIANBLUR_PROP_STANDARD_DEVIATION, standardDeviation);

    // set "optimization" value (default is D2D1_DIRECTIONALBLUR_OPTIMIZATION_BALANCED)
    D2D1_DIRECTIONALBLUR_OPTIMIZATION optimization = m_gaussianBlurParams.GetOptimization();
    spEffect->SetValue(D2D1_GAUSSIANBLUR_PROP_OPTIMIZATION, optimization);

    // set "border mode" value (default is D2D1_DIRECTIONALBLUR_OPTIMIZATION_BALANCED)
    D2D1_BORDER_MODE borderMode = m_gaussianBlurParams.GetBorderMode();
    spEffect->SetValue(D2D1_GAUSSIANBLUR_PROP_BORDER_MODE, borderMode);

    // draw the image
    spDeviceContext->DrawImage(spEffect);
}

void CFilterEffectsDemo::DrawDirectionalBlurDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap)
{
    // create Directional Blur effect
    CComPtr<ID2D1Effect> spEffect;
    spDeviceContext->CreateEffect(CLSID_D2D1DirectionalBlur, &spEffect);

    // set the input image
    spEffect->SetInput(0, pBitmap->Get());

    // set "standard deviation" property between 0.f and 20.f (default is 3.0f)
    FLOAT standardDeviation = m_directionalBlurParams.GetStandardDeviation();
    spEffect->SetValue(D2D1_DIRECTIONALBLUR_PROP_STANDARD_DEVIATION, standardDeviation);

    // set "optimization" value (default is D2D1_DIRECTIONALBLUR_OPTIMIZATION_BALANCED)
    D2D1_DIRECTIONALBLUR_OPTIMIZATION optimization = m_directionalBlurParams.GetOptimization();
    spEffect->SetValue(D2D1_DIRECTIONALBLUR_PROP_OPTIMIZATION, optimization);

    // set "border mode" value (default is D2D1_DIRECTIONALBLUR_OPTIMIZATION_BALANCED)
    D2D1_BORDER_MODE borderMode = m_directionalBlurParams.GetBorderMode();
    spEffect->SetValue(D2D1_DIRECTIONALBLUR_PROP_BORDER_MODE, borderMode);

    // set "angle" value between 0.f and 180.f (default is 0.f)
    FLOAT angle = m_directionalBlurParams.GetAngle();
    spEffect->SetValue(D2D1_DIRECTIONALBLUR_PROP_ANGLE, angle);

    // draw the image
    spDeviceContext->DrawImage(spEffect);
}

void CFilterEffectsDemo::DrawEdgeDetectDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap)
{
    // create  Edge Detection effect
    CComPtr<ID2D1Effect> spEffect;
    spDeviceContext->CreateEffect(CLSID_D2D1EdgeDetection, &spEffect);

    // set the input image
    spEffect->SetInput(0, pBitmap->Get());

    // set "strength" value between 0.01f and 1.f (default is 0.5f)
    // DO NOT set 0 value, otherwise the drawing fails and an exception is thrown!
    FLOAT strength = m_edgeDetectionParams.GetStrength();
    spEffect->SetValue(D2D1_EDGEDETECTION_PROP_STRENGTH, strength);

    // set "blur radius" value between 0.f and 10.f (default is 0.f, i.e. "no blur")
    FLOAT blurRadius = m_edgeDetectionParams.GetBlurRadius();
    spEffect->SetValue(D2D1_EDGEDETECTION_PROP_BLUR_RADIUS, blurRadius);

    // set "mode" value (default is D2D1_EDGEDETECTION_MODE_SOBEL)
    D2D1_EDGEDETECTION_MODE mode = m_edgeDetectionParams.GetMode();
    spEffect->SetValue(D2D1_EDGEDETECTION_PROP_MODE, mode);

    // set "overlay edges" BOOL value (default is FALSE)
    BOOL bOverlayEdges = m_edgeDetectionParams.GetOverlayEdges();
    spEffect->SetValue(D2D1_EDGEDETECTION_PROP_OVERLAY_EDGES, bOverlayEdges);

    // set "alpha mode" value (default is D2D1_ALPHA_MODE_PREMULTIPLIED)
    D2D1_ALPHA_MODE alphaMode = m_edgeDetectionParams.GetAlphaMode();
    spEffect->SetValue(D2D1_EDGEDETECTION_PROP_ALPHA_MODE, alphaMode);

    // draw the image
    spDeviceContext->DrawImage(spEffect);
}

void CFilterEffectsDemo::DrawMorphologyDemo(CComPtr<ID2D1DeviceContext>& spDeviceContext, CD2DBitmap* pBitmap)
{
    // create Morphology effect
    CComPtr<ID2D1Effect> spEffect;
    spDeviceContext->CreateEffect(CLSID_D2D1Morphology, &spEffect);

    // set the input image
    spEffect->SetInput(0, pBitmap->Get());

    // set "mode" value (default is D2D1_MORPHOLOGY_MODE_ERODE)
    D2D1_MORPHOLOGY_MODE mode = m_morphologyParams.GetMode();
    spEffect->SetValue(D2D1_MORPHOLOGY_PROP_MODE, mode);

    // set "width" value between 1 and 100 (default is 1)
    UINT nWidth = m_morphologyParams.GetWidth();
    spEffect->SetValue(D2D1_MORPHOLOGY_PROP_WIDTH, nWidth);

    // set "height" value between 1 and 100 (default is 1)
    UINT nHeight = m_morphologyParams.GetHeight();
    spEffect->SetValue(D2D1_MORPHOLOGY_PROP_HEIGHT, nHeight);

    // draw the image
    spDeviceContext->DrawImage(spEffect);
}

CFilterEffectsDocument* CFilterEffectsDemo::GetDocument()
{
    return dynamic_cast<CFilterEffectsDocument*> (GetDemoDocument());
}
#pragma endregion
