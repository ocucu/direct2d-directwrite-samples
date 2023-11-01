
inline void CGradientBrushParameters::SetGradientStop(size_t index, const D2D1_GRADIENT_STOP& gradientStop)
{
    m_arrGradientStops[index] = gradientStop;
}

inline void CGradientBrushParameters::SetGradientStopPosition(size_t index, FLOAT position)
{
    m_arrGradientStops[index].position = position;
}

inline void CGradientBrushParameters::SetGradientStopColor(size_t index, COLORREF color, int nAlpha /*= 255*/)
{
    m_arrGradientStops[index].color = CRenderTarget::COLORREF_TO_D2DCOLOR(color, nAlpha);
}

inline D2D1_GRADIENT_STOP CGradientBrushParameters::GetGradientStop(size_t index) const
{
    return m_arrGradientStops[index];
}

inline FLOAT CGradientBrushParameters::GetGradientStopPosition(size_t index) const
{
    return  m_arrGradientStops[index].position;
}

inline D2D1_COLOR_F CGradientBrushParameters::GetGradientStopColor(size_t index) const
{
    return  m_arrGradientStops[index].color;
}

inline void CGradientBrushParameters::SetColorInterpolationGamma(DWORD_PTR dwValue)
{
    m_colorInterpolationGamma = static_cast<D2D1_GAMMA>(dwValue);
}

inline void CGradientBrushParameters::SetColorInterpolationGamma(D2D1_GAMMA gamma)
{
    m_colorInterpolationGamma = gamma;
}

inline D2D1_GAMMA CGradientBrushParameters::GetColorInterpolationGamma() const
{
    return m_colorInterpolationGamma;
}

inline void CGradientBrushParameters::SetExtendMode(DWORD_PTR dwValue)
{
    m_extendMode = static_cast<D2D1_EXTEND_MODE>(dwValue);
}

inline D2D1_EXTEND_MODE CGradientBrushParameters::GetExtendMode() const
{
    return m_extendMode;
}