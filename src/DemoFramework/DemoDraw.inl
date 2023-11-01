
inline CDemoDocument*  CDemoDraw::GetDemoDocument()
{
    ASSERT_VALID(m_pView);
    return dynamic_cast<CDemoDocument*>(m_pView->GetDocument());
}

inline CDemoFrame*  CDemoDraw::GetDemoFrame()
{
    return dynamic_cast<CDemoFrame*>(AfxGetMainWnd());
}

inline void CDemoDraw::InvalidateView()
{
    ASSERT_VALID(m_pView);
    m_pView->Invalidate();
}
