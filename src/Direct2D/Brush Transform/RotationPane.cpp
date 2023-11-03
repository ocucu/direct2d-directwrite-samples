
#include "pch.h"
#include "RotationPane.h"
#include "RotationParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CRotationPane;
using Parameters::CRotationParameters;

CRotationPane::CRotationPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BrushTypeId brushTypeId)
    : CSamplePane(nDlgId, sampleId, nNameResId, brushTypeId)
{
}

#pragma region Overriden
void CRotationPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_ANGLE, m_sliderAngle);
    DDX_Control(pDX, IDC_SLIDER_CENTER_X, m_sliderCenterX);
    DDX_Control(pDX, IDC_SLIDER_CENTER_Y, m_sliderCenterY);
}

void CRotationPane::InitPane()
{
    m_sliderAngle.SetRange(m_nMinAngleSliderPos, m_nMaxAngleSliderPos);
    m_sliderCenterX.SetRange(m_nMinCenterSliderPos, m_nMaxCenterSliderPos);
    m_sliderCenterY.SetRange(m_nMinCenterSliderPos, m_nMaxCenterSliderPos);
}

void CRotationPane::SetSampleParameters()
{
    m_sliderAngle.SetPos(m_nDefaultAngleSliderPos - 45);
    m_sliderCenterX.SetPos(m_nDefaultCenterSliderPos);
    m_sliderCenterY.SetPos(m_nDefaultCenterSliderPos);
    ParametersChanged();
}

void CRotationPane::ResetParameters()
{
    m_sliderAngle.SetPos(m_nDefaultAngleSliderPos);
    m_sliderCenterX.SetPos(m_nDefaultCenterSliderPos);
    m_sliderCenterY.SetPos(m_nDefaultCenterSliderPos);
    ParametersChanged();
}

void CRotationPane::ParametersChanged()
{
    CRotationParameters params;
    params.SetAngle(m_sliderAngle.GetPos() - m_nDefaultAngleSliderPos);
    params.SetCenter(m_sliderCenterX.GetPos(), m_sliderCenterY.GetPos());
    UpdateView(UpdateHint::rotationChanged, params);
}
#pragma endregion
