
inline void CDirectionalBlurParameters::SetAngle(FLOAT value)
{
    m_angle = value;
}

inline FLOAT CDirectionalBlurParameters::GetAngle() const
{
    return m_angle;
}

inline CDirectionalBlurParameters& CDirectionalBlurParameters::operator=(const CDirectionalBlurParameters& params)
{
    if (this != &params)
    {
        // inherited from CGaussianBlurParameters
        SetStandardDeviation(params.GetStandardDeviation());
        SetOptimization(params.GetOptimization());
        SetBorderMode(params.GetBorderMode());
        // this class data
        m_angle = params.m_angle;
    }
    return *this;
}