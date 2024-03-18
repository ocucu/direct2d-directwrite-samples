#pragma once

namespace Panes
{
    class CTypographyPane final : public CSamplePane
    {
    public:
        CTypographyPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId);
    private:
        // Overridden
        virtual void InitPane() override;
        virtual void ResetParameters() override;
        virtual void SetSampleParameters() override;
        virtual void ParametersChanged() override;

        // Controls
        CExtendedComboBox m_comboBrushType;
        CMFCColorButton m_buttonColor;
    };
} // namespace Panes
