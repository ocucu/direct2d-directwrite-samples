// File: LineSpacingPane.cpp - CLineSpacingPane class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "LineSpacingPane.h"
#include "Parameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CLineSpacingPane;
using namespace Parameters;

CLineSpacingPane::CLineSpacingPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId)
    : CSamplePane(nDlgId, sampleId, nNameResId, nTextResId)
{
}

#pragma region Overriden
void CLineSpacingPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_LINE_SPACING_METHOD, m_comboLineSpacingMethod);
    DDX_Control(pDX, IDC_SLIDER_LINE_SPACING_FACTOR, m_sliderLineSpacingFactor);
}

void CLineSpacingPane::InitPane()
{
    FillLineSpacingMethodCombo();
    m_sliderLineSpacingFactor.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
}

void CLineSpacingPane::SetSampleParameters()
{
    CAlignmentParameters alignmentParams;
    CDirectionParameters directionParams;
    CFontParameters fontParams;
    CTabStopParameters tabStopParameters;
    CTrimmingParameters trimmingParams;
    CWordWrappingParameters wordWrappingParams;

    UpdateView(UpdateHint::alignmentChanged, alignmentParams);
    UpdateView(UpdateHint::directionChanged, directionParams);
    UpdateView(UpdateHint::fontChanged, fontParams);
    UpdateView(UpdateHint::tabStopChanged, tabStopParameters);
    UpdateView(UpdateHint::trimmingChanged, trimmingParams);
    UpdateView(UpdateHint::wordWrappingChanged, wordWrappingParams);

    m_comboLineSpacingMethod.SelectItem(DWRITE_LINE_SPACING_METHOD_UNIFORM);
    m_sliderLineSpacingFactor.SetPos(m_nDefaultSliderPos + 30);
    ParametersChanged();
}

void CLineSpacingPane::ResetParameters()
{
    m_comboLineSpacingMethod.SelectItem(DWRITE_LINE_SPACING_METHOD_DEFAULT);
    m_sliderLineSpacingFactor.SetPos(m_nDefaultSliderPos);
    ParametersChanged();
}

void CLineSpacingPane::ParametersChanged()
{
    CLineSpacingParameters params;
    params.SetRedrawFlag();
    params.SetMethod(m_comboLineSpacingMethod.GetSelectedItemData());
    params.SetFactor(m_sliderLineSpacingFactor.GetPos() / 100.f);
    UpdateView(UpdateHint::lineSpacingChanged, params);
}
#pragma endregion

#pragma region Implementation
void CLineSpacingPane::FillLineSpacingMethodCombo()
{
    m_comboLineSpacingMethod.ResetContent();
    m_comboLineSpacingMethod.AddItem(L"Default", DWRITE_LINE_SPACING_METHOD_DEFAULT);
    m_comboLineSpacingMethod.AddItem(L"Uniform", DWRITE_LINE_SPACING_METHOD_UNIFORM);
    // Note: DWRITE_LINE_SPACING_METHOD enumeration may have an additional value, DWRITE_LINE_SPACING_METHOD_PROPORTIONAL.
    //       As long as it is not a valid value for IDWriteTextFormat interface, it is not used in this demo. 
}
#pragma endregion



