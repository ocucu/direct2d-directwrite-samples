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
BOOL CPhotoEffectsFrame::LoadCustomMenu()
{
    return m_menuCustom.LoadMenu(IDR_MENU_CUSTOM);
}

BOOL CPhotoEffectsFrame::AddDockingPanes()
{
    auto spContrastPane = std::make_shared<CContrastPane>(IDD_CONTRAST_PANE, SampleId::contrast,
        IDS_SAMPLE_NAME_CONTRAST, BitmapId::pencil);
    auto spBrightnessPane = std::make_shared<CBrightnessPane>(IDD_BRIGHTNESS_PANE, SampleId::brightness,
        IDS_SAMPLE_NAME_BRIGHTNESS, BitmapId::pencil);
    auto spGrayscalePane = std::make_shared<CGrayscalePane>(IDD_GRAYSCALE_PANE, SampleId::grayscale,
        IDS_SAMPLE_NAME_GRAYSCALE, BitmapId::pencil);
    auto spInvertPane = std::make_shared<CInvertPane>(IDD_INVERT_PANE, SampleId::invert,
        IDS_SAMPLE_NAME_INVERT, BitmapId::pencil);
    auto spSepiaPane = std::make_shared<CSepiaPane>(IDD_SEPIA_PANE, SampleId::sepia,
        IDS_SAMPLE_NAME_SEPIA, BitmapId::pencil);
    auto spExposurePane = std::make_shared<CExposurePane>(IDD_EXPOSURE_PANE, SampleId::exposure,
        IDS_SAMPLE_NAME_EXPOSURE, BitmapId::pencil);

    VERIFY_BOOL_RET(AddPane(spContrastPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spBrightnessPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spGrayscalePane), FALSE);
    VERIFY_BOOL_RET(AddPane(spInvertPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spSepiaPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spExposurePane), FALSE);

    return TRUE;
}

BOOL CPhotoEffectsFrame::PreCreateWindow(CREATESTRUCT& cs)
{
    cs.cx = FRAME_CX_DEFAULT;
    cs.cy = FRAME_CY_DEFAULT;
    return __super::PreCreateWindow(cs);
}
#pragma endregion
