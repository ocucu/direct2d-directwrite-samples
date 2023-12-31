
inline void CDemoDocument::UpdateView(UpdateHint hint, CObject& params)
{
    LPARAM lHint = static_cast<LPARAM>(hint);
    UpdateAllViews(NULL, lHint, &params);
}

inline void CDemoDocument::SetSampleText(const CString& strText, bool bUpdateView /*= true*/)
{
    m_strSampleText = strText;
    if (bUpdateView)
    {
        UpdateAllViews(NULL, 0, NULL);
    }
}

inline CString CDemoDocument::GetSampleText() const
{
    return m_strSampleText;
}

inline void CDemoDocument::SetSampleFigureId(FigureId figureId, bool bUpdateView /*= true*/)
{
    m_sampleFigureId = figureId;
    if(bUpdateView)
    {
        UpdateAllViews(NULL, 0, NULL);
    }
}

inline FigureId CDemoDocument::GetSampleFigureId() const
{
    return m_sampleFigureId;
}

inline void CDemoDocument::SetSampleBitmapId(BitmapId bitmapId, bool bUpdateView /*= true*/)
{
    m_sampleBitmapId = bitmapId;
    if (bUpdateView)
    {
        UpdateAllViews(NULL, 0, NULL);
    }
}

inline BitmapId CDemoDocument::GetSampleBitmapId() const
{
    return m_sampleBitmapId;
}

inline void CDemoDocument::SetSampleBrushTypeId(BrushTypeId brushTypeId, bool bUpdateView /*= true*/)
{
	m_sampleBrushTypeId = brushTypeId;
    if (bUpdateView)
    {
        UpdateAllViews(NULL, 0, NULL);
    }
}

inline BrushTypeId CDemoDocument::GetSampleBrushTypeId() const
{
	return m_sampleBrushTypeId;
}