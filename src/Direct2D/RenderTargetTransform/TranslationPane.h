// File: TranslationPane.h - CTranslationPane class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Allows user to set x and y-axis translation parameters

#pragma once

namespace Panes
{
    class CTranslationPane final : public CSamplePane
    {
    public:
        CTranslationPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;

        // Controls
        CSliderCtrl m_sliderTranslationX;
        CSliderCtrl m_sliderTranslationY;
        // Data
        static constexpr int m_nMinSliderPos{ 0 };
        static constexpr int m_nMaxSliderPos{ 720 };
        static constexpr int m_nDefaultSliderPos{ m_nMaxSliderPos / 3 };
    };
} // namespace Panes
