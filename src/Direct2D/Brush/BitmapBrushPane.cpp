// File: BitmapBrushPane.cpp - CBitmapBrushPane class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "BitmapBrushPane.h"
#include "BitmapBrushParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CBitmapBrushPane;
using Parameters::CBitmapBrushParameters;

CBitmapBrushPane::CBitmapBrushPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId, BitmapId bitmapId)
    : CBrushPane(nDlgId, sampleId, nNameResId, figureId, bitmapId)
{
}

#pragma region Overriden
void CBitmapBrushPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_EXTEND_MODE_X, m_comboExtendModeX);
    DDX_Control(pDX, IDC_COMBO_EXTEND_MODE_Y, m_comboExtendModeY);
    DDX_Control(pDX, IDC_COMBO_INTERPOLATION_MODE, m_comboInterpolationMode);
}

void CBitmapBrushPane::InitPane()
{
    __super::InitPane();
    FillExtendModeXCombo();
    FillExtendModeYCombo();
    FillInterpolationModeCombo();
}

void CBitmapBrushPane::SetSampleParameters()
{
    m_sliderOpacity.SetPos(m_nDefaultOpacitySliderPos);
    m_sliderScale.SetPos(m_nSampleScaleSliderPos);
    m_comboExtendModeX.SelectItem(D2D1_EXTEND_MODE_WRAP);
    m_comboExtendModeY.SelectItem(D2D1_EXTEND_MODE_WRAP);
    m_comboInterpolationMode.SelectItem(D2D1_INTERPOLATION_MODE_DEFINITION_LINEAR);
    ParametersChanged();
}

void CBitmapBrushPane::ResetParameters()
{
    __super::ResetParameters();
    m_comboExtendModeX.SelectItem(D2D1_EXTEND_MODE_CLAMP);
    m_comboExtendModeY.SelectItem(D2D1_EXTEND_MODE_CLAMP);
    m_comboInterpolationMode.SelectItem(D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
    ParametersChanged();
}

void CBitmapBrushPane::ParametersChanged()
{
    CBitmapBrushParameters params;
    UpdateBrushParameters(params);
    params.SetExtendModeX(m_comboExtendModeX.GetSelectedItemData());
    params.SetExtendModeY(m_comboExtendModeY.GetSelectedItemData());
    params.SetInterpolationMode(m_comboInterpolationMode.GetSelectedItemData());
    UpdateView(UpdateHint::bitmapBrushChanged, params);
}
#pragma endregion

#pragma region Implementation
void CBitmapBrushPane::FillExtendModeXCombo()
{
    m_comboExtendModeX.ResetContent();
    m_comboExtendModeX.AddItem(L"Clamp", D2D1_EXTEND_MODE_CLAMP);
    m_comboExtendModeX.AddItem(L"Wrap", D2D1_EXTEND_MODE_WRAP);
    m_comboExtendModeX.AddItem(L"Mirror", D2D1_EXTEND_MODE_MIRROR);
}

void CBitmapBrushPane::FillExtendModeYCombo()
{
    m_comboExtendModeY.ResetContent();
    m_comboExtendModeY.AddItem(L"Clamp", D2D1_EXTEND_MODE_CLAMP);
    m_comboExtendModeY.AddItem(L"Wrap", D2D1_EXTEND_MODE_WRAP);
    m_comboExtendModeY.AddItem(L"Mirror", D2D1_EXTEND_MODE_MIRROR);
}

void CBitmapBrushPane::FillInterpolationModeCombo()
{
    m_comboInterpolationMode.ResetContent();
    m_comboInterpolationMode.AddItem(L"Nearest neighbor", D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
    m_comboInterpolationMode.AddItem(L"Linear", D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
}
#pragma endregion

