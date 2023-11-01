// File: BrushPane.cpp - CBrushPane class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "BrushParameters.h"
#include "BrushPane.h"

using Panes::CBrushPane;

CBrushPane::CBrushPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId, BitmapId bitmapId)
    : CSamplePane(nDlgId, sampleId, nNameResId, figureId, bitmapId)
{
}

CBrushPane::CBrushPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId)
    : CSamplePane(nDlgId, sampleId, nNameResId, figureId)
{
}

#pragma region Overriden
void CBrushPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_OPACITY, m_sliderOpacity);
    DDX_Control(pDX, IDC_SLIDER_SCALE, m_sliderScale);
}

void CBrushPane::InitPane()
{
    m_sliderOpacity.SetRange(m_nMinOpacitySliderPos, m_nMaxOpacitySliderPos);
    m_sliderScale.SetRange(m_nMinScaleSliderPos, m_nMaxScaleSliderPos);
}

void CBrushPane::ResetParameters()
{
    m_sliderOpacity.SetPos(m_nDefaultOpacitySliderPos);
    m_sliderScale.SetPos(m_nDefaultScaleSliderPos);
}
#pragma endregion

#pragma region Operations
void CBrushPane::UpdateBrushParameters(Parameters::CBrushParameters& params)
{
    FLOAT opacity = static_cast<FLOAT>(m_sliderOpacity.GetPos()) / m_nMaxOpacitySliderPos; // opacity between 0.f and 1.f
    params.SetOpacity(opacity);

    D2D1_MATRIX_3X2_F transformMatrix = D2D1::Matrix3x2F::Identity();
    const int nScalePos = m_sliderScale.GetPos();
    if (nScalePos != m_nDefaultScaleSliderPos)
    {
        FLOAT fScale = static_cast<FLOAT>(nScalePos) / m_nDefaultScaleSliderPos;
        transformMatrix = D2D1::Matrix3x2F::Scale(CD2DSizeF(fScale, fScale));
        params.SetTransformMatrix(transformMatrix);
    }
}
#pragma endregion