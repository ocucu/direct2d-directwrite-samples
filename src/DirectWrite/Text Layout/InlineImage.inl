
inline IDWriteInlineObject* CInlineImage::Get()
{
    return &m_xInlineImage;
}

inline CInlineImage::operator IDWriteInlineObject*()
{
    return Get();
}