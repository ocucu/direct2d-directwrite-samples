// File: PhotoEffectsFrame.h - CPhotoEffectsFrame class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#pragma once

namespace Framework
{
    class CPhotoEffectsFrame final : public CDemoFrame
    {
        DECLARE_DYNCREATE(CPhotoEffectsFrame)
    private:
        // Overridden
        virtual BOOL LoadCustomMenu() override;
        virtual BOOL AddDockingPanes() override;
        virtual BOOL PreCreateWindow(CREATESTRUCT& cs) override;
    };
} // namespace Framework
