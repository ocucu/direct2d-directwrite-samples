// File: TabStopParameters.h - CTabStopParameters class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Allows user to change the distance between two adjacent tab stops
// Note: If m_tabStopMethod is set to TAB_STOP_METHOD_FIXED, then m_tabStopDistance  
//       is passed to IDWriteTextFormat::SetIncrementalTabStop.
//       Otherwse, it is ignored.

#pragma once

namespace Parameters
{
    class CTabStopParameters final : public CSampleParameters
    {
    public:
        // Data access
        void SetTabStopMethod(DWORD_PTR dwValue);
        TAB_STOP_METHOD GetTabStopMethod() const;
        void SetTabStopDistance(int nValue);
        FLOAT GetTabStopDistance() const;
        // Copy
        CTabStopParameters& operator=(const CTabStopParameters& params);
    private:
        // Data
        TAB_STOP_METHOD m_tabStopMethod{ TAB_STOP_METHOD_DEFAULT };
        FLOAT m_tabStopDistance{ 0.f };
    };

#include "TabStopParameters.inl"
} // namespace Parameters
