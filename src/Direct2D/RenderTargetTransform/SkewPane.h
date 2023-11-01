
#pragma once

namespace Panes
{
    class CSkewPane : public CSamplePane
    {
    public:
        CSkewPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void ResetParameters() override;
        virtual void SetSampleParameters() override;
        virtual void ParametersChanged() override;

        //// Controls
        CSliderCtrl m_sliderSkewAngleX;
        CSliderCtrl m_sliderSkewAngleY;
        CSliderCtrl m_sliderSkewCenterX;
        CSliderCtrl m_sliderSkewCenterY;

        //// Data
        static constexpr int m_nMinAngleSkewPos{ 0 };
        static constexpr int m_nMaxAngleSkewPos{ 90 };
        static constexpr int m_nDefaultAngleSkewPos{ m_nMaxAngleSkewPos / 2 };
        static constexpr int m_nMinCenterSkewPosX{ 0 };
        static constexpr int m_nMaxCenterSkewPosX{ 240 };
        static constexpr int m_nDefaultCenterSkewPosX{ m_nMaxCenterSkewPosX / 2 };
        static constexpr int m_nMinCenterSkewPosY{ 0 };
        static constexpr int m_nMaxCenterSkewPosY{ 180 };
        static constexpr int m_nDefaultCenterSkewPosY{ m_nMaxCenterSkewPosY / 2 };
    };
} // namespace Panes

