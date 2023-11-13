#pragma once

namespace Panes
{
    class CContrastPane final : public CSamplePane
    {
    public:
        CContrastPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BitmapId bitmapId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;

        // Controls
        CSliderCtrl m_sliderContrast;
        CButton m_checkClampInput;

        // Data
        static constexpr int m_nMinSliderPos{ 0 };
        static constexpr int m_nMaxSliderPos{ 200 };
        static constexpr int m_nDefaultSliderPos{ m_nMaxSliderPos / 2 };
    };
} // namespace Panes
