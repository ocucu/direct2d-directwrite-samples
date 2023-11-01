// File: WordWrappingPane.h - CWordWrappingPane class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Allows user to change the text word wrapping mode

#pragma once

namespace Panes
{
    class CWordWrappingPane final : public CSamplePane
    {
    public:
        CWordWrappingPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void ResetParameters() override;
        virtual void SetSampleParameters() override;
        virtual void ParametersChanged() override;
        // Implementation
        void FillWordWrappingCombo();
        // Controls
        CExtendedComboBox m_comboWordWrapping;
    };
} // namespace Panes
