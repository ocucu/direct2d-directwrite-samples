#pragma once

namespace Parameters { class CTextLayoutParameters; }
namespace Panes
{
    class CTextLayoutPane : public CSamplePane
    {
    protected:
        CTextLayoutPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId);
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void ResetParameters() override;
        // Operations
        void UpdateTextLayoutParameters(Parameters::CTextLayoutParameters& params);
        // Controls
        CSliderCtrl m_sliderMaxWidth;
        CSliderCtrl m_sliderMaxHeight;
        CSliderCtrl m_sliderStartPosition;
        CSliderCtrl m_sliderLength;
    };
} // namespace Panes
