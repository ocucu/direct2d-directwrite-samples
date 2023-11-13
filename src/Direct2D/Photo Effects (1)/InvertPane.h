#pragma once

namespace Panes
{
    class CInvertPane final : public CSamplePane
    {
    public:
        CInvertPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BitmapId bitmapId);
        // Overridden
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;
    };
} // namespace Panes
