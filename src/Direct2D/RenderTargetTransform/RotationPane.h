#pragma once

namespace Panes
{
    class CRotationPane : public CSamplePane
    {
    public:
        CRotationPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;

        // Controls
        CSliderCtrl m_sliderRotationAngle;
        CSliderCtrl m_sliderRotationCenterX;
        CSliderCtrl m_sliderRotationCenterY;
        // Data
        static constexpr int m_nMinAngleSliderPos{ 0 };
        static constexpr int m_nMaxAngleSliderPos{ 360 };
        static constexpr int m_nDefaultAngleSliderPos{ m_nMaxAngleSliderPos / 2 };
        static constexpr int m_nMinCenterSliderPos{ 0 };
        static constexpr int m_nMaxCenterSliderPos{ 240 };
        static constexpr int m_nDefaultCenterSliderPos{ m_nMaxCenterSliderPos / 2 };
    };
} // namespace Panes

