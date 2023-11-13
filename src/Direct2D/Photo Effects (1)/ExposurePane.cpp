#include "pch.h"
#include "ExposureParameters.h"
#include "ExposurePane.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CExposurePane;
using Parameters::CExposureParameters;

CExposurePane::CExposurePane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BitmapId bitmapId)
    : CSamplePane(nDlgId, sampleId, nNameResId, bitmapId)
{
}

#pragma region Overriden
void CExposurePane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_VALUE, m_sliderValue);
}

void CExposurePane::InitPane()
{
    m_sliderValue.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
}

void CExposurePane::SetSampleParameters()
{
    m_sliderValue.SetPos(m_nMaxSliderPos * 3 / 4);
    ParametersChanged();
}

void CExposurePane::ResetParameters()
{
    m_sliderValue.SetPos(m_nDefaultSliderPos);
    ParametersChanged();
}

void CExposurePane::ParametersChanged()
{
    CExposureParameters params;
    // note: exposure value is between -2.0 and 2.0  (default is 1.0)
    FLOAT value = (m_sliderValue.GetPos() - m_nDefaultSliderPos) / 100.f;
    params.SetValue(value);
    UpdateView(UpdateHint::exposureChanged, params);
}
#pragma endregion