// File: BrushTransformFrame.h - CBrushTransformFrame class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#pragma once

namespace Framework
{
    class CBrushTransformFrame final : public CDemoFrame
    {
        DECLARE_DYNCREATE(CBrushTransformFrame)
    private:
        // Overridden
        virtual BOOL LoadCustomMenu() override;
        virtual BOOL AddDockingPanes() override;
        virtual BOOL PreCreateWindow(CREATESTRUCT& cs) override;
    };
} // namespace Framework
