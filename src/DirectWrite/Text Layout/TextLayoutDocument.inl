#include "InlineImage.h"

inline CD2DSolidColorBrush* CTextLayoutDocument::GetTextBrush() const
{
    return m_pTextBrush;
}

inline CD2DSolidColorBrush* CTextLayoutDocument::GetSolidColorBrush() const
{
    return m_pSolidColorBrush;
}

inline CD2DLinearGradientBrush* CTextLayoutDocument::GetGradientBrush() const
{
    return m_pGradientBrush;
}

inline CD2DBitmapBrush* CTextLayoutDocument::GetBitmapBrush() const
{
    return m_pBitmapBrush;
}

inline CD2DSolidColorBrush* CTextLayoutDocument::GetBackgroundBrush() const
{
    return m_pBackgroundBrush;
}

inline std::shared_ptr<CInlineImage> CTextLayoutDocument::GetRingsImage() const
{
    return m_spRingsImage;
}

inline std::shared_ptr<CInlineImage> CTextLayoutDocument::GetRoseImage() const
{
    return m_spRoseImage;
}

inline std::shared_ptr<CInlineImage> CTextLayoutDocument::GetDogImage() const
{
    return m_spDogImage;
}

