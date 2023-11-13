
#include "pch.h"
#include "ContrastParameters.h"
#include "ContrastPane.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CContrastPane;
using Parameters::CContrastParameters;

CContrastPane::CContrastPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BitmapId bitmapId)
    : CSamplePane(nDlgId, sampleId, nNameResId, bitmapId)
{
}

#pragma region Overriden
void CContrastPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_CONTRAST, m_sliderContrast);
    DDX_Control(pDX, IDC_CHECK_CLAMP_INPUT, m_checkClampInput);
}

void CContrastPane::InitPane()
{
    m_sliderContrast.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
}

void CContrastPane::SetSampleParameters()
{
    m_sliderContrast.SetPos(m_nMaxSliderPos);
    ParametersChanged();
}

void CContrastPane::ResetParameters()
{
    m_sliderContrast.SetPos(m_nDefaultSliderPos);
    m_checkClampInput.SetCheck(BST_UNCHECKED);
    ParametersChanged();
}

void CContrastPane::ParametersChanged()
{
    CContrastParameters params;
    FLOAT contrast = (m_sliderContrast.GetPos() - m_nDefaultSliderPos) / 100.f;
    params.SetContrast(contrast);
    params.SetClampInput(m_checkClampInput.GetCheck() == BST_CHECKED);
    UpdateView(UpdateHint::contrastChanged, params);
}
#pragma endregion
