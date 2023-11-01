// File: LineSpacingPane.h - CLineSpacingPane class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Allows user to set the line spacing for a multiline paragraph
// Notes:
// If 'Default' line spacing method is set, 'baseline' and 'lineSpacing' parametrs passed to IDWriteTextFormat::SetLineSpacing are ignored.
// If 'Uniform' line spacing method is set, 'baseline' parameter specifies the distance from the top of text box to the bottom of the first line of text, 
// while 'lineSpacing' parameter specifies the distance between the bottom of two consecutive lines.
// In practice, the baseline is set to the font size and 'lineSpacing' is greater or equal to 'baseline'. 
// A reasonable value for 'lineSpacing', specified by the documentation is 'baseline' * 1.25 (otherwise said, 'baseline' value is 80% of 'lineSpacing' value).  
// For demo purpose, the slider control in this pane allows user to choose a multiplication factor between 0.8 and 3.

#pragma once

namespace Panes
{
    class CLineSpacingPane final : public CSamplePane
    {
    public:
        CLineSpacingPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;
        // Implementation
        void FillLineSpacingMethodCombo();
        // Controls
        CExtendedComboBox m_comboLineSpacingMethod;
        CSliderCtrl m_sliderLineSpacingFactor;
        // Data
        static constexpr int m_nMinSliderPos{ 80 };
        static constexpr int m_nMaxSliderPos{ 300 };
        static constexpr int m_nDefaultSliderPos{ 125 };
    };
} // namespace Panes
