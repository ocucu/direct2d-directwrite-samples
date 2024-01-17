// File: TextLayoutFrame.cpp - CTextLayoutFrame class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/ 
//         e-mail: ovidiu.cucu.mvp@gmail.com

#include "pch.h"
#include "TextLayoutFrame.h"
#include "Panes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define FRAME_CX_DEFAULT    718
#define FRAME_CY_DEFAULT    484

using Framework::CTextLayoutFrame;
using namespace Panes;

IMPLEMENT_DYNCREATE(CTextLayoutFrame, CDemoFrame)

#pragma region Overridden
BOOL CTextLayoutFrame::LoadCustomMenu()
{
    return m_menuCustom.LoadMenu(IDR_MENU_CUSTOM);
}

BOOL CTextLayoutFrame::AddDockingPanes()
{
    auto spRangeFormatPane = std::make_shared<CRangeFormatPane>(IDD_RANGE_FORMAT_PANE, 
        SampleId::rangeFormat,
        IDS_SAMPLE_NAME_RANGE_FORMAT, IDS_SAMPLE_TEXT_RANGE_FORMAT, BrushTypeId::unknown);
    auto spDrawingEffectsPane = std::make_shared<CDrawingEffectsPane>(IDD_DRAWING_EFFECTS_PANE, 
        SampleId::drawingEffects,
        IDS_SAMPLE_NAME_DRAWING_EFFECTS, IDS_SAMPLE_TEXT_DRAWING_EFFECTS, BrushTypeId::gradient);

    VERIFY_BOOL_RET(AddPane(spRangeFormatPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spDrawingEffectsPane), FALSE);

    return TRUE;
}

BOOL CTextLayoutFrame::PreCreateWindow(CREATESTRUCT& cs)
{
    cs.cx = FRAME_CX_DEFAULT;
    cs.cy = FRAME_CY_DEFAULT;
    return __super::PreCreateWindow(cs);
}
#pragma endregion
