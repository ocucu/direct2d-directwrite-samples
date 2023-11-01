// File: SamplePane.inl - inline definitions for CSamplePane class
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

inline SampleId CSamplePane::GetSampleId() const
{
    return m_sampleId;
}

inline CString CSamplePane::GetSampleName() const
{
    return m_strSampleName;
}

inline void CSamplePane::SetSampleText(UINT nResId)
{
    ATLVERIFY(m_strSampleText.LoadString(nResId));
}

inline CString CSamplePane::GetSampleText() const
{
    return m_strSampleText;
}

inline FigureId CSamplePane::GetSampleFigureId() const
{
    return m_sampleFigureId;
}

inline BitmapId CSamplePane::GetSampleBitmapId() const
{
    return m_sampleBitmapId;
}



