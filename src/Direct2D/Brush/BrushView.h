// File: BrushView.h - CBrushView class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: The window used for drawing

#pragma once

namespace Framework
{
    class CBrushView final : public CDemoView
    {
        DECLARE_DYNCREATE(CBrushView)
    private:
        // Overridden
        virtual void ClearBackground(CHwndRenderTarget* pRenderTarget) override;
        virtual void Draw(CHwndRenderTarget* pRenderTarget) override;
        virtual void OnInitialUpdate() override;
        virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

        // demo drawing operations object
        std::unique_ptr<class CBrushDemo> m_spDemo;
        // background brush
        CD2DBitmapBrush* m_pBackgroundBrush{ NULL };
    };
} // namespace Framework