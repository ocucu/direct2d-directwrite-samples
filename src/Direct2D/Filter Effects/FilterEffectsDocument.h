#pragma once

namespace Framework
{
    class CFilterEffectsDocument final : public CDemoDocument
    {
        DECLARE_DYNCREATE(CFilterEffectsDocument);
        // Data access
        CD2DBitmap* GetBitmap() const;
    private:
        // Overridden
        virtual BOOL CreateD2DResources(CHwndRenderTarget* pRenderTarget) override;

        // Data
        // sample bitmap
        CD2DBitmap* m_pBitmap{ NULL };
    };

#include "FilterEffectsDocument.inl"
} // namespace Framework



