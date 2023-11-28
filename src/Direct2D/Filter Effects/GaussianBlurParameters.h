#pragma once

namespace Parameters
{
    class CGaussianBlurParameters : public CObject
    {
    public:
        // Data access
        void SetStandardDeviation(FLOAT value);
        FLOAT GetStandardDeviation() const;
        void SetOptimization(DWORD_PTR dwValue);
        D2D1_DIRECTIONALBLUR_OPTIMIZATION GetOptimization() const;
        void SetBorderMode(DWORD_PTR dwValue);
        D2D1_BORDER_MODE GetBorderMode() const;
        // Copy
        CGaussianBlurParameters& operator=(const CGaussianBlurParameters& params);
    private:
        // Data
        FLOAT m_standardDeviation{ 3.0f };
        D2D1_DIRECTIONALBLUR_OPTIMIZATION m_optimization;
        D2D1_BORDER_MODE m_borderMode;
    };

#include "GaussianBlurParameters.inl"
} // namespace Parameters