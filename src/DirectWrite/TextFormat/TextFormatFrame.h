// File: TextFormatFrame.h - CTextFormatFrame class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#pragma once

namespace Framework
{
    class CTextFormatFrame final : public CDemoFrame
    {
        DECLARE_DYNCREATE(CTextFormatFrame)
    private:
        // Overridden
        virtual BOOL AddDockingPanes() override;
        virtual BOOL PreCreateWindow(CREATESTRUCT& cs) override;
    };
} // namespace Framework

