#pragma once

namespace Parameters
{
    class CStraightenParameters final : public CObject
    {
    public:
        // Data access
        void SetAngle(FLOAT value);
        FLOAT GetAngle() const;
        void SetMaintainSize(BOOL value);
        BOOL GetMaintainSize() const;
        void SetScaleMode(DWORD_PTR dwValue);
        D2D1_STRAIGHTEN_SCALE_MODE GetScaleMode() const;

        // Copy
        CStraightenParameters& operator=(const CStraightenParameters& params);
    private:
        // Data
        FLOAT m_angle{ 0.f };
        BOOL m_maintainSize{ FALSE };
        D2D1_STRAIGHTEN_SCALE_MODE m_scaleMode;
    };

#include "StraightenParameters.inl"
} // namespace Parameters