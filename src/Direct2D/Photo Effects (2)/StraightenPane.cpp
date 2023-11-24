
#include "pch.h"
#include "StraightenPane.h"
#include "StraightenParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Panes::CStraightenPane;
using Parameters::CStraightenParameters;

CStraightenPane::CStraightenPane(UINT nDlgId, SampleId sampleId, UINT nNameResId)
    : CSamplePane(nDlgId, sampleId, nNameResId)
{
}

#pragma region Overriden
void CStraightenPane::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_ANGLE, m_sliderAngle);
    DDX_Control(pDX, IDC_CHECK_MAINTAIN_SIZE, m_checkMaintainSize);
    DDX_Control(pDX, IDC_COMBO_SCALE_MODE, m_comboScaleMode);
}

void CStraightenPane::InitPane()
{
    m_sliderAngle.SetRange(m_nMinSliderPos, m_nMaxSliderPos);
    FillScaleModeCombo();
}

void CStraightenPane::SetSampleParameters()
{
    m_checkMaintainSize.SetCheck(BST_CHECKED);
    m_sliderAngle.SetPos(m_nDefSliderPos + 50);
    m_comboScaleMode.SelectItem(D2D1_STRAIGHTEN_SCALE_MODE_CUBIC);
    ParametersChanged();
}

void CStraightenPane::ResetParameters()
{
    m_checkMaintainSize.SetCheck(BST_UNCHECKED);
    m_sliderAngle.SetPos(m_nDefSliderPos);
    m_comboScaleMode.SelectItem(D2D1_STRAIGHTEN_SCALE_MODE_LINEAR);
    ParametersChanged();
}

void CStraightenPane::ParametersChanged()
{
    CStraightenParameters params;
    // set angle between -45.f and 45.f (default is 0.f)
    FLOAT angle = (m_sliderAngle.GetPos() - m_nDefSliderPos) / 10.f;
    params.SetAngle(angle);
    // set maintain size flag (default value is FALSE)?
    params.SetMaintainSize(m_checkMaintainSize.GetCheck() == BST_CHECKED);
    // set scale mode (default value is D2D1_STRAIGHTEN_SCALE_MODE_LINEAR)
    params.SetScaleMode(m_comboScaleMode.GetSelectedItemData());
    UpdateView(UpdateHint::straightenChanged, params);
}
#pragma endregion

#pragma region Implementation
void CStraightenPane::FillScaleModeCombo()
{
    m_comboScaleMode.ResetContent();
    m_comboScaleMode.AddItem(L"Nearest neghbor", D2D1_STRAIGHTEN_SCALE_MODE_NEAREST_NEIGHBOR);
    m_comboScaleMode.AddItem(L"Linear", D2D1_STRAIGHTEN_SCALE_MODE_LINEAR);
    m_comboScaleMode.AddItem(L"Cubic", D2D1_STRAIGHTEN_SCALE_MODE_CUBIC);
    m_comboScaleMode.AddItem(L"Multi sample linear", D2D1_STRAIGHTEN_SCALE_MODE_MULTI_SAMPLE_LINEAR);
    m_comboScaleMode.AddItem(L"Anisotropic", D2D1_STRAIGHTEN_SCALE_MODE_ANISOTROPIC);
}
#pragma endregion