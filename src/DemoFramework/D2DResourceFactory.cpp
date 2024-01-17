#include "pch.h"
#include "DemoFramework.h"
#include "D2DResourceFactory.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CD2DResourceFactory::CD2DResourceFactory(CRenderTarget* pRenderTarget)
    : m_pRenderTarget(pRenderTarget)
{
    VERIFY_D2D_RESOURCE(m_pRenderTarget);
}

#pragma region Operations
BOOL CD2DResourceFactory::LoadD2DBitmap(UINT nResID, const CString& strResType, CD2DBitmap*& pBitmap)
{
    delete pBitmap;
    pBitmap = NULL;
    pBitmap = new CD2DBitmap(m_pRenderTarget, nResID, strResType);
    VERIFY_PTR_RET(pBitmap, FALSE);
    pBitmap->Create(m_pRenderTarget);
    VERIFY_D2D_RESOURCE_RET(pBitmap, FALSE);
    return TRUE;
}

BOOL CD2DResourceFactory::LoadD2DBitmapBrush(UINT nResID, const CString& strResType, CD2DBitmapBrush*& pBrush,
    D2D1_EXTEND_MODE extendModeX /*= D2D1_EXTEND_MODE_WRAP*/, 
    D2D1_EXTEND_MODE extendModeY /*= D2D1_EXTEND_MODE_WRAP*/)
{
    delete pBrush;
    pBrush = NULL;
    D2D1_BITMAP_BRUSH_PROPERTIES props = D2D1::BitmapBrushProperties(extendModeX, extendModeY);
    pBrush = new CD2DBitmapBrush(m_pRenderTarget, nResID, strResType, CD2DSizeU(), &props);
    pBrush->Create(m_pRenderTarget);
    VERIFY_D2D_RESOURCE_RET(pBrush, FALSE);
    return TRUE;
}

BOOL CD2DResourceFactory::CreateBrush(COLORREF color, CD2DSolidColorBrush*& pBrush, int nAlpha /*= 255*/)
{
    delete pBrush;
    pBrush = NULL;
    pBrush = new CD2DSolidColorBrush(m_pRenderTarget, color, nAlpha);
    pBrush->Create(m_pRenderTarget);
    VERIFY_D2D_RESOURCE_RET(pBrush, FALSE);
    return TRUE;
}

BOOL CD2DResourceFactory::CreateBrush(const CD2DPointF& startPoint, const CD2DPointF& endPoint,
    COLORREF startColor, COLORREF endColor, CD2DLinearGradientBrush*& pBrush)
{
    delete pBrush;
    pBrush = NULL;
    constexpr UINT stopsCount = 2;
    D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES props{ startPoint, endPoint };
    D2D1_GRADIENT_STOP stops[stopsCount] =
    {
        { 0.f, CRenderTarget::COLORREF_TO_D2DCOLOR(startColor) },
        { 1.f, CRenderTarget::COLORREF_TO_D2DCOLOR(endColor) }
    };
    pBrush = new CD2DLinearGradientBrush(m_pRenderTarget, stops, stopsCount, props);
    pBrush->Create(m_pRenderTarget);
    VERIFY_D2D_RESOURCE_RET(pBrush, FALSE);

    return TRUE;
}

BOOL CD2DResourceFactory::CreateArrowGeometry(const CD2DSizeF& size, FLOAT veePos, CD2DPathGeometry*& pPathGeometry)
{
    delete pPathGeometry;
    pPathGeometry = NULL;
    pPathGeometry = new CD2DPathGeometry(m_pRenderTarget);
    VERIFY_PTR_RET(pPathGeometry, FALSE);
    pPathGeometry->Create(m_pRenderTarget);
    VERIFY_D2D_RESOURCE_RET(pPathGeometry, FALSE);

    CD2DGeometrySink sink(*pPathGeometry);
    if (!sink.IsValid())
    {
        delete pPathGeometry;
        return FALSE;
    }

    FLOAT x0 = 0.f;
    FLOAT x1 = size.width * veePos;
    FLOAT x2 = size.width;
    FLOAT y0 = 0.f;
    FLOAT y1 = size.height / 4.f;
    FLOAT y2 = y1 * 2.f;
    FLOAT y3 = y1 * 3.f;
    FLOAT y4 = size.height;

    sink.BeginFigure(CD2DPointF(x0, y1), D2D1_FIGURE_BEGIN_FILLED);
    sink.AddLine(CD2DPointF(x1, y1));
    sink.AddLine(CD2DPointF(x1, y0));
    sink.AddLine(CD2DPointF(x2, y2));
    sink.AddLine(CD2DPointF(x1, y4));
    sink.AddLine(CD2DPointF(x1, y3));
    sink.AddLine(CD2DPointF(x0, y3));
    sink.EndFigure(D2D1_FIGURE_END_CLOSED);

    return TRUE;
}
#pragma endregion