// File: BrushTransformFrame.cpp - CBrushTransformFrame class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "BrushTransformFrame.h"
#include "Panes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define FRAME_CX_DEFAULT    710
#define FRAME_CY_DEFAULT    422

using Framework::CBrushTransformFrame;
using namespace Panes;

IMPLEMENT_DYNCREATE(CBrushTransformFrame, CDemoFrame)

#pragma region Overridden
BOOL CBrushTransformFrame::LoadCustomMenu()
{
    return m_menuCustom.LoadMenu(IDR_MENU_CUSTOM);
}

BOOL CBrushTransformFrame::AddDockingPanes()
{
    auto spTranslationPane = std::make_shared<CTranslationPane>(IDD_TRANSLATION_PANE, SampleId::translation,
        IDS_SAMPLE_NAME_TRANSLATION, BrushTypeId::bitmap);
    auto spRotationPane = std::make_shared<CRotationPane>(IDD_ROTATION_PANE, SampleId::rotation,
        IDS_SAMPLE_NAME_ROTATION, BrushTypeId::linearGradient);
    auto spScalePane = std::make_shared<CScalePane>(IDD_SCALE_PANE, SampleId::scale,
        IDS_SAMPLE_NAME_SCALE, BrushTypeId::bitmap);
    auto spSkewPane = std::make_shared<CSkewPane>(IDD_SKEW_PANE, SampleId::skew,
        IDS_SAMPLE_NAME_SKEW, BrushTypeId::radialGradient);

    VERIFY_BOOL_RET(AddPane(spTranslationPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spRotationPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spScalePane), FALSE);
    VERIFY_BOOL_RET(AddPane(spSkewPane), FALSE);

    return TRUE;
}

BOOL CBrushTransformFrame::PreCreateWindow(CREATESTRUCT& cs)
{
    cs.cx = FRAME_CX_DEFAULT;
    cs.cy = FRAME_CY_DEFAULT;
    return __super::PreCreateWindow(cs);
}
#pragma endregion
