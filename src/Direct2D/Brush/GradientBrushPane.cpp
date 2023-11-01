// File: GradientBrushPane.cpp - CGradientBrushPane class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "GradientBrushPane.h"
#include "GradientBrushParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CGradientBrushPane;
using Parameters::CGradientBrushParameters;

CGradientBrushPane::CGradientBrushPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId)
    : CBrushPane(nDlgId, sampleId, nNameResId, figureId)
{
}

#pragma region Overriden
void CGradientBrushPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BUTTON_FIRST_COLOR, m_buttonFirstColor);
    DDX_Control(pDX, IDC_BUTTON_SECOND_COLOR, m_buttonSecondColor);
    DDX_Control(pDX, IDC_BUTTON_THIRD_COLOR, m_buttonThirdColor);
    DDX_Control(pDX, IDC_COMBO_COLOR_INTERPOLATION, m_comboColorInterpolation);
    DDX_Control(pDX, IDC_COMBO_EXTEND_MODE_X, m_comboExtendMode);
}

void CGradientBrushPane::InitPane()
{
    __super::InitPane();
    FillColorInterpolationCombo();
    FillExtendModeCombo();
}

void CGradientBrushPane::ResetParameters()
{
    __super::ResetParameters();
    m_buttonFirstColor.SetColor(D2D1::ColorF::Red);
    m_buttonSecondColor.SetColor(D2D1::ColorF::Green);
    m_buttonThirdColor.SetColor(D2D1::ColorF::Blue);
    m_comboColorInterpolation.SelectItem(D2D1_GAMMA_2_2);
    m_comboExtendMode.SelectItem(D2D1_EXTEND_MODE_CLAMP);
    ParametersChanged();
}
#pragma endregion

#pragma region Operations
void CGradientBrushPane::UpdateGradientBrushParameters(Parameters::CGradientBrushParameters& params)
{
    UpdateBrushParameters(params);
    params.SetGradientStopColor(0, m_buttonFirstColor.GetColor());
    params.SetGradientStopColor(1, m_buttonSecondColor.GetColor());
    params.SetGradientStopColor(2, m_buttonThirdColor.GetColor());
    params.SetColorInterpolationGamma(m_comboColorInterpolation.GetSelectedItemData());
    params.SetExtendMode(m_comboExtendMode.GetSelectedItemData());
}
#pragma endregion

#pragma region Implementation
void CGradientBrushPane::FillColorInterpolationCombo()
{
    m_comboColorInterpolation.ResetContent();
    m_comboColorInterpolation.AddItem(L"Standard RGB gamma", D2D1_GAMMA_2_2);
    m_comboColorInterpolation.AddItem(L"Linear-gamma color space", D2D1_GAMMA_1_0);
}

void CGradientBrushPane::FillExtendModeCombo()
{
    m_comboExtendMode.ResetContent();
    m_comboExtendMode.AddItem(L"Clamp", D2D1_EXTEND_MODE_CLAMP);
    m_comboExtendMode.AddItem(L"Wrap", D2D1_EXTEND_MODE_WRAP);
    m_comboExtendMode.AddItem(L"Mirror", D2D1_EXTEND_MODE_MIRROR);
}
#pragma endregion

