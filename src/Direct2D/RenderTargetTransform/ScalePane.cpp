#include "pch.h"
#include "ScalePane.h"
#include "ScaleParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CScalePane;
using Parameters::CScaleParameters;

CScalePane::CScalePane(UINT nDlgId, SampleId sampleId, UINT nNameResId, FigureId figureId)
    : CSamplePane(nDlgId, sampleId, nNameResId, figureId)
{
}

#pragma region Overriden
void CScalePane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_SCALE_SIZE_X, m_sliderScaleSizeX);
    DDX_Control(pDX, IDC_SLIDER_SCALE_SIZE_Y, m_sliderScaleSizeY);
    DDX_Control(pDX, IDC_SLIDER_SCALE_CENTER_X, m_sliderScaleCenterX);
    DDX_Control(pDX, IDC_SLIDER_SCALE_CENTER_Y, m_sliderScaleCenterY);
}

void CScalePane::InitPane()
{
    m_sliderScaleSizeX.SetRange(m_nMinScaleSizePos, m_nMaxScaleSizePos);
    m_sliderScaleSizeY.SetRange(m_nMinScaleSizePos, m_nMaxScaleSizePos);
    m_sliderScaleCenterX.SetRange(m_nMinScaleCenterXPos, m_nMaxScaleCenterXPos);
    m_sliderScaleCenterY.SetRange(m_nMinScaleCenterYPos, m_nMaxScaleCenterYPos);
}

void CScalePane::SetSampleParameters()
{
    m_sliderScaleSizeX.SetPos(m_nDefaultScaleSizePos + 15);
    m_sliderScaleSizeY.SetPos(m_nDefaultScaleSizePos + 50);
    m_sliderScaleCenterX.SetPos(m_nDefaultScaleCenterXPos);
    m_sliderScaleCenterY.SetPos(m_nDefaultScaleCenterYPos);
    ParametersChanged();
}

void CScalePane::ResetParameters()
{
    m_sliderScaleSizeX.SetPos(m_nDefaultScaleSizePos);
    m_sliderScaleSizeY.SetPos(m_nDefaultScaleSizePos);
    m_sliderScaleCenterX.SetPos(m_nDefaultScaleCenterYPos);
    m_sliderScaleCenterY.SetPos(m_nDefaultScaleCenterYPos);
    ParametersChanged();
}

void CScalePane::ParametersChanged()
{
    CScaleParameters params;
    params.SetRedrawFlag();
    FLOAT scaleX = m_sliderScaleSizeX.GetPos() / 100.f;
    FLOAT scaleY = m_sliderScaleSizeY.GetPos() / 100.f;
    params.SetSize(scaleX, scaleY);
    int nCenterX = m_sliderScaleCenterX.GetPos();
    int nCenterY = m_sliderScaleCenterY.GetPos();
    params.SetCenter(nCenterX, nCenterY);
    UpdateView(UpdateHint::scaleChanged, params);
}
#pragma endregion

