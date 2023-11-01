// File: TabStopPane.h - CTabStopPane class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Allows user to change the distance between two adjacent tab stops

#pragma once

namespace Panes
{
    class CTabStopPane final : public CSamplePane
    {
    public:
        CTabStopPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;
        // Implementation
        void FillTabStopMethodCombo();
        // Controls
        CExtendedComboBox m_comboTabStopMethod;
        CSliderCtrl m_sliderTabStopDistance;
        // Data
        static constexpr int m_nMinSliderPos{ 24 };
        static constexpr int m_nMaxSliderPos{ 144 };
        static constexpr int m_nDefaultSliderPos{ 96 };
    };
}
