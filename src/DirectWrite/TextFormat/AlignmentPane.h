// File: AlignmentPane.h - CAlignmentPane class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Allows user to change text and paragraph alignment

#pragma once

namespace Panes
{
    class CAlignmentPane final : public CSamplePane
    {
    public:
        CAlignmentPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;
        // Implementation
        void FillTextAlignmentCombo();
        void FillParagraphAlignmentCombo();
        // Controls
        CExtendedComboBox m_comboTextAlignment;
        CExtendedComboBox m_comboParagraphAlignment;
        // Data
        CString m_strSampleText;
    };
} // namespace Panes

