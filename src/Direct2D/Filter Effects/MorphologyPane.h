#pragma once

namespace Panes
{
    class CMorphologyPane final : public CSamplePane
    {
    public:
        CMorphologyPane(UINT nDlgId, SampleId sampleId, UINT nNameResId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;

        // Implementation
        void FillModeCombo();

        // Controls
        CExtendedComboBox m_comboMode;
        CSliderCtrl m_sliderWidth;
        CSliderCtrl m_sliderHeight;
  
        // Data
        static constexpr int m_nMinSliderPos{ 1 };
        static constexpr int m_nMaxSliderPos{ 100 };
        static constexpr int m_nDefSliderPos{ m_nMinSliderPos };
    };
} // namespace Panes
