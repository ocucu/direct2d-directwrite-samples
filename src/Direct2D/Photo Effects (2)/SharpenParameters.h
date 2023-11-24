
#pragma once

namespace Parameters
{
    class CSharpenParameters final : public CObject
    {
    public:
        // Data access
        void SetSharpness(FLOAT value);
        FLOAT GetSharpness() const;
        void SetThreshold(FLOAT value);
        FLOAT GetThreshold() const;
        // Copy
        CSharpenParameters& operator=(const CSharpenParameters& params);
    private:
        // Data
        FLOAT m_sharpness{ 0.f };
        FLOAT m_threshold{ 0.f };
    };

#include "SharpenParameters.inl"
} // namespace Parameters 


