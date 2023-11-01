#pragma once
#include "GradientBrushPane.h"

namespace Panes
{
    class CRadialGradientBrushPane : public CGradientBrushPane
    {
    public:
        CRadialGradientBrushPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;
        // Controls
        CSliderCtrl m_sliderCenterX;
        CSliderCtrl m_sliderCenterY;
        CSliderCtrl m_sliderOffsetX;
        CSliderCtrl m_sliderOffsetY;
        CSliderCtrl m_sliderRadiusX;
        CSliderCtrl m_sliderRadiusY;
        // Data
        static constexpr int m_nMinCenterSliderPos{ 0 };
        static constexpr int m_nMaxCenterSliderPos{ 400 };
        static constexpr int m_nDefaultCenterSliderPos{ 200 };
        static constexpr int m_nMinOffsetSliderPos{ 0 };
        static constexpr int m_nMaxOffsetSliderPos{ 400 };
        static constexpr int m_nDefaultOffsetSliderPos{ 200 };
        static constexpr int m_nMinRadiusSliderPos{ 40 };
        static constexpr int m_nMaxRadiusSliderPos{ 300 };
        static constexpr int m_nDefaultRadiusSliderPos{ 200 };
    };
} // namespace Panes
