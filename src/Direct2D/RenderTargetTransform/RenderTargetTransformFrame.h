// File: RenderTargetTransformFrame.h - CRenderTargetTransformFrame class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#pragma once

namespace Framework
{
    class CRenderTargetTransformFrame final : public CDemoFrame
    {
        DECLARE_DYNCREATE(CRenderTargetTransformFrame)
    private:
        // Overridden
        virtual BOOL LoadCustomMenu() override;
        virtual BOOL AddDockingPanes() override;
        virtual BOOL PreCreateWindow(CREATESTRUCT& cs) override;
    };
} // namespace Framework
