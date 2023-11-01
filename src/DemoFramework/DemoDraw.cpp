#include "pch.h"
#include "DemoFramework.h"
#include "DemoDraw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CDemoDraw::CDemoDraw(CDemoView* pView)
    : m_pView(pView)
{
    ATLASSERT(m_pView->GetSafeHwnd());
}
