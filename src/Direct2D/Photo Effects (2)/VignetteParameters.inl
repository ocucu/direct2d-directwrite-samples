
inline void CVignetteParameters::SetColor(COLORREF color, FLOAT opacity)
{
    D2D1_COLOR_F colorF = CRenderTarget::COLORREF_TO_D2DCOLOR(color);
    m_color =  D2D1::ColorF(colorF.r, colorF.g, colorF.b, opacity);
}

inline D2D1::ColorF CVignetteParameters::GetColor() const
{
    return m_color;
}

inline void CVignetteParameters::SetTransitionSize(FLOAT value)
{
    m_transitionSize = value;
}

inline FLOAT CVignetteParameters::GetTransitionSize() const
{
    return m_transitionSize;
}

inline void CVignetteParameters::SetStrength(FLOAT value)
{
    m_strength = value;
}

inline FLOAT CVignetteParameters::GetStrength() const
{
    return m_strength;
}

inline CVignetteParameters& CVignetteParameters::operator=(const CVignetteParameters& params)
{
    if (this != &params)
    {
        m_color = params.m_color;
        m_transitionSize = params.m_transitionSize;
        m_strength = params.m_strength;
    }
    return *this;
}
