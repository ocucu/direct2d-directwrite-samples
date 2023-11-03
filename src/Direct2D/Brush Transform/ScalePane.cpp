#include "pch.h"
#include "ScalePane.h"
#include "ScaleParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CScalePane;
using Parameters::CScaleParameters;

CScalePane::CScalePane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BrushTypeId brushTypeId)
    : CSamplePane(nDlgId, sampleId, nNameResId, brushTypeId)
{
}

#pragma region Overriden
void CScalePane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_SIZE_X, m_sliderSizeX);
    DDX_Control(pDX, IDC_SLIDER_SIZE_Y, m_sliderSizeY);
    DDX_Control(pDX, IDC_SLIDER_CENTER_X, m_sliderCenterX);
    DDX_Control(pDX, IDC_SLIDER_CENTER_Y, m_sliderCenterY);
}

void CScalePane::InitPane()
{
    m_sliderSizeX.SetRange(m_nMinScaleSizePos, m_nMaxScaleSizePos);
    m_sliderSizeY.SetRange(m_nMinScaleSizePos, m_nMaxScaleSizePos);
    m_sliderCenterX.SetRange(m_nMinScaleCenterPos, m_nMaxScaleCenterPos);
    m_sliderCenterY.SetRange(m_nMinScaleCenterPos, m_nMaxScaleCenterPos);
}

void CScalePane::SetSampleParameters()
{
    m_sliderSizeX.SetPos(m_nDefaultScaleSizePos - 30);
    m_sliderSizeY.SetPos(m_nDefaultScaleSizePos - 30);
    m_sliderCenterX.SetPos(m_nDefaultScaleCenterPos);
    m_sliderCenterY.SetPos(m_nDefaultScaleCenterPos);
    ParametersChanged();
}

void CScalePane::ResetParameters()
{
    m_sliderSizeX.SetPos(m_nDefaultScaleSizePos);
    m_sliderSizeY.SetPos(m_nDefaultScaleSizePos);
    m_sliderCenterX.SetPos(m_nDefaultScaleCenterPos);
    m_sliderCenterY.SetPos(m_nDefaultScaleCenterPos);
    ParametersChanged();
}

void CScalePane::ParametersChanged()
{
    CScaleParameters params;
    FLOAT scaleX = m_sliderSizeX.GetPos() / 100.f;
    FLOAT scaleY = m_sliderSizeY.GetPos() / 100.f;
    params.SetSize(scaleX, scaleY);
    params.SetCenter(m_sliderCenterX.GetPos(), m_sliderCenterY.GetPos());
    UpdateView(UpdateHint::scaleChanged, params);
}
#pragma endregion

