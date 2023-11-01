
#include "pch.h"
#include "RotationPane.h"
#include "RotationParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CRotationPane;
using Parameters::CRotationParameters;

CRotationPane::CRotationPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId)
    : CSamplePane(nDlgId, sampleId, nNameResId, figureId)
{
}

#pragma region Overriden
void CRotationPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_ROTATION_ANGLE, m_sliderRotationAngle);
    DDX_Control(pDX, IDC_SLIDER_ROTATION_CENTER_X, m_sliderRotationCenterX);
    DDX_Control(pDX, IDC_SLIDER_ROTATION_CENTER_Y, m_sliderRotationCenterY);
}

void CRotationPane::InitPane()
{
    m_sliderRotationAngle.SetRange(m_nMinAngleSliderPos, m_nMaxAngleSliderPos);
    m_sliderRotationCenterX.SetRange(m_nMinCenterSliderPos, m_nMaxCenterSliderPos);
    m_sliderRotationCenterY.SetRange(m_nMinCenterSliderPos, m_nMaxCenterSliderPos);
}

void CRotationPane::SetSampleParameters()
{
    m_sliderRotationAngle.SetPos(m_nDefaultAngleSliderPos - 45);
    m_sliderRotationCenterX.SetPos(m_nDefaultCenterSliderPos);
    m_sliderRotationCenterY.SetPos(m_nDefaultCenterSliderPos);
    ParametersChanged();
}

void CRotationPane::ResetParameters()
{
    m_sliderRotationAngle.SetPos(m_nDefaultAngleSliderPos);
    m_sliderRotationCenterX.SetPos(m_nDefaultCenterSliderPos);
    m_sliderRotationCenterY.SetPos(m_nDefaultCenterSliderPos);
    ParametersChanged();
}

void CRotationPane::ParametersChanged()
{
    CRotationParameters params;
    params.SetRedrawFlag();
    int nAngle = m_sliderRotationAngle.GetPos() - m_nDefaultAngleSliderPos;
    params.SetAngle(nAngle);
    int nCenterX = m_sliderRotationCenterX.GetPos();
    int nCenterY = m_sliderRotationCenterY.GetPos();
    params.SetCenter(nCenterX, nCenterY);
    UpdateView(UpdateHint::rotationChanged, params);
}
#pragma endregion
