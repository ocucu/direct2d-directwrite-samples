#pragma once

#include "BrushPane.h"

namespace Panes
{
    class CBitmapBrushPane final : public CBrushPane
    {
    public:
        CBitmapBrushPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId, BitmapId bitmapId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;
        // Implementation
        void FillExtendModeXCombo();
        void FillExtendModeYCombo();
        void FillInterpolationModeCombo();
        // Controls
        CExtendedComboBox m_comboExtendModeX;
        CExtendedComboBox m_comboExtendModeY;
        CExtendedComboBox m_comboInterpolationMode;
        // Data
        static constexpr int m_nSampleScaleSliderPos{ 30 };
    }; 
} // namespace Panes

