// File: MorphologyPane.cpp - CMorphologyPane class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/ 
//         e-mail: ovidiu.cucu.mvp@gmail.com

#include "pch.h"
#include "MorphologyPane.h"
#include "MorphologyParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CMorphologyPane;
using Parameters::CMorphologyParameters;

CMorphologyPane::CMorphologyPane(UINT nDlgId, SampleId sampleId, UINT nNameResId)
    : CSamplePane(nDlgId, sampleId, nNameResId)
{
}

#pragma region Overriden
void CMorphologyPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_MODE, m_comboMode);
    DDX_Control(pDX, IDC_SLIDER_WIDTH, m_sliderWidth);
    DDX_Control(pDX, IDC_SLIDER_HEIGHT, m_sliderHeight);
}

void CMorphologyPane::InitPane()
{
    FillModeCombo();
    m_sliderWidth.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    m_sliderHeight.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
}

void CMorphologyPane::SetSampleParameters()
{
    m_comboMode.SelectItem(D2D1_MORPHOLOGY_MODE_DILATE);
    m_sliderWidth.SetPos(12);
    m_sliderHeight.SetPos(1);
    ParametersChanged();
}

void CMorphologyPane::ResetParameters()
{
    m_comboMode.SelectItem(D2D1_MORPHOLOGY_MODE_ERODE);
    m_sliderWidth.SetPos(m_nDefSliderPos);
    m_sliderHeight.SetPos(m_nDefSliderPos);
    ParametersChanged();
}

void CMorphologyPane::ParametersChanged()
{
    CMorphologyParameters params;
    params.SetMode(m_comboMode.GetSelectedItemData());
    params.SetWidth(m_sliderWidth.GetPos());
    params.SetHeight(m_sliderHeight.GetPos());
    UpdateView(UpdateHint::morphologyChanged, params);
}
#pragma endregion

#pragma region Implementation
void CMorphologyPane::FillModeCombo()
{
    m_comboMode.ResetContent();
    m_comboMode.AddItem(L"Erode", D2D1_MORPHOLOGY_MODE_ERODE);
    m_comboMode.AddItem(L"Dilate", D2D1_MORPHOLOGY_MODE_DILATE);
}
#pragma endregion