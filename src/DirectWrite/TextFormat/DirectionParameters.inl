// File: DirectionParameters.inl - inline definitions for CDirectionParameters class
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

inline void CDirectionParameters::SetFlowDirection(DWORD_PTR dwValue)
{
    m_flowDirection = static_cast<DWRITE_FLOW_DIRECTION>(dwValue);
}

inline DWRITE_FLOW_DIRECTION CDirectionParameters::GetFlowDirection() const
{
    return m_flowDirection;
}

inline void CDirectionParameters::SetReadingDirection(DWORD_PTR dwValue)
{
    m_readingDirection = static_cast<DWRITE_READING_DIRECTION>(dwValue);
}

inline DWRITE_READING_DIRECTION CDirectionParameters::GetReadingDirection() const
{
    return m_readingDirection;
}

inline CDirectionParameters& CDirectionParameters::operator=(const CDirectionParameters& params)
{
    if (this != &params)
    {
        SetRedrawFlag(params.GetRedrawFlag());
        m_flowDirection = params.m_flowDirection;
        m_readingDirection = params.m_readingDirection;
    }
    return *this;
}
