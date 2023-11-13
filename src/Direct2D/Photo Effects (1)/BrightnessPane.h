#pragma once

namespace Panes
{
    class CBrightnessPane final : public CSamplePane
    {
    public:
        CBrightnessPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BitmapId bitmapId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;

        // Controls
        CSliderCtrl m_sliderWhitePointX;
        CSliderCtrl m_sliderWhitePointY;
        CSliderCtrl m_sliderBlackPointX;
        CSliderCtrl m_sliderBlackPointY;

        // Data
        static constexpr int m_nMinSliderPos{ 0 };
        static constexpr int m_nMaxSliderPos{ 100 };
    };
} // namespace Panes

