#pragma once

namespace Panes
{
    class CScalePane : public CSamplePane
    {
    public:
        CScalePane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BrushTypeId brushTypeId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void ResetParameters() override;
        virtual void SetSampleParameters() override;
        virtual void ParametersChanged() override;

        // Controls
        CSliderCtrl m_sliderSizeX;
        CSliderCtrl m_sliderSizeY;
        CSliderCtrl m_sliderCenterX;
        CSliderCtrl m_sliderCenterY;

        //// Data
        static constexpr int m_nMinScaleSizePos{ 20 };
        static constexpr int m_nMaxScaleSizePos{ 120 };
        static constexpr int m_nDefaultScaleSizePos{ 100 };
        static constexpr int m_nMinScaleCenterPos{ 0 };
        static constexpr int m_nMaxScaleCenterPos{ 128 };
        static constexpr int m_nDefaultScaleCenterPos{ m_nMinScaleCenterPos };
    };
} // namespace Panes
