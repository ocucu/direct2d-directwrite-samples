// File: RangeFormatPane.cpp - CRangeFormatPane class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/
//         e-mail: ovidiu.cucu.mvp@gmail.com

#include "pch.h"
#include "RangeFormatPane.h"
#include "Parameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CRangeFormatPane;
using namespace Parameters;

CRangeFormatPane::CRangeFormatPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId, BrushTypeId brushTypeId)
    : CTextLayoutPane(nDlgId, sampleId, nNameResId, nTextResId, brushTypeId)
{
}

#pragma region Overriden
void CRangeFormatPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_FONT_FAMILY, m_comboFontFamily);
    DDX_Control(pDX, IDC_SLIDER_FONT_SIZE, m_sliderFontSize);
    DDX_Control(pDX, IDC_COMBO_FONT_WEIGHT, m_comboFontWeight);
    DDX_Control(pDX, IDC_COMBO_FONT_STYLE, m_comboFontStyle);
    DDX_Control(pDX, IDC_COMBO_FONT_STRETCH, m_comboFontStretch);
    DDX_Control(pDX, IDC_CHECK_UNDERLINE, m_checkUnderline);
    DDX_Control(pDX, IDC_CHECK_STRIKETHROUGH, m_checkStrikethrough);
}

void CRangeFormatPane::InitPane()
{
    __super::InitPane();
    FillFontFamilyCombo();
    m_sliderFontSize.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    FillFontWeightCombo();
    FillFontStyleCombo();
    FillFontStretchCombo();
}

void CRangeFormatPane::SetSampleParameters()
{
    // set some values to get a nice sample picture
    m_sliderMaxWidth.SetPos(400);
    m_sliderMaxHeight.SetPos(100);
    m_sliderStartPosition.SetPos(4);
    m_sliderLength.SetPos(17);
    m_comboFontFamily.SelectItem(L"Calibri");
    m_sliderFontSize.SetPos(32);
    m_comboFontWeight.SelectItem(DWRITE_FONT_WEIGHT_BOLD);
    m_comboFontStyle.SelectItem(DWRITE_FONT_STYLE_ITALIC);
    m_comboFontStretch.SelectItem(DWRITE_FONT_STRETCH_NORMAL);
    m_checkUnderline.SetCheck(BST_UNCHECKED);
    m_checkStrikethrough.SetCheck(BST_UNCHECKED);
    
    ParametersChanged();
}

void CRangeFormatPane::ResetParameters()
{
    __super::ResetParameters();
    m_comboFontFamily.SelectItem(L"Arial");
    m_sliderFontSize.SetPos(m_nDefSliderPos);
    // set default values
    m_comboFontWeight.SelectItem(DWRITE_FONT_WEIGHT_NORMAL);
    m_comboFontStyle.SelectItem(DWRITE_FONT_STYLE_NORMAL);
    m_comboFontStretch.SelectItem(DWRITE_FONT_STRETCH_NORMAL);
    m_checkUnderline.SetCheck(BST_UNCHECKED);
    m_checkStrikethrough.SetCheck(BST_UNCHECKED);
    
    ParametersChanged();
}

void CRangeFormatPane::ParametersChanged()
{
    CRangeFormatParameters params;

    UpdateTextLayoutParameters(params);
    params.SetFontFamily(m_comboFontFamily.GetSelectedItemText());
    params.SetFontSize(m_sliderFontSize.GetPos());
    params.SetFontWeight(m_comboFontWeight.GetSelectedItemData());
    params.SetFontStyle(m_comboFontStyle.GetSelectedItemData());
    params.SetFontStretch(m_comboFontStretch.GetSelectedItemData());
    params.SetUnderline(m_checkUnderline.GetCheck() == BST_CHECKED);
    params.SetStrikethrough(m_checkStrikethrough.GetCheck() == BST_CHECKED);
    
    UpdateView(UpdateHint::rangeFormatChanged, params);
}
#pragma endregion

#pragma region Implementation
void CRangeFormatPane::FillFontFamilyCombo()
{
    m_comboFontFamily.ResetContent();
    m_comboFontFamily.AddItem(L"Arial");
    m_comboFontFamily.AddItem(L"Calibri");
    m_comboFontFamily.AddItem(L"Impact");
    m_comboFontFamily.AddItem(L"Bahnschrift");
    m_comboFontFamily.AddItem(L"Bodoni MT");
    m_comboFontFamily.AddItem(L"Segoe UI");
    m_comboFontFamily.AddItem(L"Consolas");
}

void CRangeFormatPane::FillFontWeightCombo()
{
    m_comboFontWeight.ResetContent();
    m_comboFontWeight.AddItem(L"Normal", DWRITE_FONT_WEIGHT_NORMAL);
    m_comboFontWeight.AddItem(L"Bold", DWRITE_FONT_WEIGHT_BOLD);
}

void CRangeFormatPane::FillFontStyleCombo()
{
    m_comboFontStyle.ResetContent();
    m_comboFontStyle.AddItem(L"Normal", DWRITE_FONT_STYLE_NORMAL);
    m_comboFontStyle.AddItem(L"Oblique", DWRITE_FONT_STYLE_OBLIQUE);
    m_comboFontStyle.AddItem(L"Italic", DWRITE_FONT_STYLE_ITALIC);
}

void CRangeFormatPane::FillFontStretchCombo()
{
    m_comboFontStretch.ResetContent();
    m_comboFontStretch.AddItem(L"Condensed", DWRITE_FONT_STRETCH_CONDENSED);
    m_comboFontStretch.AddItem(L"Normal", DWRITE_FONT_STRETCH_NORMAL);
    m_comboFontStretch.AddItem(L"Expanded", DWRITE_FONT_STRETCH_EXPANDED);
}
#pragma endregion
