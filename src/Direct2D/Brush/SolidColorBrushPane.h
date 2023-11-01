// File: SolidColorBrushPane.h - CSolidColorBrushPane class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Allows user to set solid color brush parameters

#pragma once
#include "BrushPane.h"

namespace Panes
{
    class CSolidColorBrushPane final : public CBrushPane
    {
    public:
        CSolidColorBrushPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void ResetParameters() override;
        virtual void SetSampleParameters() override;
        virtual void ParametersChanged() override;
        // Controls
        CMFCColorButton m_buttonColor;
    };
} // namespace Panes
