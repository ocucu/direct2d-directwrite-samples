#include "pch.h"
#include "BrushTransformDocument.h"

#define ID_BRUSHTYPE_FIRST      ID_BRUSHTYPE_BITMAP
#define ID_BRUSHTYPE_LAST       ID_BRUSHTYPE_RADIALGRADIENT

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Framework::CBrushTransformDocument;

IMPLEMENT_DYNCREATE(CBrushTransformDocument, CDemoDocument);

#pragma region Overridden
BOOL CBrushTransformDocument::CreateD2DResources(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE_RET(pRenderTarget, FALSE);

    // create sample brushes
    VERIFY_BOOL_RET(CreateSampleBitmapBrush(pRenderTarget), FALSE);
    VERIFY_BOOL_RET(CreateSampleLinearGradientBrush(pRenderTarget), FALSE);
    VERIFY_BOOL_RET(CreateSampleRadialGradientBrush(pRenderTarget), FALSE);

    return TRUE;
}
#pragma endregion

#pragma region Implementation
BOOL CBrushTransformDocument::CreateSampleBitmapBrush(CHwndRenderTarget* pRenderTarget)
{
    D2D1_BITMAP_BRUSH_PROPERTIES props =
        D2D1::BitmapBrushProperties(D2D1_EXTEND_MODE_WRAP, D2D1_EXTEND_MODE_WRAP);
    m_pSampleBitmapBrush =
        new CD2DBitmapBrush(pRenderTarget, IDB_PNG_ROSE, L"PNG", CD2DSizeU(), &props);
    m_pSampleBitmapBrush->Create(pRenderTarget);
    VERIFY_D2D_RESOURCE_RET(m_pSampleBitmapBrush, FALSE);

    return TRUE;
}

BOOL CBrushTransformDocument::CreateSampleLinearGradientBrush(CHwndRenderTarget* pRenderTarget)
{
    constexpr UINT gradientStopCount{ 3 };
    D2D1_GRADIENT_STOP gradientStops[gradientStopCount] =
    {
        {0.0f, D2D1::ColorF(D2D1::ColorF::Blue)},
        {0.5f, D2D1::ColorF(D2D1::ColorF::DeepSkyBlue)},
        {1.0f, D2D1::ColorF(D2D1::ColorF::LightBlue)}
    };

    CD2DPointF startPoint{ 0.f, m_brushSize.height / 2.f };
    CD2DPointF endPoint{ m_brushSize.width, m_brushSize.height / 2.f };
    D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES props = 
        D2D1::LinearGradientBrushProperties(startPoint, endPoint);
    m_pSampleLinearGradientBrush =
        new CD2DLinearGradientBrush(pRenderTarget, gradientStops, gradientStopCount, props, 
            D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_WRAP);
    m_pSampleLinearGradientBrush->Create(pRenderTarget);
    VERIFY_D2D_RESOURCE_RET(m_pSampleLinearGradientBrush, FALSE);

    return TRUE;
}

BOOL CBrushTransformDocument::CreateSampleRadialGradientBrush(CHwndRenderTarget* pRenderTarget)
{
    constexpr UINT gradientStopCount{ 3 };
    D2D1_GRADIENT_STOP gradientStops[gradientStopCount] =
    {
        {0.0f, D2D1::ColorF(D2D1::ColorF::White)},
        {0.5f, D2D1::ColorF(D2D1::ColorF::Red)},
        {1.0f, D2D1::ColorF(D2D1::ColorF::DarkRed)}
    };

    CD2DPointF center{ m_brushSize.width / 2.f, m_brushSize.height / 2.f };
    CD2DPointF gradientOriginOffset{ 30.f, 10.f };
    FLOAT radiusX{ m_brushSize.width / 2.f };
    FLOAT radiusY{ m_brushSize.height / 2.f };
    D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES props = 
        D2D1::RadialGradientBrushProperties(center, gradientOriginOffset, radiusX, radiusY);

    m_pSampleRadialGradientBrush = 
        new CD2DRadialGradientBrush(pRenderTarget, gradientStops, gradientStopCount, props,
            D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_WRAP);
    m_pSampleRadialGradientBrush->Create(pRenderTarget);
    VERIFY_D2D_RESOURCE_RET(m_pSampleRadialGradientBrush, FALSE);

    return TRUE;
}
#pragma endregion

#pragma region Message handlers
BEGIN_MESSAGE_MAP(CBrushTransformDocument, CDemoDocument)
    ON_UPDATE_COMMAND_UI_RANGE(ID_BRUSHTYPE_FIRST, ID_BRUSHTYPE_LAST, &CBrushTransformDocument::OnBrushTypeUpdateCommandUI)
    ON_COMMAND_RANGE(ID_BRUSHTYPE_FIRST, ID_BRUSHTYPE_LAST, &CBrushTransformDocument::OnBrushTypeCommand)
END_MESSAGE_MAP()

void CBrushTransformDocument::OnBrushTypeUpdateCommandUI(CCmdUI* pCmdUI)
{
    const UINT nID = pCmdUI->m_nID;
    const BrushTypeId brushTypeId = static_cast<BrushTypeId>(nID - ID_BRUSHTYPE_FIRST + 1);
    pCmdUI->SetCheck(brushTypeId == GetSampleBrushTypeId());
}

void CBrushTransformDocument::OnBrushTypeCommand(UINT nID)
{
    SetSampleBrushTypeId(static_cast<BrushTypeId>(nID - ID_BRUSHTYPE_FIRST + 1));
}
#pragma endregion
