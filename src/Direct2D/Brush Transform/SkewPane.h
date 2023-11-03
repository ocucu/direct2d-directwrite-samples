
#pragma once

namespace Panes
{
    class CSkewPane : public CSamplePane
    {
    public:
        CSkewPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BrushTypeId brushTypeId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void ResetParameters() override;
        virtual void SetSampleParameters() override;
        virtual void ParametersChanged() override;

        //// Controls
        CSliderCtrl m_sliderAngleX;
        CSliderCtrl m_sliderAngleY;
        CSliderCtrl m_sliderCenterX;
        CSliderCtrl m_sliderCenterY;

        //// Data
        static constexpr int m_nMinAnglePos{ 0 };
        static constexpr int m_nMaxAnglePos{ 90 };
        static constexpr int m_nDefaultAnglePos{ m_nMaxAnglePos / 2 };
        static constexpr int m_nMinCenterPos{ 0 };
        static constexpr int m_nMaxCenterPos{ 128 };
        static constexpr int m_nDefaultCenterPos{ m_nMinCenterPos };
    };
} // namespace Panes

