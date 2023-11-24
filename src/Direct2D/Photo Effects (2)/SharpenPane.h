#pragma once

namespace Panes
{
    class CSharpenPane final : public CSamplePane
    {
    public:
        CSharpenPane(UINT nDlgId, SampleId sampleId, UINT nNameResId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;

        // Controls
        CSliderCtrl m_sliderSharpness;
        CSliderCtrl m_sliderThreshold;

        // Data
        static constexpr int m_nMinSliderPos{ 0 };
        static constexpr int m_nMaxSliderPos{ 100 };
        static constexpr int m_nDefSliderPos{ m_nMinSliderPos };
    };
} // namespace Panes

