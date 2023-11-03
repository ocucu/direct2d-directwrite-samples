#pragma once

namespace Framework
{
    class CBrushTransformDocument final : public CDemoDocument
    {
        DECLARE_DYNCREATE(CBrushTransformDocument);
        // Data access
        CD2DBitmapBrush* GetSampleBitmapBrush() const;
        CD2DLinearGradientBrush* GetSampleLinearGradientBrush() const;
        CD2DRadialGradientBrush* GetSampleRadialGradientBrush() const;

    private:
        // Overridden
        virtual BOOL CreateD2DResources(CHwndRenderTarget* pRenderTarget) override;

        // Implementation
        BOOL CreateSampleBitmapBrush(CHwndRenderTarget* pRenderTarget);
        BOOL CreateSampleLinearGradientBrush(CHwndRenderTarget* pRenderTarget);
        BOOL CreateSampleRadialGradientBrush(CHwndRenderTarget* pRenderTarget);

        // Message handlers
        DECLARE_MESSAGE_MAP()
        afx_msg void OnBrushTypeUpdateCommandUI(CCmdUI* pCmdUI);
        afx_msg void OnBrushTypeCommand(UINT nID);

        // Data
        // sample brushes
        CD2DBitmapBrush* m_pSampleBitmapBrush{ NULL };
        CD2DLinearGradientBrush* m_pSampleLinearGradientBrush{ NULL };
        CD2DRadialGradientBrush* m_pSampleRadialGradientBrush{ NULL };
        // brush size
        const CD2DSizeF m_brushSize{ 128.f, 128.f };
    };

#include "BrushTransformDocument.inl"
} // namespace Framework



