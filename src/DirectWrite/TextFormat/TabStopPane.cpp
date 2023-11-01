// File: TabStopPane.cpp - CTabStopPane class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "TabStopPane.h"
#include "Parameters.h" 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CTabStopPane;
using namespace Parameters;;

CTabStopPane::CTabStopPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId)
    : CSamplePane(nDlgId, sampleId, nNameResId, nTextResId)
{
}

#pragma region Overriden
void CTabStopPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_TAB_STOP_METHOD, m_comboTabStopMethod);
    DDX_Control(pDX, IDC_SLIDER_TAB_STOP_DISTANCE, m_sliderTabStopDistance);
}

void CTabStopPane::InitPane()
{
    FillTabStopMethodCombo();
    m_sliderTabStopDistance.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    ParametersChanged();
}

void CTabStopPane::SetSampleParameters()
{
    CAlignmentParameters alignmentParams;
    CDirectionParameters directionParams;
    CFontParameters fontParams;
    CLineSpacingParameters lineSpacingParams;
    CTrimmingParameters trimmingParams;
    CWordWrappingParameters wordWrappingParams;
    
    trimmingParams.SetTrimmingGranularity(DWRITE_TRIMMING_GRANULARITY_CHARACTER);
    wordWrappingParams.SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);

    UpdateView(UpdateHint::alignmentChanged, alignmentParams);
    UpdateView(UpdateHint::directionChanged, directionParams);
    UpdateView(UpdateHint::fontChanged, fontParams);
    UpdateView(UpdateHint::lineSpacingChanged, lineSpacingParams);
    UpdateView(UpdateHint::trimmingChanged, trimmingParams);
    UpdateView(UpdateHint::wordWrappingChanged, wordWrappingParams);

    m_comboTabStopMethod.SelectItem(TAB_STOP_METHOD_FIXED);
    m_sliderTabStopDistance.SetPos(m_nDefaultSliderPos + 16);
    ParametersChanged();
}

void CTabStopPane::ResetParameters()
{
    m_comboTabStopMethod.SelectItem(TAB_STOP_METHOD_DEFAULT);
    m_sliderTabStopDistance.SetPos(m_nDefaultSliderPos);
    ParametersChanged();
}

void CTabStopPane::ParametersChanged()
{
    CTabStopParameters params;
    params.SetRedrawFlag();
    params.SetTabStopMethod(m_comboTabStopMethod.GetSelectedItemData());
    params.SetTabStopDistance(m_sliderTabStopDistance.GetPos());
    UpdateView(UpdateHint::tabStopChanged, params);
}
#pragma endregion

#pragma region Implementation
void CTabStopPane::FillTabStopMethodCombo()
{
    m_comboTabStopMethod.ResetContent();
    m_comboTabStopMethod.AddItem(L"Default", TAB_STOP_METHOD_DEFAULT);
    m_comboTabStopMethod.AddItem(L"Fixed", TAB_STOP_METHOD_FIXED);
}
#pragma endregion