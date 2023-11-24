#pragma once

namespace Framework
{
    class CPhotoEffectsDocument final : public CDemoDocument
    {
        DECLARE_DYNCREATE(CPhotoEffectsDocument);
        // Data access
        CD2DBitmap* GetBitmap() const;
    private:
        // Overridden
        virtual BOOL CreateD2DResources(CHwndRenderTarget* pRenderTarget) override;

        // Data
        // sample bitmap
        CD2DBitmap* m_pBitmap{ NULL };
    };

#include "PhotoEffectsDocument.inl"
} // namespace Framework



