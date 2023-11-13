#pragma once

namespace Panes
{
    class CGrayscalePane final : public CSamplePane
    {
    public:
        CGrayscalePane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BitmapId bitmapId);
        // Overridden
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;
    };
} // namespace Panes