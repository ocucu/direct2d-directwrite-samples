// File: AlignmentParameters.h - CAlignmentParameters class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: encapsulates the text and paragraph alignment options 

#pragma once

namespace Parameters
{
    class CAlignmentParameters final : public CSampleParameters
    {
    public:
        // Data access
        void SetTextAlignment(DWORD_PTR dwValue);
        DWRITE_TEXT_ALIGNMENT GetTextAlignment() const;
        void SetParagraphAlignment(DWORD_PTR dwValue);
        DWRITE_PARAGRAPH_ALIGNMENT GetParagraphAlignment() const;
        // Copy
        CAlignmentParameters& operator=(const CAlignmentParameters& params);
    private:
        // Data
        DWRITE_TEXT_ALIGNMENT m_textAlignment{ DWRITE_TEXT_ALIGNMENT_LEADING };
        DWRITE_PARAGRAPH_ALIGNMENT m_paragraphAlignment{ DWRITE_PARAGRAPH_ALIGNMENT_NEAR };
    };

#include "AlignmentParameters.inl"
}
