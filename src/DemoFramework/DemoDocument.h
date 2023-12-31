// File: DemoDocument.h - CDemoDocument class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

#pragma once

class DEMOFRAMEWORK_EXP CDemoDocument : public CDocument
{
    DECLARE_DYNAMIC(CDemoDocument)
public:
    // Operations
    void UpdateView(UpdateHint hint, CObject& params);
    void SetSampleText(const CString& strText, bool bUpdateView = true);
    CString GetSampleText() const;
    void SetSampleFigureId(FigureId figureId, bool bUpdateView = true);
    FigureId GetSampleFigureId() const;
    void SetSampleBitmapId(BitmapId bitmapId, bool bUpdateView = true);
    BitmapId GetSampleBitmapId() const;
	void SetSampleBrushTypeId(BrushTypeId brushTypeId, bool bUpdateView = true);
	BrushTypeId GetSampleBrushTypeId() const;
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
	BrushTypeId m_sampleBrushTypeId{ static_cast<BrushTypeId>(0) }; // BrushTypeId::unknown 
};

#include "DemoDocument.inl"

