// File: DemoView.cpp - CDemoView class implementation
// Author: Ovidiu Cucu -  https://codexpertro.wordpress.com/

#include "pch.h"
#include "DemoFramework.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNAMIC(CDemoView, CView)

#pragma region Overridden
void CDemoView::OnDraw(CDC* pDC)
{
    UNREFERENCED_PARAMETER(pDC);
    // Just to override base class pure virtual method.
    // To performa drawing in derived class, override Draw method. 
}

void CDemoView::ResetRenderTarget(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    // Set identity transform for render target
    // Override this for additional initialization before drawing
    pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
}

void CDemoView::ClearBackground(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    // Clear the background using the system window color.
    // Override this for using another color or a brush.
    pRenderTarget->Clear(CRenderTarget::COLORREF_TO_D2DCOLOR(::GetSysColor(COLOR_WINDOW)));
}
#pragma endregion

#pragma region Message handlers
BEGIN_MESSAGE_MAP(CDemoView, CView)
    ON_WM_CREATE()
    ON_REGISTERED_MESSAGE(AFX_WM_DRAW2D, &CDemoView::OnAfxDraw2D)
    ON_REGISTERED_MESSAGE(AFX_WM_RECREATED2DRESOURCES, &CDemoView::OnAfxRecreated2DResources)
END_MESSAGE_MAP()


int CDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (__super::OnCreate(lpCreateStruct) == -1)
        return -1;

    EnableD2DSupport();
    return 0;
}

LRESULT CDemoView::OnAfxDraw2D(WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(wParam);
    CHwndRenderTarget* pRenderTarget = reinterpret_cast<CHwndRenderTarget*>(lParam);

    ResetRenderTarget(pRenderTarget);
    ClearBackground(pRenderTarget);
    Draw(pRenderTarget);

    return TRUE;
}

LRESULT CDemoView::OnAfxRecreated2DResources(WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(wParam);
    UNREFERENCED_PARAMETER(lParam);
    ATLTRACE("The render target has been lost and recreated");
    // The HWND render target has been lost but re-created by MFC framework with all contained resources.
    // So far, nothing to do here or maybe write some info in a log file to see it happened.
    return TRUE;
}
#pragma endregion
