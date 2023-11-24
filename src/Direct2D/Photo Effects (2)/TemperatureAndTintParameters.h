#pragma once

namespace Parameters
{
    class CTemperatureAndTintParameters final : public CObject
    {
    public:
        // Data access
        void SetTemperature(FLOAT value);
        FLOAT GetTemperature() const;
        void SetTint(FLOAT value);
        FLOAT GetTint() const;
        // Copy
        CTemperatureAndTintParameters& operator=(const CTemperatureAndTintParameters& params);
    private:
        // Data
        FLOAT m_temperature{ 0.f };
        FLOAT m_tint{ 0.f };
    };

#include "TemperatureAndTintParameters.inl"
} // namespace Parameters
