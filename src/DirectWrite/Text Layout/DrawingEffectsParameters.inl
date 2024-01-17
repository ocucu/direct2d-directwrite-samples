
inline void CDrawingEffectsParameters::SetBrushColor(COLORREF color)
{
    m_brushColor = CRenderTarget::COLORREF_TO_D2DCOLOR(color);
}

inline D2D1_COLOR_F CDrawingEffectsParameters::GetBrushColor() const
{
    return m_brushColor;
}

inline CDrawingEffectsParameters& CDrawingEffectsParameters::operator=(const CDrawingEffectsParameters& params)
{
    if (this != &params)
    {
        // inherited from CTextLayoutParameters
        SetMaxSize(params.GetMaxSize());
        SetTextRange(params.GetTextRange());
        // this class parameters
        m_brushColor = params.m_brushColor;
    }
    return *this;
}