// File: DirectionParameters.h - CDirectionParameters class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: encapsulates the text flow and reading direction options 

#pragma once

namespace Parameters
{
    class CDirectionParameters final : public CSampleParameters
    {
    public:
        // Data access
        void SetFlowDirection(DWORD_PTR dwValue);
        DWRITE_FLOW_DIRECTION GetFlowDirection() const;
        void SetReadingDirection(DWORD_PTR dwValue);
        DWRITE_READING_DIRECTION GetReadingDirection() const;
        // Copy
        CDirectionParameters& operator=(const CDirectionParameters& params);
    private:
        // Data
        DWRITE_FLOW_DIRECTION m_flowDirection{ DWRITE_FLOW_DIRECTION_TOP_TO_BOTTOM };
        DWRITE_READING_DIRECTION m_readingDirection{ DWRITE_READING_DIRECTION_LEFT_TO_RIGHT };
    };

#include "DirectionParameters.inl"
} // namespace Parameters
