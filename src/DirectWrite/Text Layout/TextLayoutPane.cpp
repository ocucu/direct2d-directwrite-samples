// File: GradientBrushPane.cpp - CGradientBrushPane class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "TextLayoutPane.h"
#include "TextLayoutParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CTextLayoutPane;
using Parameters::CTextLayoutParameters;

CTextLayoutPane::CTextLayoutPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId)
    : CSamplePane(nDlgId, sampleId, nNameResId, nTextResId)
{
}

#pragma region Overriden
void CTextLayoutPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_MAX_WIDTH, m_sliderMaxWidth);
    DDX_Control(pDX, IDC_SLIDER_MAX_HEIGHT, m_sliderMaxHeight);
    DDX_Control(pDX, IDC_SLIDER_START_POSITION, m_sliderStartPosition);
    DDX_Control(pDX, IDC_SLIDER_LENGTH, m_sliderLength);
}

void CTextLayoutPane::InitPane()
{
    m_sliderMaxWidth.SetRange(200, 456);
    m_sliderMaxHeight.SetRange(100, 312);
    m_sliderStartPosition.SetRange(0, 100);
    m_sliderLength.SetRange(0, 100);
}

void CTextLayoutPane::ResetParameters()
{
    m_sliderMaxWidth.SetPos(456);
    m_sliderMaxHeight.SetPos(380);
    m_sliderStartPosition.SetPos(0);
    m_sliderLength.SetPos(0);
}
#pragma endregion

#pragma region Operations
void CTextLayoutPane::UpdateTextLayoutParameters(Parameters::CTextLayoutParameters& params)
{
    FLOAT maxWidth = static_cast<FLOAT>(m_sliderMaxWidth.GetPos());
    FLOAT maxHeight = static_cast<FLOAT>(m_sliderMaxHeight.GetPos());
    CD2DSizeF sizeMax{ maxWidth, maxHeight };
    params.SetMaxSize(sizeMax);

    UINT32 startPosition = static_cast<UINT32>(m_sliderStartPosition.GetPos());
    UINT32 length = static_cast<UINT32>(m_sliderLength.GetPos());
    DWRITE_TEXT_RANGE textRange{ startPosition, length };
    params.SetTextRange(textRange);
}
#pragma endregion