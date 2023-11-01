// File: DirectionPane.cpp - CDirectionPane class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "DirectionPane.h"
#include "Parameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CDirectionPane;
using namespace Parameters;

CDirectionPane::CDirectionPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId)
    : CSamplePane(nDlgId, sampleId, nNameResId, nTextResId)
{
}

#pragma region Overriden
void CDirectionPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);

    DDX_Control(pDX, IDC_COMBO_FLOW_DIRECTION, m_comboFlowDirection);
    DDX_Control(pDX, IDC_COMBO_READING_DIRECTION, m_comboReadingDirection);
}

void CDirectionPane::InitPane()
{
    FillFlowDirectionCombo();
    FillReadingDirectionCombo();
}

void CDirectionPane::SetSampleParameters()
{
    CAlignmentParameters alignmentParams;
    CFontParameters fontParams;
    CLineSpacingParameters lineSpacingParams;
    CTabStopParameters tabStopParameters;
    CTrimmingParameters trimmingParams;
    CWordWrappingParameters wordWrappingParams;

    UpdateView(UpdateHint::alignmentChanged, alignmentParams);
    UpdateView(UpdateHint::fontChanged, fontParams);
    UpdateView(UpdateHint::lineSpacingChanged, lineSpacingParams);
    UpdateView(UpdateHint::tabStopChanged, tabStopParameters);
    UpdateView(UpdateHint::trimmingChanged, trimmingParams);
    UpdateView(UpdateHint::wordWrappingChanged, wordWrappingParams);

    m_comboFlowDirection.SelectItem(DWRITE_FLOW_DIRECTION_RIGHT_TO_LEFT);
    m_comboReadingDirection.SelectItem(DWRITE_READING_DIRECTION_TOP_TO_BOTTOM);
    ParametersChanged();
}

void CDirectionPane::ResetParameters()
{
    m_comboFlowDirection.SelectItem(DWRITE_FLOW_DIRECTION_TOP_TO_BOTTOM);
    m_comboReadingDirection.SelectItem(DWRITE_READING_DIRECTION_LEFT_TO_RIGHT);
    ParametersChanged();
}

void CDirectionPane::ParametersChanged()
{
    CDirectionParameters params;
    params.SetRedrawFlag();
    params.SetFlowDirection(m_comboFlowDirection.GetSelectedItemData());
    params.SetReadingDirection(m_comboReadingDirection.GetSelectedItemData());
    UpdateView(UpdateHint::directionChanged, params);
}
#pragma endregion

#pragma region Implementation
void CDirectionPane::FillFlowDirectionCombo()
{
    m_comboFlowDirection.ResetContent();
    m_comboFlowDirection.AddItem(L"Top to bottom", DWRITE_FLOW_DIRECTION_TOP_TO_BOTTOM);
    m_comboFlowDirection.AddItem(L"Bottom to top", DWRITE_FLOW_DIRECTION_BOTTOM_TO_TOP);
    m_comboFlowDirection.AddItem(L"Left to right", DWRITE_FLOW_DIRECTION_LEFT_TO_RIGHT);
    m_comboFlowDirection.AddItem(L"Right to left", DWRITE_FLOW_DIRECTION_RIGHT_TO_LEFT);
}

void CDirectionPane::FillReadingDirectionCombo()
{
    m_comboReadingDirection.ResetContent();
    m_comboReadingDirection.AddItem(L"Left to right", DWRITE_READING_DIRECTION_LEFT_TO_RIGHT);
    m_comboReadingDirection.AddItem(L"Right to left", DWRITE_READING_DIRECTION_RIGHT_TO_LEFT);
    m_comboReadingDirection.AddItem(L"Top to bottom", DWRITE_READING_DIRECTION_TOP_TO_BOTTOM);
    m_comboReadingDirection.AddItem(L"Bottom to top", DWRITE_READING_DIRECTION_BOTTOM_TO_TOP);
}
#pragma endregion
