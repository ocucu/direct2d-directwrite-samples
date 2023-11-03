// File: SamplePane.h - CSamplePane class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Abstract base class for docking panes used to set sample parameters 
//          (e.g. text font parameters, alignment parameters, etc.)
// Notes: 
//   override CSamplePane::InitPane to initialize pane controls (e.g. fill combo boxes, set sliders range, etc.)
//   override CSamplePane::ResetParameters to set defalut values for parameters (e.g. "leading" for text alignnment)
//   override CSamplePane::SetSampleParameters to set some parameter values for currently selected sample 
//            (e.g. to better illustrate trimming, we would prefer to initially set "No wrap")  
//   override CSamplePane::ParametersChanged to update the view content when a parameter has been changed.

#pragma once

    class DEMOFRAMEWORK_EXP CSamplePane : public CPaneDialog
    {
        friend class CDemoFrame;
    public:
        CSamplePane(UINT nDlgResId, SampleId sampleId, UINT nNameResId, UINT nTextResId);
        CSamplePane(UINT nDlgResId, SampleId sampleId, UINT nNameResId, FigureId figureId);
        CSamplePane(UINT nDlgResId, SampleId sampleId, UINT nNameResId, BrushTypeId brushTypeId);
        CSamplePane(UINT nDlgResId, SampleId sampleId, UINT nNameResId, FigureId figureId, BitmapId bitmapId);
    protected:
        // Operations
        BOOL Create(CDemoFrame* pFrame);
        SampleId GetSampleId() const;
        CString GetSampleName() const;
        void SetSampleText(UINT nResId);
        CString GetSampleText() const;
        FigureId GetSampleFigureId() const;
        BitmapId GetSampleBitmapId() const;
        BrushTypeId GetSampleBrushTypeId() const;
        void UpdateView(UpdateHint hint, CObject& params);

        // Override
        virtual void InitPane() = 0;
        virtual void SetSampleParameters() = 0;
        virtual void ResetParameters() = 0;
        virtual void ParametersChanged() = 0;

        // Implementation
    protected:
        CDemoDocument* GetDemoDocument();
        CDemoFrame* GetDemoFrame();
    private:
        virtual void ShowPane(BOOL bShow, BOOL bDelay, BOOL bActivate) override;
        virtual BOOL FloatPane(CRect rectFloat,
            AFX_DOCK_METHOD dockMethod = DM_UNKNOWN, bool bShow = true) override final;
        virtual void OnAfterDock(CBasePane* pBar,
            LPCRECT lpRect, AFX_DOCK_METHOD dockMethod) override final;
        virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam) override final;

        // Message handlers
        DECLARE_MESSAGE_MAP()
        afx_msg LRESULT HandleInitDialog(WPARAM wParam, LPARAM lParam);
        afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
        afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
        afx_msg void OnButtonSampleText();
        afx_msg void OnButtonReset();
        afx_msg void OnButtonUpdateCommandUI(CCmdUI* pCmdUI);

        // Data
        UINT m_nDlgResId{ 0 };
        SampleId m_sampleId{ static_cast<SampleId>(0) }; // SampleId::unknown
        CString m_strSampleName;
        CString m_strSampleText;
        FigureId m_sampleFigureId{ static_cast<FigureId>(0) }; // FigureId::unknown
        BitmapId m_sampleBitmapId{ static_cast<BitmapId>(0) }; // BitmapId::unknown
        BrushTypeId m_sampleBrushTypeId{ static_cast<BrushTypeId>(0) }; // BrushTypeId::unknown
    };

#include "SamplePane.inl"
