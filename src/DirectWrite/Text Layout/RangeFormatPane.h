// File: RangeFormatPane.h - CRangeFormatPane class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Allows user to change the font parameters (family name, weight, style and stretch)

#pragma once
#include "TextLayoutPane.h"

namespace Panes
{
    class CRangeFormatPane final : public CTextLayoutPane
    {
    public:
        CRangeFormatPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId);
    private:
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
        CMFCColorButton m_buttonColor;
        // Data
        static constexpr int m_nMinSliderPos{ 12 };
        static constexpr int m_nMaxSliderPos{ 96 };
        static constexpr int m_nDefSliderPos{ 24 };
    };
} // namespace Panes
