#pragma once

class CSampleParameters : public CObject
{
public:
    // Data access
    void SetRedrawFlag(bool bRedraw = true) { m_bRedrawFlag = bRedraw; }
    bool GetRedrawFlag() const { return m_bRedrawFlag; }
protected:
    // Data
    bool m_bRedrawFlag{ false };
};


