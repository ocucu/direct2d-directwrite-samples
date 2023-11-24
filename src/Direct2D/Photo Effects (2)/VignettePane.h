#pragma once

namespace Panes
{
    class CVignettePane final : public CSamplePane
    {
    public:
        CVignettePane(UINT nDlgId, SampleId sampleId, UINT nNameResId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;

        // Controls
        CMFCColorButton m_buttonColor;
        CSliderCtrl m_sliderTransitionSize;
        CSliderCtrl m_sliderStrength;
        CSliderCtrl m_sliderColorOpacity;
        // Data
        static constexpr int m_nMinSliderPos{ 0 };
        static constexpr int m_nMaxSliderPos{ 100 };
    };
} // namespace Panes
