// File: LinearGradientBrushPane.cpp - CLinearGradientBrushPane class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "LinearGradientBrushPane.h"
#include "LinearGradientBrushParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CLinearGradientBrushPane;
using Parameters::CLinearGradientBrushParameters;

CLinearGradientBrushPane::CLinearGradientBrushPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId)
    : CGradientBrushPane(nDlgId, sampleId, nNameResId, figureId)
{
}

#pragma region Overriden
void CLinearGradientBrushPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_START_POINT_X, m_sliderStartPointX);
    DDX_Control(pDX, IDC_SLIDER_START_POINT_Y, m_sliderStartPointY);
    DDX_Control(pDX, IDC_SLIDER_END_POINT_X, m_sliderEndPointX);
    DDX_Control(pDX, IDC_SLIDER_END_POINT_Y, m_sliderEndPointY);
}

void CLinearGradientBrushPane::InitPane()
{
    __super::InitPane();
    m_sliderStartPointX.SetRange(m_nMinPointSliderPosX, m_nMaxPointSliderPosX);
    m_sliderStartPointY.SetRange(m_nMinPointSliderPosY, m_nMaxPointSliderPosY);
    m_sliderEndPointX.SetRange(m_nMinPointSliderPosX, m_nMaxPointSliderPosX);
    m_sliderEndPointY.SetRange(m_nMinPointSliderPosY, m_nMaxPointSliderPosY);
}

void CLinearGradientBrushPane::SetSampleParameters()
{
    ResetParameters();
}

void CLinearGradientBrushPane::ResetParameters()
{
    __super::ResetParameters();
    m_sliderStartPointX.SetPos(m_nMinPointSliderPosX);
    m_sliderStartPointY.SetPos(m_nMaxPointSliderPosY / 2);
    m_sliderEndPointX.SetPos(m_nMaxPointSliderPosX);
    m_sliderEndPointY.SetPos(m_nMaxPointSliderPosY / 2);
    ParametersChanged();
}

void CLinearGradientBrushPane::ParametersChanged()
{
    CLinearGradientBrushParameters params;
    UpdateGradientBrushParameters(params);
    int nStartPointX = m_sliderStartPointX.GetPos();
    int nStartPointY = m_sliderStartPointY.GetPos();
    params.SetStartPoint(nStartPointX, nStartPointY);
    int nEndPointX = m_sliderEndPointX.GetPos();
    int nEndPointY = m_sliderEndPointY.GetPos();
    params.SetEndPoint(nEndPointX, nEndPointY);
    UpdateView(UpdateHint::linearGradientBrushChanged, params);
}
#pragma endregion
