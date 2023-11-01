// File: RenderTargetTransformFrame.cpp - CRenderTargetTransformFrame class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "RenderTargetTransformFrame.h"
#include "Panes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define ID_IMAGE_FIRST      ID_IMAGE_RECTANGLE
#define ID_IMAGE_LAST       ID_IMAGE_PICTURE
#define FRAME_CX_DEFAULT    654
#define FRAME_CY_DEFAULT    422

using Framework::CRenderTargetTransformFrame;
using namespace Panes;

IMPLEMENT_DYNCREATE(CRenderTargetTransformFrame, CDemoFrame)

#pragma region Overridden
BOOL CRenderTargetTransformFrame::LoadCustomMenu()
{
    return m_menuCustom.LoadMenu(IDR_MENU_CUSTOM);
}

BOOL CRenderTargetTransformFrame::AddDockingPanes()
{
    auto spTranslationPane = std::make_shared<CTranslationPane>(IDD_TRANSLATION_PANE, SampleId::translation,
        IDS_SAMPLE_NAME_TRANSLATION, FigureId::picture);
    auto spRotationPane = std::make_shared<CRotationPane>(IDD_ROTATION_PANE, SampleId::rotation,
        IDS_SAMPLE_NAME_ROTATION, FigureId::arrow);
    auto spScalePane = std::make_shared<CScalePane>(IDD_SCALE_PANE, SampleId::scale,
        IDS_SAMPLE_NAME_SCALE, FigureId::rectangle);
    auto spSkewPane = std::make_shared<CSkewPane>(IDD_SKEW_PANE, SampleId::skew,
        IDS_SAMPLE_NAME_SKEW, FigureId::rectangle);

    VERIFY_BOOL_RET(AddPane(spTranslationPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spRotationPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spScalePane), FALSE);
    VERIFY_BOOL_RET(AddPane(spSkewPane), FALSE);

    return TRUE;
}

BOOL CRenderTargetTransformFrame::PreCreateWindow(CREATESTRUCT& cs)
{
    cs.cx = FRAME_CX_DEFAULT;
    cs.cy = FRAME_CY_DEFAULT;
    return __super::PreCreateWindow(cs);
}
#pragma endregion
