#pragma once
#include "GaussianBlurPane.h"

namespace Panes
{
    class CDirectionalBlurPane final : public CGaussianBlurPane
    {
    public:
        CDirectionalBlurPane(UINT nDlgId, SampleId sampleId, UINT nNameResId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;

        // Controls
        CSliderCtrl m_sliderAngle;

        // Data
        static constexpr int m_nMinSliderPos{ 0 };
        static constexpr int m_nMaxSliderPos{ 180 };
        static constexpr int m_nDefSliderPos{ m_nMinSliderPos };
    };
} // namespace Panes

