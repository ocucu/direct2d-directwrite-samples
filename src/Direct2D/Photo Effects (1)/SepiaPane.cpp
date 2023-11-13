
#include "pch.h"
#include "SepiaParameters.h"
#include "SepiaPane.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CSepiaPane;
using Parameters::CSepiaParameters;

CSepiaPane::CSepiaPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BitmapId bitmapId)
    : CSamplePane(nDlgId, sampleId, nNameResId, bitmapId)
{
}

#pragma region Overriden
void CSepiaPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_INTENSITY, m_sliderIntensity);
    DDX_Control(pDX, IDC_COMBO_ALPHA_MODE, m_comboAlphaMode);
}

void CSepiaPane::InitPane()
{
    m_sliderIntensity.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    FillAlphaModeCombo();
}

void CSepiaPane::SetSampleParameters()
{
    m_sliderIntensity.SetPos(m_nMaxSliderPos * 3 / 4);
    m_comboAlphaMode.SelectItem(D2D1_ALPHA_MODE_PREMULTIPLIED);
    ParametersChanged();
}

void CSepiaPane::ResetParameters()
{
    m_sliderIntensity.SetPos(m_nDefaultSliderPos);
    m_comboAlphaMode.SelectItem(D2D1_ALPHA_MODE_PREMULTIPLIED);
    ParametersChanged();
}

void CSepiaPane::ParametersChanged()
{
    CSepiaParameters params;
    FLOAT intensity = m_sliderIntensity.GetPos() / 100.f;
    params.SetIntensity(intensity);
    params.SetAlphaMode(m_comboAlphaMode.GetSelectedItemData());
    UpdateView(UpdateHint::sepiaChanged, params);
}
#pragma endregion

#pragma region Implementation
void CSepiaPane::FillAlphaModeCombo()
{
    m_comboAlphaMode.ResetContent();
    m_comboAlphaMode.AddItem(L"Premultiplied", D2D1_ALPHA_MODE_PREMULTIPLIED);
    m_comboAlphaMode.AddItem(L"Straight", D2D1_ALPHA_MODE_STRAIGHT);
    m_comboAlphaMode.AddItem(L"Ignore", D2D1_ALPHA_MODE_IGNORE);
}
#pragma endregion
