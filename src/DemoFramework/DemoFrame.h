// File: DemoFrame.h - CDemoFrame class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Base class for main frame in demo applications
// Notes: Override CDemoFrame::InitSamples in order to create and init the docking panes
//        used for changing samples drawing parameters.
//        Override CDemoFrame::SetInitialSamplePane in order to set the initial active pane.
//        Override CDemoFrame::LoadCustomMenu is is necessary to insert additional popup menu(s)
//        into the main frame menu. 

#pragma once

class DEMOFRAMEWORK_EXP CDemoFrame : public CFrameWndEx
{
    DECLARE_DYNAMIC(CDemoFrame)
public:
    // Operations
    BOOL Init();
    BOOL AddPane(std::shared_ptr<CSamplePane> spPane);
    void ActivatePane(SampleId sampleId);
    SampleId GetActivePaneId() const { return m_activePaneId; }

protected:
    // Overridden
    virtual void SetInitialSamplePane();
    virtual BOOL LoadCustomMenu();
    virtual BOOL AddDockingPanes();
    virtual void OnUpdateFrameTitle(BOOL bAddToTitle) override;

private:
    // Implementation
    BOOL AddDockingMenu();
    void UpdateFrameTitle(const CString strAddToTitle);

    // Data
protected:
    SampleId m_activePaneId{ static_cast<SampleId>(0) }; // SampleId::unknown
    CMenu m_menuCustom;
private:
    std::shared_ptr<CDockablePane> m_spAttachToPane;
    CMFCMenuBar m_wndMenuBar;
    CMenu m_menu;
    std::unique_ptr<CMenu> m_spSampleMenu;
    std::list<std::shared_ptr<CSamplePane>> m_listPanes;

    // Message handlers
    DECLARE_MESSAGE_MAP()
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSampleUpdateCommandUI(CCmdUI* pCmdUI);
    afx_msg void OnSampleCommand(UINT nID);
    afx_msg LRESULT CDemoFrame::OnActiveTabChanged(WPARAM wParam, LPARAM lParam);
};


