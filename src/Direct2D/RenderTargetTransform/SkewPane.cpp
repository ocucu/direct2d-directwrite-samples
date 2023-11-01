#include "pch.h"
#include "SkewPane.h"
#include "SkewParmeters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CSkewPane;
using Parameters::CSkewParmeters;

CSkewPane::CSkewPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId)
    : CSamplePane(nDlgId, sampleId, nNameResId, figureId)
{
}

#pragma region Overriden
void CSkewPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_SKEW_ANGLE_X, m_sliderSkewAngleX);
    DDX_Control(pDX, IDC_SLIDER_SKEW_ANGLE_Y, m_sliderSkewAngleY);
    DDX_Control(pDX, IDC_SLIDER_SKEW_CENTER_X, m_sliderSkewCenterX);
    DDX_Control(pDX, IDC_SLIDER_SKEW_CENTER_Y, m_sliderSkewCenterY);
}

void CSkewPane::InitPane()
{
    m_sliderSkewAngleX.SetRange(m_nMinAngleSkewPos, m_nMaxAngleSkewPos);
    m_sliderSkewAngleY.SetRange(m_nMinAngleSkewPos, m_nMaxAngleSkewPos);
    m_sliderSkewCenterX.SetRange(m_nMinCenterSkewPosX, m_nMaxCenterSkewPosX);
    m_sliderSkewCenterY.SetRange(m_nMinCenterSkewPosY, m_nMaxCenterSkewPosY);
}

void CSkewPane::SetSampleParameters()
{
    m_sliderSkewAngleX.SetPos(m_nDefaultAngleSkewPos - 15);
    m_sliderSkewAngleY.SetPos(m_nDefaultAngleSkewPos - 15);
    m_sliderSkewCenterX.SetPos(m_nDefaultCenterSkewPosX);
    m_sliderSkewCenterY.SetPos(m_nDefaultCenterSkewPosY);
    ParametersChanged();
}

void CSkewPane::ResetParameters()
{
    m_sliderSkewAngleX.SetPos(m_nDefaultAngleSkewPos);
    m_sliderSkewAngleY.SetPos(m_nDefaultAngleSkewPos);
    m_sliderSkewCenterX.SetPos(m_nDefaultCenterSkewPosX);
    m_sliderSkewCenterY.SetPos(m_nDefaultCenterSkewPosY);
    ParametersChanged();
}

void CSkewPane::ParametersChanged()
{
    CSkewParmeters params;
    params.SetRedrawFlag();
    params.SetAngleX(m_sliderSkewAngleX.GetPos() - m_nDefaultAngleSkewPos);
    params.SetAngleY(m_sliderSkewAngleY.GetPos() - m_nDefaultAngleSkewPos);
    int nCenterX = m_sliderSkewCenterX.GetPos();
    int nCenterY = m_sliderSkewCenterY.GetPos();
    params.SetCenter(nCenterX, nCenterY);
    UpdateView(UpdateHint::skewChanged, params);
}
#pragma endregion

