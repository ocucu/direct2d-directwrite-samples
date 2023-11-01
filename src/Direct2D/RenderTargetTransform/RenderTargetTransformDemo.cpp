// File: RenderTargetTransformDemo.cpp - CRenderTargetTransformDemo class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "RenderTargetTransformDemo.h"

using Framework::CRenderTargetTransformDocument;
using namespace Parameters;

CRenderTargetTransformDemo::CRenderTargetTransformDemo(CDemoView* pView)
    : CDemoDraw(pView)
{
}

#pragma region Overridden
void CRenderTargetTransformDemo::DrawDemo(CHwndRenderTarget* pRenderTarget)
{   
    VERIFY_D2D_RESOURCE(pRenderTarget);
 
    SampleId sampleId = GetDemoFrame()->GetActivePaneId();
    switch (sampleId)
    {
    case SampleId::translation:
        DrawTranslationSample(pRenderTarget);
        break;
    case SampleId::rotation:
        DrawRotationSample(pRenderTarget);
        break;
    case SampleId::scale:
        DrawScaleSample(pRenderTarget);
        break;
    case SampleId::skew:
        DrawSkewSample(pRenderTarget);
        break;
    default:
        ATLTRACE("Unhandled SampleId value");
        break;
    }
    pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
    DrawInfoText(pRenderTarget);
}
#pragma endregion

#pragma region Operations
void CRenderTargetTransformDemo::OnTranslationChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CTranslationParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_translationParams = *pParams;
    if (pParams->GetRedrawFlag())
        InvalidateView();
}

void CRenderTargetTransformDemo::OnRotationChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CRotationParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_rotationParams = *pParams;
    if (pParams->GetRedrawFlag())
        InvalidateView();
}

void CRenderTargetTransformDemo::OnScaleChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CScaleParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_scaleParams = *pParams;
    if (pParams->GetRedrawFlag())
        InvalidateView();
}

void CRenderTargetTransformDemo::OnSkewChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CSkewParmeters*>(pHint);
    ASSERT_VALID(pParams);
    m_skewParams = *pParams;
    if (pParams->GetRedrawFlag())
        InvalidateView();
}
#pragma endregion

#pragma region Implementation
void CRenderTargetTransformDemo::DrawTranslationSample(CHwndRenderTarget* pRenderTarget)
{
    CD2DSizeF size = m_translationParams.GetSize();
    D2D1_MATRIX_3X2_F translation = D2D1::Matrix3x2F::Translation(size);
    // draw translated figure
    pRenderTarget->SetTransform(translation);
    DrawDemoFigure(pRenderTarget);
    // draw non-translated "hollow" figure
    pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
    DrawDemoFigure(pRenderTarget, 0.2f);
}

void CRenderTargetTransformDemo::DrawRotationSample(CHwndRenderTarget* pRenderTarget)
{
    FLOAT angle = m_rotationParams.GetAngle();
    CD2DPointF center = m_rotationParams.GetCenter();
    D2D1_MATRIX_3X2_F rotation = D2D1::Matrix3x2F::Rotation(angle, center);
    D2D1_MATRIX_3X2_F translation = TranslationToCenter(pRenderTarget, m_rectangle);

    // draw rotated figure
    pRenderTarget->SetTransform(rotation * translation);
    DrawDemoFigure(pRenderTarget);
    // draw non-rotated "hollow" figure
    pRenderTarget->SetTransform(translation);
    DrawDemoFigure(pRenderTarget, 0.2f);
    // draw rotation center pont
    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    DrawCenter(pRenderTarget, center, pDoc->GetRotateCenterBitmap());
}

void CRenderTargetTransformDemo::DrawScaleSample(CHwndRenderTarget* pRenderTarget)
{
    CD2DSizeF size = m_scaleParams.GetSize();
    CD2DPointF center = m_scaleParams.GetCenter();
    D2D1_MATRIX_3X2_F scale = D2D1::Matrix3x2F::Scale(size, center);
    D2D1_MATRIX_3X2_F translation = TranslationToCenter(pRenderTarget, m_rectangle);

    // draw scaled figure
    pRenderTarget->SetTransform(scale * translation);
    DrawDemoFigure(pRenderTarget);
    // draw non-scaled "hollow" figure
    pRenderTarget->SetTransform(translation);
    DrawDemoFigure(pRenderTarget, 0.2f);
    // draw scale center point
    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    DrawCenter(pRenderTarget, center, pDoc->GetScaleCenterBitmap());
}

void CRenderTargetTransformDemo::DrawSkewSample(CHwndRenderTarget* pRenderTarget)
{
    FLOAT angleX = m_skewParams.GetAngleX();
    FLOAT angleY = m_skewParams.GetAngleY();
    CD2DPointF center = m_skewParams.GetCenter();
    D2D1_MATRIX_3X2_F skew = D2D1::Matrix3x2F::Skew(angleX, angleY, center);
    D2D1_MATRIX_3X2_F translation = TranslationToCenter(pRenderTarget, m_rectangle);
    
    // draw skewed figure 
    pRenderTarget->SetTransform(skew * translation);
    DrawDemoFigure(pRenderTarget);
    // draw non-skewed "hollow" figure 
    pRenderTarget->SetTransform(translation);
    DrawDemoFigure(pRenderTarget, 0.2f);
    // draw skew center point
    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    DrawCenter(pRenderTarget, center, pDoc->GetSkewCenterBitmap());
}

void CRenderTargetTransformDemo::DrawDemoFigure(CHwndRenderTarget* pRenderTarget, FLOAT opacity /*= 1.f*/)
{
    FigureId figureId = GetDemoDocument()->GetSampleFigureId();
    switch (figureId)
    {
    case FigureId::rectangle:
        DrawDemoRectangle(pRenderTarget, opacity);
        break;
    case FigureId::arrow:
        DrawDemoArrow(pRenderTarget, opacity);
        break;
    case FigureId::picture:
        DrawDemoPicture(pRenderTarget, opacity);
        break;
    default:
        ATLTRACE("Unhandled FigureId value");
        break;
    }
}

void CRenderTargetTransformDemo::DrawDemoRectangle(CHwndRenderTarget* pRenderTarget, FLOAT opacity)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    auto pFillBrush = pDoc->GetFillBrush();
    VERIFY_D2D_RESOURCE(pFillBrush);
    auto pLineBrush = pDoc->GetLineBrush();
    VERIFY_D2D_RESOURCE(pLineBrush);

    pFillBrush->SetOpacity(opacity);
    pLineBrush->SetOpacity(opacity);
    pRenderTarget->FillRectangle(m_rectangle, pFillBrush);
    pRenderTarget->DrawRectangle(m_rectangle, pLineBrush);
}

void CRenderTargetTransformDemo::DrawDemoArrow(CHwndRenderTarget* pRenderTarget, FLOAT opacity)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    auto pArrowGeometry = pDoc->GetArrowGeometry();
    VERIFY_D2D_RESOURCE(pArrowGeometry);
    auto pFillBrush = pDoc->GetFillBrush();
    VERIFY_D2D_RESOURCE(pFillBrush);
    auto pLineBrush = pDoc->GetLineBrush();
    VERIFY_D2D_RESOURCE(pLineBrush);

    pFillBrush->SetOpacity(opacity);
    pLineBrush->SetOpacity(opacity);
    pRenderTarget->FillGeometry(pArrowGeometry, pFillBrush);
    pRenderTarget->DrawGeometry(pArrowGeometry, pLineBrush);
}

void CRenderTargetTransformDemo::DrawDemoPicture(CHwndRenderTarget* pRenderTarget, FLOAT opacity)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    auto pPictureBitmap = pDoc->GetPictureBitmap();
    VERIFY_D2D_RESOURCE(pPictureBitmap);

    CD2DSizeF size = pPictureBitmap->GetSize();
    CD2DRectF rect{ 0.f, 0.f, size.width, size.height };
    pRenderTarget->DrawBitmap(pPictureBitmap, rect, opacity);
}

void CRenderTargetTransformDemo::DrawCenter(CHwndRenderTarget* pRenderTarget, const CD2DPointF& center, CD2DBitmap* pBitmap)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    VERIFY_D2D_RESOURCE(pBitmap);
    FLOAT left = center.x - m_sizeCenterBitmap.width / 2.f;
    FLOAT top = center.y - m_sizeCenterBitmap.height / 2.f;
    FLOAT right = center.x + m_sizeCenterBitmap.width / 2.f;
    FLOAT bottom = center.y + m_sizeCenterBitmap.height / 2.f;
    CD2DRectF rect{ left, top, right, bottom  };
    pRenderTarget->DrawBitmap(pBitmap, rect);
}

void CRenderTargetTransformDemo::DrawInfoText(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    auto pTextBrush = pDoc->GetTextBrush();
    VERIFY_D2D_RESOURCE(pTextBrush);

    CString strText;
    SampleId sampleId = GetDemoFrame()->GetActivePaneId();
    switch (sampleId)
    {
    case SampleId::translation:
        strText.Format(L"Translation\nX size: %.f\nY size: %.f",
            m_translationParams.GetSize().width, m_translationParams.GetSize().height);
        break;
    case SampleId::rotation:
        strText.Format(L"Rotation\nAngle: %.f°\nX center: %.f\nY center: %.f", 
            m_rotationParams.GetAngle(), m_rotationParams.GetCenter().x, m_rotationParams.GetCenter().y);
        break;
    case SampleId::scale:
        strText.Format(L"Scale\nX size: %.2f\nY size: %.2f\nX center: %.f\nY center: %.f",
            m_scaleParams.GetSize().width, m_scaleParams.GetSize().height, m_scaleParams.GetCenter().x, m_scaleParams.GetCenter().y);
        break;
    case SampleId::skew:
        strText.Format(L"Skew\nX angle: %.f°\nY angle: %.f°\nX center: %.f\nY center: %.f",
            m_skewParams.GetAngleX(), m_skewParams.GetAngleY(), m_skewParams.GetCenter().x, m_skewParams.GetCenter().y);
        break;
    default:
        ATLTRACE("Unhandled SampleId value");
        break;
    }
    CD2DSizeF size = pRenderTarget->GetSize();
    constexpr FLOAT margin = 10.f;
    CD2DRectF rect{ margin, margin, size.width - margin, size.height - margin };
    CD2DTextFormat textFormat(pRenderTarget, L"Arial", 16, DWRITE_FONT_WEIGHT_BOLD);
    pRenderTarget->DrawText(strText, rect, pTextBrush, &textFormat);
}

D2D1_MATRIX_3X2_F CRenderTargetTransformDemo::TranslationToCenter(CHwndRenderTarget* pRenderTarget, const CD2DRectF& rectFigure)
{
    CD2DSizeF sizeRenderTarget = pRenderTarget->GetSize();
    CD2DSizeF sizeFigure{ rectFigure.right - rectFigure.left, rectFigure.bottom - rectFigure.top };
    FLOAT x = (sizeRenderTarget.width > sizeFigure.width) ? (sizeRenderTarget.width - sizeFigure.width) / 2.f : 0.f;
    FLOAT y = (sizeRenderTarget.height > sizeFigure.height) ? (sizeRenderTarget.height - sizeFigure.height) / 2.f : 0.f;
    return D2D1::Matrix3x2F::Translation(x, y);
}

CRenderTargetTransformDocument* CRenderTargetTransformDemo::GetDocument()
{
    return dynamic_cast<CRenderTargetTransformDocument*> (GetDemoDocument());
}
#pragma endregion
