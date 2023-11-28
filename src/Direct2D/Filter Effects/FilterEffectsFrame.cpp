// File: FilterEffectsFrame.cpp - CFilterEffectsFrame class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/ 
//         e-mail: ovidiu.cucu.mvp@gmail.com

#include "pch.h"
#include "FilterEffectsFrame.h"
#include "Panes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define FRAME_CX_DEFAULT    718
#define FRAME_CY_DEFAULT    468

using Framework::CFilterEffectsFrame;
using namespace Panes;

IMPLEMENT_DYNCREATE(CFilterEffectsFrame, CDemoFrame)

#pragma region Overridden
BOOL CFilterEffectsFrame::AddDockingPanes()
{
    auto spGaussianBlurPane = std::make_shared<CGaussianBlurPane>(IDD_GAUSSIAN_BLUR_PANE, SampleId::gaussianBlur,
        IDS_SAMPLE_NAME_GAUSSIAN_BLUR);
    auto spDirectionalBlurPane = std::make_shared<CDirectionalBlurPane>(IDD_DIRECTIONAL_BLUR_PANE, SampleId::directionalBlur,
        IDS_SAMPLE_NAME_DIRECTIONAL_BLUR);
    auto spEdgeDetectionPane = std::make_shared<CEdgeDetectionPane>(IDD_EDGE_DETECTION_PANE, SampleId::edgeDetection,
        IDS_SAMPLE_NAME_EDGE_DETECTION);
    auto spMorphologyPane = std::make_shared<CMorphologyPane>(IDD_MORPHOLOGY_PANE, 
        SampleId::morphology, IDS_SAMPLE_NAME_MORPHOLOGY);

    VERIFY_BOOL_RET(AddPane(spGaussianBlurPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spDirectionalBlurPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spEdgeDetectionPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spMorphologyPane), FALSE);

    return TRUE;
}

BOOL CFilterEffectsFrame::PreCreateWindow(CREATESTRUCT& cs)
{
    cs.cx = FRAME_CX_DEFAULT;
    cs.cy = FRAME_CY_DEFAULT;
    return __super::PreCreateWindow(cs);
}
#pragma endregion
