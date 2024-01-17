#pragma once

namespace Framework
{
    class CTextLayoutDocument final : public CDemoDocument
    {
        DECLARE_DYNCREATE(CTextLayoutDocument);
    public:
        // Operations
        CD2DSolidColorBrush* GetTextBrush();
        CD2DSolidColorBrush* GetSolidColorBrush();
        CD2DLinearGradientBrush* GetGradientBrush();
        CD2DBitmapBrush* GetBitmapBrush();
        CD2DSolidColorBrush* GetBackgroundBrush();
    private:
        // Overridden
        virtual BOOL CreateD2DResources(CHwndRenderTarget* pRenderTarget) override;

        // Message handlers
        DECLARE_MESSAGE_MAP()
        afx_msg void OnBrushTypeUpdateCommandUI(CCmdUI* pCmdUI);
        afx_msg void OnBrushTypeCommand(UINT nID);

        // Data
        // Direct2D resources
        CD2DSolidColorBrush* m_pTextBrush{ NULL };
        CD2DSolidColorBrush* m_pSolidColorBrush{ NULL };
        CD2DLinearGradientBrush* m_pGradientBrush{ NULL };
        CD2DBitmapBrush* m_pBitmapBrush{ NULL };
        CD2DSolidColorBrush* m_pBackgroundBrush{ NULL };
    };

#include "TextLayoutDocument.inl"
} // namespace Framework



