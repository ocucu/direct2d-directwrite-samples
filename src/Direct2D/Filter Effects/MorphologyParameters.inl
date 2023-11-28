
inline void CMorphologyParameters::SetMode(DWORD_PTR dwValue)
{
    m_mode = static_cast<D2D1_MORPHOLOGY_MODE>(dwValue);
}

inline D2D1_MORPHOLOGY_MODE CMorphologyParameters::GetMode() const
{
    return m_mode;
}

inline void CMorphologyParameters::SetWidth(int nValue)
{
    m_width = static_cast<UINT>(nValue);
}

inline UINT CMorphologyParameters::GetWidth() const
{
    return m_width;
}

inline void CMorphologyParameters::SetHeight(int nValue)
{
    m_height = static_cast<UINT>(nValue);
}

inline UINT CMorphologyParameters::GetHeight() const
{
    return m_height;
}

inline CMorphologyParameters& CMorphologyParameters::operator=(const CMorphologyParameters& params)
{
    if (this != &params)
    {
        m_mode = params.m_mode;
        m_width = params.m_width;
        m_height = params.m_height;
    }
    return *this;
}
