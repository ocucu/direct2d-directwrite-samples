#pragma once

namespace Panes
{
    class CInlineImagesPane final : public CSamplePane
    {
    public:
        CInlineImagesPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId);
    private:
        // Overridden
        virtual void InitPane() override;
        virtual void ResetParameters() override;
        virtual void SetSampleParameters() override;
        virtual void ParametersChanged() override;
    };
} // namespace Panes
