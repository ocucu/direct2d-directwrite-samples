// File: GradientBrushPane.h - CGradientBrushPane class definition
// Purpose: Abstract base class for CLinearGradientBrushPane and CRadialGradientBrushPane

#pragma once
#include "BrushPane.h"

namespace Parameters { class CGradientBrushParameters; }
namespace Panes
{
    class CGradientBrushPane : public CBrushPane
    {
    protected:
        CGradientBrushPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId);
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void ResetParameters() override;
        // Operations
        void UpdateGradientBrushParameters(Parameters::CGradientBrushParameters& params);
        // Implementation
        void FillColorInterpolationCombo();
        void FillExtendModeCombo();

        // Controls
        CMFCColorButton m_buttonFirstColor;
        CMFCColorButton m_buttonSecondColor;
        CMFCColorButton m_buttonThirdColor;
        CExtendedComboBox m_comboColorInterpolation;
        CExtendedComboBox m_comboExtendMode;
        // Data
    };
} // namespace Panes
