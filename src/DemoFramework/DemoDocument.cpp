// File: DemoDocument.cpp - CDemoDocument class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "DemoFramework.h"
#include "ChangeTextDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNAMIC(CDemoDocument, CDocument)

void CDemoDocument::ShowSampleTextDialog()
{
    CChangeTextDialog dlg(m_strSampleText, AfxGetMainWnd());
    if (IDOK == dlg.DoModal())
    {
        SetSampleText(dlg.GetText());
    }
}

BOOL CDemoDocument::CreateD2DResources(CHwndRenderTarget* pRenderTarget)
{
    UNREFERENCED_PARAMETER(pRenderTarget);
    return TRUE;
}

BOOL CDemoDocument::OnNewDocument()
{
    if (!__super::OnNewDocument()) 
        return FALSE;

    POSITION pos = GetFirstViewPosition();
    if (!pos) 
        return FALSE;

    CView* pView = GetNextView(pos);
    ASSERT_KINDOF(CDemoView, pView);
    CHwndRenderTarget* pRenderTarget = pView->GetRenderTarget();
    VERIFY_D2D_RESOURCE_RET(pRenderTarget, FALSE);
    if (!CreateD2DResources(pRenderTarget))
        return FALSE;

    return TRUE;
}

