#pragma once

namespace Panes
{
    class CStraightenPane final : public CSamplePane
    {
    public:
        CStraightenPane(UINT nDlgId, SampleId sampleId, UINT nNameResId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;

        // Implementation
        void FillScaleModeCombo();

        // Controls
        CSliderCtrl m_sliderAngle;
        CButton m_checkMaintainSize;
        CExtendedComboBox m_comboScaleMode;

        // Data
        static constexpr int m_nMinSliderPos{ 0 };
        static constexpr int m_nMaxSliderPos{ 900 };
        static constexpr int m_nDefSliderPos{ m_nMaxSliderPos / 2 };
    };
} // namespace Panes
