#pragma once

namespace Parameters
{
    class CExposureParameters final : public CObject
    {
    public:
        // Data access
        void SetValue(FLOAT value);
        FLOAT GetValue() const;
        // Copy
        CExposureParameters& operator=(const CExposureParameters& params);
    private:
        // Data
        FLOAT m_value{ 0.f };
    };

#include "ExposureParameters.inl"
} // namespace Parameters
