// File: FontPane.cpp - CFontPane class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "FontPane.h"
#include "Parameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CFontPane;
using namespace Parameters;

CFontPane::CFontPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId)
    : CSamplePane(nDlgId, sampleId, nNameResId, nTextResId)
{
}

#pragma region Overriden
void CFontPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    
    DDX_Control(pDX, IDC_COMBO_FONT_FAMILY, m_comboFontFamily);
    DDX_Control(pDX, IDC_SLIDER_FONT_SIZE, m_sliderFontSize);
    DDX_Control(pDX, IDC_COMBO_FONT_WEIGHT, m_comboFontWeight);
    DDX_Control(pDX, IDC_COMBO_FONT_STYLE, m_comboFontStyle);
    DDX_Control(pDX, IDC_COMBO_FONT_STRETCH, m_comboFontStretch);
}

void CFontPane::InitPane()
{
    FillFontFamilyCombo();
    m_sliderFontSize.SetRange(10, 192);
    FillFontWeightCombo();
    FillFontStyleCombo();
    FillFontStretchCombo();
}

void CFontPane::SetSampleParameters()
{
    CAlignmentParameters alignmentParams;
    CDirectionParameters directionParams;
    CLineSpacingParameters lineSpacingParams;
    CTabStopParameters tabStopParameters;
    CTrimmingParameters trimmingParams;
    CWordWrappingParameters wordWrappingParams;

    UpdateView(UpdateHint::alignmentChanged, alignmentParams);
    UpdateView(UpdateHint::directionChanged, directionParams);
    UpdateView(UpdateHint::lineSpacingChanged, lineSpacingParams);
    UpdateView(UpdateHint::tabStopChanged, tabStopParameters);
    UpdateView(UpdateHint::trimmingChanged, trimmingParams);
    UpdateView(UpdateHint::wordWrappingChanged, wordWrappingParams);

    m_comboFontFamily.SelectItem(L"Bodoni MT");
    m_sliderFontSize.SetPos(32);
    m_comboFontWeight.SelectItem(DWRITE_FONT_WEIGHT_BOLD);
    m_comboFontStyle.SelectItem(DWRITE_FONT_STYLE_ITALIC);
    m_comboFontStretch.SelectItem(DWRITE_FONT_STRETCH_NORMAL);
    ParametersChanged();
}

void CFontPane::ResetParameters()
{
    m_comboFontFamily.SelectItem(L"Arial");
    m_sliderFontSize.SetPos(24);
    m_comboFontWeight.SelectItem(DWRITE_FONT_WEIGHT_NORMAL);
    m_comboFontStyle.SelectItem(DWRITE_FONT_STYLE_NORMAL);
    m_comboFontStretch.SelectItem(DWRITE_FONT_STRETCH_NORMAL);
    ParametersChanged();
}

void CFontPane::ParametersChanged()
{
    CFontParameters params;
    params.SetRedrawFlag();
    params.SetFontFamily(m_comboFontFamily.GetSelectedItemText());
    params.SetFontSize(m_sliderFontSize.GetPos());
    params.SetFontWeight(m_comboFontWeight.GetSelectedItemData());
    params.SetFontStyle(m_comboFontStyle.GetSelectedItemData());
    params.SetFontStretch(m_comboFontStretch.GetSelectedItemData());
    UpdateView(UpdateHint::fontChanged, params);
}
#pragma endregion

#pragma region Implementation
void CFontPane::FillFontFamilyCombo()
{
    m_comboFontFamily.ResetContent();
    m_comboFontFamily.AddItem(L"Arial");
    m_comboFontFamily.AddItem(L"Bahnschrift");
    m_comboFontFamily.AddItem(L"Bodoni MT");
    m_comboFontFamily.AddItem(L"Segoe UI");
    m_comboFontFamily.AddItem(L"Consolas");
}

void CFontPane::FillFontWeightCombo()
{
    m_comboFontWeight.ResetContent();
    m_comboFontWeight.AddItem(L"Thin", DWRITE_FONT_WEIGHT_THIN);
    m_comboFontWeight.AddItem(L"Extra-light", DWRITE_FONT_WEIGHT_EXTRA_LIGHT);
    m_comboFontWeight.AddItem(L"Ultra-light", DWRITE_FONT_WEIGHT_ULTRA_LIGHT);
    m_comboFontWeight.AddItem(L"Light", DWRITE_FONT_WEIGHT_LIGHT);
    m_comboFontWeight.AddItem(L"Semi-light", DWRITE_FONT_WEIGHT_SEMI_LIGHT);
    m_comboFontWeight.AddItem(L"Normal", DWRITE_FONT_WEIGHT_NORMAL);
    m_comboFontWeight.AddItem(L"Regular", DWRITE_FONT_WEIGHT_REGULAR);
    m_comboFontWeight.AddItem(L"Medium", DWRITE_FONT_WEIGHT_MEDIUM);
    m_comboFontWeight.AddItem(L"Demi-bold", DWRITE_FONT_WEIGHT_DEMI_BOLD);
    m_comboFontWeight.AddItem(L"Semi-bold", DWRITE_FONT_WEIGHT_SEMI_BOLD);
    m_comboFontWeight.AddItem(L"Bold", DWRITE_FONT_WEIGHT_BOLD);
    m_comboFontWeight.AddItem(L"Extra-bold", DWRITE_FONT_WEIGHT_EXTRA_BOLD);
    m_comboFontWeight.AddItem(L"Ultra-bold", DWRITE_FONT_WEIGHT_ULTRA_BOLD);
    m_comboFontWeight.AddItem(L"Black", DWRITE_FONT_WEIGHT_BLACK);
    m_comboFontWeight.AddItem(L"Heavy", DWRITE_FONT_WEIGHT_HEAVY);
    m_comboFontWeight.AddItem(L"Extra-lack", DWRITE_FONT_WEIGHT_EXTRA_BLACK);
    m_comboFontWeight.AddItem(L"Ultra-black", DWRITE_FONT_WEIGHT_ULTRA_BLACK);
}

void CFontPane::FillFontStyleCombo()
{
    m_comboFontStyle.ResetContent();
    m_comboFontStyle.AddItem(L"Normal", DWRITE_FONT_STYLE_NORMAL);
    m_comboFontStyle.AddItem(L"Oblique", DWRITE_FONT_STYLE_OBLIQUE);
    m_comboFontStyle.AddItem(L"Italic", DWRITE_FONT_STYLE_ITALIC);
}

void CFontPane::FillFontStretchCombo()
{
    m_comboFontStretch.ResetContent();
    m_comboFontStretch.AddItem(L"Ultra-condensed", DWRITE_FONT_STRETCH_ULTRA_CONDENSED);
    m_comboFontStretch.AddItem(L"Extra-condensed", DWRITE_FONT_STRETCH_EXTRA_CONDENSED);
    m_comboFontStretch.AddItem(L"Condensed", DWRITE_FONT_STRETCH_CONDENSED);
    m_comboFontStretch.AddItem(L"Semi-condensed", DWRITE_FONT_STRETCH_SEMI_CONDENSED);
    m_comboFontStretch.AddItem(L"Normal", DWRITE_FONT_STRETCH_NORMAL);
    m_comboFontStretch.AddItem(L"Medium", DWRITE_FONT_STRETCH_MEDIUM);
    m_comboFontStretch.AddItem(L"Semi-expanded", DWRITE_FONT_STRETCH_SEMI_EXPANDED);
    m_comboFontStretch.AddItem(L"Expanded", DWRITE_FONT_STRETCH_EXPANDED);
    m_comboFontStretch.AddItem(L"Extra-expanded", DWRITE_FONT_STRETCH_EXTRA_EXPANDED);
    m_comboFontStretch.AddItem(L"Ultra-expanded", DWRITE_FONT_STRETCH_ULTRA_EXPANDED);
}
#pragma endregion
