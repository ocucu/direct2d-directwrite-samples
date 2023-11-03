// File: DemoFrame.cpp - CDemoFrame class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "DemoFramework.h"
#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNAMIC(CDemoFrame, CFrameWndEx)

#pragma region Operations
BOOL CDemoFrame::Init()
{
    SetInitialSamplePane();
    VERIFY_BOOL_RET(LoadCustomMenu(), FALSE);
    VERIFY_BOOL_RET(AddDockingPanes(), FALSE);
    VERIFY_BOOL_RET(AddDockingMenu(), FALSE);
    ActivatePane(m_activePaneId);
    return TRUE;
}

BOOL CDemoFrame::AddPane(std::shared_ptr<CSamplePane> spPane)
{
    ATLASSERT(spPane && (spPane->GetSampleId() != static_cast<SampleId>(0)));

    if (static_cast<SampleId>(0) == m_activePaneId)
    {
        m_activePaneId = spPane->GetSampleId();
    }

    if (!m_spAttachToPane)
    {
        m_spAttachToPane = spPane;
        VERIFY_BOOL_RET(spPane->Create(this), FALSE);
        VERIFY_BOOL_RET(spPane->DockToFrameWindow(CBRS_LEFT), FALSE);
    }
    else
    {
        VERIFY_BOOL_RET(spPane->Create(this), FALSE);
        VERIFY_BOOL_RET(spPane->AttachToTabWnd(m_spAttachToPane.get(), DM_SHOW, FALSE), FALSE);
    }

    m_listPanes.push_back(spPane);
    return TRUE;
}

void CDemoFrame::ActivatePane(SampleId sampleId)
{
    for (const auto& spPane : m_listPanes)
    {
        if (spPane->GetSampleId() == sampleId)
        {
            CDemoDocument* pDoc = dynamic_cast<CDemoDocument*>(GetActiveDocument());
            ASSERT_VALID(pDoc);
            pDoc->SetSampleText(spPane->GetSampleText());
            pDoc->SetSampleFigureId(spPane->GetSampleFigureId());
            pDoc->SetSampleBitmapId(spPane->GetSampleBitmapId());
            pDoc->SetSampleBrushTypeId(spPane->GetSampleBrushTypeId());
            spPane->SetSampleParameters();
            spPane->ShowPane(TRUE, FALSE, TRUE);
            UpdateFrameTitle(spPane->GetSampleName());
            break;
        }
    }
}

void CDemoFrame::SetInitialSamplePane()
{
    // Override this in order to set the initial active pane.
    // Otherwise, the first added pane becomes active when application starts.
    m_activePaneId = static_cast<SampleId>(0);
}

BOOL CDemoFrame::LoadCustomMenu()
{
    // override this in order to load an application specific menu to be inserted next to "Samples". 
    return TRUE;
}

BOOL CDemoFrame::AddDockingPanes()
{
    // override this in order to add docking sample panes
    return TRUE;
}

BOOL CDemoFrame::AddDockingMenu()
{
    VERIFY(m_menu.LoadMenu(IDR_DEMOFRAMEWORK));
    m_spSampleMenu = std::make_unique<CMenu>();

    // create and insert "Samples" menu
    VERIFY_BOOL_RET(m_spSampleMenu->CreatePopupMenu(), FALSE);
    for (const auto& spPane : m_listPanes)
    {
        SampleId sampleId = spPane->GetSampleId();
        UINT_PTR nItemId = static_cast<UINT_PTR>(sampleId) + ID_SAMPLE_FIRST;
        CString strItemText = spPane->GetSampleName();
        m_spSampleMenu->AppendMenu(MF_STRING, nItemId, strItemText);
    }

    int nInsertPos = 1;
    m_menu.InsertMenu(nInsertPos, MF_BYPOSITION | MF_POPUP | MF_STRING,
        reinterpret_cast<UINT_PTR>(m_spSampleMenu->GetSafeHmenu()), L"&Sample");

    if (m_menuCustom.GetSafeHmenu())
    {
        const int nItemCount = m_menuCustom.GetMenuItemCount();
        for (int nIntem = 0; nIntem < nItemCount; nIntem++)
        {
            CMenu* pSubMenu = m_menuCustom.GetSubMenu(nIntem);
            if (pSubMenu)
            {
                CString strText;
                m_menuCustom.GetMenuString(nIntem, strText, MF_BYPOSITION);
                m_menu.InsertMenu(++nInsertPos, MF_BYPOSITION | MF_POPUP | MF_STRING,
                    reinterpret_cast<UINT_PTR>(pSubMenu->GetSafeHmenu()), strText);
            }
        }
    }

    HMENU hMenu = m_menu.GetSafeHmenu();
    m_wndMenuBar.Create(this);
    m_wndMenuBar.CreateFromMenu(hMenu);

    m_wndMenuBar.EnableDocking(CBRS_ALIGN_TOP | CBRS_ALIGN_BOTTOM);
    DockPane(&m_wndMenuBar);
    return TRUE;
}

void CDemoFrame::UpdateFrameTitle(const CString strAddToTitle)
{
    CString strFrameTitle;
    CString strAppName = AfxGetApp()->m_pszAppName;
    strFrameTitle.Format(L"%s - %s sample", strAppName.GetString(), strAddToTitle.GetString());
    SetWindowText(strFrameTitle);
}

void CDemoFrame::OnUpdateFrameTitle(BOOL bAddToTitle)
{
    UNREFERENCED_PARAMETER(bAddToTitle);
    // this only override the base class method and does nothing;
    // instead, the CDemoFrame::UpdateFrame is called when a pane is activated (inside CDemoFrame::ActivatePane). 
}
#pragma endregion

#pragma region Message handlers
BEGIN_MESSAGE_MAP(CDemoFrame, CFrameWndEx)
    ON_WM_CREATE()
    ON_UPDATE_COMMAND_UI_RANGE(ID_SAMPLE_FIRST, ID_SAMPLE_LAST, &CDemoFrame::OnSampleUpdateCommandUI)
    ON_COMMAND_RANGE(ID_SAMPLE_FIRST, ID_SAMPLE_LAST, &CDemoFrame::OnSampleCommand)
    ON_REGISTERED_MESSAGE(AFX_WM_CHANGE_ACTIVE_TAB, &CDemoFrame::OnActiveTabChanged)
END_MESSAGE_MAP()

int CDemoFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (__super::OnCreate(lpCreateStruct) == -1)
        return -1;

    // enable frame docking
    CDockingManager::SetDockingMode(DT_SMART);
    EnableDocking(CBRS_ALIGN_ANY);

    // set application look
    CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));
    return 0;
}

void CDemoFrame::OnSampleUpdateCommandUI(CCmdUI* pCmdUI)
{
    UINT nID = pCmdUI->m_nID;
    pCmdUI->SetCheck((m_activePaneId == static_cast<SampleId>(nID - ID_SAMPLE_FIRST)) ? TRUE : FALSE);
}

void CDemoFrame::OnSampleCommand(UINT nID)
{
    m_activePaneId = static_cast<SampleId>(nID - ID_SAMPLE_FIRST);
    ActivatePane(m_activePaneId);
}

LRESULT CDemoFrame::OnActiveTabChanged(WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    SampleId sampleId = static_cast<SampleId>(wParam + 1);
    m_activePaneId = sampleId;
    ActivatePane(m_activePaneId);
    return 0;
}
#pragma endregion
