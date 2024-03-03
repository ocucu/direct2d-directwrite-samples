// File: InlineImage.h - CInlineImage class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#pragma once

class CInlineImage : public CCmdTarget
{
public:
    CInlineImage(CHwndRenderTarget* pRenderTarget, CD2DBitmap* pBitmap);
    BOOL IsValid();
    IDWriteInlineObject* Get();
    operator IDWriteInlineObject*();

public:
    DECLARE_INTERFACE_MAP()
    BEGIN_INTERFACE_PART(InlineImage, IDWriteInlineObject)
        STDMETHOD(Draw)(void*, IDWriteTextRenderer*, FLOAT, FLOAT, BOOL, BOOL, IUnknown*);
    STDMETHOD(GetMetrics)(DWRITE_INLINE_OBJECT_METRICS*);
    STDMETHOD(GetOverhangMetrics)(DWRITE_OVERHANG_METRICS*);
    STDMETHOD(GetBreakConditions)(DWRITE_BREAK_CONDITION*, DWRITE_BREAK_CONDITION*);
    CHwndRenderTarget* m_pRenderTarget;
    CD2DBitmap* m_pBitmap;
    END_INTERFACE_PART(InlineImage)
};

#include "InlineImage.inl"
