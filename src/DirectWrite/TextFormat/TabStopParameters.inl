// File: TabStopParameters.inl - inline definitions for CTabStopParameters class
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

inline void CTabStopParameters::SetTabStopMethod(DWORD_PTR dwValue)
{
    m_tabStopMethod = static_cast<TAB_STOP_METHOD>(dwValue);
}

inline TAB_STOP_METHOD CTabStopParameters::GetTabStopMethod() const
{
    return m_tabStopMethod;
}

inline void CTabStopParameters::SetTabStopDistance(int nValue)
{
    m_tabStopDistance = static_cast<FLOAT>(nValue);
}

inline FLOAT CTabStopParameters::GetTabStopDistance() const
{
    return m_tabStopDistance;
}

inline CTabStopParameters& CTabStopParameters::operator=(const CTabStopParameters& params)
{
    if (this != &params)
    {
        SetRedrawFlag(params.GetRedrawFlag());
        m_tabStopMethod = params.m_tabStopMethod;
        m_tabStopDistance = params.m_tabStopDistance;
    }
    return *this;
}
