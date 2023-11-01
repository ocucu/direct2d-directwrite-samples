// File: TrimmingParameters.h - CTrimmingParameters class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: encapsulates the text trimming options 

#pragma once

namespace Parameters
{
    class CTrimmingParameters final : public CSampleParameters
    {
    public:
        // Data access
        void SetTrimmingGranularity(DWORD_PTR dwValue);
        void SetTrimmingGranularity(DWRITE_TRIMMING_GRANULARITY trimmingGranularity);
        void SetDelimiter(DWORD_PTR dwValue);
        void SetDelimiterCount(int nValue);
        DWRITE_TRIMMING GetTrimming() const;
        // Copy
        CTrimmingParameters& operator=(const CTrimmingParameters& params);
    private:
        // Data
        DWRITE_TRIMMING m_trimming{ DWRITE_TRIMMING_GRANULARITY_NONE, 0, 0 };
    };

#include "TrimmingParameters.inl"
} // namespace Parameters
