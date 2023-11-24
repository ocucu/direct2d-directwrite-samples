#pragma once

namespace Panes
{
    class CTemperatureAndTintPane final : public CSamplePane
    {
    public:
        CTemperatureAndTintPane(UINT nDlgId, SampleId sampleId, UINT nNameResId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;

        // Controls
        CSliderCtrl m_sliderTemperature;
        CSliderCtrl m_sliderTint;

        // Data
        static constexpr int m_nMinSliderPos{ 0 };
        static constexpr int m_nMaxSliderPos{ 200 };
        static constexpr int m_nDefSliderPos{ m_nMaxSliderPos / 2 };
    };
} // namespace Panes
