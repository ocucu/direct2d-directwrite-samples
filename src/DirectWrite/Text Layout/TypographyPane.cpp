// File: InlineImagesPane.cpp - CInlineImagesPane class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/
//         e-mail: ovidiu.cucu.mvp@gmail.com

#include "pch.h"
#include "TypographyPane.h"
#include "TypographyParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CTypographyPane;
using Parameters::CTypographyParameters;

CTypographyPane::CTypographyPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId)
    : CSamplePane(nDlgId, sampleId, nNameResId, nTextResId)
{
}

#pragma region Overriden
void CTypographyPane::InitPane()
{
    // just override
}

void CTypographyPane::SetSampleParameters()
{
    ParametersChanged();
}

void CTypographyPane::ResetParameters()
{
    ParametersChanged();
}

void CTypographyPane::ParametersChanged()
{
    CTypographyParameters params;
    UpdateView(UpdateHint::typographyChanged, params);
}
#pragma endregion