
namespace Framework
{
    inline CD2DBitmap* CBrushDocument::GetColorMatrixBitmap() const
    {
        return m_pColorMatrixBitmap;
    }

    inline CD2DBitmap* CBrushDocument::GetCatBitmap() const
    {
        return m_pCatBitmap;
    }

    inline CD2DBitmap* CBrushDocument::GetMFCIconBitmap() const
    {
        return m_pMFCIconBitmap;
    }

    inline CD2DSolidColorBrush* CBrushDocument::GetDrawInfoBrush() const
    {
        return m_pDrawInfoBrush;
    }
} // namespace Framework
