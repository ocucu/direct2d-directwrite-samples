// File: DirectionPane.h - CDirectionPane class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Allows user to change flow and reading direction for the text

#pragma once

namespace Panes
{
    class CDirectionPane final : public CSamplePane
    {
    public:
        CDirectionPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void ResetParameters() override;
        virtual void SetSampleParameters() override;
        virtual void ParametersChanged() override;
        // Implementation
        void FillFlowDirectionCombo();
        void FillReadingDirectionCombo();
        // Controls
        CExtendedComboBox m_comboFlowDirection;
        CExtendedComboBox m_comboReadingDirection;
    };
} // namespace Panes