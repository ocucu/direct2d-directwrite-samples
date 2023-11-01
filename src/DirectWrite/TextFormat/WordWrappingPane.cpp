// File: WordWrappingPane.cpp - CWordWrappingPane class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "WordWrappingPane.h"
#include "Parameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CWordWrappingPane;
using namespace Parameters;

CWordWrappingPane::CWordWrappingPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId)
    : CSamplePane(nDlgId, sampleId, nNameResId, nTextResId)
{
}

#pragma region Overriden
void CWordWrappingPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_WORD_WRAPPING, m_comboWordWrapping);
}

void CWordWrappingPane::InitPane()
{
    FillWordWrappingCombo();
}

void CWordWrappingPane::SetSampleParameters()
{
    CAlignmentParameters alignmentParams;
    CDirectionParameters directionParams;
    CFontParameters fontParams;
    CLineSpacingParameters lineSpacingParams;
    CTabStopParameters tabStopParameters;
    CTrimmingParameters trimmingParams;

    fontParams.SetFontSize(32);

    UpdateView(UpdateHint::alignmentChanged, alignmentParams);
    UpdateView(UpdateHint::directionChanged, directionParams);
    UpdateView(UpdateHint::fontChanged, fontParams);
    UpdateView(UpdateHint::lineSpacingChanged, lineSpacingParams);
    UpdateView(UpdateHint::tabStopChanged, tabStopParameters);
    UpdateView(UpdateHint::trimmingChanged, trimmingParams);

    m_comboWordWrapping.SelectItem(DWRITE_WORD_WRAPPING_WHOLE_WORD);
    ParametersChanged();
}

void CWordWrappingPane::ParametersChanged()
{
    CWordWrappingParameters params;
    params.SetRedrawFlag();
    params.SetWordWrapping(m_comboWordWrapping.GetSelectedItemData());
    UpdateView(UpdateHint::wordWrappingChanged, params);
}

void CWordWrappingPane::ResetParameters()
{
    m_comboWordWrapping.SelectItem(DWRITE_WORD_WRAPPING_WRAP);
    ParametersChanged();
}
#pragma endregion

#pragma region Implementation
void CWordWrappingPane::FillWordWrappingCombo()
{
    m_comboWordWrapping.ResetContent();
    m_comboWordWrapping.AddItem(L"Wrap", DWRITE_WORD_WRAPPING_WRAP);
    m_comboWordWrapping.AddItem(L"No wrap", DWRITE_WORD_WRAPPING_NO_WRAP);
    m_comboWordWrapping.AddItem(L"Emergency break", DWRITE_WORD_WRAPPING_EMERGENCY_BREAK);
    m_comboWordWrapping.AddItem(L"Whole word", DWRITE_WORD_WRAPPING_WHOLE_WORD);
    m_comboWordWrapping.AddItem(L"Character", DWRITE_WORD_WRAPPING_CHARACTER);
}
#pragma endregion