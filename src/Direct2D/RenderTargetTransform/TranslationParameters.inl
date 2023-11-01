// File: TranslationParameters.inl - inline definitions for CTranslationParameters class
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

inline void CTranslationParameters::SetSize(int width, int height)
{
    m_size.width = static_cast<FLOAT>(width);
    m_size.height = static_cast<FLOAT>(height);
}

inline const CD2DSizeF& CTranslationParameters::GetSize() const
{
    return m_size;
}

inline CTranslationParameters& CTranslationParameters::operator=(CTranslationParameters& params)
{
    if (this != &params)
    {
        SetRedrawFlag(params.GetRedrawFlag());
        m_size = params.m_size;
    }
    return *this;
}
