
inline void CBrightnessParameters::SetWhitePoint(const D2D1_VECTOR_2F& value)
{
    m_whitePoint = value;
}

inline D2D1_VECTOR_2F CBrightnessParameters::GetWhitePoint() const
{
    return m_whitePoint;
}

inline void CBrightnessParameters::SetBlackPoint(const D2D1_VECTOR_2F& value)
{
    m_blackPoint = value;
}

inline D2D1_VECTOR_2F CBrightnessParameters::GetBlackPoint() const
{
    return m_blackPoint;
}

inline CBrightnessParameters& CBrightnessParameters::operator=(const CBrightnessParameters& params)
{
    if (this != &params)
    {
        m_whitePoint = params.m_whitePoint;
        m_blackPoint = params.m_blackPoint;
    }
    return *this;
}