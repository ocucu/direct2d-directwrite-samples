#pragma once
#include "TextLayoutPane.h"

namespace Panes
{
    class CDrawingEffectsPane final : public CTextLayoutPane
    {
    public:
        CDrawingEffectsPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId, BrushTypeId brushTypeId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void ResetParameters() override;
        virtual void SetSampleParameters() override;
        virtual void ParametersChanged() override;

        // Controls
        CExtendedComboBox m_comboBrushType;
        CMFCColorButton m_buttonColor;
    };
} // namespace Panes