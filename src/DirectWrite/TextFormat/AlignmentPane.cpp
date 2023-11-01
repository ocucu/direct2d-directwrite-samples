// File: AlignmentPane.cpp - CAlignmentPane class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "AlignmentPane.h"
#include "Parameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CAlignmentPane;
using namespace Parameters;

CAlignmentPane::CAlignmentPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId)
    : CSamplePane(nDlgId, sampleId, nNameResId, nTextResId)
{
}

#pragma region Overriden
void CAlignmentPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_TEXT_ALIGNMENT, m_comboTextAlignment);
    DDX_Control(pDX, IDC_COMBO_PARAGRAPH_ALIGNMENT, m_comboParagraphAlignment);
}

void CAlignmentPane::InitPane()
{
    FillTextAlignmentCombo();
    FillParagraphAlignmentCombo();
}

void CAlignmentPane::SetSampleParameters()
{
    CDirectionParameters directionParams;
    CFontParameters fontParams;
    CLineSpacingParameters lineSpacingParams;
    CTabStopParameters tabStopParameters;
    CTrimmingParameters trimmingParams;
    CWordWrappingParameters wordWrappingParams;

    UpdateView(UpdateHint::directionChanged, directionParams);
    UpdateView(UpdateHint::fontChanged, fontParams);
    UpdateView(UpdateHint::lineSpacingChanged, lineSpacingParams);
    UpdateView(UpdateHint::tabStopChanged, tabStopParameters);
    UpdateView(UpdateHint::trimmingChanged, trimmingParams);
    UpdateView(UpdateHint::wordWrappingChanged, wordWrappingParams);
    
    m_comboTextAlignment.SelectItem(DWRITE_TEXT_ALIGNMENT_JUSTIFIED);
    m_comboParagraphAlignment.SelectItem(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
    ParametersChanged();
}

void CAlignmentPane::ResetParameters()
{
    m_comboTextAlignment.SelectItem(DWRITE_TEXT_ALIGNMENT_LEADING);
    m_comboParagraphAlignment.SelectItem(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
    ParametersChanged();
}

void CAlignmentPane::ParametersChanged()
{
    CAlignmentParameters params;
    params.SetRedrawFlag();
    params.SetTextAlignment(m_comboTextAlignment.GetSelectedItemData());
    params.SetParagraphAlignment(m_comboParagraphAlignment.GetSelectedItemData());
    UpdateView(UpdateHint::alignmentChanged, params);
}
#pragma endregion

#pragma region Implementation
void CAlignmentPane::FillTextAlignmentCombo()
{
    m_comboTextAlignment.ResetContent();
    m_comboTextAlignment.AddItem(L"Leading", DWRITE_TEXT_ALIGNMENT_LEADING);
    m_comboTextAlignment.AddItem(L"Trailing", DWRITE_TEXT_ALIGNMENT_TRAILING);
    m_comboTextAlignment.AddItem(L"Center", DWRITE_TEXT_ALIGNMENT_CENTER);
    m_comboTextAlignment.AddItem(L"Justified", DWRITE_TEXT_ALIGNMENT_JUSTIFIED);
}

void CAlignmentPane::FillParagraphAlignmentCombo()
{
    m_comboParagraphAlignment.ResetContent();
    m_comboParagraphAlignment.AddItem(L"Near", DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
    m_comboParagraphAlignment.AddItem(L"Far", DWRITE_PARAGRAPH_ALIGNMENT_FAR);
    m_comboParagraphAlignment.AddItem(L"Center", DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
}
#pragma endregion
