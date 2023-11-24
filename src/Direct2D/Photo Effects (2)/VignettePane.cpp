#include "pch.h"
#include "VignettePane.h"
#include "VignetteParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CVignettePane;
using Parameters::CVignetteParameters;

CVignettePane::CVignettePane(UINT nDlgId, SampleId sampleId, UINT nNameResId)
    : CSamplePane(nDlgId, sampleId, nNameResId)
{
}

#pragma region Overriden
void CVignettePane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BUTTON_COLOR, m_buttonColor);
    DDX_Control(pDX, IDC_SLIDER_COLOR_OPACITY, m_sliderColorOpacity);
    DDX_Control(pDX, IDC_SLIDER_TRANSITION_SIZE, m_sliderTransitionSize);
    DDX_Control(pDX, IDC_SLIDER_STRENGTH, m_sliderStrength);
}

void CVignettePane::InitPane()
{
    m_sliderColorOpacity.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    m_sliderTransitionSize.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    m_sliderStrength.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
}

void CVignettePane::SetSampleParameters()
{
    // set some initial values, just to take a nice picture
    m_buttonColor.SetColor(RGB(192, 192, 192));
    m_sliderColorOpacity.SetPos(m_nMaxSliderPos * 3 / 4);
    m_sliderTransitionSize.SetPos(m_nMaxSliderPos * 3 / 4);
    m_sliderStrength.SetPos(m_nMaxSliderPos * 3 / 4);
    ParametersChanged();
}

void CVignettePane::ResetParameters()
{
    // set the default values
    m_buttonColor.SetColor(RGB(0, 0, 0));
    m_sliderTransitionSize.SetPos(m_nMinSliderPos + 10);
    m_sliderStrength.SetPos(m_nMaxSliderPos / 2);
    m_sliderColorOpacity.SetPos(m_nMaxSliderPos);
    ParametersChanged();
}

void CVignettePane::ParametersChanged()
{
    CVignetteParameters params;
    COLORREF color = m_buttonColor.GetColor();
    FLOAT colorOpacity = m_sliderColorOpacity.GetPos() / 100.f;
    params.SetColor(color, colorOpacity);
    FLOAT transitionSize = m_sliderTransitionSize.GetPos() / 100.f;
    params.SetTransitionSize(transitionSize);
    FLOAT strength = m_sliderStrength.GetPos() / 100.f;
    params.SetStrength(strength);
    UpdateView(UpdateHint::vignetteChanged, params);
}
#pragma endregion
