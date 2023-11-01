// File: TrimmingPane.cpp - CTrimmingPane class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "TrimmingPane.h"
#include "Parameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CTrimmingPane;
using namespace Parameters;

CTrimmingPane::CTrimmingPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId)
    : CSamplePane(nDlgId, sampleId, nNameResId, nTextResId)
{
}

#pragma region Overriden
void CTrimmingPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_TRIMMING_GRANULARITY, m_comboTrimmingGranularity);
    DDX_Control(pDX, IDC_COMBO_TRIMMING_DELIMITER, m_comboTrimmingDelimiter);
    DDX_Control(pDX, IDC_SPIN_TRIMMING_DELIMITER_COUNT, m_spinTrimmingDelimiterCount);
}

void CTrimmingPane::InitPane()
{
    FillTrimingGranularityCombo();
    FillTrimingDelimiterCombo();
    m_spinTrimmingDelimiterCount.SetRange(0, 9);
}

void CTrimmingPane::SetSampleParameters()
{
    CAlignmentParameters alignmentParams;
    CDirectionParameters directionParams;
    CFontParameters fontParams;
    CLineSpacingParameters lineSpacingParams;
    CTabStopParameters tabStopParameters;
    CWordWrappingParameters wordWrappingParams;

    wordWrappingParams.SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);

    UpdateView(UpdateHint::alignmentChanged, alignmentParams);
    UpdateView(UpdateHint::directionChanged, directionParams);
    UpdateView(UpdateHint::fontChanged, fontParams);
    UpdateView(UpdateHint::lineSpacingChanged, lineSpacingParams);
    UpdateView(UpdateHint::tabStopChanged, tabStopParameters);
    UpdateView(UpdateHint::wordWrappingChanged, wordWrappingParams);

    m_comboTrimmingGranularity.SelectItem(DWRITE_TRIMMING_GRANULARITY_WORD);
    m_comboTrimmingDelimiter.SelectItem('\\');
    m_spinTrimmingDelimiterCount.SetPos(1);
    ParametersChanged();
}

void CTrimmingPane::ResetParameters()
{
    m_comboTrimmingGranularity.SelectItem(DWRITE_TRIMMING_GRANULARITY_NONE);
    m_comboTrimmingDelimiter.SelectItem(0);
    m_spinTrimmingDelimiterCount.SetPos(0);
    ParametersChanged();
}

void CTrimmingPane::ParametersChanged()
{
    CTrimmingParameters params;
    params.SetRedrawFlag();
    params.SetTrimmingGranularity(m_comboTrimmingGranularity.GetSelectedItemData());
    params.SetDelimiter(m_comboTrimmingDelimiter.GetSelectedItemData());
    params.SetDelimiterCount(m_spinTrimmingDelimiterCount.GetPos());

    UpdateView(UpdateHint::trimmingChanged, params);
}
#pragma endregion

#pragma region Implementation
void CTrimmingPane::FillTrimingGranularityCombo()
{
    m_comboTrimmingGranularity.ResetContent();
    m_comboTrimmingGranularity.AddItem(L"None", DWRITE_TRIMMING_GRANULARITY_NONE);
    m_comboTrimmingGranularity.AddItem(L"Character", DWRITE_TRIMMING_GRANULARITY_CHARACTER);
    m_comboTrimmingGranularity.AddItem(L"Word", DWRITE_TRIMMING_GRANULARITY_WORD);
}

void CTrimmingPane::FillTrimingDelimiterCombo()
{
    m_comboTrimmingDelimiter.ResetContent();
    m_comboTrimmingDelimiter.AddItem(L"None", 0);
    m_comboTrimmingDelimiter.AddItem(L"\\", '\\');
    m_comboTrimmingDelimiter.AddItem(L"/", '/');
}
#pragma endregion
