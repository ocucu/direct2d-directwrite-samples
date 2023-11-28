// File: GaussianBlurPane.cpp - CGaussianBlurPane class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/ 
//         e-mail: ovidiu.cucu.mvp@gmail.com

#include "pch.h"
#include "GaussianBlurPane.h"
#include "GaussianBlurParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CGaussianBlurPane;
using Parameters::CGaussianBlurParameters;

CGaussianBlurPane::CGaussianBlurPane(UINT nDlgId, SampleId sampleId, UINT nNameResId)
    : CSamplePane(nDlgId, sampleId, nNameResId)
{
}

#pragma region Overriden
void CGaussianBlurPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_STANDARD_DEVIATION, m_sliderStandardDeviation);
    DDX_Control(pDX, IDC_COMBO_OPTIMIZATION, m_comboOptimization);
    DDX_Control(pDX, IDC_COMBO_BORDER_MODE, m_comboBorderMode);
}

void CGaussianBlurPane::InitPane()
{
    m_sliderStandardDeviation.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    FillOptimizationCombo();
    FillBorderModeCombo();
}

void CGaussianBlurPane::SetSampleParameters()
{
    // set some initial values, just to take a nice picture
    m_sliderStandardDeviation.SetPos(350);
    m_comboOptimization.SelectItem(D2D1_GAUSSIANBLUR_OPTIMIZATION_SPEED);
    m_comboBorderMode.SelectItem(D2D1_BORDER_MODE_HARD);
    ParametersChanged();
}

void CGaussianBlurPane::ResetParameters()
{
    // set default values
    m_sliderStandardDeviation.SetPos(m_nDefSliderPos);
    m_comboOptimization.SelectItem(D2D1_GAUSSIANBLUR_OPTIMIZATION_BALANCED);
    m_comboBorderMode.SelectItem(D2D1_BORDER_MODE_SOFT);
    ParametersChanged();
}

void CGaussianBlurPane::ParametersChanged()
{
    CGaussianBlurParameters params;
    UpdateGaussianBlurParameters(params);
    UpdateView(UpdateHint::gaussianBlurChanged, params);
}
#pragma endregion

#pragma region Operations
void CGaussianBlurPane::UpdateGaussianBlurParameters(CGaussianBlurParameters& params)
{
    FLOAT standardDeviation = m_sliderStandardDeviation.GetPos() / 100.f;
    params.SetStandardDeviation(standardDeviation);
    params.SetOptimization(m_comboOptimization.GetSelectedItemData());
    params.SetBorderMode(m_comboBorderMode.GetSelectedItemData());
}
#pragma endregion

#pragma region Implementation
void CGaussianBlurPane::FillOptimizationCombo()
{
    m_comboOptimization.ResetContent();
    m_comboOptimization.AddItem(L"Speed", D2D1_DIRECTIONALBLUR_OPTIMIZATION_SPEED);
    m_comboOptimization.AddItem(L"Balanced", D2D1_DIRECTIONALBLUR_OPTIMIZATION_BALANCED);
    m_comboOptimization.AddItem(L"Quality", D2D1_DIRECTIONALBLUR_OPTIMIZATION_QUALITY);
}

void CGaussianBlurPane::FillBorderModeCombo()
{
    m_comboBorderMode.ResetContent();
    m_comboBorderMode.AddItem(L"Soft", D2D1_BORDER_MODE_SOFT);
    m_comboBorderMode.AddItem(L"Hard", D2D1_BORDER_MODE_HARD);
}
#pragma endregion