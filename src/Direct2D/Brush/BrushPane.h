// File: BrushPane.h - CBrushPane class definition
// Purpose: Abstract base class for CSolidColorBrush, and CGradientBrush

#pragma once

namespace Parameters{ class CBrushParameters; }
namespace Panes
{
    class CBrushPane : public CSamplePane
    {
    public:
        CBrushPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId, BitmapId bitmapId);
        CBrushPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId);
    protected:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void ResetParameters() override;
        // Operations
        void UpdateBrushParameters(Parameters::CBrushParameters& params);
    protected:
        // Controls
        CSliderCtrl m_sliderOpacity;
        CSliderCtrl m_sliderScale;
        // Data
        static constexpr int m_nMinOpacitySliderPos{ 0 };
        static constexpr int m_nMaxOpacitySliderPos{ 100 };
        static constexpr int m_nDefaultOpacitySliderPos{ m_nMaxOpacitySliderPos };
        static constexpr int m_nMinScaleSliderPos{ 10 };
        static constexpr int m_nMaxScaleSliderPos{ 120 };
        static constexpr int m_nDefaultScaleSliderPos{ 100 };
    };
} // namespace Panes