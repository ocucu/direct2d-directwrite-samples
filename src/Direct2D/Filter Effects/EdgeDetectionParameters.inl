
inline void CEdgeDetectionParameters::SetStrength(FLOAT value)
{
    m_strength = value;
}

inline FLOAT CEdgeDetectionParameters::GetStrength() const
{
    return m_strength;
}

inline void CEdgeDetectionParameters::SetBlurRadius(FLOAT value)
{
    m_blurRadius = value;
}

inline FLOAT CEdgeDetectionParameters::GetBlurRadius() const
{
    return m_blurRadius;
}

inline void CEdgeDetectionParameters::SetMode(DWORD_PTR dwValue)
{
    m_mode = static_cast<D2D1_EDGEDETECTION_MODE>(dwValue);
}

inline D2D1_EDGEDETECTION_MODE CEdgeDetectionParameters::GetMode() const
{
    return m_mode;
}

inline void CEdgeDetectionParameters::SetOverlayEdges(BOOL bValue)
{
    m_bOverlayEdges = bValue;
}

inline BOOL CEdgeDetectionParameters::GetOverlayEdges() const
{
    return m_bOverlayEdges;
}

inline void CEdgeDetectionParameters::SetAlphaMode(DWORD_PTR dwValue)
{
    m_alphaMode = static_cast<D2D1_ALPHA_MODE>(dwValue);
}

inline D2D1_ALPHA_MODE CEdgeDetectionParameters::GetAlphaMode() const
{
    return m_alphaMode;
}

inline CEdgeDetectionParameters& CEdgeDetectionParameters::operator=(const CEdgeDetectionParameters& params)
{
    if (this != &params)
    {
        m_strength = params.m_strength;
        m_blurRadius = params.m_blurRadius;
        m_mode = params.m_mode;
        m_bOverlayEdges = params.m_bOverlayEdges;
        m_alphaMode = params.m_alphaMode;
    }
    return *this;
}
