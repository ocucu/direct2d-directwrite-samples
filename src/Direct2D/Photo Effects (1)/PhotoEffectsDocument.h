#pragma once

namespace Framework
{
    class CPhotoEffectsDocument final : public CDemoDocument
    {
        DECLARE_DYNCREATE(CPhotoEffectsDocument);
        // Data access
        CD2DBitmap* GetCatBitmap() const;
        CD2DBitmap* GetPencilBitmap() const;
        CD2DBitmap* GetGrayscaleBitmap() const;
    private:
        // Overridden
        virtual BOOL CreateD2DResources(CHwndRenderTarget* pRenderTarget) override;
        // Message handlers
        DECLARE_MESSAGE_MAP()
        afx_msg void OnImageUpdateCommandUI(CCmdUI* pCmdUI);
        afx_msg void OnImageCommand(UINT nID);

        // Data
        // sample bitmaps
        CD2DBitmap* m_pCatBitmap{ NULL };
        CD2DBitmap* m_pPencilBitmap{ NULL };
        CD2DBitmap* m_pGrayscaleBitmap{ NULL };
    };

#include "PhotoEffectsDocument.inl"
} // namespace Framework



