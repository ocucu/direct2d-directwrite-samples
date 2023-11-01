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

CTranslationPane::CTranslationPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId)
    : CSamplePane(nDlgId, sampleId, nNameResId, figureId)
{
}

#pragma region Overriden
void CTranslationPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_TRANSLATION_X, m_sliderTranslationX);
    DDX_Control(pDX, IDC_SLIDER_TRANSLATION_Y, m_sliderTranslationY);
}

void CTranslationPane::InitPane()
{
    m_sliderTranslationX.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    m_sliderTranslationY.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
}

void CTranslationPane::SetSampleParameters()
{
    m_sliderTranslationX.SetPos(m_nDefaultSliderPos + 120);
    m_sliderTranslationY.SetPos(m_nDefaultSliderPos + 90);
    ParametersChanged();
}

void CTranslationPane::ResetParameters()
{
    m_sliderTranslationX.SetPos(m_nDefaultSliderPos);
    m_sliderTranslationY.SetPos(m_nDefaultSliderPos);
    ParametersChanged();
}

void CTranslationPane::ParametersChanged()
{
    CTranslationParameters params;
    params.SetRedrawFlag();
    int width = m_sliderTranslationX.GetPos() - m_nDefaultSliderPos;
    int height = m_sliderTranslationY.GetPos() - m_nDefaultSliderPos;
    params.SetSize(width, height);
    UpdateView(UpdateHint::translationChanged, params);
}
#pragma endregion


