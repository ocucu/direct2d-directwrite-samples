// File: TranslationParameters.h - CTranslationParameters class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/ 

#pragma once

namespace Parameters
{
    class CTranslationParameters final : public CSampleParameters
    {
    public:
        // Data access
        void SetSize(int width, int height);
        const CD2DSizeF& GetSize() const;
        // Copy
        CTranslationParameters& operator=(CTranslationParameters& params);
    private:
        // Data
        CD2DSizeF m_size;
    };

#include "TranslationParameters.inl"
} // namespace Parameters



