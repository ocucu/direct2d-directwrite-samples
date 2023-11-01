#pragma once

namespace Framework
{
    class CBrushDocument final : public CDemoDocument
    {
        DECLARE_DYNCREATE(CBrushDocument);
        // Data access
        CD2DBitmap* GetColorMatrixBitmap() const;
        CD2DBitmap* GetCatBitmap() const;
        CD2DBitmap* GetMFCIconBitmap() const;
        CD2DSolidColorBrush* GetDrawInfoBrush() const;

    private:
        // Overridden
        virtual BOOL CreateD2DResources(CHwndRenderTarget* pRenderTarget) override;
        
        // Message handlers
        DECLARE_MESSAGE_MAP()
        afx_msg void OnFigureUpdateCommandUI(CCmdUI* pCmdUI);
        afx_msg void OnFigureCommand(UINT nID);
        afx_msg void OnBitmapUpdateCommandUI(CCmdUI* pCmdUI);
        afx_msg void OnBitmapCommand(UINT nID);

        // Direct2D resources
        CD2DBitmap* m_pColorMatrixBitmap{ NULL };
        CD2DBitmap* m_pCatBitmap{ NULL };
        CD2DBitmap* m_pMFCIconBitmap{ NULL };
        CD2DSolidColorBrush* m_pDrawInfoBrush{ NULL };
    };
} // namespace Framework

#include "BrushDocument.inl"

