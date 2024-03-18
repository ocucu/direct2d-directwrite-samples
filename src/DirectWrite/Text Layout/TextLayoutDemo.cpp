// File:   TextLayoutDemo.cpp - CTextLayoutDemo class implementation
// Author: Ovidiu Cucu 
//         blog: https://codexpertro.wordpress.com/ 
//         e-mail: ovidiu.cucu.mvp@gmail.com 
// Notes:  Some may notice repeated code in DemoXyz functions and/or not enough defensive approach.   
//         I've intentionally wrote them like that, for simplicity.
//         Anyway, if you intend to use it in your own project, you're free to refactor those functions or just get a hint.

#include "pch.h"
#include "TextLayoutDemo.h"

using namespace Framework;
using namespace Parameters;

CTextLayoutDemo::CTextLayoutDemo(CDemoView* pView)
    : CDemoDraw(pView)
{
}

#pragma region Overridden
void CTextLayoutDemo::DrawDemo(CHwndRenderTarget* pRenderTarget)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(10.f, 10.f));

    // create CD2DTextFormat object 
    CD2DTextFormat textFormat(
        pRenderTarget,  // window render target
        L"Arial",       // font family name
        24.f);          // font size in DIP (1/96 inch)

    SampleId sampleId = GetDemoFrame()->GetActivePaneId();
    switch (sampleId)
    {
    case SampleId::rangeFormat:
        DemoTextRangeFormat(pRenderTarget, textFormat);
        break;
    case SampleId::drawingEffects:
        DemoDrawingEffects(pRenderTarget, textFormat);
        break;
    case SampleId::inlineImages:
        DemoInlineImages(pRenderTarget, textFormat);
        break;
    case SampleId::typography:
        DemoTypography(pRenderTarget, textFormat);
        break;
    default:
        ATLTRACE("Unhandled SampleId");
        break;
    }
}
#pragma endregion

#pragma region Operations
void CTextLayoutDemo::OnRangeFormatChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CRangeFormatParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_rangeFormatParams = *pParams;
    InvalidateView();
}

void CTextLayoutDemo::OnDrawingEffectsChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CDrawingEffectsParameters*>(pHint);
    ASSERT_VALID(pParams);
    m_drawingEffectsParams = *pParams;
    InvalidateView();
}

void CTextLayoutDemo::OnInlineImageChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CInlineImagesParameters*>(pHint);
    ASSERT_VALID(pParams);
    DBG_UNREFERENCED_LOCAL_VARIABLE(pParams);
    InvalidateView();
}

void CTextLayoutDemo::OnTypographyChanged(CObject* pHint)
{
    auto pParams = dynamic_cast<CTypographyParameters*>(pHint);
    ASSERT_VALID(pParams);
    DBG_UNREFERENCED_LOCAL_VARIABLE(pParams);
    InvalidateView();
}
#pragma endregion

#pragma region Demo functions
void CTextLayoutDemo::DemoTextRangeFormat(CHwndRenderTarget* pRenderTarget, CD2DTextFormat& textFormat)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    VERIFY_D2D_RESOURCE(&textFormat);

    // fill text layout box
    const CD2DSizeF& sizeMax = m_rangeFormatParams.GetMaxSize();
    FillTextLayoutBackground(pRenderTarget, sizeMax);

    // get text block brush
    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    auto pTextBlockBrush = pDoc->GetTextBrush();
    VERIFY_D2D_RESOURCE(pTextBlockBrush);
    // get sample text
    CString strText = pDoc->GetSampleText();

    // create CD2DTextLayout object
    CD2DTextLayout textLayout(
        pRenderTarget,  // window render target
        strText,        // text to be drawn
        textFormat,     // text block format
        sizeMax         // the size of layout box
    );
    VERIFY_D2D_RESOURCE(&textLayout);

    const DWRITE_TEXT_RANGE& textRange = m_rangeFormatParams.GetTextRange();

    // set range font family name
    CString strFontFamily = m_rangeFormatParams.GetFontFamily();
    textLayout.SetFontFamilyName(strFontFamily, textRange);

    // get IDWriteTextLayout interface
    IDWriteTextLayout* pTextLayout = textLayout.Get();

    // set range font size in DIP
    FLOAT fontSize = m_rangeFormatParams.GetFontSize();
    pTextLayout->SetFontSize(fontSize, textRange);

    // set range font weight
    DWRITE_FONT_WEIGHT fontWeight = m_rangeFormatParams.GetFontWeight();
    pTextLayout->SetFontWeight(fontWeight, textRange);

    // set range font style
    DWRITE_FONT_STYLE fontStyle = m_rangeFormatParams.GetFontStyle();
    pTextLayout->SetFontStyle(fontStyle, textRange);

    // set range font stretch
    DWRITE_FONT_STRETCH fontStretch = m_rangeFormatParams.GetFontStretch();
    pTextLayout->SetFontStretch(fontStretch, textRange);

    // set range underline
    BOOL bUnderline = m_rangeFormatParams.GetUnderline();
    pTextLayout->SetUnderline(bUnderline, textRange);

    // set range strikethrough
    BOOL bStrikethrough = m_rangeFormatParams.GetStrikethrough();
    pTextLayout->SetStrikethrough(bStrikethrough, textRange);
    
    // draw text layout
    pRenderTarget->DrawTextLayout(CD2DPointF(), &textLayout, pTextBlockBrush);
}

void CTextLayoutDemo::DemoDrawingEffects(CHwndRenderTarget* pRenderTarget, CD2DTextFormat& textFormat)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    VERIFY_D2D_RESOURCE(&textFormat);

    // fill text layout box
    const CD2DSizeF& sizeMax = m_drawingEffectsParams.GetMaxSize();
    FillTextLayoutBackground(pRenderTarget, sizeMax);

    // get text block brush
    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    auto pTextBlockBrush = pDoc->GetTextBrush();
    VERIFY_D2D_RESOURCE(pTextBlockBrush);
    // get sample text
    CString strText = pDoc->GetSampleText();

    // create CD2DTextLayout object
    CD2DTextLayout textLayout(
        pRenderTarget,  // window render target
        strText,        // text to be drawn
        textFormat,     // text block format
        sizeMax         // the size of layout box
    );
    VERIFY_D2D_RESOURCE(&textLayout);

    const DWRITE_TEXT_RANGE& textRange = m_drawingEffectsParams.GetTextRange();
    textLayout.SetFontFamilyName(L"Impact", textRange);

    IDWriteTextLayout* pTextLayout = textLayout.Get();
    pTextLayout->SetFontSize(116.f, textRange);

    // select sample text range brush
    CD2DBrush* pTextRangeBrush{ NULL };
    SelectSampleBrush(pTextRangeBrush);
    VERIFY_D2D_RESOURCE(pTextRangeBrush);

    // set some range brush attributes
    if (pTextRangeBrush->IsKindOf(RUNTIME_CLASS(CD2DLinearGradientBrush)))
    {
        CD2DPointF endPoint{ sizeMax.width, sizeMax.height };
        dynamic_cast<CD2DLinearGradientBrush*>(pTextRangeBrush)->SetEndPoint(endPoint);
    }
    else if (pTextRangeBrush->IsKindOf(RUNTIME_CLASS(CD2DSolidColorBrush)))
    {
        D2D1_COLOR_F color = m_drawingEffectsParams.GetBrushColor();
        dynamic_cast<CD2DSolidColorBrush*>(pTextRangeBrush)->SetColor(color);
    }

    // pass the brush to IDWriteTextLayout::SetDrawingEffect
    pTextLayout->SetDrawingEffect(pTextRangeBrush->Get(), textRange);

    // draw text layout
    pRenderTarget->DrawTextLayout(CD2DPointF(), &textLayout, pTextBlockBrush);
}

void CTextLayoutDemo::DemoInlineImages(CHwndRenderTarget* pRenderTarget, CD2DTextFormat& textFormat)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    VERIFY_D2D_RESOURCE(&textFormat);
    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    // get sample text
    CD2DText text(pDoc->GetSampleText());

    // create CD2DTextLayout object
    CD2DTextLayout textLayout(
        pRenderTarget,           // window render target
        text.GetString(),        // text to be drawn
        textFormat,              // text block format
        pRenderTarget->GetSize() // the size of layout box
    );
    VERIFY_D2D_RESOURCE(&textLayout);

    // IDWriteTextLayout interface
    IDWriteTextLayout* pTextLayout = textLayout.Get();

    DWRITE_TEXT_RANGE textRange{ 0 };
    // create and set inline image objects
    auto spRingsImage = pDoc->GetRingsImage();
    if(spRingsImage->IsValid() && text.GetTagTextRange(L"[IMAGE:RINGS]", textRange))
    {
        pTextLayout->SetInlineObject(spRingsImage->Get(), textRange);
    }

    auto spRoseImage = pDoc->GetRoseImage();
    if (spRoseImage->IsValid() && text.GetTagTextRange(L"[IMAGE:ROSE]", textRange))
    {
        pTextLayout->SetInlineObject(spRoseImage->Get(), textRange);
    }

    auto spDogImage = pDoc->GetDogImage();
    if (spDogImage->IsValid() && text.GetTagTextRange(L"[IMAGE:DOG]", textRange))
    {
        pTextLayout->SetInlineObject(spDogImage->Get(), textRange);
    }

    // get text block brush
    auto pTextBlockBrush = pDoc->GetTextBrush();
    VERIFY_D2D_RESOURCE(pTextBlockBrush);

    // draw text layout
    pRenderTarget->DrawTextLayout(CD2DPointF(), &textLayout, pTextBlockBrush);
}

void CTextLayoutDemo::DemoTypography(CHwndRenderTarget* pRenderTarget, CD2DTextFormat& textFormat)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    VERIFY_D2D_RESOURCE(&textFormat);
    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    // get sample text
    CD2DText text(pDoc->GetSampleText());

    // create CD2DTextLayout object
    CD2DTextLayout textLayout(
        pRenderTarget,           // window render target
        text.GetString(),        // text to be drawn
        textFormat,              // text block format
        pRenderTarget->GetSize() // the size of layout box
    );
    VERIFY_D2D_RESOURCE(&textLayout);

    DWRITE_TEXT_RANGE textRange{ 0, text.GetLength() };
    textLayout.SetFontFamilyName(L"Gabriola", textRange);

    // IDWriteTextLayout interface
    IDWriteTextLayout* pTextLayout = textLayout.Get();
    pTextLayout->SetFontSize(36.f, textRange);
    pTextLayout->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);

    HRESULT hr = S_OK;
    if (text.GetTagTextRange(L"CH3–CH2–OH", textRange))
    {
        hr = SetTypographicFeature(textLayout, 
            DWRITE_FONT_FEATURE_TAG_SCIENTIFIC_INFERIORS, textRange);
        ASSERT(SUCCEEDED(hr));
    }

    if (text.GetTagTextRange(L"1/456", textRange))
    {
        hr = SetTypographicFeature(textLayout,
            DWRITE_FONT_FEATURE_TAG_FRACTIONS, textRange);
        ASSERT(SUCCEEDED(hr));
    }

    if (text.GetTagTextRange(L"Fancy Typography Rendering", textRange))
    {
        hr = SetTypographicFeature(textLayout,
            DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_7, textRange);
        ASSERT(SUCCEEDED(hr));
    }
    
    // get text block brush
    auto pTextBlockBrush = pDoc->GetTextBrush();
    VERIFY_D2D_RESOURCE(pTextBlockBrush);

    // draw text layout
    pRenderTarget->DrawTextLayout(CD2DPointF(), &textLayout, pTextBlockBrush);

}
#pragma endregion

#pragma region Implementation
void CTextLayoutDemo::SelectSampleBrush(CD2DBrush*& pBrush)
{
    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    BrushTypeId brushTypeId = pDoc->GetSampleBrushTypeId();
    switch (brushTypeId)
    {
    case BrushTypeId::unknown:
    case BrushTypeId::solid_color:
        pBrush = pDoc->GetSolidColorBrush();
        break;
    case BrushTypeId::gradient:
        pBrush = pDoc->GetGradientBrush();
        break;
    case BrushTypeId::bitmap:
        pBrush = pDoc->GetBitmapBrush();
        break;
    default:
        ATLTRACE("Unhandled BrushTypeId");
        break;
    }
}

void CTextLayoutDemo::FillTextLayoutBackground(CHwndRenderTarget* pRenderTarget, const CD2DSizeF& sizeMax)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    auto pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    // get sample text
    CString strText = pDoc->GetSampleText();

    CD2DSolidColorBrush* pBrush = pDoc->GetBackgroundBrush();
    VERIFY_D2D_RESOURCE(pBrush);
    CD2DRectF rect{ 0.f, 0.f, sizeMax.width, sizeMax.height };
    pRenderTarget->FillRectangle(rect, pBrush);    
}

CTextLayoutDocument* CTextLayoutDemo::GetDocument()
{
    return dynamic_cast<CTextLayoutDocument*> (GetDemoDocument());
}

HRESULT CTextLayoutDemo::SetTypographicFeature(
    CD2DTextLayout& textLayout,
    DWRITE_FONT_FEATURE_TAG featureTag, 
    DWRITE_TEXT_RANGE textRange)
{
    // get the global IDWriteFactory pointer
    IDWriteFactory* pIDWriteFactory = AfxGetD2DState()->GetWriteFactory();

    // create IDWriteTypography instance
    CComPtr<IDWriteTypography> spIDWriteTypography;
    HRESULT hr = pIDWriteFactory->CreateTypography(&spIDWriteTypography);
    if (FAILED(hr)) 
        return hr;

    // add font feature
    DWRITE_FONT_FEATURE fontFeature;
    fontFeature.nameTag = featureTag;
    fontFeature.parameter = 1;
    hr = spIDWriteTypography->AddFontFeature(fontFeature);
    if (FAILED(hr)) 
        return hr;

    // set the typography in a range of the text layout
    hr = textLayout.Get()->SetTypography(spIDWriteTypography, textRange);
    if (FAILED(hr)) 
        return hr;

    return S_OK;
}
#pragma endregion
