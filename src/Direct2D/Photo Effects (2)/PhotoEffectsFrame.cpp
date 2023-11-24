// File: PhotoEffectsFrame.cpp - CPhotoEffectsFrame class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "PhotoEffectsFrame.h"
#include "Panes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define FRAME_CX_DEFAULT    718
#define FRAME_CY_DEFAULT    422

using Framework::CPhotoEffectsFrame;
using namespace Panes;

IMPLEMENT_DYNCREATE(CPhotoEffectsFrame, CDemoFrame)

#pragma region Overridden
BOOL CPhotoEffectsFrame::AddDockingPanes()
{
    auto spSharpenPane = std::make_shared<CSharpenPane>(IDD_SHARPEN_PANE, SampleId::sharpen,
        IDS_SAMPLE_NAME_SHARPEN);
    auto spStraightenPane = std::make_shared<CStraightenPane>(IDD_STRAIGHTEN_PANE, SampleId::straighten,
        IDS_SAMPLE_NAME_STRAIGHTEN);
    auto spVignettePane = std::make_shared<CVignettePane>(IDD_VIGNETTE_PANE, SampleId::vignette,
        IDS_SAMPLE_NAME_VIGNETTE);
    auto spHighlightsAndShadowsPane = std::make_shared<CHighlightsAndShadowsPane>(IDD_HIGHLIGHTS_SHADOW_PANE, 
        SampleId::highlightsAndShadows, IDS_SAMPLE_NAME_HIGHLIGHTS_SHADOW);
    auto spTemperatureAndTintPane = std::make_shared<CTemperatureAndTintPane>(IDD_TEMPERATURE_TINT_PANE,
        SampleId::temperatureAndTint, IDS_SAMPLE_NAME_TEMPERATURE_TINT);

    VERIFY_BOOL_RET(AddPane(spSharpenPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spStraightenPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spVignettePane), FALSE);
    VERIFY_BOOL_RET(AddPane(spHighlightsAndShadowsPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spTemperatureAndTintPane), FALSE);

    return TRUE;
}

BOOL CPhotoEffectsFrame::PreCreateWindow(CREATESTRUCT& cs)
{
    cs.cx = FRAME_CX_DEFAULT;
    cs.cy = FRAME_CY_DEFAULT;
    return __super::PreCreateWindow(cs);
}
#pragma endregion
