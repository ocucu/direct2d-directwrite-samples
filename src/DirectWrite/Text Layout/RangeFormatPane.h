// File: RangeFormatPane.h - CRangeFormatPane class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Allows user to change the text range format parameters 
//          such as font family name, weight, style and stretch, underline and strikethrough     

#pragma once
#include "TextLayoutPane.h"

namespace Panes
{
    class CRangeFormatPane : public CTextLayoutPane
    {
    public:
        CRangeFormatPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId, BrushTypeId brushTypeId);
    protected:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void ResetParameters() override;
        virtual void SetSampleParameters() override;
        virtual void ParametersChanged() override;
        // Implementation
        void FillFontFamilyCombo();
        void FillFontWeightCombo();
        void FillFontStyleCombo();
        void FillFontStretchCombo();
        // Controls
        CExtendedComboBox m_comboFontFamily;
        CSliderCtrl m_sliderFontSize;
        CExtendedComboBox m_comboFontWeight;
        CExtendedComboBox m_comboFontStyle;
        CExtendedComboBox m_comboFontStretch;
        CButton m_checkUnderline;
        CButton m_checkStrikethrough;
        // Data
        static constexpr int m_nMinSliderPos{ 12 };
        static constexpr int m_nMaxSliderPos{ 116 };
        static constexpr int m_nDefSliderPos{ 24 };
    };
} // namespace Panes
