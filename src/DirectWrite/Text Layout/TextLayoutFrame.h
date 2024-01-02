// File: TextLayoutFrame.h - CTextLayoutFrame class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#pragma once

namespace Framework
{
    class CTextLayoutFrame final : public CDemoFrame
    {
        DECLARE_DYNCREATE(CTextLayoutFrame)
    private:
        // Overridden
        virtual BOOL AddDockingPanes() override;
        virtual BOOL PreCreateWindow(CREATESTRUCT& cs) override;
    };
} // namespace Framework
