// File: TrimmingPane.h - CTrimmingPane class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Allows user to change the text trimming granularity and/or separator

#pragma once

namespace Panes
{
    class CTrimmingPane final : public CSamplePane
    {
    public:
        CTrimmingPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;
        // Implementation
        void FillTrimingGranularityCombo();
        void FillTrimingDelimiterCombo();
        // Controls
        CExtendedComboBox m_comboTrimmingGranularity;
        CExtendedComboBox m_comboTrimmingDelimiter;
        CSpinButtonCtrl m_spinTrimmingDelimiterCount;
    };
} // namespace Panes
    
