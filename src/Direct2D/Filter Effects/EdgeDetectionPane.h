#pragma once

namespace Panes
{
    class CEdgeDetectionPane final : public CSamplePane
    {
    public:
        CEdgeDetectionPane(UINT nDlgId, SampleId sampleId, UINT nNameResId);
    private:
        // Overridden
        virtual void DoDataExchange(CDataExchange* pDX) override;
        virtual void InitPane() override;
        virtual void SetSampleParameters() override;
        virtual void ResetParameters() override;
        virtual void ParametersChanged() override;

        // Implementation
        void FillModeCombo();
        void FillAlphaModeCombo();

        // Controls
        CSliderCtrl m_sliderStrength;
        CSliderCtrl m_sliderBlurRadius;
        CExtendedComboBox m_comboMode;
        CButton m_checkOverlayEdge;
        CExtendedComboBox m_comboAlphaMode;

        // Data
        static constexpr int m_nMinSliderPos{ 0 };
        static constexpr int m_nMaxSliderPos{ 100 };
        static constexpr int m_nDefStrengthSliderPos{ 50 };
        static constexpr int m_nDefBlurRadiusSliderPos{ 0 };
    };
} // namespace Panes
