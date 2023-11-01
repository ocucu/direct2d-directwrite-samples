// File: BrushFrame.h - CBrushFrame class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#pragma once

namespace Framework
{
    class CBrushFrame final : public CDemoFrame
    {
        DECLARE_DYNCREATE(CBrushFrame)
    private:
        // Overridden
        virtual BOOL LoadCustomMenu() override;
        virtual BOOL AddDockingPanes() override;
        virtual BOOL PreCreateWindow(CREATESTRUCT& cs) override;
    };
} // namespace Framework
