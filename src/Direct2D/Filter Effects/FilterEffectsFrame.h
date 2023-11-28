// File: FilterEffectsFrame.h - CFilterEffectsFrame class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#pragma once

namespace Framework
{
    class CFilterEffectsFrame final : public CDemoFrame
    {
        DECLARE_DYNCREATE(CFilterEffectsFrame)
    private:
        // Overridden
        virtual BOOL AddDockingPanes() override;
        virtual BOOL PreCreateWindow(CREATESTRUCT& cs) override;
    };
} // namespace Framework
