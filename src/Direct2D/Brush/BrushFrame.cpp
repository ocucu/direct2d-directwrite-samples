// File: BrushFrame.cpp - CBrushFrame class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "BrushFrame.h"
#include "Panes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define FRAME_CX_DEFAULT    710
#define FRAME_CY_DEFAULT    496

using Framework::CBrushFrame;
using namespace Panes;

IMPLEMENT_DYNCREATE(CBrushFrame, CDemoFrame)

#pragma region Overridden
BOOL CBrushFrame::LoadCustomMenu()
{
    return m_menuCustom.LoadMenu(IDR_MENU_CUSTOM);
}

BOOL CBrushFrame::AddDockingPanes()
{
    IDD_BITMAP_BRUSH_PANE;
    auto spSolidColorBrushPane = std::make_shared<CSolidColorBrushPane>(IDD_SOLID_COLOR_BRUSH_PANE, 
        SampleId::solidColorBrush, IDS_SOLID_COLOR_BRUSH, FigureId::rectangle);
    auto spBitmapBrushPane = std::make_shared<CBitmapBrushPane>(IDD_BITMAP_BRUSH_PANE, 
        SampleId::bitmapBrush, IDS_BITMAP_BRUSH, FigureId::none, BitmapId::cat);
    auto spLinearGradientBrushBrushPane = std::make_shared<CLinearGradientBrushPane>(IDD_LINEAR_GRADIENT_BRUSH_PANE, 
        SampleId::linearGradientBrush, IDS_LINEAR_GRADIENT_BRUSH, FigureId::none);
    auto spRadialGradientBrushBrushPane = std::make_shared<CRadialGradientBrushPane>(IDD_RADIAL_GRADIENT_BRUSH_PANE, 
        SampleId::radialGradientBrush, IDS_RADIAL_GRADIENT_BRUSH, FigureId::none);

    VERIFY_BOOL_RET(AddPane(spSolidColorBrushPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spBitmapBrushPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spLinearGradientBrushBrushPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spRadialGradientBrushBrushPane), FALSE);

    return TRUE;
}

BOOL CBrushFrame::PreCreateWindow(CREATESTRUCT& cs)
{
    cs.cx = FRAME_CX_DEFAULT;
    cs.cy = FRAME_CY_DEFAULT;
    return __super::PreCreateWindow(cs);
}
#pragma endregion
