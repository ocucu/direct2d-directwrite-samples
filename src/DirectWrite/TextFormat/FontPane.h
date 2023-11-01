// File: FontPane.h - CFontPane class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Allows user to change the font parameters (family name, weight, style and stretch)

#pragma once

namespace Panes
{
    class CFontPane final : public CSamplePane
    {
    public:
        CFontPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId);
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
    };
} // namespace Panes
