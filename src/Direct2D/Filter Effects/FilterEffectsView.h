// File: FilterEffectsView.h - CFilterEffectsView class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: The window used for drawing

#pragma once

namespace Framework
{
    class CFilterEffectsView final : public CDemoView
    {
        DECLARE_DYNCREATE(CFilterEffectsView)
    private:
        // Overridden
        virtual void Draw(CHwndRenderTarget* pRenderTarget) override;
        virtual void OnInitialUpdate() override;
        virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

        // demo drawing operations object
        std::unique_ptr<class CFilterEffectsDemo> m_spDemo;
    };
} // namespace Framework