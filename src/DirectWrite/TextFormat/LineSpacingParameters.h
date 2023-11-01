// File: LineSpacingParameters.h - CLineSpacingParameters class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: encapsulates the parameters for setting line spacing in a multiline paragraph 
// Note: For usability reasons, this class does not keep 'baseline' and 'lineSpacing' parameters 
// which are passed to IDWriteTextFormat::SetLineSpacing.
// Instead, it keeps a multiplication factor for calculating lineSpacing, i.e. lineSpacing = baseline * m_factor.
// See also the notes from LineSpacingPane.h

#pragma once

namespace Parameters
{
    class CLineSpacingParameters final : public CSampleParameters
    {
    public:
        // Data access
        void SetMethod(DWORD_PTR dwValue);
        DWRITE_LINE_SPACING_METHOD GetMethod() const;
        void SetFactor(FLOAT fValue);
        FLOAT GetFactor() const;
        // Copy
        CLineSpacingParameters& operator=(const CLineSpacingParameters& params);
    private:
        // Data
        DWRITE_LINE_SPACING_METHOD m_method{ DWRITE_LINE_SPACING_METHOD_DEFAULT };
        FLOAT m_factor{ 1.25f };
    };

#include "LineSpacingParameters.inl"
} // namespace Parameters
