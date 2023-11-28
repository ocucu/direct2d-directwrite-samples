// File: EdgeDetectionPane.cpp - CEdgeDetectionPane class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/ 
//         e-mail: ovidiu.cucu.mvp@gmail.com

#include "pch.h"
#include "EdgeDetectionPane.h"
#include "EdgeDetectionParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CEdgeDetectionPane;
using Parameters::CEdgeDetectionParameters;

CEdgeDetectionPane::CEdgeDetectionPane(UINT nDlgId, SampleId sampleId, UINT nNameResId)
    : CSamplePane(nDlgId, sampleId, nNameResId)
{
}

#pragma region Overriden
void CEdgeDetectionPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_STRENGTH, m_sliderStrength);
    DDX_Control(pDX, IDC_SLIDER_BLUR_RADIUS, m_sliderBlurRadius);
    DDX_Control(pDX, IDC_COMBO_MODE, m_comboMode);
    DDX_Control(pDX, IDC_CHECK_OVERLAY_EDGES, m_checkOverlayEdge);
    DDX_Control(pDX, IDC_COMBO_ALPHA_MODE, m_comboAlphaMode);
}

void CEdgeDetectionPane::InitPane()
{
    m_sliderStrength.SetRange(m_nMinSliderPos + 1, m_nMaxSliderPos);
    m_sliderBlurRadius.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    FillModeCombo();
    FillAlphaModeCombo();
}

void CEdgeDetectionPane::SetSampleParameters()
{
    ResetParameters();
}

void CEdgeDetectionPane::ResetParameters()
{
    // set the default values
    m_sliderStrength.SetPos(m_nDefStrengthSliderPos);
    m_sliderBlurRadius.SetPos(m_nDefBlurRadiusSliderPos);
    m_comboMode.SelectItem(D2D1_EDGEDETECTION_MODE_SOBEL);
    m_checkOverlayEdge.SetCheck(BST_UNCHECKED);
    m_comboAlphaMode.SelectItem(D2D1_ALPHA_MODE_PREMULTIPLIED);
    ParametersChanged();
}

void CEdgeDetectionPane::ParametersChanged()
{
    CEdgeDetectionParameters params;
    params.SetStrength(m_sliderStrength.GetPos() / 100.f);
    params.SetBlurRadius(m_sliderBlurRadius.GetPos() / 10.f);
    params.SetMode(m_comboMode.GetSelectedItemData());
    params.SetOverlayEdges(m_checkOverlayEdge.GetCheck() == BST_CHECKED);
    params.SetAlphaMode(m_comboAlphaMode.GetSelectedItemData());
    UpdateView(UpdateHint::edgeDetectionChanged, params);
}
#pragma endregion

#pragma region Implementation
void CEdgeDetectionPane::FillModeCombo()
{
    m_comboMode.ResetContent();
    m_comboMode.AddItem(L"Sobel", D2D1_EDGEDETECTION_MODE_SOBEL);
    m_comboMode.AddItem(L"Prewitt", D2D1_EDGEDETECTION_MODE_PREWITT);
}

void CEdgeDetectionPane::FillAlphaModeCombo()
{
    m_comboAlphaMode.ResetContent();
    m_comboAlphaMode.AddItem(L"Premultiplied", D2D1_ALPHA_MODE_PREMULTIPLIED);
    m_comboAlphaMode.AddItem(L"Straight", D2D1_ALPHA_MODE_STRAIGHT);
    m_comboAlphaMode.AddItem(L"Ignore", D2D1_ALPHA_MODE_IGNORE);
}
#pragma endregion
