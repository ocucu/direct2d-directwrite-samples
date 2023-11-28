// File: DirectionalBlurPane.cpp - CDirectionalBlurPane class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/ 
//         e-mail: ovidiu.cucu.mvp@gmail.com 

#include "pch.h"
#include "DirectionalBlurPane.h"
#include "DirectionalBlurParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CDirectionalBlurPane;
using Parameters::CDirectionalBlurParameters;

CDirectionalBlurPane::CDirectionalBlurPane(UINT nDlgId, SampleId sampleId, UINT nNameResId)
    : CGaussianBlurPane(nDlgId, sampleId, nNameResId)
{
}

#pragma region Overriden
void CDirectionalBlurPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_ANGLE, m_sliderAngle);
}

void CDirectionalBlurPane::InitPane()
{
    __super::InitPane();
    m_sliderAngle.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
}

void CDirectionalBlurPane::SetSampleParameters()
{
    // set some initial values, just to take a nice picture
    m_sliderStandardDeviation.SetPos(900);
    m_sliderAngle.SetPos(22);
    m_comboOptimization.SelectItem(D2D1_GAUSSIANBLUR_OPTIMIZATION_QUALITY);
    m_comboBorderMode.SelectItem(D2D1_BORDER_MODE_HARD);
    ParametersChanged();
}

void CDirectionalBlurPane::ResetParameters()
{
    // set the default values
    m_sliderAngle.SetPos(m_nDefSliderPos);
    __super::ResetParameters();
}

void CDirectionalBlurPane::ParametersChanged()
{
    CDirectionalBlurParameters params;
    __super::UpdateGaussianBlurParameters(params);
    params.SetAngle(static_cast<FLOAT>(m_sliderAngle.GetPos()));
    UpdateView(UpdateHint::directionalBlurChanged, params);
}
#pragma endregion
