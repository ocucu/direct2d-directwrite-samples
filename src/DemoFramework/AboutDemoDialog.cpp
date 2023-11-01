// File: AboutDemoDialog.cpp - CAboutDemoDialog class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/


#include "pch.h"
#include "resource.h"
#include "AboutDemoDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CAboutDemoDialog::CAboutDemoDialog(const CString& strCaption)
    : CDialog(IDD_ABOUT_DEMO, NULL)
{
    m_strCaption.Format(L"About %s", strCaption.GetString());
}

BOOL CAboutDemoDialog::OnInitDialog()
{
    __super::OnInitDialog();

    SetWindowText(m_strCaption);
    return TRUE;
}
