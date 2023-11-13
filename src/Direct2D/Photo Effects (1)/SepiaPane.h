#pragma once

namespace Panes
{
    class CSepiaPane final : public CSamplePane
    {
    public:
        CSepiaPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BitmapId bitmapId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;

        // Implementation
        void FillAlphaModeCombo();

        // Controls
        CSliderCtrl m_sliderIntensity;
        CExtendedComboBox m_comboAlphaMode;

        // Data
        static constexpr int m_nMinSliderPos{ 0 };
        static constexpr int m_nMaxSliderPos{ 100 };
        static constexpr int m_nDefaultSliderPos{ m_nMaxSliderPos / 2 };
    };

} // namespace Panes
