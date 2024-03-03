#include "pch.h"
#include "DemoFramework.h"
#include "D2DText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int CD2DText::GetTagTextRange(const CString& strTag, DWRITE_TEXT_RANGE& textRange, int nStartPos /*= 0*/)
{
    textRange.startPosition = m_strText.Find(strTag, nStartPos);
    if (-1 == textRange.startPosition)
        return -1; // not found

    textRange.length = strTag.GetLength();
    return textRange.startPosition + textRange.length; // first position after the tag
}
