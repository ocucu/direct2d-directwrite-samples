#pragma once

namespace Parameters { class CGaussianBlurParameters; }
namespace Panes
{
    class CGaussianBlurPane : public CSamplePane
    {
    public:
        CGaussianBlurPane(UINT nDlgId, SampleId sampleId, UINT nNameResId);
    protected:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;

        // Operation
        void UpdateGaussianBlurParameters(Parameters::CGaussianBlurParameters& params);

        // Controls
        CSliderCtrl m_sliderStandardDeviation;
        CExtendedComboBox m_comboOptimization;
        CExtendedComboBox m_comboBorderMode;

    private:
        // Implementation
        void FillOptimizationCombo();
        void FillBorderModeCombo();

        // Data
        static constexpr int m_nMinSliderPos{ 0 };
        static constexpr int m_nMaxSliderPos{ 2000 };
        static constexpr int m_nDefSliderPos{ 300 };
    };
} // namespace Panes
