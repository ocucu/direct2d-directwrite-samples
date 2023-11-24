
#include "pch.h"
#include "SharpenPane.h"
#include "SharpenParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CSharpenPane;
using Parameters::CSharpenParameters;

CSharpenPane::CSharpenPane(UINT nDlgId, SampleId sampleId, UINT nNameResId)
    : CSamplePane(nDlgId, sampleId, nNameResId)
{
}

#pragma region Overriden
void CSharpenPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_SHARPNESS, m_sliderSharpness);
    DDX_Control(pDX, IDC_SLIDER_THRESHOLD, m_sliderThreshold);
}

void CSharpenPane::InitPane()
{
    m_sliderSharpness.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    m_sliderThreshold.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
}

void CSharpenPane::SetSampleParameters()
{
    m_sliderSharpness.SetPos(m_nMaxSliderPos);
    m_sliderThreshold.SetPos(m_nMaxSliderPos);
    ParametersChanged();
}

void CSharpenPane::ResetParameters()
{
    m_sliderSharpness.SetPos(m_nDefSliderPos);
    m_sliderThreshold.SetPos(m_nDefSliderPos);
    ParametersChanged();
}

void CSharpenPane::ParametersChanged()
{
    CSharpenParameters params;
    // sharpness value between 0.f and 10.f
    FLOAT sharpness = m_sliderSharpness.GetPos() / 10.f;
    params.SetSharpness(sharpness);
    // threshold value between 0.f and 1.f
    FLOAT threshold = m_sliderThreshold.GetPos() / 100.f;
    params.SetThreshold(threshold);
    UpdateView(UpdateHint::sharpenChanged, params);
}
#pragma endregion
