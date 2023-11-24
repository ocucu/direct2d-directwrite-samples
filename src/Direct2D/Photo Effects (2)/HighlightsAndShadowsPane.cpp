#include "pch.h"
#include "HighlightsAndShadowsPane.h"
#include "HighlightsAndShadowsParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CHighlightsAndShadowsPane;
using Parameters::CHighlightsAndShadowsParameters;

CHighlightsAndShadowsPane::CHighlightsAndShadowsPane(UINT nDlgId, SampleId sampleId, UINT nNameResId)
    : CSamplePane(nDlgId, sampleId, nNameResId)
{
}

#pragma region Overriden
void CHighlightsAndShadowsPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_HIGHLIGHTS, m_sliderHighlights);
    DDX_Control(pDX, IDC_SLIDER_SHADOWS, m_sliderShadows);
    DDX_Control(pDX, IDC_SLIDER_CLARITY, m_sliderClarity);
    DDX_Control(pDX, IDC_COMBO_INPUT_GAMMA, m_comboInputGamma);
    DDX_Control(pDX, IDC_SLIDER_MASK_BLUR_RADIUS, m_sliderMaskBlurRasius);
}

void CHighlightsAndShadowsPane::InitPane()
{
    m_sliderHighlights.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    m_sliderShadows.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    m_sliderClarity.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    FillInputGammaCombo();
    m_sliderMaskBlurRasius.SetRange(m_nRadiusMinSliderPos, m_nRadiusMaxSliderPos);
}

void CHighlightsAndShadowsPane::SetSampleParameters()
{
    m_sliderHighlights.SetPos(m_nMaxSliderPos * 3 / 4);
    m_sliderShadows.SetPos(m_nMaxSliderPos / 4);
    m_sliderClarity.SetPos(m_nMaxSliderPos * 3 / 4);
    m_comboInputGamma.SelectItem(D2D1_HIGHLIGHTSANDSHADOWS_INPUT_GAMMA_LINEAR);
    m_sliderMaskBlurRasius.SetPos(m_nRadiusDefSliderPos);
    ParametersChanged();
}

void CHighlightsAndShadowsPane::ResetParameters()
{
    m_sliderHighlights.SetPos(m_nDefSliderPos);
    m_sliderShadows.SetPos(m_nDefSliderPos);
    m_sliderClarity.SetPos(m_nDefSliderPos);
    m_comboInputGamma.SelectItem(D2D1_HIGHLIGHTSANDSHADOWS_INPUT_GAMMA_SRGB);
    m_sliderMaskBlurRasius.SetPos(m_nRadiusDefSliderPos);
    ParametersChanged();
}

void CHighlightsAndShadowsPane::ParametersChanged()
{
    CHighlightsAndShadowsParameters params;

    FLOAT highlights = (m_sliderHighlights.GetPos() - m_nDefSliderPos) / 100.f;
    params.SetHighlights(highlights);
    FLOAT shadows = (m_sliderShadows.GetPos() - m_nDefSliderPos) / 100.f;
    params.SetShadows(shadows);
    FLOAT clarity = (m_sliderClarity.GetPos() - m_nDefSliderPos) / 100.f;
    params.SetClarity(clarity);
    DWORD_PTR inputGamma = m_comboInputGamma.GetSelectedItemData();
    params.SetInputGamma(inputGamma);
    FLOAT maskBlurRadius = m_sliderMaskBlurRasius.GetPos() / 100.f;
    params.SetMaskBlurRadius(maskBlurRadius);

    UpdateView(UpdateHint::highlightsAndShadowsChanged, params);
}
#pragma endregion

#pragma region Implementation
void CHighlightsAndShadowsPane::FillInputGammaCombo()
{
    m_comboInputGamma.ResetContent();
    m_comboInputGamma.AddItem(L"Linear", D2D1_HIGHLIGHTSANDSHADOWS_INPUT_GAMMA_LINEAR);
    m_comboInputGamma.AddItem(L"sRGB", D2D1_HIGHLIGHTSANDSHADOWS_INPUT_GAMMA_SRGB);
}
#pragma endregion