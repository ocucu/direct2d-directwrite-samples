#pragma once

namespace Parameters
{
    class CTextLayoutParameters : public CObject
    {
    public:
        // Data access
        void SetMaxSize(const CD2DSizeF& sizeMax);
        const CD2DSizeF& GetMaxSize() const;
        void SetTextRange(const DWRITE_TEXT_RANGE& textRange);
        const DWRITE_TEXT_RANGE& GetTextRange() const;
        // Copy
        CTextLayoutParameters& operator=(const CTextLayoutParameters& params);
    private:
        // Data
        DWRITE_TEXT_RANGE m_textRange{ 0, 0 };
        CD2DSizeF m_sizeMax{ 456.f, 380.f };
        //FLOAT m_maxWidth{ 456.f };
        //FLOAT m_maxHeight{ 380.f };
    };

#include "TextLayoutParameters.inl"
} // namespace Parameters
