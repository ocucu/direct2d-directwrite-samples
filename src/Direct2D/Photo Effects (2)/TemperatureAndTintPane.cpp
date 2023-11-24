#include "pch.h"
#include "TemperatureAndTintPane.h"
#include "TemperatureAndTintParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CTemperatureAndTintPane;
using Parameters::CTemperatureAndTintParameters;

CTemperatureAndTintPane::CTemperatureAndTintPane(UINT nDlgId, SampleId sampleId, UINT nNameResId)
    : CSamplePane(nDlgId, sampleId, nNameResId)
{
}

#pragma region Overriden
void CTemperatureAndTintPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_TEMPERATURE, m_sliderTemperature);
    DDX_Control(pDX, IDC_SLIDER_TINT, m_sliderTint);
}

void CTemperatureAndTintPane::InitPane()
{
    m_sliderTemperature.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    m_sliderTint.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
}

void CTemperatureAndTintPane::SetSampleParameters()
{
    m_sliderTemperature.SetPos(90);
    m_sliderTint.SetPos(80);
    ParametersChanged();
}

void CTemperatureAndTintPane::ResetParameters()
{
    m_sliderTemperature.SetPos(m_nDefSliderPos);
    m_sliderTint.SetPos(m_nDefSliderPos);
    ParametersChanged();
}

void CTemperatureAndTintPane::ParametersChanged()
{
    CTemperatureAndTintParameters params;
    FLOAT temperature = (m_sliderTemperature.GetPos() - m_nDefSliderPos) / 100.f;
    params.SetTemperature(temperature);
    FLOAT tint = (m_sliderTint.GetPos() - m_nDefSliderPos) / 100.f;
    params.SetTint(tint);
    UpdateView(UpdateHint::temperatureAndTintChanged, params);
}
#pragma endregion