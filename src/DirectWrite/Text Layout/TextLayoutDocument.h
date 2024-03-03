#pragma once
#include "InlineImage.h"

namespace Framework
{
    class CTextLayoutDocument final : public CDemoDocument
    {
        DECLARE_DYNCREATE(CTextLayoutDocument);
    public:
        // Operations
        CD2DSolidColorBrush* GetTextBrush() const;
        CD2DSolidColorBrush* GetSolidColorBrush() const;
        CD2DLinearGradientBrush* GetGradientBrush() const;
        CD2DBitmapBrush* GetBitmapBrush() const;
        CD2DSolidColorBrush* GetBackgroundBrush() const;
        std::shared_ptr<CInlineImage> GetRingsImage() const;
        std::shared_ptr<CInlineImage> GetRoseImage() const;
        std::shared_ptr<CInlineImage> GetDogImage() const;
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
        std::shared_ptr<CInlineImage> m_spRingsImage;
        std::shared_ptr<CInlineImage> m_spRoseImage;
        std::shared_ptr<CInlineImage> m_spDogImage;
    };

#include "TextLayoutDocument.inl"
} // namespace Framework



