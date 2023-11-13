#pragma once

namespace Panes
{
    class CExposurePane final : public CSamplePane
    {
    public:
        CExposurePane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BitmapId bitmapId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;

        // Controls
        CSliderCtrl m_sliderValue;

        // Data
        static constexpr int m_nMinSliderPos{ 0 };
        static constexpr int m_nMaxSliderPos{ 400 };
        static constexpr int m_nDefaultSliderPos{ m_nMaxSliderPos / 2 };
    };
} // namespace Panes
