#include "pch.h"
#include "SkewPane.h"
#include "SkewParmeters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CSkewPane;
using Parameters::CSkewParmeters;

CSkewPane::CSkewPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BrushTypeId brushTypeId)
    : CSamplePane(nDlgId, sampleId, nNameResId, brushTypeId)
{
}

#pragma region Overriden
void CSkewPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_ANGLE_X, m_sliderAngleX);
    DDX_Control(pDX, IDC_SLIDER_ANGLE_Y, m_sliderAngleY);
    DDX_Control(pDX, IDC_SLIDER_CENTER_X, m_sliderCenterX);
    DDX_Control(pDX, IDC_SLIDER_CENTER_Y, m_sliderCenterY);
}

void CSkewPane::InitPane()
{
    m_sliderAngleX.SetRange(m_nMinAnglePos, m_nMaxAnglePos);
    m_sliderAngleY.SetRange(m_nMinAnglePos, m_nMaxAnglePos);
    m_sliderCenterX.SetRange(m_nMinCenterPos, m_nMaxCenterPos);
    m_sliderCenterY.SetRange(m_nMinCenterPos, m_nMaxCenterPos);
}

void CSkewPane::SetSampleParameters()
{
    m_sliderAngleX.SetPos(m_nDefaultAnglePos - 15);
    m_sliderAngleY.SetPos(m_nDefaultAnglePos - 15);
    m_sliderCenterX.SetPos(m_nDefaultCenterPos);
    m_sliderCenterY.SetPos(m_nDefaultCenterPos);
    ParametersChanged();
}

void CSkewPane::ResetParameters()
{
    m_sliderAngleX.SetPos(m_nDefaultAnglePos);
    m_sliderAngleY.SetPos(m_nDefaultAnglePos);
    m_sliderCenterX.SetPos(m_nDefaultCenterPos);
    m_sliderCenterY.SetPos(m_nDefaultCenterPos);
    ParametersChanged();
}

void CSkewPane::ParametersChanged()
{
    CSkewParmeters params;
    params.SetAngleX(m_sliderAngleX.GetPos() - m_nDefaultAnglePos);
    params.SetAngleY(m_sliderAngleY.GetPos() - m_nDefaultAnglePos);
    params.SetCenter(m_sliderCenterX.GetPos(), m_sliderCenterY.GetPos());
    UpdateView(UpdateHint::skewChanged, params);
}
#pragma endregion

