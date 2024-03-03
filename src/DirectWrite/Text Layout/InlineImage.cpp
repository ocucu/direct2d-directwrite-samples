// File: InlineImage.cpp - CInlineImage class implementation
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Implements IDWriteInlineObject methods in order to draw an inline image
// Note: 

#include "pch.h"
#include "InlineImage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CInlineImage::CInlineImage(CHwndRenderTarget* pRenderTarget, CD2DBitmap* pBitmap)
{
    VERIFY_D2D_RESOURCE(pRenderTarget);
    VERIFY_D2D_RESOURCE(pBitmap);
    m_xInlineImage.m_pBitmap = pBitmap;
    m_xInlineImage.m_pRenderTarget = pRenderTarget;
}

#pragma region IDWriteInlineObject implementation
BEGIN_INTERFACE_MAP(CInlineImage, CCmdTarget)
    INTERFACE_PART(CInlineImage, __uuidof(IDWriteInlineObject), InlineImage)
END_INTERFACE_MAP()

STDMETHODIMP CInlineImage::XInlineImage::Draw(void* clientDrawingContext,
    IDWriteTextRenderer* textRenderer, FLOAT fOriginX, FLOAT fOriginY,
    BOOL bIsSideways, BOOL bIsRightToLeft, IUnknown* clientDrawingEffect)
{
    UNREFERENCED_PARAMETER(clientDrawingEffect);
    UNREFERENCED_PARAMETER(bIsRightToLeft);
    UNREFERENCED_PARAMETER(bIsSideways);
    UNREFERENCED_PARAMETER(textRenderer);
    UNREFERENCED_PARAMETER(clientDrawingContext);
    METHOD_PROLOGUE(CInlineImage, InlineImage);
    ASSERT_VALID(m_pRenderTarget);
    ASSERT_VALID(m_pBitmap);

    if (m_pRenderTarget->IsValid() && m_pBitmap->IsValid())
    {
        CD2DSizeF sizeBitmap = m_pBitmap->GetSize();
        m_pRenderTarget->DrawBitmap(m_pBitmap,
            CD2DRectF(fOriginX, fOriginY,
                fOriginX + sizeBitmap.width, fOriginY + sizeBitmap.height));
    }
    return S_OK;
}

STDMETHODIMP CInlineImage::XInlineImage::GetBreakConditions(
    DWRITE_BREAK_CONDITION* breakConditionBefore,
    DWRITE_BREAK_CONDITION * breakConditionAfter)
{
    METHOD_PROLOGUE(CInlineImage, InlineImage);
    *breakConditionBefore = DWRITE_BREAK_CONDITION_NEUTRAL;
    *breakConditionAfter = DWRITE_BREAK_CONDITION_NEUTRAL;
    return S_OK;
}

STDMETHODIMP CInlineImage::XInlineImage::GetMetrics(DWRITE_INLINE_OBJECT_METRICS* metrics)
{
    METHOD_PROLOGUE(CInlineImage, InlineImage);
    ASSERT_VALID(m_pBitmap);

    DWRITE_INLINE_OBJECT_METRICS inlineMetrics = { 0 };
    if (m_pBitmap->IsValid())
    {
        CD2DSizeF sizeBitmap = m_pBitmap->GetSize();
        inlineMetrics.width = sizeBitmap.width;
        inlineMetrics.height = sizeBitmap.height;
        inlineMetrics.baseline = sizeBitmap.height / 2;
    }
    *metrics = inlineMetrics;
    return S_OK;
}

STDMETHODIMP CInlineImage::XInlineImage::GetOverhangMetrics(DWRITE_OVERHANG_METRICS* overhangs)
{
    METHOD_PROLOGUE(CInlineImage, InlineImage);
    overhangs->left = 0;
    overhangs->top = 0;
    overhangs->right = 0;
    overhangs->bottom = 0;
    return S_OK;
}

STDMETHODIMP CInlineImage::XInlineImage::QueryInterface(REFIID iid, LPVOID far* ppvObj)
{
    METHOD_PROLOGUE(CInlineImage, InlineImage);
    return pThis->ExternalQueryInterface(&iid, ppvObj);
}

STDMETHODIMP_(ULONG) CInlineImage::XInlineImage::AddRef()
{
    METHOD_PROLOGUE(CInlineImage, InlineImage);
    return pThis->ExternalAddRef();
}

STDMETHODIMP_(ULONG) CInlineImage::XInlineImage::Release()
{
    METHOD_PROLOGUE(CInlineImage, InlineImage);
    return pThis->ExternalRelease();
}
#pragma endregion

#pragma region CInlineImage implementation
BOOL CInlineImage::IsValid()
{
    return (NULL != m_xInlineImage.m_pBitmap) && (NULL != m_xInlineImage.m_pRenderTarget)
        && m_xInlineImage.m_pBitmap->IsValid() && m_xInlineImage.m_pRenderTarget->IsValid();
}
#pragma endregion
