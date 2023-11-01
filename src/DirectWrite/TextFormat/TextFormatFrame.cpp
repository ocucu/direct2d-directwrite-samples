// File: TextFormatFrame.cpp - CTextFormatFrame class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#include "pch.h"
#include "TextFormatFrame.h"
#include "Panes.h"

#define FRAME_CX_DEFAULT    654
#define FRAME_CY_DEFAULT    422

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using Framework::CTextFormatFrame;
using namespace Panes;

IMPLEMENT_DYNCREATE(CTextFormatFrame, CDemoFrame)

#pragma region Overridden
BOOL CTextFormatFrame::AddDockingPanes()
{
    auto spFontPane = std::make_shared<CFontPane>(IDD_FONT_PANE, SampleId::font,
        IDS_SAMPLE_NAME_FONT, IDS_SAMPLE_TEXT_FONT);
    auto spAlignmentPane = std::make_shared<CAlignmentPane>(IDD_ALIGNMENT_PANE, SampleId::alignment,
        IDS_SAMPLE_NAME_ALIGNMENT, IDS_SAMPLE_TEXT_ALIGNMENT);
    auto spWordWrappingPane = std::make_shared<CWordWrappingPane>(IDD_WORD_WRAPPING_PANE, SampleId::wordWrapping,
        IDS_SAMPLE_NAME_WORD_WRAPPING, IDS_SAMPLE_TEXT_WORD_WRAPPING);
    auto spTrimmingPane = std::make_shared<CTrimmingPane>(IDD_TRIMMING_PANE, SampleId::trimming,
        IDS_SAMPLE_NAME_TRIMMING, IDS_SAMPLE_TEXT_TRIMMING);
    auto spDirectionPane = std::make_shared<CDirectionPane>(IDD_DIRECTION_PANE, SampleId::direction,
        IDS_SAMPLE_NAME_DIRECTION, IDS_SAMPLE_TEXT_DIRECTION);
    auto spLineSpacingPane = std::make_shared<CLineSpacingPane>(IDD_LINE_SPACING_PANE, SampleId::lineSpacing,
        IDS_SAMPLE_NAME_LINE_SPACING, IDS_SAMPLE_TEXT_LINE_SPACING);
    auto spTabStopPane = std::make_shared<CTabStopPane>(IDD_TAB_STOP_PANE, SampleId::tabStop,
        IDS_SAMPLE_NAME_TAB_STOP, IDS_SAMPLE_TEXT_TAB_STOP);

    VERIFY_BOOL_RET(AddPane(spFontPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spAlignmentPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spWordWrappingPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spTrimmingPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spDirectionPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spLineSpacingPane), FALSE);
    VERIFY_BOOL_RET(AddPane(spTabStopPane), FALSE);

    return TRUE;
}

BOOL Framework::CTextFormatFrame::PreCreateWindow(CREATESTRUCT& cs)
{
    cs.cx = FRAME_CX_DEFAULT;
    cs.cy = FRAME_CY_DEFAULT;
    return CDemoFrame::PreCreateWindow(cs);
}
#pragma endregion