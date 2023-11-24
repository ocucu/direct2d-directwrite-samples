
inline void CHighlightsAndShadowsParameters::SetHighlights(FLOAT value)
{
    m_highlights = value;
}

inline FLOAT CHighlightsAndShadowsParameters::GetHighlights() const
{
    return m_highlights;
}

inline void CHighlightsAndShadowsParameters::SetShadows(FLOAT value)
{
    m_shadows = value;
}

inline FLOAT CHighlightsAndShadowsParameters::GetShadows() const
{
    return m_shadows;
}

inline void CHighlightsAndShadowsParameters::SetClarity(FLOAT value)
{
    m_clarity = value;
}

inline FLOAT CHighlightsAndShadowsParameters::GetClarity() const
{
    return m_clarity;
}

inline void CHighlightsAndShadowsParameters::SetInputGamma(DWORD_PTR dwValue)
{
    m_inputGamma = static_cast<D2D1_HIGHLIGHTSANDSHADOWS_INPUT_GAMMA>(dwValue);
}

inline D2D1_HIGHLIGHTSANDSHADOWS_INPUT_GAMMA CHighlightsAndShadowsParameters::GetInputGamma() const
{
    return m_inputGamma;
}

inline void CHighlightsAndShadowsParameters::SetMaskBlurRadius(FLOAT value)
{
    m_maskBlurRadius = value;
}

inline FLOAT CHighlightsAndShadowsParameters::GetMaskBlurRadius() const
{
    return m_maskBlurRadius;
}

// Copy
inline CHighlightsAndShadowsParameters& CHighlightsAndShadowsParameters::operator=(const CHighlightsAndShadowsParameters& params)
{
    if (this != &params)
    {
        m_highlights = params.m_highlights;
        m_shadows = params.m_shadows;
        m_clarity = params.m_clarity;
        m_inputGamma = params.m_inputGamma;
        m_maskBlurRadius = params.m_maskBlurRadius;
    }
    return *this;
}
