// File: DemoView.h - CDemoView class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Extends CView MFC class in order to include Direct2D/DirectWrite support
// Notes: 
//   override CDemoView::ClearBackground if need to change the default background (system window color)
//   override CDemoView::Draw in order to perform drawing

#pragma once

class DEMOFRAMEWORK_EXP CDemoView : public CView
{
    DECLARE_DYNAMIC(CDemoView)
protected:
    CDemoView() = default;
    virtual ~CDemoView() = default;

    // Overridden
    virtual void OnInitialUpdate() = 0;
    virtual void ClearBackground(CHwndRenderTarget* pRenderTarget);
    virtual void Draw(CHwndRenderTarget* pRenderTarget) = 0;

private:
    virtual void OnDraw(CDC* pDC) final override;
    virtual void ResetRenderTarget(CHwndRenderTarget* pRenderTarget);

    // Message handlers
    DECLARE_MESSAGE_MAP()
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg LRESULT OnAfxDraw2D(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnAfxRecreated2DResources(WPARAM wParam, LPARAM lParam);
};
