// File: WordWrappingParameters.h - CWordWrappingParameters class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: encapsulates the text word wrapping option 

#pragma once

namespace Parameters
{
    class CWordWrappingParameters final : public CSampleParameters
    {
    public:
        // Data access
        void SetWordWrapping(DWORD_PTR dwValue);
        void SetWordWrapping(DWRITE_WORD_WRAPPING wordWrapping);
        DWRITE_WORD_WRAPPING GetWordWrapping() const;
        // Copy
        CWordWrappingParameters& operator=(const CWordWrappingParameters& params);
    private:
        // Data
        DWRITE_WORD_WRAPPING m_wordWrapping{ DWRITE_WORD_WRAPPING_WRAP };
    };

#include "WordWrappingParameters.inl"
} // namespace Parameters
