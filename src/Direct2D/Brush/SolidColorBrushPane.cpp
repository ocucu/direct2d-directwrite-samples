// File: SolidColorBrushPane.cpp - CSolidColorBrushPane class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "SolidColorBrushPane.h"
#include "SolidColorBrushParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CSolidColorBrushPane;
using Parameters::CSolidColorBrushParameters;

CSolidColorBrushPane::CSolidColorBrushPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId)
    : CBrushPane(nDlgId, sampleId, nNameResId, figureId)
{
}

#pragma region Overriden
void CSolidColorBrushPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BUTTON_COLOR, m_buttonColor);
}

void CSolidColorBrushPane::InitPane()
{
    __super::InitPane();
}

void CSolidColorBrushPane::SetSampleParameters()
{
    m_buttonColor.SetColor(RGB(0, 0, 255));
    // just for demo purpose, initially set 50% opacity
    m_sliderOpacity.SetPos(m_nMaxOpacitySliderPos / 2);
    ParametersChanged();
}

void CSolidColorBrushPane::ResetParameters()
{
    __super::ResetParameters();
    m_buttonColor.SetColor(RGB(0, 0, 255));
    ParametersChanged();
}

void CSolidColorBrushPane::ParametersChanged()
{
    CSolidColorBrushParameters params;
    UpdateBrushParameters(params);
    params.SetColor(m_buttonColor.GetColor());
    UpdateView(UpdateHint::solidColorBrushChanged, params);
}
#pragma endregion
