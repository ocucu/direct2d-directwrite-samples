// File: DemoApp.cpp - CDemoApp class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "DemoFramework.h"
#include "AboutDemoDialog.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CDemoApp::CDemoApp(
    CRuntimeClass* pFrameClass,
    CRuntimeClass* pViewClass,
    CRuntimeClass* pDocumentClass /*= NULL*/)
    : m_pFrameClass(pFrameClass),
    m_pViewClass(pViewClass),
    m_pDocumentClass(pDocumentClass)
{
}

#pragma region Overridden
BOOL CDemoApp::InitInstance()
{
    INITCOMMONCONTROLSEX InitCtrls;
    InitCtrls.dwSize = sizeof(InitCtrls);
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    ::InitCommonControlsEx(&InitCtrls);

    CWinAppEx::InitInstance();

    AfxOleInit();
    AfxEnableControlContainer();
    EnableTaskbarInteraction(FALSE);
    SetRegistryKey(L"codexpertro");
    LoadStdProfileSettings(0);

    CSingleDocTemplate* pDocTemplate = new CSingleDocTemplate(
        IDR_DEMOFRAMEWORK,
        m_pDocumentClass,
        m_pFrameClass,
        m_pViewClass);

    AddDocTemplate(pDocTemplate);

    CCommandLineInfo cmdInfo;
    ParseCommandLine(cmdInfo);
    if (!ProcessShellCommand(cmdInfo))
        return FALSE;

    auto pFrame = dynamic_cast<CDemoFrame*>(m_pMainWnd);
    VERIFY_PTR_RET(pFrame, FALSE);
    VERIFY_BOOL_RET(pFrame->Init(), FALSE);

    return TRUE;
}

int CDemoApp::ExitInstance()
{
    AfxOleTerm(FALSE);
    return __super::ExitInstance();
}
#pragma endregion

#pragma region Message handlers
BEGIN_MESSAGE_MAP(CDemoApp, CWinAppEx)
    ON_COMMAND(ID_APP_ABOUT, &CDemoApp::OnAppAbout)
END_MESSAGE_MAP()

void CDemoApp::OnAppAbout()
{
    CAboutDemoDialog dlgAbout(m_pszAppName);
    dlgAbout.DoModal();
}
#pragma endregion


