
#include "pch.h"
#include "BrightnessPane.h"
#include "BrightnessParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CBrightnessPane;
using Parameters::CBrightnessParameters;

CBrightnessPane::CBrightnessPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BitmapId bitmapId)
    : CSamplePane(nDlgId, sampleId, nNameResId, bitmapId)
{
}

#pragma region Overriden
void CBrightnessPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_WHITE_POINT_X, m_sliderWhitePointX);
    DDX_Control(pDX, IDC_SLIDER_WHITE_POINT_Y, m_sliderWhitePointY);
    DDX_Control(pDX, IDC_SLIDER_BLACK_POINT_X, m_sliderBlackPointX);
    DDX_Control(pDX, IDC_SLIDER_BLACK_POINT_Y, m_sliderBlackPointY);
}

void CBrightnessPane::InitPane()
{
    m_sliderWhitePointX.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    m_sliderWhitePointY.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    m_sliderBlackPointX.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    m_sliderBlackPointY.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
}

void CBrightnessPane::SetSampleParameters()
{
    m_sliderWhitePointX.SetPos(75);
    m_sliderWhitePointY.SetPos(m_nMaxSliderPos);
    m_sliderBlackPointX.SetPos(m_nMinSliderPos);
    m_sliderBlackPointY.SetPos(25);

    ParametersChanged();
}

void CBrightnessPane::ResetParameters()
{
    m_sliderWhitePointX.SetPos(m_nMaxSliderPos);
    m_sliderWhitePointY.SetPos(m_nMaxSliderPos);
    m_sliderBlackPointX.SetPos(m_nMinSliderPos);
    m_sliderBlackPointY.SetPos(m_nMinSliderPos);
    ParametersChanged();
}

void CBrightnessPane::ParametersChanged()
{
    CBrightnessParameters params;

    FLOAT whitePointX = m_sliderWhitePointX.GetPos() / 100.f;
    FLOAT whitePointY = m_sliderWhitePointY.GetPos() / 100.f;
    params.SetWhitePoint(D2D1::Vector2F(whitePointX, whitePointY));

    FLOAT blackPointX = m_sliderBlackPointX.GetPos() / 100.f;
    FLOAT blackPointY = m_sliderBlackPointY.GetPos() / 100.f;
    params.SetBlackPoint(D2D1::Vector2F(blackPointX, blackPointY));

    UpdateView(UpdateHint::brightnessChanged, params);
}
#pragma endregion
