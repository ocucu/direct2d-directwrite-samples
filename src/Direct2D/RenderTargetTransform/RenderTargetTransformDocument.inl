
namespace Framework
{
    inline CD2DSolidColorBrush* CRenderTargetTransformDocument::GetTextBrush()
    {
        return m_pTextBrush;
    }

    inline CD2DSolidColorBrush* CRenderTargetTransformDocument::GetLineBrush()
    {
        return m_pLineBrush;
    }

    inline CD2DLinearGradientBrush* CRenderTargetTransformDocument::GetFillBrush()
    {
        return m_pFillBrush;
    }

    inline CD2DPathGeometry* CRenderTargetTransformDocument::GetArrowGeometry()
    {
        return m_pArrowGeometry;
    }

    inline CD2DBitmap* CRenderTargetTransformDocument::GetPictureBitmap()
    {
        return m_pPictureBitmap;
    }

    inline CD2DBitmap* CRenderTargetTransformDocument::GetScaleCenterBitmap()
    {
        return m_pScaleCenterBitmap;
    }

    inline CD2DBitmap* CRenderTargetTransformDocument::GetRotateCenterBitmap()
    {
        return m_pRotateCenterBitmap;
    }

    inline CD2DBitmap* CRenderTargetTransformDocument::GetSkewCenterBitmap()
    {
        return m_pSkewCenterBitmap;
    }
} // namespace Framework