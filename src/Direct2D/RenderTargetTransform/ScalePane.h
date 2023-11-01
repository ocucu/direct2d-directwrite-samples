#pragma once

namespace Panes
{
    class CScalePane : public CSamplePane
    {
    public:
        CScalePane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void ResetParameters() override;
        virtual void SetSampleParameters() override;
        virtual void ParametersChanged() override;

        // Controls
        CSliderCtrl m_sliderScaleSizeX;
        CSliderCtrl m_sliderScaleSizeY;
        CSliderCtrl m_sliderScaleCenterX;
        CSliderCtrl m_sliderScaleCenterY;

        //// Data
        static constexpr int m_nMinScaleSizePos{ 10 };
        static constexpr int m_nMaxScaleSizePos{ 250 };
        static constexpr int m_nDefaultScaleSizePos{ 100 };
        static constexpr int m_nMinScaleCenterXPos{ 0 };
        static constexpr int m_nMaxScaleCenterXPos{ 240 };
        static constexpr int m_nDefaultScaleCenterXPos{ 0 };
        static constexpr int m_nMinScaleCenterYPos{ 0 };
        static constexpr int m_nMaxScaleCenterYPos{ 180 };
        static constexpr int m_nDefaultScaleCenterYPos{ m_nMaxScaleCenterYPos / 2 };
    };
} // namespace Panes
