#include "pch.h"
#include "InvertPane.h"

using Panes::CInvertPane;

CInvertPane::CInvertPane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BitmapId bitmapId)
    : CSamplePane(nDlgId, sampleId, nNameResId, bitmapId)
{
}

#pragma region Overridden
void CInvertPane::InitPane()
{
    // nothing to do; just overrides pure virtual method
}

void CInvertPane::SetSampleParameters()
{
    // note: invert effect has no parameters; just notufy the view to apply it.
    CDemoDocument* pDoc = GetDemoDocument();
    ASSERT_VALID(pDoc);
    pDoc->UpdateAllViews(NULL);
}

void CInvertPane::ResetParameters()
{
    // nothing to do; just overrides pure virtual method
}

void CInvertPane::ParametersChanged()
{
    // nothing to do; just overrides pure virtual method
}
#pragma endregion