// File: D2DText.h - CD2DText class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: Utility class with methods for handling texts such as get the text range for a given tag

#pragma once

class DEMOFRAMEWORK_EXP CD2DText
{
public:
    CD2DText(const CString& strText) : m_strText{ strText } {}
    ~CD2DText() = default;
    // Operations
    const CString& GetString() { return m_strText; }
    int GetLength() { return m_strText.GetLength(); }
    int GetTagTextRange(const CString& strTag, DWRITE_TEXT_RANGE& textRange, int nStartPos = 0);
private:
    // Data
    CString m_strText;
};

