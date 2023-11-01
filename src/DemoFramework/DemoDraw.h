// File: DemoDraw.h - CDemoDraw class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Abstract base class for drawing demo classes
// Notes: 
//   keeps drawing stuff in a CDemoDraw-derived class, rather than in the view class.
//   override CDemoDraw::Draw in order to perform Direct2D/DirectWrite drawing operations

#pragma once

class DEMOFRAMEWORK_EXP CDemoDraw
{
public:
    CDemoDraw(CDemoView* pView);
    // Override
    virtual void DrawDemo(CHwndRenderTarget* pRenderTarget) = 0;

protected:
    // Implementation
    CDemoDocument* GetDemoDocument();
    CDemoFrame* GetDemoFrame();
    void InvalidateView();
    // Data
private:
    // view window
    CDemoView* m_pView{ NULL };
};

#include "DemoDraw.inl"

