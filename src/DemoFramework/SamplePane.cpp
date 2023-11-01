// File: SamplePane.cpp - CSamplePane class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "DemoFramework.h"
#include "SamplePane.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// reuse standard message box IDs for pane buttons 
#define IDC_PANE_BUTTON_FIRST       IDCANCEL
#define IDC_PANE_BUTTON_LAST        IDNO
#define IDC_BUTTON_SAMPLE_TEXT      IDCANCEL
#define IDC_BUTTON_RESET            IDABORT

#pragma region Constructors
CSamplePane::CSamplePane(UINT nDlgResId, SampleId sampleId, UINT nNameResId, UINT nTextResId)
    : m_nDlgResId(nDlgResId),
    m_sampleId(sampleId)
{
    ATLVERIFY(m_strSampleName.LoadString(nNameResId));
    ATLVERIFY(m_strSampleText.LoadString(nTextResId));
    m_lpszBarTemplateName = MAKEINTRESOURCE(nDlgResId);
}

CSamplePane::CSamplePane(UINT nDlgResId, SampleId sampleId, UINT nNameResId, FigureId figureId)
    : m_nDlgResId(nDlgResId),
    m_sampleId(sampleId),
    m_sampleFigureId(figureId)
{
    ATLVERIFY(m_strSampleName.LoadString(nNameResId));
    m_lpszBarTemplateName = MAKEINTRESOURCE(nDlgResId);
}

CSamplePane::CSamplePane(UINT nDlgResId, SampleId sampleId, UINT nNameResId, FigureId figureId, BitmapId bitmapId)
    : m_nDlgResId(nDlgResId),
    m_sampleId(sampleId),
    m_sampleFigureId(figureId),
    m_sampleBitmapId(bitmapId)
{
    ATLVERIFY(m_strSampleName.LoadString(nNameResId));
    m_lpszBarTemplateName = MAKEINTRESOURCE(nDlgResId);
}
#pragma endregion

#pragma region Operations
BOOL CSamplePane::Create(CDemoFrame* pFrame)
{
    ASSERT_VALID(pFrame);
    auto pApp = dynamic_cast<CDemoApp*>(AfxGetApp());
    ASSERT_VALID(pApp);

    DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT;
    DWORD dwTabbedStyle = AFX_CBRS_OUTLOOK_TABS;
    DWORD dwControlBarStyle = AFX_CBRS_FLOAT | AFX_CBRS_RESIZE;
    if (!__super::CreateEx(0, m_strSampleName, pFrame, CRect(10, 10, 110, 110), TRUE, m_nDlgResId, dwStyle,
        dwTabbedStyle, dwControlBarStyle, NULL))
    {
        return FALSE;
    }

    // set minimum size to fit entire dialog area
    m_sizeMin.cx = m_sizeDialog.cx;
    m_sizeMin.cy = m_sizeDialog.cy - GetCaptionHeight() - 2 * ::GetSystemMetrics(SM_CYEDGE);

    // enable docking
    EnableDocking(CBRS_ALIGN_LEFT | CBRS_ALIGN_RIGHT);
    return TRUE;
}

void CSamplePane::UpdateView(UpdateHint hint, CObject& params)
{
    CDemoDocument* pDoc = GetDemoDocument();
    VERIFY_PTR(pDoc);
    pDoc->UpdateView(hint, params);
}
#pragma endregion

#pragma region Overridden
BOOL CSamplePane::OnCommand(WPARAM wParam, LPARAM lParam)
{
    HWND hWnd = reinterpret_cast<HWND>(lParam);
    if (::IsWindow(hWnd))
    {
        const WORD wNotifyCode = HIWORD(wParam);
        const WORD wControlID = LOWORD(wParam);
        switch (wNotifyCode)
        {
        case CBN_SELCHANGE:
            ParametersChanged();
            return FALSE; // handled
        case BN_CLICKED:
            if ((wControlID >= IDC_PANE_BUTTON_FIRST) && (wControlID <= IDC_PANE_BUTTON_LAST))
            {
                break;
            }
            else
            {
                ParametersChanged();
                return FALSE; // handled
            }
        }
    }
    return CPaneDialog::OnCommand(wParam, lParam);
}

void CSamplePane::ShowPane(BOOL bShow, BOOL bDelay, BOOL bActivate)
{
    __super::ShowPane(bShow, bDelay, bActivate);
}

BOOL CSamplePane::FloatPane(CRect rectFloat, AFX_DOCK_METHOD dockMethod, bool bShow)
{
    if (rectFloat.Width() == 100)
    {
        int cx = m_sizeDialog.cx + m_cxLeftBorder + m_cxRightBorder - 2 * ::GetSystemMetrics(SM_CXEDGE);
        int cy = m_sizeDialog.cy + m_cyTopBorder + m_cyBottomBorder + 2 * ::GetSystemMetrics(SM_CYEDGE);
        rectFloat.SetRect(0, 0, cx, cy);
        rectFloat.OffsetRect(10, 10);
    }
    return __super::FloatPane(rectFloat, dockMethod, bShow);
}

void  CSamplePane::OnAfterDock(CBasePane* pBar, LPCRECT lpRect, AFX_DOCK_METHOD dockMethod)
{
    if (pBar)
    {
        if (pBar->IsKindOf(RUNTIME_CLASS(CBaseTabbedPane)))
            pBar->EnableGripper(FALSE);
        else
            pBar->EnableGripper(TRUE);
    }
    __super::OnAfterDock(pBar, lpRect, dockMethod);
}
#pragma endregion

#pragma region Implementation
CDemoDocument* CSamplePane::GetDemoDocument()
{
    CDemoFrame* pFrame = GetDemoFrame();
    VERIFY_PTR_RET(pFrame, NULL);
    auto pDoc = dynamic_cast<CDemoDocument*>(pFrame->GetActiveDocument());
    return pDoc;
}

CDemoFrame* CSamplePane::GetDemoFrame()
{
    auto pFrame = dynamic_cast<CDemoFrame*>(AfxGetMainWnd());
    ASSERT_VALID(pFrame);
    return pFrame;
}
#pragma endregion

#pragma region Message handlers
BEGIN_MESSAGE_MAP(CSamplePane, CPaneDialog)
    ON_WM_HSCROLL()
    ON_MESSAGE(WM_INITDIALOG, &CSamplePane::HandleInitDialog)
    ON_BN_CLICKED(IDC_BUTTON_SAMPLE_TEXT, &CSamplePane::OnButtonSampleText)
    ON_BN_CLICKED(IDC_BUTTON_RESET, &CSamplePane::OnButtonReset)
    ON_UPDATE_COMMAND_UI_RANGE(IDC_PANE_BUTTON_FIRST, IDC_PANE_BUTTON_LAST, &CSamplePane::OnButtonUpdateCommandUI)
    ON_WM_VSCROLL()
END_MESSAGE_MAP()

LRESULT CSamplePane::HandleInitDialog(WPARAM wParam, LPARAM lParam)
{
    __super::HandleInitDialog(wParam, lParam);

    InitPane();
    //auto pFrame = GetDemoFrame();
    //ASSERT_VALID(pFrame);
    //if (pFrame->GetActivePaneId() == GetSampleId())
    //{
    //    SetSampleParameters();
    //}
    return TRUE;
}

void CSamplePane::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    if (pScrollBar->GetSafeHwnd())
    {
        switch (nSBCode)
        {
        case TB_LINEUP:
        case TB_LINEDOWN:
        case TB_PAGEUP:
        case TB_PAGEDOWN:
        case TB_THUMBTRACK:
        case TB_TOP:
        case TB_BOTTOM:
            ParametersChanged();
            break;
        }
    }
    __super::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CSamplePane::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    if (pScrollBar->GetSafeHwnd())
    {
        ParametersChanged();
    }
    __super::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CSamplePane::OnButtonSampleText()
{
    CDemoDocument* pDoc = GetDemoDocument();
    VERIFY_PTR(pDoc);
    pDoc->ShowSampleTextDialog();
}

void CSamplePane::OnButtonReset()
{
    ResetParameters();
}

void CSamplePane::OnButtonUpdateCommandUI(CCmdUI* pCmdUI)
{
    pCmdUI->Enable(TRUE);
}

