// File: DrawingEffectsPane.cpp - CDrawingEffectsPane class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/
//         e-mail: ovidiu.cucu.mvp@gmail.com

#include "pch.h"
#include "DrawingEffectsPane.h"
#include "Parameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CDrawingEffectsPane;
using namespace Parameters;

CDrawingEffectsPane::CDrawingEffectsPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId, BrushTypeId brushTypeId)
    : CTextLayoutPane(nDlgId, sampleId, nNameResId, nTextResId, brushTypeId)
{
}

#pragma region Overriden
void CDrawingEffectsPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BUTTON_BRUSH_COLOR, m_buttonColor);
}

void CDrawingEffectsPane::InitPane()
{
    __super::InitPane();
}

void CDrawingEffectsPane::SetSampleParameters()
{
    // set some values to get a nice sample picture
    m_sliderMaxWidth.SetPos(456);
    m_sliderMaxHeight.SetPos(396);
    m_sliderStartPosition.SetPos(0);
    m_sliderLength.SetPos(20);
    m_buttonColor.SetColor(RGB(0, 0, 255));
    ParametersChanged();
}

void CDrawingEffectsPane::ResetParameters()
{
    m_sliderMaxWidth.SetPos(456);
    m_sliderMaxHeight.SetPos(396);
    m_sliderStartPosition.SetPos(0);
    m_sliderLength.SetPos(0);
    m_buttonColor.SetColor(RGB(0, 0, 0));
    ParametersChanged();
}

void CDrawingEffectsPane::ParametersChanged()
{
    CDrawingEffectsParameters params;
    UpdateTextLayoutParameters(params);
    params.SetBrushColor(m_buttonColor.GetColor());
    UpdateView(UpdateHint::drawingEffectsChanged, params);
}
#pragma endregion


