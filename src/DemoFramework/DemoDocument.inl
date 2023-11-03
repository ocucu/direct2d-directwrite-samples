
inline void CDemoDocument::UpdateView(UpdateHint hint, CObject& params)
{
    LPARAM lHint = static_cast<LPARAM>(hint);
    UpdateAllViews(NULL, lHint, &params);
}

inline void CDemoDocument::SetSampleText(const CString& strText)
{
    m_strSampleText = strText;
    UpdateAllViews(NULL, 0, NULL);
}

inline CString CDemoDocument::GetSampleText() const
{
    return m_strSampleText;
}

inline void CDemoDocument::SetSampleFigureId(FigureId figureId)
{
    m_sampleFigureId = figureId;
    UpdateAllViews(NULL, 0, NULL);
}

inline FigureId CDemoDocument::GetSampleFigureId() const
{
    return m_sampleFigureId;
}

inline void CDemoDocument::SetSampleBitmapId(BitmapId bitmapId)
{
    m_sampleBitmapId = bitmapId;
    UpdateAllViews(NULL, 0, NULL);
}

inline BitmapId CDemoDocument::GetSampleBitmapId() const
{
    return m_sampleBitmapId;
}

inline void CDemoDocument::SetSampleBrushTypeId(BrushTypeId brushTypeId)
{
	m_sampleBrushTypeId = brushTypeId;
	UpdateAllViews(NULL, 0, NULL);

}

inline BrushTypeId CDemoDocument::GetSampleBrushTypeId() const
{
	return m_sampleBrushTypeId;
}