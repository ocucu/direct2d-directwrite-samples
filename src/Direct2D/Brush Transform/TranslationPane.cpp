// File: TranslationPane.cpp - CTranslationPane class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "TranslationPane.h"
#include "TranslationParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CTranslationPane;
using Parameters::CTranslationParameters;

CTranslationPane::CTranslationPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BrushTypeId brushTypeId)
    : CSamplePane(nDlgId, sampleId, nNameResId, brushTypeId)
{
}

#pragma region Overriden
void CTranslationPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_SIZE_X, m_sliderSizeX);
    DDX_Control(pDX, IDC_SLIDER_SIZE_Y, m_sliderSizeY);
}

void CTranslationPane::InitPane()
{
    m_sliderSizeX.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    m_sliderSizeY.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
}

void CTranslationPane::SetSampleParameters()
{
    m_sliderSizeX.SetPos(m_nDefaultSliderPos + 64);
    m_sliderSizeY.SetPos(m_nDefaultSliderPos + 64);
    ParametersChanged();
}

void CTranslationPane::ResetParameters()
{
    m_sliderSizeX.SetPos(m_nDefaultSliderPos);
    m_sliderSizeY.SetPos(m_nDefaultSliderPos);
    ParametersChanged();
}

void CTranslationPane::ParametersChanged()
{
    CTranslationParameters params;
    params.SetSize(m_sliderSizeX.GetPos(), m_sliderSizeY.GetPos());
    UpdateView(UpdateHint::translationChanged, params);
}
#pragma endregion


