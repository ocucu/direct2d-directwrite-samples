// File: BrushDemo.cpp - CBrushDemo class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "BrushDemo.h"


using Framework::CBrushDocument;
using namespace Parameters;

CBrushDemo::CBrushDemo(CDemoView* pView)
    : CDemoDraw(pView)
{
}

#pragma region Overridden
void CBrushDemo::DrawDemo(CHwndRenderTarget* pRenderTarget)
{   
    VERIFY_D2D_RESOURCE(pRenderTarget);

    SampleId sampleId = GetDemoFrame()->GetActivePaneId();
    switch (sampleId)
    {
    case SampleId::solidColorBrush:
        DemoSolidColorBrush(pRenderTarget);
        break;
    case SampleId::bitmapBrush:
        DemoBitmapBrush(pRenderTarget);
        break;
    case SampleId::linearGradientBrush:
        DemoLinearGradientBrush(pRenderTarget);
        break;
    case SampleId::radialGradientBrush:
        DemoRadialGradientBrush(pRenderTarget);
        break;
    default:
        ATLTRACE("Unhandled SampleId value");
        break;
    }
}
#pragma endregion

#pragma region Operations
void CBrushDemo::OnSolidColorBrushChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CSolidColorBrushParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_solidColorBrushParams = *pParams;
    InvalidateView();
}

void CBrushDemo::OnBitmapBrushChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CBitmapBrushParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_bitmapBrushParams = *pParams;
    InvalidateView();
}

void CBrushDemo::OnLinearGradientBrushChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CLinearGradientBrushParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_linearGradientBrushParams = *pParams;
    InvalidateView();
}

void CBrushDemo::OnRadialGradiontBrushChanged(CObject* pHint)
{
    UNREFERENCED_PARAMETER(pHint);
    auto pParams = dynamic_cast<CRadialGradientBrushParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_radialGradientBrushParams = *pParams;
    InvalidateView();
}
#pragma endregion

#pragma region Demo functions
void CBrushDemo::DemoSolidColorBrush(CHwndRenderTarget* pRenderTarget)
{
  
    D2D1_COLOR_F color = m_solidColorBrushParams.GetColor();
    FLOAT opacity = m_solidColorBrushParams.GetOpacity();
    CD2DSolidColorBrush brush(pRenderTarget, color);
    HRESULT hr = brush.Create(pRenderTarget);
    if (SUCCEEDED(hr))
    {
        brush.SetOpacity(opacity);
        FillDemo(pRenderTarget, brush);

        CString strInfoText;
        strInfoText.Format(L"Opacity: %.2f\nColor: (%.2f, %.2f, %.2f)", opacity, color.r, color.g, color.b);
        DrawInfoText(pRenderTarget, strInfoText);
    }
}

void CBrushDemo::DemoBitmapBrush(CHwndRenderTarget* pRenderTarget)
{
    CD2DBitmap* pBitmap{ NULL };
    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    BitmapId bitmapId = pDoc->GetSampleBitmapId();
    switch (bitmapId)
    {
    case BitmapId::colorMatrix:
        pBitmap = pDoc->GetColorMatrixBitmap();
        break;
    case BitmapId::cat:
        pBitmap = pDoc->GetCatBitmap();
        break;
    case BitmapId::mfcIcon:
        pBitmap = pDoc->GetMFCIconBitmap();
        break;
    default:
        ATLTRACE("Unhandled BitmapId value");
        break;
    }

    VERIFY_D2D_RESOURCE(pBitmap);

    CD2DBitmapBrush brush(pRenderTarget);
    brush.SetBitmap(pBitmap);
    HRESULT hr = brush.Create(pRenderTarget);

    if (SUCCEEDED(hr))
    {
        brush.SetOpacity(m_bitmapBrushParams.GetOpacity());
        brush.SetExtendModeX(m_bitmapBrushParams.GetExtendModeX());
        brush.SetExtendModeY(m_bitmapBrushParams.GetExtendModeY());
        brush.SetTransform(&m_bitmapBrushParams.GetTransformMatrix());
        FillDemo(pRenderTarget, brush);
    }
}

void CBrushDemo::DemoLinearGradientBrush(CHwndRenderTarget* pRenderTarget)
{
    constexpr UINT gradientStopsCount = 3;
    D2D1_GRADIENT_STOP gradientStops[gradientStopsCount];
    gradientStops[0] = m_linearGradientBrushParams.GetGradientStop(0);
    gradientStops[1] = m_linearGradientBrushParams.GetGradientStop(1);
    gradientStops[2] = m_linearGradientBrushParams.GetGradientStop(2);

    CD2DPointF startPoint = m_linearGradientBrushParams.GetStartPoint();
    CD2DPointF endPoint = m_linearGradientBrushParams.GetEndPoint();
    D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES linearGradientBrushProps = 
        D2D1::LinearGradientBrushProperties(startPoint, endPoint);

    D2D1_GAMMA colorInterpolationGamma = m_linearGradientBrushParams.GetColorInterpolationGamma();
    D2D1_EXTEND_MODE extendMode = m_linearGradientBrushParams.GetExtendMode();
    FLOAT opacity = m_linearGradientBrushParams.GetOpacity();
    D2D1_MATRIX_3X2_F transformMatrix = m_linearGradientBrushParams.GetTransformMatrix();
    CD2DBrushProperties brushProps{ transformMatrix, opacity };

    CD2DLinearGradientBrush brush(
        pRenderTarget,              // render target
        gradientStops,              // array of D2D1_GRADIENT_STOP structures.
        gradientStopsCount,         // the number of gradient stops in the gradientStops array
        linearGradientBrushProps,   // start and end point of the gradient
        colorInterpolationGamma,    // the space in which color interpolation between the gradient stops is performed
        extendMode,                 // the behavior of the gradient outside the [0,1] normalized range
        &brushProps);               // opacity and brush transform matrix

    HRESULT hr = brush.Create(pRenderTarget);
    if (SUCCEEDED(hr))
    {
        FillDemo(pRenderTarget, brush);

        CString strInfoText;
        strInfoText.Format(
            L"Gradient stop 0: %.1f (%.1f, %.1f, %.1f)\n"
            L"Gradient stop 1: %.1f (%.2f, %.1f, %.1f)\n"
            L"Gradient stop 2: %.1f (%.2f, %.1f, %.1f)\n"
            L"Start point: (%.0f, %.0f)\n"
            L"End point: (%.0f, %.0f)",
            gradientStops[0].position, gradientStops[0].color.r, gradientStops[0].color.g, gradientStops[0].color.b,
            gradientStops[1].position, gradientStops[1].color.r, gradientStops[1].color.g, gradientStops[1].color.b,
            gradientStops[2].position, gradientStops[2].color.r, gradientStops[2].color.g, gradientStops[2].color.b,
            startPoint.x, startPoint.y,
            endPoint.x, endPoint.y
        );
        DrawInfoText(pRenderTarget, strInfoText);
    }
}

void CBrushDemo::DemoRadialGradientBrush(CHwndRenderTarget* pRenderTarget)
{
    constexpr UINT gradientStopsCount = 3;
    D2D1_GRADIENT_STOP gradientStops[gradientStopsCount];
    gradientStops[0] = m_radialGradientBrushParams.GetGradientStop(0);
    gradientStops[1] = m_radialGradientBrushParams.GetGradientStop(1);
    gradientStops[2] = m_radialGradientBrushParams.GetGradientStop(2);

    D2D1_POINT_2F center = m_radialGradientBrushParams.GetCenter();
    D2D1_POINT_2F offset = m_radialGradientBrushParams.GetOffset();
    FLOAT radiusX = m_radialGradientBrushParams.GetRadiusX();
    FLOAT radiusY = m_radialGradientBrushParams.GetRadiusY();
    D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES radialGradientBrushProps =
        D2D1::RadialGradientBrushProperties(center, offset, radiusX, radiusY);

    D2D1_GAMMA colorInterpolationGamma = m_radialGradientBrushParams.GetColorInterpolationGamma();
    D2D1_EXTEND_MODE extendMode = m_radialGradientBrushParams.GetExtendMode();
    FLOAT opacity = m_radialGradientBrushParams.GetOpacity();
    D2D1_MATRIX_3X2_F transformMatrix = m_radialGradientBrushParams.GetTransformMatrix();
    CD2DBrushProperties brushProps{ transformMatrix, opacity };

    CD2DRadialGradientBrush brush(
        pRenderTarget,              // render target
        gradientStops,              // array of D2D1_GRADIENT_STOP structures.
        gradientStopsCount,         // the number of gradient stops in the gradientStops array
        radialGradientBrushProps,   // center, origin offset, x and y radius
        colorInterpolationGamma,    // the space in which color interpolation between the gradient stops is performed
        extendMode,                 // the behavior of the gradient outside the [0,1] normalized range
        &brushProps);               // opacity and brush transform matrix

    HRESULT hr = brush.Create(pRenderTarget);
    if (SUCCEEDED(hr))
    {
        FillDemo(pRenderTarget, brush);

        CString strInfoText;
        strInfoText.Format(
            L"Gradient stop 0: %.1f (%.1f, %.1f, %.1f)\n"
            L"Gradient stop 1: %.1f (%.2f, %.1f, %.1f)\n"
            L"Gradient stop 2: %.1f (%.2f, %.1f, %.1f)\n"
            L"Center: (%.0f, %.0f)\n"
            L"Origin offset: (%.0f, %.0f)\n"
            L"Radius: (%.0f, %.0f)",
            gradientStops[0].position, gradientStops[0].color.r, gradientStops[0].color.g, gradientStops[0].color.b,
            gradientStops[1].position, gradientStops[1].color.r, gradientStops[1].color.g, gradientStops[1].color.b,
            gradientStops[2].position, gradientStops[2].color.r, gradientStops[2].color.g, gradientStops[2].color.b,
            center.x, center.y,
            offset.x, offset.y,
            radiusX, radiusY
        );
        DrawInfoText(pRenderTarget, strInfoText);
    }
}
#pragma endregion

#pragma region Implementation
void CBrushDemo::FillDemo(CHwndRenderTarget* pRenderTarget, CD2DBrush& brush)
{
    FigureId figureId = GetDemoDocument()->GetSampleFigureId();
    switch (figureId)
    {
    case FigureId::none:
        FillDemoRenderTarget(pRenderTarget, brush);
        break;
    case FigureId::rectangle:
        FillDemoRectangle(pRenderTarget, brush);
        break;
    case FigureId::ellipse:
        FillDemoEllipse(pRenderTarget, brush);
        break;
    default:
        ATLTRACE("Unhandled FigureId value");
        break;
    }
}

void CBrushDemo::FillDemoRenderTarget(CHwndRenderTarget* pRenderTarget, CD2DBrush& brush)
{
    CD2DSizeF size = pRenderTarget->GetSize();
    CD2DRectF rect{ 0.f, 0.f, size.width, size.height };
    pRenderTarget->FillRectangle(rect, &brush);
}

void CBrushDemo::FillDemoRectangle(CHwndRenderTarget* pRenderTarget, CD2DBrush& brush)
{
    pRenderTarget->FillRectangle(m_fillRectangle, &brush);
}

void CBrushDemo::FillDemoEllipse(CHwndRenderTarget* pRenderTarget, CD2DBrush& brush)
{
    CD2DEllipse ellipse{ m_fillRectangle };
    pRenderTarget->FillEllipse(ellipse, &brush);
}

void CBrushDemo::DrawInfoText(CHwndRenderTarget* pRenderTarget, const CString& strText)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    auto pBrush = pDoc->GetDrawInfoBrush();
    VERIFY_D2D_RESOURCE(pBrush);
    CD2DSizeF size = pRenderTarget->GetSize();
    CD2DRectF rect{ 40.f, 40.f, size.width, size.height };
    CD2DTextFormat textFormat(pRenderTarget, L"Arial", 16, DWRITE_FONT_WEIGHT_BOLD);
    pRenderTarget->DrawText(strText, rect, pBrush, &textFormat);
}

CBrushDocument* CBrushDemo::GetDocument()
{
    return dynamic_cast<CBrushDocument*> (GetDemoDocument());
}
#pragma endregion
