// File: D2DResourceFactory.h - CD2DResourceFactory class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Utility class with methods for creating Direct2D resources (bitmaps, brushes, etc.)

#pragma once

class DEMOFRAMEWORK_EXP CD2DResourceFactory
{
public:
    CD2DResourceFactory(CRenderTarget* pRenderTarget);
    // Operations
    BOOL LoadD2DBitmap(UINT nResID, const CString& strResType, CD2DBitmap*& pBitmap);
    BOOL LoadD2DBitmapBrush(UINT nResID, const CString& strResType, CD2DBitmapBrush*& pBrush,
        D2D1_EXTEND_MODE extendModeX = D2D1_EXTEND_MODE_WRAP, D2D1_EXTEND_MODE extendModeY = D2D1_EXTEND_MODE_WRAP);
    BOOL CreateBrush(COLORREF color, CD2DSolidColorBrush*& pBrush, int nAlpha = 255);
    BOOL CreateBrush(const CD2DPointF& startPoint, const CD2DPointF& endPoint,
        COLORREF startColor, COLORREF endColor, CD2DLinearGradientBrush*& pBrush);
    BOOL CreateArrowGeometry(const CD2DSizeF& size, FLOAT veePos, CD2DPathGeometry*& pPathGeometry);
private:
    CRenderTarget* m_pRenderTarget{ NULL };
};

