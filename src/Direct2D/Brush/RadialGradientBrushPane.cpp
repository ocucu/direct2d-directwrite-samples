// File: RadialGradientBrushPane.cpp - CRadialGradientBrushPane class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "RadialGradientBrushPane.h"
#include "RadialGradientBrushParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CRadialGradientBrushPane;
using Parameters::CRadialGradientBrushParameters;

CRadialGradientBrushPane::CRadialGradientBrushPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId)
    : CGradientBrushPane(nDlgId, sampleId, nNameResId, figureId)
{
}

#pragma region Overriden
void CRadialGradientBrushPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_CENTER_X, m_sliderCenterX);
    DDX_Control(pDX, IDC_SLIDER_CENTER_Y, m_sliderCenterY);
    DDX_Control(pDX, IDC_SLIDER_OFFSET_X, m_sliderOffsetX);
    DDX_Control(pDX, IDC_SLIDER_OFFSET_Y, m_sliderOffsetY);
    DDX_Control(pDX, IDC_SLIDER_RADIUS_X, m_sliderRadiusX);
    DDX_Control(pDX, IDC_SLIDER_RADIUS_Y, m_sliderRadiusY);
}

void CRadialGradientBrushPane::InitPane()
{
    __super::InitPane();
    m_sliderCenterX.SetRange(m_nMinCenterSliderPos, m_nMaxCenterSliderPos);
    m_sliderCenterY.SetRange(m_nMinCenterSliderPos, m_nMaxCenterSliderPos);
    m_sliderOffsetX.SetRange(m_nMinOffsetSliderPos, m_nMaxOffsetSliderPos);
    m_sliderOffsetY.SetRange(m_nMinOffsetSliderPos, m_nMaxOffsetSliderPos);
    m_sliderRadiusX.SetRange(m_nMinRadiusSliderPos, m_nMaxRadiusSliderPos);
    m_sliderRadiusY.SetRange(m_nMinRadiusSliderPos, m_nMaxRadiusSliderPos);
}

void CRadialGradientBrushPane::SetSampleParameters()
{
    __super::ResetParameters();
    // set some hard-coded values for taking a nice picture :)
    m_buttonFirstColor.SetColor(RGB(255, 255, 255));
    m_buttonSecondColor.SetColor(RGB(255, 0, 0));
    m_buttonThirdColor.SetColor(RGB(128, 0, 0));
    m_sliderCenterX.SetPos(229);
    m_sliderCenterY.SetPos(200);
    m_sliderRadiusX.SetPos(237);
    m_sliderRadiusY.SetPos(200);
    m_sliderOffsetX.SetPos(m_nDefaultOffsetSliderPos + 60);
    m_sliderOffsetY.SetPos(m_nDefaultOffsetSliderPos + 20);

    ParametersChanged();
}

void CRadialGradientBrushPane::ResetParameters()
{
    __super::ResetParameters();
    m_sliderCenterX.SetPos(m_nDefaultCenterSliderPos);
    m_sliderCenterY.SetPos(m_nDefaultCenterSliderPos);
    m_sliderOffsetX.SetPos(m_nDefaultOffsetSliderPos);
    m_sliderOffsetY.SetPos(m_nDefaultOffsetSliderPos);
    m_sliderRadiusX.SetPos(m_nDefaultRadiusSliderPos);
    m_sliderRadiusY.SetPos(m_nDefaultRadiusSliderPos);
    ParametersChanged();
}

void CRadialGradientBrushPane::ParametersChanged()
{
    CRadialGradientBrushParameters params;
    UpdateGradientBrushParameters(params);

    params.SetCenter(m_sliderCenterX.GetPos(), m_sliderCenterY.GetPos());
    int offsetX = m_sliderOffsetX.GetPos() - m_nDefaultOffsetSliderPos;
    int offsetY = m_sliderOffsetY.GetPos() - m_nDefaultOffsetSliderPos;
    params.SetOffset(offsetX, offsetY);
    params.SetRadiusX(m_sliderRadiusX.GetPos());
    params.SetRadiusY(m_sliderRadiusY.GetPos());
    UpdateView(UpdateHint::radialGradientBrushChanged, params);
}
#pragma endregion

