// File: ChangeTextDialog.cpp - CChangeTextDialog class implementation
// Author: Ovidiu Cucu -  https://codexpertro.wordpress.com/

#include "pch.h"
#include "DemoFramework.h"
#include "resource.h"
#include "ChangeTextDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CChangeTextDialog::CChangeTextDialog(const CString& strText, CWnd* pParent)
    : CDialog(IDD_SAMPLE_TEXT, pParent),
    m_strText(strText)
{
}

#pragma region Overridden
BOOL CChangeTextDialog::OnInitDialog()
{
    __super::OnInitDialog();
    m_font.CreatePointFont(100, L"Verdana");
    CWnd* pWnd = GetWindow(GW_CHILD);
    while (pWnd)
    {
        pWnd->SetFont(&m_font);
        pWnd = pWnd->GetWindow(GW_HWNDNEXT);
    }
    return TRUE;
}

void CChangeTextDialog::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_TEXT, m_strText);
}
#pragma endregion


