#include "pch.h"
#include "GrayscalePane.h"

using Panes::CGrayscalePane;

CGrayscalePane::CGrayscalePane(UINT nDlgId, SampleId sampleId, UINT nNameResId, BitmapId bitmapId)
    : CSamplePane(nDlgId, sampleId, nNameResId, bitmapId)
{
}

#pragma region Overridden
void CGrayscalePane::InitPane()
{
    // nothing to do; just overrides pure virtual method
}

void CGrayscalePane::SetSampleParameters()
{
    // note: grayscale effect has no parameters; just notufy the view to apply it.
    CDemoDocument* pDoc = GetDemoDocument();
    ASSERT_VALID(pDoc);
    pDoc->UpdateAllViews(NULL);
}

void CGrayscalePane::ResetParameters()
{
    // nothing to do; just overrides pure virtual method
}

void CGrayscalePane::ParametersChanged()
{
    // nothing to do; just overrides pure virtual method
}
#pragma endregion
