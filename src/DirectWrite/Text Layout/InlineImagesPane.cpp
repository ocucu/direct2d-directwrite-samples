// File: InlineImagesPane.cpp - CInlineImagesPane class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/
//         e-mail: ovidiu.cucu.mvp@gmail.com

#include "pch.h"
#include "InlineImagesPane.h"
#include "InlineImagesParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CInlineImagesPane;
using Parameters::CInlineImagesParameters;

CInlineImagesPane::CInlineImagesPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, UINT nTextResId)
    : CSamplePane(nDlgId, sampleId, nNameResId, nTextResId)
{
}

#pragma region Overriden
void CInlineImagesPane::InitPane()
{
    // just override
}

void CInlineImagesPane::SetSampleParameters()
{
    ParametersChanged();
}

void CInlineImagesPane::ResetParameters()
{
    ParametersChanged();
}

void CInlineImagesPane::ParametersChanged()
{
    CInlineImagesParameters params;
    UpdateView(UpdateHint::inlineImagesChanged, params);
}
#pragma endregion