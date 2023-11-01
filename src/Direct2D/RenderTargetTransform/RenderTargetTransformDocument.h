#pragma once

namespace Framework
{
    class CRenderTargetTransformDocument final : public CDemoDocument
    {
        DECLARE_DYNCREATE(CRenderTargetTransformDocument);
        // Data access
        CD2DSolidColorBrush* GetTextBrush();
        CD2DSolidColorBrush* GetLineBrush();
        CD2DLinearGradientBrush* GetFillBrush();
        CD2DPathGeometry* GetArrowGeometry();
        CD2DBitmap* GetPictureBitmap();
        CD2DBitmap* GetScaleCenterBitmap();
        CD2DBitmap* GetRotateCenterBitmap();
        CD2DBitmap* GetSkewCenterBitmap();

    private:
        // Overridden
        virtual BOOL CreateD2DResources(CHwndRenderTarget* pRenderTarget) override;

        // Message handlers
        DECLARE_MESSAGE_MAP()
        afx_msg void OnFigureUpdateCommandUI(CCmdUI* pCmdUI);
        afx_msg void OnFigureCommand(UINT nID);

        // Data
        // Direct2D resources
        CD2DSolidColorBrush* m_pTextBrush{ NULL };
        CD2DSolidColorBrush* m_pLineBrush{ NULL };
        CD2DLinearGradientBrush* m_pFillBrush{ NULL };
        CD2DPathGeometry* m_pArrowGeometry{ NULL };
        CD2DBitmap* m_pPictureBitmap{ NULL };
        CD2DBitmap* m_pScaleCenterBitmap{ NULL };
        CD2DBitmap* m_pRotateCenterBitmap{ NULL };
        CD2DBitmap* m_pSkewCenterBitmap{ NULL };
        // arrow geometry attributtes
        const CD2DSizeF m_sizeArrow{ 240.f, 240.f };
        const FLOAT m_ArrowVeePos{ 0.6f };
    };
} // namespace Framework

#include "RenderTargetTransformDocument.inl"

