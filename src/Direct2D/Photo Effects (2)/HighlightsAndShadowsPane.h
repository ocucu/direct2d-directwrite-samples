#pragma once

namespace Panes
{
    class CHighlightsAndShadowsPane final : public CSamplePane
    {
    public:
        CHighlightsAndShadowsPane(UINT nDlgId, SampleId sampleId, UINT nNameResId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;

        // Implementation
        void FillInputGammaCombo();

        // Controls
        CSliderCtrl m_sliderHighlights;
        CSliderCtrl m_sliderShadows;
        CSliderCtrl m_sliderClarity;
        CExtendedComboBox m_comboInputGamma;
        CSliderCtrl m_sliderMaskBlurRasius;

        // Data
        static constexpr int m_nMinSliderPos{ 0 };
        static constexpr int m_nMaxSliderPos{ 200 };
        static constexpr int m_nDefSliderPos{ m_nMaxSliderPos / 2 };
        static constexpr int m_nRadiusMinSliderPos{ 0 };
        static constexpr int m_nRadiusMaxSliderPos{ 1000 };
        static constexpr int m_nRadiusDefSliderPos{ 120 };
    };
} // namespace Panes
