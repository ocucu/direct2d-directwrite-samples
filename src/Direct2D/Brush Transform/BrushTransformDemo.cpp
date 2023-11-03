// File: BrushTransformDemo.cpp - CBrushTransformDemo class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "BrushTransformDemo.h"

using Framework::CBrushTransformDocument;
using namespace Parameters;

CBrushTransformDemo::CBrushTransformDemo(CDemoView* pView)
    : CDemoDraw(pView)
{
}

#pragma region Overridden
void CBrushTransformDemo::DrawDemo(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);

    CD2DBrush* pBrush{ NULL };
    SelectBrush(pBrush);
    VERIFY_D2D_RESOURCE(pBrush);

    D2D1_MATRIX_3X2_F matrix = D2D1::Matrix3x2F::Identity();
    pBrush->SetTransform(&matrix);
    CD2DSizeF size = pRenderTarget->GetSize();
    CD2DRectF rect{ 0.f, 0.f, size.width / 2.f, size.height };
    pRenderTarget->FillRectangle(rect, pBrush);

    SampleId sampleId = GetDemoFrame()->GetActivePaneId();
    switch (sampleId)
    {
    case SampleId::translation:
        ApplyTranslationTransform(pBrush);
        break;
    case SampleId::rotation:
        ApplyRotationTransform(pBrush);
        break;
    case SampleId::scale:
        ApplyScaleTransform(pBrush);
        break;
    case SampleId::skew:
        ApplySkewTransform(pBrush);
        break;
    default:
        ATLTRACE("Unhandled SampleId");
    }

    pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(CD2DSizeF(size.width / 2.f, 0.f)));
    pRenderTarget->FillRectangle(rect, pBrush);
}
#pragma endregion

#pragma region Operations
void CBrushTransformDemo::OnTranslationChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CTranslationParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_translationParams = *pParams;
    InvalidateView();
}

void CBrushTransformDemo::OnRotationChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CRotationParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_rotationParams = *pParams;
    InvalidateView();
}

void CBrushTransformDemo::OnScaleChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CScaleParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_scaleParams = *pParams;
    InvalidateView();
}

void CBrushTransformDemo::OnSkewChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CSkewParmeters*>(pHint);
    ASSERT_VALID(pParams);
    m_skewParams = *pParams;
    InvalidateView();
}
#pragma endregion

#pragma region Implementation
void CBrushTransformDemo::SelectBrush(CD2DBrush*& pBrush)
{
    CBrushTransformDocument* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    BrushTypeId brushTypeId = pDoc->GetSampleBrushTypeId();
    switch (brushTypeId)
    {
    case BrushTypeId::bitmap:
        pBrush = pDoc->GetSampleBitmapBrush();
        break;
    case BrushTypeId::linearGradient:
        pBrush = pDoc->GetSampleLinearGradientBrush();
        break;
    case BrushTypeId::radialGradient:
        pBrush = pDoc->GetSampleRadialGradientBrush();
        break;
    default:
        ATLTRACE("Unhandled BrushTypeId");
        break;
    }
}

void CBrushTransformDemo::ApplyTranslationTransform(CD2DBrush*& pBrush)
{
    CD2DSizeF size = m_translationParams.GetSize();
    D2D1_MATRIX_3X2_F matrix = D2D1::Matrix3x2F::Translation(size);
    pBrush->SetTransform(&matrix);
}

void CBrushTransformDemo::ApplyRotationTransform(CD2DBrush*& pBrush)
{
    FLOAT angle = m_rotationParams.GetAngle();
    CD2DPointF center = m_rotationParams.GetCenter();
    D2D1_MATRIX_3X2_F matrix = D2D1::Matrix3x2F::Rotation(angle, center);
    pBrush->SetTransform(&matrix);
}

void CBrushTransformDemo::ApplyScaleTransform(CD2DBrush*& pBrush)
{
    CD2DSizeF size = m_scaleParams.GetSize();
    CD2DPointF center = m_scaleParams.GetCenter();
    D2D1_MATRIX_3X2_F matrix = D2D1::Matrix3x2F::Scale(size, center);
    pBrush->SetTransform(&matrix);
}

void CBrushTransformDemo::ApplySkewTransform(CD2DBrush*& pBrush)
{
    FLOAT angleX = m_skewParams.GetAngleX();
    FLOAT angleY = m_skewParams.GetAngleY();
    CD2DPointF center = m_skewParams.GetCenter();
    D2D1_MATRIX_3X2_F matrix = D2D1::Matrix3x2F::Skew(angleX, angleY, center);
    pBrush->SetTransform(&matrix);
}

CBrushTransformDocument* CBrushTransformDemo::GetDocument()
{
    return dynamic_cast<CBrushTransformDocument*> (GetDemoDocument());
}
#pragma endregion
