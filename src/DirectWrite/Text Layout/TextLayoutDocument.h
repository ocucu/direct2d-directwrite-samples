#pragma once

namespace Framework
{
    class CTextLayoutDocument final : public CDemoDocument
    {
        DECLARE_DYNCREATE(CTextLayoutDocument);
    public:
        // Operations
        CD2DSolidColorBrush* GetTextBrush();
        CD2DSolidColorBrush* GetBackgroundBrush();
    private:
        // Overridden
        virtual BOOL CreateD2DResources(CHwndRenderTarget* pRenderTarget) override;

        // Data
        // Direct2D resources
        CD2DSolidColorBrush* m_pTextBrush{ NULL };
        CD2DSolidColorBrush* m_pBackgroundBrush{ NULL };
    };

#include "TextLayoutDocument.inl"
} // namespace Framework



