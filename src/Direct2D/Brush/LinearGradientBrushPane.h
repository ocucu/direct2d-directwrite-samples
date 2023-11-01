#pragma once

#include "GradientBrushPane.h"

namespace Panes
{
    class CLinearGradientBrushPane final : public CGradientBrushPane
    {
    public:
        CLinearGradientBrushPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;
        // Controls
        CSliderCtrl m_sliderStartPointX;
        CSliderCtrl m_sliderStartPointY;
        CSliderCtrl m_sliderEndPointX;
        CSliderCtrl m_sliderEndPointY;
        // Data
        static constexpr int m_nMinPointSliderPosX{ 0 };
        static constexpr int m_nMaxPointSliderPosX{ 436 };
        static constexpr int m_nMinPointSliderPosY{ 0 };
        static constexpr int m_nMaxPointSliderPosY{ 326 };
    };
} // namespace Panes
