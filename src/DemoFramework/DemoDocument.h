// File: DemoDocument.h - CDemoDocument class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#pragma once

class DEMOFRAMEWORK_EXP CDemoDocument : public CDocument
{
    DECLARE_DYNAMIC(CDemoDocument)
public:
    // Operations
    void UpdateView(UpdateHint hint, CObject& params);
    void SetSampleText(const CString& strText);
    CString GetSampleText() const;
    void SetSampleFigureId(FigureId figureId);
    FigureId GetSampleFigureId() const;
    void SetSampleBitmapId(BitmapId bitmapId);
    BitmapId GetSampleBitmapId() const;
    void ShowSampleTextDialog();
protected:
    // Overridden
    virtual BOOL OnNewDocument() override;
    virtual BOOL CreateD2DResources(CHwndRenderTarget* pRenderTarget);
private:
    // Data
    CString m_strSampleText;
    FigureId m_sampleFigureId{ static_cast<FigureId>(0) }; // FigureId::unknown 
    BitmapId m_sampleBitmapId{ static_cast<BitmapId>(0) }; // BitmapId::unknown 
};

#include "DemoDocument.inl"

